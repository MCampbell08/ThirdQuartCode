#pragma once
#include "Request.h"

typedef void (*TestFunc)(void);

class Command
    {
    public:
        Command (const char cmd[], Request req, TestFunc func = nullptr);
        ~Command ();

    public:     // Command is really just a data container, so data is public
        char*    m_str;
        Request  m_req;
        TestFunc m_func;
    };

