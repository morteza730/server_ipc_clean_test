#include "presenter/bcrRequestPresenter.hpp"
#include "presenter/viewmodels/namedValue.hpp"
#include <QQmlEngine>

Presenter<BCRRequest>::Presenter(std::unique_ptr<ControllerBoundary<BCRRequest>> controller, ViewmodelRegistry &registry)
    : IPresenter<BCRRequest>(std::move(controller)), registry{registry},
    helper{std::make_unique<PresenterBCRRequestHelper>(*this)}
{
    qmlRegisterSingletonInstance<PresenterBCRRequestHelper>("Backend.Viewcontrol", 1, 0, "BCRRequest", helper.get());
}

void Presenter<BCRRequest>::update(const PresenterData<BCRRequest> &pData)
{
    std::shared_ptr<NamedValue> bcrRequestState = registry.loadViewmodel<NamedValue>("bcr_request_state");

    bcrRequestState->setValue(QString::fromStdString(pData.get().data));
}

Presenter<BCRRequest>::~Presenter() = default;

void Presenter<BCRRequest>::answerBCRRequest(const std::string &answer)
{
    BCRRequestState statusState;
    statusState.data = answer;

    PresenterData<BCRRequest> pData(statusState);
    this->presenterDataChanged(pData);
}
