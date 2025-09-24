#pragma once

#include <QObject>

#include "IPCInterface/ipcMessage.hpp"

template <typename TUsecase>
class Controller;

namespace ipc {
class ServerInterface;
}

class IPCInterface: public QObject
{
    Q_OBJECT

public:
    IPCInterface();
    ~IPCInterface();
    void send(const QString &clientUID, const ipc::IPCMessage &serverMessage);

private:
    static std::unique_ptr<ipc::ServerInterface> server;
    static std::atomic<int> instance_count;
    virtual void receiveDataInternal(const ipc::IPCMessage &clientMessage) = 0;
    
private slots:
    void receiveData(const QString &clientUID);
    void newClientConnected();
};

template <typename TUsecase>
class IPCVisitor: public IPCInterface
{
public:
    IPCVisitor(Controller<TUsecase> *object);

    virtual void receiveDataInternal(const ipc::IPCMessage &clientMessage) final override;
    void sendData(const QString &clientUID,ipc::IPCMessage serverMessage);

private:
    Controller<TUsecase> *controller;
};

template <typename TUsecase>
inline IPCVisitor<TUsecase>::IPCVisitor(Controller<TUsecase> *object)
    : controller{object}
{
}

template <typename TUsecase>
void IPCVisitor<TUsecase>::receiveDataInternal(const ipc::IPCMessage &clientMessage)
{
    controller->receiveData(clientMessage);
}

template <typename TUsecase>
inline void IPCVisitor<TUsecase>::sendData(const QString &clientUID, ipc::IPCMessage serverMessage)
{
    IPCInterface::send(clientUID,serverMessage);
}
