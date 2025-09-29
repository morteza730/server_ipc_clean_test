#include "controller/vasInfoController.hpp"

inline const QString clientUID = "client";

Controller<VASInfo>::Controller()
    : IController<VASInfo>(),
    ipcVisitor{std::make_unique<IPCVisitor<VASInfo>>(this)}
{}

Controller<VASInfo>::~Controller() = default;

void Controller<VASInfo>::update(const ControllerData<VASInfo> &cData)
{
    ipc::IPCMessage message(CommandMode::VasType,QString::fromStdString(cData.get().data));
    sendData(message);
}

void Controller<VASInfo>::sendData(ipc::IPCMessage serverMessage)
{
    ipcVisitor->send(clientUID,serverMessage);
}

