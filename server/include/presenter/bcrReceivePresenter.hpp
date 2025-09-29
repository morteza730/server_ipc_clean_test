#pragma once

#include "usecase/bcrReceiveUsecase.hpp"
#include "core/ipresenter.hpp"
#include "presenter/viewInterface/viewmodelRegistry.hpp"

#include <QObject>

class PresenterBCRReceiveHelper;

template<>
struct Presenter<BCRReceive> : public IPresenter<BCRReceive>
{
    Presenter(std::unique_ptr<ControllerBoundary<BCRReceive>> controller, ViewmodelRegistry &registry = ViewmodelRegistry::get());
    ~Presenter();

    virtual void update(const PresenterData<BCRReceive>& pData) override final {}
    void sendBCRReceive();

private:
    ViewmodelRegistry& registry;
    std::unique_ptr<PresenterBCRReceiveHelper> helper;
};

class PresenterBCRReceiveHelper: public QObject
{
    Q_OBJECT

public:
    PresenterBCRReceiveHelper(Presenter<BCRReceive>& presenter) : presenter{presenter} {}

    Q_INVOKABLE void send() {presenter.sendBCRReceive();}

private:
    Presenter<BCRReceive> &presenter;
};
