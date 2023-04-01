#pragma once

#include <sdkddkver.h>
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <cstdlib>
#include <sys/types.h>
#include <fstream>
#include <string>

#define INTERNET_PROTOCOL 0
#define LOG_ERROR "ERROR"
#define LOG_INFO "INFO"
#define LOG_WARNING "WARNING"
#define DEFUALT_PORT "27015"
#define STATUS_FAIL -1
#define BUFFER_LEN 1024

// Forward declarations becuase windows is a piece of shit sometimes
#ifdef __cplusplus
extern "C" {
#endif
   void WSAAPI freeaddrinfo( struct addrinfo* );

   int WSAAPI getaddrinfo( const char*, const char*, const struct addrinfo*,
                 struct addrinfo** );

   int WSAAPI getnameinfo( const struct sockaddr*, socklen_t, char*, DWORD,
                char*, DWORD, int );
#ifdef __cplusplus
}
#endif

class Socket_Handler
{
    private:
        SOCKET socketHandle = INVALID_SOCKET;
        struct addrinfo * address = NULL;
        struct addrinfo * ptr = NULL;
        struct addrinfo hints;
        std::ofstream logFile;
        WSADATA wsaData;
        SOCKET clientHandle = INVALID_SOCKET;

        inline void log(std::string, std::string);
        void initWSA();
        void initLog();
        void initAddr();
        void initAndBindSocket();
    protected:
    public:
        Socket_Handler();
        ~Socket_Handler();
        void sockListen();
        void sockAccept();
        void echo();
};