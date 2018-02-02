#include "Command.h"
#include "StringFuncs.h"

Command::Command (const char cmd[], Request req, TestFunc func)
    {
    m_str  = StringFuncs::StringDup (cmd);
    m_req  = req;
    m_func = func;
    }

Command::~Command ()
    {
    //delete m_str;
    m_str  = nullptr;
    m_func = nullptr;
    m_req  = Request::unknown;
    }
