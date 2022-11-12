#include "../declarations/RuntimeException.h"

namespace Latno_Exceptions 
{
    RuntimeException::RuntimeException(std::string _information) 
    {
        information = _information;
    }

    std::string RuntimeException::GetErrorName() {
        return name;
    }
}