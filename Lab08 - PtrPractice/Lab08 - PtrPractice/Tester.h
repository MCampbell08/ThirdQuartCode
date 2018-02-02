#pragma once
#include <vector>
#include "Command.h"

class Tester
    {
    public:
        Tester ();
        ~Tester ();

    public: // Input Functions
        void    ProcessInput ();
        Command GetCommand ();

        static char* TF (bool b) { return b ? "True" : "False";  }

    public: // Test functions
        static void Equal ();
        static void Palindrome ();
        static void Compare ();
        static void Len ();
        static void Sub ();
        static void Reverse ();
        static void Lower ();
        static void Copy ();
        static void Dup ();
        static void Reverse2 ();
        static void Concat ();
        static void Lower2 ();
        static void Vowels ();
        static void Test ();

    private:
        std::vector<Command> m_cmds;
    };

