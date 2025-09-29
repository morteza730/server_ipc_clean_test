#include "controller/bcrReceiveController.hpp"

inline const QString clientUID = "client";

Controller<BCRReceive>::Controller()
    : IController<BCRReceive>(),
    ipcVisitor{std::make_unique<IPCVisitor<BCRReceive>>(this)}
{}

Controller<BCRReceive>::~Controller() = default;

void Controller<BCRReceive>::update(const ControllerData<BCRReceive> &cData)
{
    ipc::IPCMessage message(CommandMode::BCR,QString::fromStdString(cData.get().data));
    sendData(message);
}

void Controller<BCRReceive>::sendData(ipc::IPCMessage serverMessage)
{
    ipcVisitor->send(clientUID,serverMessage);
}
