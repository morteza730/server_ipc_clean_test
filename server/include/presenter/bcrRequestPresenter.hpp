#pragma once

#include "usecase/bcrRequestUsecase.hpp"
#include "core/ipresenter.hpp"
#include "presenter/viewInterface/viewmodelRegistry.hpp"

class PresenterBCRRequestHelper;

template<>
struct Presenter<BCRRequest> : public IPresenter<BCRRequest>
{
    Presenter(std::unique_ptr<ControllerBoundary<BCRRequest>> controller, ViewmodelRegistry &registry = ViewmodelRegistry::get());
    ~Presenter();

    virtual void update(const PresenterData<BCRRequest>& pData) override final;
    void answerBCRRequest(const std::string &answer);

private:
    ViewmodelRegistry& registry;
    std::unique_ptr<PresenterBCRRequestHelper> helper;
};

#include <QObject>

class PresenterBCRRequestHelper: public QObject
{
    Q_OBJECT

public:
    PresenterBCRRequestHelper(Presenter<BCRRequest>& presenter): presenter{presenter} {}
    Q_INVOKABLE void answerBCRRequest(const QString &answer) {presenter.answerBCRRequest(answer.toStdString());}

private:
    Presenter<BCRRequest> &presenter;
};
