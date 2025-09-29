#pragma once

#include "usecase/vasInfoUsecase.hpp"
#include "core/ipresenter.hpp"
#include "presenter/viewInterface/viewmodelRegistry.hpp"


#include <QObject>

class PresenterVASInfoHelper;

template<>
struct Presenter<VASInfo> : public IPresenter<VASInfo>
{
    Presenter(std::unique_ptr<ControllerBoundary<VASInfo>> controller, ViewmodelRegistry &registry = ViewmodelRegistry::get());
    ~Presenter();

    virtual void update(const PresenterData<VASInfo>& pData) override final {}
    void sendVASInfo();

private:
    ViewmodelRegistry& registry;
    std::unique_ptr<PresenterVASInfoHelper> helper;
};

class PresenterVASInfoHelper: public QObject
{
    Q_OBJECT

public:
    PresenterVASInfoHelper(Presenter<VASInfo>& presenter) : presenter{presenter} {}

    Q_INVOKABLE void send() {presenter.sendVASInfo();}

private:
    Presenter<VASInfo> &presenter;
};




