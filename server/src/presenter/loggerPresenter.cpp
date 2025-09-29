#include "presenter/loggerPresenter.hpp"
#include "presenter/viewmodels/namedValue.hpp"


Presenter<Logger>::Presenter(std::unique_ptr<ControllerBoundary<Logger> > controller, ViewmodelRegistry &registry)
    : IPresenter<Logger>(std::move(controller)),
    registry{registry}
{}

Presenter<Logger>::~Presenter() = default;

void Presenter<Logger>::update(const PresenterData<Logger> &pData)
{
    std::shared_ptr<NamedValue> logInfo = registry.loadViewmodel<NamedValue>("log_info");

    QString info;
    info += logInfo->getValue<QString>();
    info += QString("%1 \n").arg(QString::fromStdString(pData.get().info));

    logInfo->setValue(info);
}
