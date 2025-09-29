#pragma once

#include "core/icontroller.hpp"
#include "IPCInterface/ipcMessage.hpp"
#include "usecase/loggerUsecase.hpp"
#include "DAInterface/ipcVisitor.hpp"


template<>
struct Controller<Logger>: public IController<Logger>
{
    Controller();
    ~Controller();

    void sendData(ipc::IPCMessage serverMessage) {}
    void receiveData(ipc::IPCMessage serverMessage);
    virtual void update(const ControllerData<Logger> &cData) override final {}

private:
    std::unique_ptr<IPCVisitor<Logger>> ipcVisitor;
};
