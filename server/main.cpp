#include <iostream>

#include "socket_handler.hpp"

int main()
{
    std::cout << "Beginning program." << std::endl;
    Socket_Handler socket;
    std::cout << "Finished socket creation." << std::endl;
    socket.sockListen();
    // socket.sockAccept();
    // socket.echo();
    return 0;
}