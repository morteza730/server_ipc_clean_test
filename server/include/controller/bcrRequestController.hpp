#pragma once

#include "core/icontroller.hpp"
#include "IPCInterface/ipcMessage.hpp"
#include "usecase/bcrRequestUsecase.hpp"
#include "DAInterface/ipcVisitor.hpp"

template<>
struct Controller<BCRRequest>: public IController<BCRRequest>
{
    Controller();
    ~Controller();

    void sendData(ipc::IPCMessage clientMessage);
    void receiveData(ipc::IPCMessage serverMessage);
    virtual void update(const ControllerData<BCRRequest> &cData) override final;

private:
    std::unique_ptr<IPCVisitor<BCRRequest>> ipcVisitor;
};
