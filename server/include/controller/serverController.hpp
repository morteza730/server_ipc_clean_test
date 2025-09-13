#pragma once


#include "core/icontroller.hpp"
#include "IPCInterface/ipcMessage.hpp"
#include "usecase/serverUsecase.hpp"

#include <QObject>


class IPCVisitor;

template<>
struct Controller<ServerUsecase>: public IController<ServerUsecase>
{
    Controller();
    ~Controller();

    void sendData(ipc::IPCMessage serverMessage);
    void receiveData(ipc::IPCMessage serverMessage);
    virtual void update(const ControllerData<ServerUsecase> &cData) override final;

private:
    std::unique_ptr<IPCVisitor> ipcVisitor;
};

namespace ipc {
class ServerInterface;
}

class IPCVisitor: public QObject
{
    Q_OBJECT

public:
    IPCVisitor(Controller<ServerUsecase> *object);
    ~IPCVisitor();

    void send(ipc::IPCMessage message);

private:
    Controller<ServerUsecase> *controller;
    std::unique_ptr<ipc::ServerInterface> server;

private slots:
    void receive();
};
