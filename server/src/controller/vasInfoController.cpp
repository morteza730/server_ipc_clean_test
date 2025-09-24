#include "controller/vasInfoController.hpp"

inline const QString clientUID = "client";

Controller<VasInfoUsecase>::Controller()
    : IController<VasInfoUsecase>(),
    ipcVisitor{std::make_unique<IPCVisitor<VasInfoUsecase>>(this)}
{}

Controller<VasInfoUsecase>::~Controller() = default;

void Controller<VasInfoUsecase>::receiveData(ipc::IPCMessage serverMessage)
{
    switch (serverMessage.mode()) {
    case CommandMode::Trx:
    {
        VASDetails details;
        details.data = serverMessage.data().toStdString();
        ControllerData<VasInfoUsecase> cData(details);
        this->controllerDataChanged(cData);
    }break;
    default:
        break;
    }
}

void Controller<VasInfoUsecase>::update(const ControllerData<VasInfoUsecase> &cData)
{
    ipc::IPCMessage message(CommandMode::VasType,QString::fromStdString(cData.get().data));
    sendData(message);
}

void Controller<VasInfoUsecase>::sendData(ipc::IPCMessage serverMessage)
{
    ipcVisitor->send(clientUID,serverMessage);
}

