#pragma once

#include "core/icontroller.hpp"
#include "IPCInterface/ipcMessage.hpp"
#include "usecase/vasInfoUsecase.hpp"
#include "DAInterface/ipcVisitor.hpp"


template<>
struct Controller<VasInfoUsecase>: public IController<VasInfoUsecase>
{
    Controller();
    ~Controller();

    void sendData(ipc::IPCMessage serverMessage);
    void receiveData(ipc::IPCMessage serverMessage);
    virtual void update(const ControllerData<VasInfoUsecase> &cData) override final;

private:
    std::unique_ptr<IPCVisitor<VasInfoUsecase>> ipcVisitor;
};
