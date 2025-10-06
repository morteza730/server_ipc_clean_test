#pragma once

#include "core/icontroller.hpp"
#include "IPCInterface/ipcMessage.hpp"
#include "usecase/verificationUsecase.hpp"
#include "DAInterface/ipcVisitor.hpp"

template<>
struct Controller<Verification>: public IController<Verification>
{
    Controller();
    ~Controller();

    void sendData(ipc::IPCMessage serverMessage);
    void receiveData(ipc::IPCMessage clientMessage) {}
    virtual void update(const ControllerData<Verification> &cData) override final;

private:
    std::unique_ptr<IPCVisitor<Verification>> ipcVisitor;
};
