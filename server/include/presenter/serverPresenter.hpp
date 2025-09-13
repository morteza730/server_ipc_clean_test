#pragma once

#include "usecase/serverUsecase.hpp"
#include "core/ipresenter.hpp"

#include <QObject>

class PresenterHelper;

template<>
struct Presenter<ServerUsecase> : public IPresenter<ServerUsecase>
{
    Presenter(std::unique_ptr<ControllerBoundary<ServerUsecase>> controller);
    ~Presenter();

    virtual void update(const PresenterData<ServerUsecase>& pData) override final;
    void send(std::string data);

private:
    std::unique_ptr<PresenterHelper> helper;
};

class PresenterHelper: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString clientData READ clientData WRITE setClientData NOTIFY clientDataUpdated FINAL)
    Q_PROPERTY(QString serverData READ serverData WRITE setServerData NOTIFY serverDataUpdated FINAL)

public:
    PresenterHelper(Presenter<ServerUsecase>& presenter);

    Q_INVOKABLE void send();

    Presenter<ServerUsecase> &presenter;

    const QString &clientData() const { return m_clientData; }
    const QString &serverData() const {return m_serverData;}

    void setClientData(const QString &data)
    {
        m_clientData = data;
        emit clientDataUpdated();
    }

    void setServerData(const QString &data)
    {
        m_serverData = data;
        emit serverDataUpdated();
    }

private:
    QString m_clientData;
    QString m_serverData;

signals:
    void clientDataUpdated();
    void serverDataUpdated();
};




