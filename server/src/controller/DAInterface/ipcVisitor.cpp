#include "IPCInterface/serverInterface.hpp"
#include "controller/DAInterface/ipcVisitor.hpp"
#include <iostream>

std::unique_ptr<ipc::ServerInterface> IPCInterface::server = nullptr;
std::atomic<int> IPCInterface::instance_count{0};

IPCInterface::IPCInterface()
{
    if (!server)
        server = ipc::ServerInterface::create("server");

    QObject::connect(server.get(),&ipc::ServerInterface::readyRead, this, &IPCInterface::receiveData);
    QObject::connect(server.get(),&ipc::ServerInterface::clientConnected, this, &IPCInterface::newClientConnected);

    if (instance_count.fetch_add(1,std::memory_order_acq_rel) == 0)
        server->startServer();
}

IPCInterface::~IPCInterface()
{
    if (instance_count.fetch_sub(1, std::memory_order_acq_rel) == 1)
        server->stopServer();
}

void IPCInterface::receiveData(const QString &clientUID)
{
    static ipc::IPCMessage cachedMessage;

    while (server->getMessageCount(clientUID) > 0)
    {
        cachedMessage = server->readMessage(clientUID);
    }
    receiveDataInternal(cachedMessage);
}

void IPCInterface::newClientConnected()
{
}

void IPCInterface::send(const QString &clientUID, const ipc::IPCMessage &serverMessage)
{
    server->sendMessage(clientUID,serverMessage);
}
