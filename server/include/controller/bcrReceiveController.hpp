#pragma once

#include "core/icontroller.hpp"
#include "IPCInterface/ipcMessage.hpp"
#include "usecase/bcrReceiveUsecase.hpp"
#include "DAInterface/ipcVisitor.hpp"


template<>
struct Controller<BCRReceive>: public IController<BCRReceive>
{
    Controller();
    ~Controller();

    void sendData(ipc::IPCMessage serverMessage);
    void receiveData(ipc::IPCMessage serverMessage) {}
    virtual void update(const ControllerData<BCRReceive> &cData) override final;

private:
    std::unique_ptr<IPCVisitor<BCRReceive>> ipcVisitor;
};
