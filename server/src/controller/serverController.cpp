#include "controller/serverController.hpp"
#include "IPCInterface/serverInterface.hpp"

Controller<ServerUsecase>::Controller()
    : IController<ServerUsecase>(),
    ipcVisitor{std::make_unique<IPCVisitor>(this)}
{}

Controller<ServerUsecase>::~Controller() = default;

void Controller<ServerUsecase>::receiveData(ipc::IPCMessage serverMessage)
{
    ControllerData<ServerUsecase> cData(
        static_cast<int>(serverMessage.mode()),
        serverMessage.data().toStdString());

    this->controllerDataChanged(cData);
}

void Controller<ServerUsecase>::update(const ControllerData<ServerUsecase> &cData)
{
    ipc::IPCMessage message(CommandMode::VasType,QString::fromStdString(cData.data));
    sendData(message);
}

void Controller<ServerUsecase>::sendData(ipc::IPCMessage serverMessage)
{
    ipcVisitor->send(serverMessage);
}


IPCVisitor::IPCVisitor(Controller<ServerUsecase> *object)
    : server{ipc::ServerInterface::create("server")},
    controller{object}
{
    QObject::connect(server.get(),&ipc::ServerInterface::readyRead, this, &IPCVisitor::receive);

    server->startServer();
}

void IPCVisitor::send(ipc::IPCMessage message)
{
    server->sendMessage("client", message);
}

void IPCVisitor::receive()
{
    while (server->getMessageCount("client") > 0)
    {
        ipc::IPCMessage msg = server->readMessage("client");
        controller->receiveData(msg);
    }

}

IPCVisitor::~IPCVisitor() = default;

