#pragma once
#include <winsock2.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
namespace Latno
{
    class HTTPTransfer {
    public:
        HTTPTransfer();
        ~HTTPTransfer();

        char* readUrl(const std::string& url, long& bytesReturnedOut, char** headerOut);
        bool sendJSON(const std::string& url, const std::string& jsonData);

    private:
        void parseUrl(const std::string& url, std::string& serverName, std::string& filepath, std::string& filename);
        SOCKET connectToServer(const char* serverName, WORD portNum);
        int getHeaderLength(const char* content);

        HINSTANCE hInst;
        WSADATA wsaData;
    };
}
