#pragma once

#include "core/application.hpp"
#include <QObject>

class QGuiApplication;
class QQmlApplicationEngine;

class Server: public QObject, public Application
{
    Q_OBJECT

public:
    Server(int &argc, char **argv);
    ~Server();

private:
    std::unique_ptr<QGuiApplication> app;
    std::unique_ptr<QQmlApplicationEngine> qmlEngine;

    void initQMLEngine();
    void initPresenters();

    virtual void initializeInternal() override;
    virtual int runInternal() override;
    virtual void terminateInternal() override;
};
