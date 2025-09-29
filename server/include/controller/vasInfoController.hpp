#pragma once

#include "core/icontroller.hpp"
#include "IPCInterface/ipcMessage.hpp"
#include "usecase/vasInfoUsecase.hpp"
#include "DAInterface/ipcVisitor.hpp"


template<>
struct Controller<VASInfo>: public IController<VASInfo>
{
    Controller();
    ~Controller();

    void sendData(ipc::IPCMessage serverMessage);
    void receiveData(ipc::IPCMessage serverMessage) {}
    virtual void update(const ControllerData<VASInfo> &cData) override final;

private:
    std::unique_ptr<IPCVisitor<VASInfo>> ipcVisitor;
};
