#pragma once

#include "usecase/verificationUsecase.hpp"
#include "core/ipresenter.hpp"
#include "presenter/viewInterface/viewmodelRegistry.hpp"

class PresenterVerificationHelper;

template<>
struct Presenter<Verification> : public IPresenter<Verification>
{
    Presenter(std::unique_ptr<ControllerBoundary<Verification>> controller, ViewmodelRegistry &registry = ViewmodelRegistry::get());
    ~Presenter();

    virtual void update(const PresenterData<Verification>& pData) override final {}
    void verify();

private:
    ViewmodelRegistry& registry;
    std::unique_ptr<PresenterVerificationHelper> helper;
};

#include <QObject>

class PresenterVerificationHelper: public QObject
{
    Q_OBJECT

public:
    PresenterVerificationHelper(Presenter<Verification>& presenter): presenter{presenter} {}
    Q_INVOKABLE void verify() {presenter.verify();}

private:
    Presenter<Verification> &presenter;
};
