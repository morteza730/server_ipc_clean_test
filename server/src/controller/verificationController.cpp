#include "controller/verificationController.hpp"


inline const QString clientUID = "client";

Controller<Verification>::Controller()
    : IController<Verification>(),
    ipcVisitor{std::make_unique<IPCVisitor<Verification>>(this)}
{
}

Controller<Verification>::~Controller() = default;

void Controller<Verification>::update(const ControllerData<Verification> &cData)
{
    ipc::IPCMessage messageTrx(CommandMode::Trx,
                               QString::fromStdString(cData.get().data),
                               QString::fromStdString(cData.get().reserve));
    sendData(messageTrx);
}

void Controller<Verification>::sendData(ipc::IPCMessage serverMessage)
{
    ipcVisitor->sendData(clientUID, serverMessage);
}

