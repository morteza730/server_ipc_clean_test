#include "controller/bcrRequestController.hpp"

inline const QString clientUID = "client";

Controller<BCRRequest>::Controller()
    : IController<BCRRequest>(),
    ipcVisitor{std::make_unique<IPCVisitor<BCRRequest>>(this)}
{
}

Controller<BCRRequest>::~Controller() = default;

void Controller<BCRRequest>::update(const ControllerData<BCRRequest> &cData)
{
    ipc::IPCMessage messageBCR(CommandMode::BCR,
                               QString::fromStdString(cData.get().status)
                               );
    sendData(messageBCR);
}

void Controller<BCRRequest>::receiveData(ipc::IPCMessage serverMessage)
{
    QString data = serverMessage.data();
    switch (serverMessage.mode()) {
    case CommandMode::BCR:
    {
        BCRRequestFlag requestFlag;
        requestFlag.status = data.toStdString();
        ControllerData<BCRRequest> cData(requestFlag);
        this->controllerDataChanged(cData);
    }break;
    default:
        break;
    }
}

void Controller<BCRRequest>::sendData(ipc::IPCMessage clientMessage)
{
    ipcVisitor->sendData(clientUID,clientMessage);
}
