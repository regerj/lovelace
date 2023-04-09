////////////////////////////////////////////////////////////////////////////////
//! \file server_socket.hpp
//! \author Jacob Reger (regerjacob@gmail.com)
//! \brief Header file for server socket class.
//! \version 0.1
//! \date 2023-04-08
//! 
//! \copyright Copyright (c) 2023
//! 
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "..\inc\socket_handler.hpp"

////////////////////////////////////////////////////////////////////////////////
//! \brief A class for interacting with the server's socket connection that it
//! listens on.
////////////////////////////////////////////////////////////////////////////////
class Server_Socket: public Socket_Handler
{
    private:
        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Handle to a specific client's comm socket.
        //! 
        ////////////////////////////////////////////////////////////////////////////////
        SOCKET clientHandle = INVALID_SOCKET;

        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Function that initializes and binds to a socket for listening for
        //! new connections.
        //! 
        //! \return SOCK_STATUS representing if the operation succeeded or failed. 
        ////////////////////////////////////////////////////////////////////////////////
        SOCK_STATUS initAndBindSocket();

        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Function that gets the address information for the new connections
        //! listening port.
        //! 
        //! \return SOCK_STATUS 
        ////////////////////////////////////////////////////////////////////////////////
        SOCK_STATUS initAddr();

        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Wrapper around recv socket function taking C++ string.
        //! 
        //! \param buffer C++ string for receiving message.
        //! \param size Size of the message, deprecated and will be removed.
        //! \return SOCK_STATUS representing if the operation succeeded or failed.
        ////////////////////////////////////////////////////////////////////////////////
        SOCK_STATUS sockReceive(std::string &buffer, int &size);

        ////////////////////////////////////////////////////////////////////////////////
        //! \brief This function wraps the raw send socket function for easier error
        //! handling and use with C++ style strings, abstracting away the C Strings.
        //! 
        //! \param buffer C++ string for the buffer, contains the message to send.
        //! \param size The size of the buffer, will be removed later.
        //! \return SOCK_STATUS representing if the operation succeeded or failed.
        ////////////////////////////////////////////////////////////////////////////////
        SOCK_STATUS sockSend(std::string buffer, int &size);
    protected:
    public:
        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Construct a new Server_Socket object.
        //! 
        ////////////////////////////////////////////////////////////////////////////////
        Server_Socket();

        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Destroy the Server_Socket object.
        //! 
        ////////////////////////////////////////////////////////////////////////////////
        ~Server_Socket();

        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Listen to the socket for new connections.
        //! 
        //! \return SOCK_STATUS representing if the operation succeeded or failed.
        ////////////////////////////////////////////////////////////////////////////////
        SOCK_STATUS sockListen();

        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Accept a new connection.
        //! 
        //! \return SOCK_STATUS representing if the operation succeeded or failed.
        ////////////////////////////////////////////////////////////////////////////////
        SOCK_STATUS sockAccept();

        ////////////////////////////////////////////////////////////////////////////////
        //! \brief Echo the received messages back to the sender.
        //! 
        //! \return SOCK_STATUS representing if the operation succeeded or failed.
        ////////////////////////////////////////////////////////////////////////////////
        SOCK_STATUS echo();
};