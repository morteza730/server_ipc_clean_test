#include "presenter/bcrReceivePresenter.hpp"
#include "presenter/viewmodels/namedValue.hpp"
#include <QQmlEngine>

inline std::string bcrReceiveSample = "2500";

Presenter<BCRReceive>::Presenter(std::unique_ptr<ControllerBoundary<BCRReceive> > controller, ViewmodelRegistry &registry)
    : IPresenter<BCRReceive>(std::move(controller)),
    registry{registry},
    helper{std::make_unique<PresenterBCRReceiveHelper>(*this)}
{
    qmlRegisterSingletonInstance<PresenterBCRReceiveHelper>("Backend.Viewcontrol", 1, 0, "BCRReceive", helper.get());

    std::shared_ptr<NamedValue> bcrReceive = registry.loadViewmodel<NamedValue>("bcr_receive_info");
    bcrReceive->setValue(QString::fromStdString(bcrReceiveSample));
}

Presenter<BCRReceive>::~Presenter() = default;

void Presenter<BCRReceive>::sendBCRReceive()
{
    std::shared_ptr<NamedValue> bcrReceive = registry.loadViewmodel<NamedValue>("bcr_receive_info");

    BCRReceiveInfo receivedInfo;
    receivedInfo.info = bcrReceive->getValue<QString>().toStdString();

    PresenterData<BCRReceive> pData(receivedInfo);
    this->presenterDataChanged(pData);
}
