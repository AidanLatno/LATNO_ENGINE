#pragma once
#include "Definitions.h"
#include <string>

class RuntimeException : public std::exception
{
    public: 
        std::string name;
        int code = RUNTIME_EXCEPTION;
        
        RuntimeException(std::string _information);
        std::string GetErrorName();
    private:
        std::string information;
};