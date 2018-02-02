#include "Tester.h"
#include <iostream>
#include "StringFuncs.h"
#include <assert.h>
#include <string>

const int bufferSize = 1000;
char      buffer [bufferSize];
char      buffer2[bufferSize];
char      buffer3[bufferSize];

Tester::Tester ()
    {
    m_cmds.push_back (Command ("equal",      Request::equal,      Equal));
    m_cmds.push_back (Command ("palindrome", Request::palindrome, Palindrome));
    m_cmds.push_back (Command ("compare",    Request::compare,    Compare));
    m_cmds.push_back (Command ("len",        Request::len,        Len));
    m_cmds.push_back (Command ("sub",        Request::sub,        Sub));
    m_cmds.push_back (Command ("reverse",    Request::reverse,    Reverse));
    m_cmds.push_back (Command ("lower",      Request::lower,      Lower));
    m_cmds.push_back (Command ("copy",       Request::copy,       Copy));
    m_cmds.push_back (Command ("dup",        Request::dup,        Dup));
    m_cmds.push_back (Command ("reverse2",   Request::reverse2,   Reverse2));
    m_cmds.push_back (Command ("concat",     Request::concat,     Concat));
    m_cmds.push_back (Command ("lower2",     Request::lower2,     Lower2));
    m_cmds.push_back (Command ("vowels",     Request::vowels,     Vowels));
    m_cmds.push_back (Command ("test",       Request::test,       Test));
    m_cmds.push_back (Command ("quit",       Request::quit));
    m_cmds.push_back (Command ("exit",       Request::quit));
    m_cmds.push_back (Command ("x",          Request::quit));
    m_cmds.push_back (Command ("q",          Request::quit));
    }

Tester::~Tester ()
    {
    }

void Tester::ProcessInput ()
    {
    for (;;)
        {
        Command c = GetCommand ();
        if (c.m_req == Request::quit) return;
        if (c.m_req == Request::unknown)
            {
            printf ("Ignoring Unknown command [%s]\n", c.m_str);
            continue;
            }
        c.m_func ();  // execute the function for this command
        }
    }

Command Tester::GetCommand ()
    {
    printf ("Please enter a command: ");
    std::cin >> buffer;
    StringFuncs::ToLower (buffer);
    for (Command& c : m_cmds)
        {
        bool compare = (0 == StringFuncs::StringCompare   (buffer, c.m_str));
        bool equals  =       StringFuncs::StringsAreEqual (buffer, c.m_str);
        assert (compare == equals);
        if (equals) return c;
        }
    return Command (buffer, Request::unknown);
    }

void Tester::Equal ()
    {
    std::cin >> buffer >> buffer2;
    bool result = StringFuncs::StringsAreEqual (buffer, buffer2);
    printf ("StringsAreEqual(\"%s\", \"%s\") is %s\n", buffer, buffer2, TF (result));
    }

void Tester::Palindrome ()
    {
    std::cin >> buffer;
    bool result = StringFuncs::IsPalindrome (buffer);
    printf ("IsPalindrome(\"%s\") is %s\n", buffer, TF (result));
    }

void Tester::Compare ()
    {
    std::cin >> buffer >> buffer2;
    int result = StringFuncs::StringCompare (buffer, buffer2);
    printf ("StringCompare(\"%s\", \"%s\") returns %d ", buffer, buffer2, result);
    if      (result <  0) printf ("because %s <  %s.\n", buffer, buffer2);
    else if (result == 0) printf ("because %s == %s.\n", buffer, buffer2);
    else                  printf ("because %s >  %s.\n", buffer, buffer2);
    }

void Tester::Concat ()
    {
    std::cin >> buffer >> buffer2 >> buffer3;
    if (StringFuncs::StringsAreEqual (buffer3, "xyz")) *buffer3 = '\0';
    char* deleteMe = StringFuncs::StringConcat (buffer, buffer2, buffer3);
    printf ("StringConcat(\"%s\", \"%s\", \"%s\") = [%s]\n", buffer, buffer2, buffer3, deleteMe);
    delete[] deleteMe;
    }

void Tester::Lower2 ()
    {
    std::cin >> buffer;
    const char* const p = buffer;
    char* deleteMe = StringFuncs::ToLower (p);
    assert (buffer != deleteMe);
    printf ("ToLower((const char*)\"%s\") is %s\n", buffer, deleteMe);
    delete[] deleteMe;
    }

void Tester::Vowels ()
    {
    /*std::cin >> buffer;
    int vowels = StringFuncs::CountVowels (buffer);
    printf ("CountVowels(\"%s\") = %d\n.", buffer, vowels);*/
    }

void T (bool cond, const char* str)
    {
    const  int  bufsiz       = 100;
    static int  numTests     = 0;
    static int  currTest     = 0;
    static char buff[bufsiz] = { '0' };
    ++numTests;
    if (strcmp (buff, str))
        {
        strcpy_s (buff, bufsiz, str);
        currTest = 1;
        printf ("----\n");
        }
    else ++currTest;
    char* result = cond ? "...." : "FAIL";
    printf ("Test %3d: %s : %2d - %s\n", numTests, result, currTest, str);
    }

void Tester::Test ()
    {
    printf ("----- Begin Test -----\n");
    char s1[] = "umbrella";
    char s2[] = "zmbrella";
    char s3[] = "Madam";
    char s4[] = "madam";
    char s5[] = "allerbmu";
    char s6[] = "a";
    char s7[] = "";
    char s8[] = "WOW! That HURT!";
    char s9[] = "wow! that hurt!";

    char t1[] = "start";
    char t2[] = "engines";
    char t3[] = ".your.";
    char t4[] = "start.your.engines";
    char t5[] = "A";
    char t6[] = "";

    T (!StringFuncs::StringsAreEqual (s1, s2), "Equal");
    *s2 = 'u';
    T ( StringFuncs::StringsAreEqual (s1, s2),  "Equal");
    T ( StringFuncs::StringsAreEqual ("", ""),  "Equal");
    T (!StringFuncs::StringsAreEqual ("", "a"), "Equal");
    T (!StringFuncs::StringsAreEqual ("a", ""), "Equal");
  // T ( StringFuncs::StringsAreEqual (0, 0),    "Equal");

    T (!StringFuncs::IsPalindrome (s3),    "Palindrome");
    T ( StringFuncs::IsPalindrome (s4),    "Palindrome");
    T ( StringFuncs::IsPalindrome (""),    "Palindrome");
  // T ( StringFuncs::IsPalindrome (0),     "Palindrome"); // aborts on purpose

    T (0 <  StringFuncs::StringCompare (s1, s4),  "Compare");
    T (0 == StringFuncs::StringCompare (s1, s2),  "Compare");
    T (0 >  StringFuncs::StringCompare (s4, s1),  "Compare");
    T (0 == StringFuncs::StringCompare ("", ""),  "Compare");
    T (0 >  StringFuncs::StringCompare ("", "a"), "Compare");
    T (0 <  StringFuncs::StringCompare ("a", ""), "Compare");

    T (8 == StringFuncs::StringLen (s1),  "Len");
    T (1 == StringFuncs::StringLen ("a"), "Len");
    T (0 == StringFuncs::StringLen (""),  "Len");
  //  T (0 == StringFuncs::StringLen (0),   "Len"); // picky - you can ignore this

    T ( 2 == StringFuncs::FindSubString (s1, "bre"), "Sub");
    T ( 5 == StringFuncs::FindSubString (s1, "l"),   "Sub");
    T (-1 == StringFuncs::FindSubString (s1, "lll"), "Sub");
  //  T ( 0 == StringFuncs::FindSubString (s1, ""),    "Sub");    // you can ignore this
    T (-1 == StringFuncs::FindSubString ("", "abc"), "Sub");
  //  T ( 0 == StringFuncs::FindSubString ("", ""),    "Sub");    // ignore this

    T (0 == strcmp (s5,  StringFuncs::StringReverse (s1)), "Reverse"); // in-place modify!
    T (0 == strcmp (s2,  StringFuncs::StringReverse (s1)), "Reverse"); // should be ok after this
    T (0 == strcmp ("a", StringFuncs::StringReverse (s6)), "Reverse");
    T (0 == strcmp ("",  StringFuncs::StringReverse (s7)), "Reverse");

    const int siz = bufferSize;
    strcpy_s (buffer, siz, s8);
    T (0 == strcmp (s9,  StringFuncs::ToLower (buffer)), "Lower");
    strcpy_s (buffer, siz, "A");
    T (0 == strcmp (s6,  StringFuncs::ToLower (buffer)), "Lower");
    strcpy_s (buffer, siz, "");
    T (0 == strcmp ("",  StringFuncs::ToLower (buffer)), "Lower");

    T ((8 == StringFuncs::StringCopy (s1, buffer, siz)) && (0 == strcmp(s1, buffer)), "Copy");
    T ((1 == StringFuncs::StringCopy (s6, buffer, siz)) && (0 == strcmp(s6, buffer)), "Copy");
    T ((0 == StringFuncs::StringCopy ("", buffer, siz)) && (0 == strcmp("", buffer)), "Copy");

    char*p;
    T ((0 != (p = StringFuncs::StringDup (s1))) && (p != s1) && (0 == strcmp(s1, p)), "Dup");
    delete[] p;
    T ((0 != (p = StringFuncs::StringDup (s6))) && (p != s6) && (0 == strcmp(s6, p)), "Dup");
    delete[] p;
    T ((0 != (p = StringFuncs::StringDup (s7))) && (p != s7) && (0 == strcmp(s7, p)), "Dup");
    delete[] p;

    T ((0 != (p = StringFuncs::StringReverse ((const char*)s1))) && (p != s1) && (0 == strcmp(s5, p)), "Reverse2");
    delete[] p;
    T ((0 != (p = StringFuncs::StringReverse ((const char*)s6))) && (p != s1) && (0 == strcmp(s6, p)), "Reverse2");
    delete[] p;
    T ((0 != (p = StringFuncs::StringReverse ((const char*)""))) && (p != s1) && (0 == strcmp("", p)), "Reverse2");
    delete[] p;

    T ((0 != (p = StringFuncs::StringConcat (t1, t2, t3))) && (0 == strcmp (t4, p)), "Concat");
    delete[] p;
    T ((0 != (p = StringFuncs::StringConcat ("a", "b", ""))) && (0 == strcmp ("ab", p)), "Concat");
    delete[] p;
    T ((0 != (p = StringFuncs::StringConcat ("a", "", "b"))) && (0 == strcmp ("ab", p)), "Concat");
    delete[] p;
    T ((0 != (p = StringFuncs::StringConcat ("a", "", "b"))) && (0 == strcmp ("ab", p)), "Concat");
    delete[] p;
    T ((0 != (p = StringFuncs::StringConcat ("a", "", ""))) && (0 == strcmp ("a", p)), "Concat");
    delete[] p;
    T ((0 != (p = StringFuncs::StringConcat ("", "a", ""))) && (0 == strcmp ("a", p)), "Concat");
    delete[] p;
    T ((0 != (p = StringFuncs::StringConcat ("", "", "a"))) && (0 == strcmp ("a", p)), "Concat");
    delete[] p;
    T ((0 != (p = StringFuncs::StringConcat ("", "", ""))) && (0 == strcmp ("", p)), "Concat");
    delete[] p;


    T ((0 != (p = StringFuncs::ToLower ((const char*)s8))) && (0 == strcmp (s9, p)) && (p != s8), "Lower2");
    delete[] p;
    T ((0 != (p = StringFuncs::ToLower ((const char*)t5))) && (0 == strcmp ("a", p)) && (p != t5), "Lower2");
    delete[] p;
    T ((0 != (p = StringFuncs::ToLower ((const char*)t6))) && (0 == strcmp ("", p)) && (p != t6), "Lower2");
    delete[] p;

    printf ("----- End   Test -----\n");
    }

void Tester::Len ()
    {
    std::cin >> buffer;
    int len = StringFuncs::StringLen (buffer);
    printf ("Len(\"%s\") = %d.\n", buffer, len);
    }

void Tester::Sub ()
    {
    std::cin >> buffer >> buffer2;
    int index = StringFuncs::FindSubString (buffer, buffer2);
    printf ("FindSubString(\"%s\", \"%s\") = %d.\n", buffer, buffer2, index);
    }

void Tester::Reverse ()
    {
    std::cin >> buffer;
    StringFuncs::StringCopy (buffer, buffer2, bufferSize);
    char *p = StringFuncs::StringReverse (buffer);
    assert (p == buffer);
    printf ("Reverse([\"%s\") = [%s]\n", buffer2, buffer);
    }

void Tester::Lower ()
    {
    std::cin >> buffer;
    char* p = StringFuncs::ToLower (buffer);
    assert (buffer == p);
    printf ("ToLower((const char*)\"%s\") is [%s]\n", buffer, p);
    }

void Tester::Copy ()
    {
    std::cin >> buffer;
    int len = StringFuncs::StringCopy (buffer, buffer2, bufferSize);
    assert (len == StringFuncs::StringLen (buffer));
    assert (len == StringFuncs::StringLen (buffer2));
    printf ("StringCopy(\"%s\") = [%s]\n", buffer, buffer2);
    }

void Tester::Dup ()
    {
    std::cin >> buffer;
    char* p = StringFuncs::StringDup (buffer); // on the heap
    assert (buffer != p);
    assert (StringFuncs::StringLen(p) == StringFuncs::StringLen (buffer));
    assert (StringFuncs::StringsAreEqual (p, buffer));
    assert (0 == StringFuncs::StringCompare (p, buffer));
    printf ("StringDup(\"%s\") = [%s]\n", buffer, p);
    delete[] p;
    }

void Tester::Reverse2 ()
    {
    std::cin >> buffer;
    char* p = StringFuncs::StringReverse ((const char*)buffer); // on the heap
    assert (buffer != p);
    printf ("Reverse2(%s) = [%s]\n", buffer, p);
    delete[] p;
    }
