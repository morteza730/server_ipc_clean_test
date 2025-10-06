#include "presenter/verificationPresenter.hpp"
#include "presenter/viewmodels/namedValue.hpp"
#include <QQmlEngine>

inline std::string verificationDataSample = "verification data";

Presenter<Verification>::Presenter(std::unique_ptr<ControllerBoundary<Verification>> controller, ViewmodelRegistry &registry)
    : IPresenter<Verification>(std::move(controller)), registry{registry},
    helper{std::make_unique<PresenterVerificationHelper>(*this)}
{
    qmlRegisterSingletonInstance<PresenterVerificationHelper>("Backend.Viewcontrol", 1, 0, "Verification", helper.get());

    std::shared_ptr<NamedValue> verificationInfo = registry.loadViewmodel<NamedValue>("verification_info");
    verificationInfo->setValue(QString::fromStdString(verificationDataSample));
}

Presenter<Verification>::~Presenter() = default;

void Presenter<Verification>::verify()
{
    std::shared_ptr<NamedValue> verificationState = registry.loadViewmodel<NamedValue>("verification_state");
    std::shared_ptr<NamedValue> verificationInfo = registry.loadViewmodel<NamedValue>("verification_info");
    
    VerificationInfo info;
    info.status = verificationState->getValue<bool>();
    info.details = verificationInfo->getValue<QString>().toStdString();

    PresenterData<Verification> pData(info);
    this->presenterDataChanged(pData);
}

