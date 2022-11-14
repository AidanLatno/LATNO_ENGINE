#include "../declarations/RuntimeException.h"

Latno_Exceptions::RuntimeException::RuntimeException(std::string _information)
{
    information = _information;
}

std::string Latno_Exceptions::RuntimeException::GetErrorName()
{
    return name;
}