#pragma once

#include "usecase/vasInfoUsecase.hpp"
#include "core/ipresenter.hpp"
#include "presenter/viewInterface/viewmodelRegistry.hpp"


#include <QObject>

class PresenterVasInfoHelper;

template<>
struct Presenter<VasInfoUsecase> : public IPresenter<VasInfoUsecase>
{
    Presenter(std::unique_ptr<ControllerBoundary<VasInfoUsecase>> controller, ViewmodelRegistry &registry = ViewmodelRegistry::get());
    ~Presenter();

    virtual void update(const PresenterData<VasInfoUsecase>& pData) override final;
    void sendVasInfo();

private:
    ViewmodelRegistry& registry;
    std::unique_ptr<PresenterVasInfoHelper> helper;
};

class PresenterVasInfoHelper: public QObject
{
    Q_OBJECT

public:
    PresenterVasInfoHelper(Presenter<VasInfoUsecase>& presenter) : presenter{presenter} {}

    Q_INVOKABLE void send() {presenter.sendVasInfo();}

private:
    Presenter<VasInfoUsecase> &presenter;
};




