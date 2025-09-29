#pragma once

#include "usecase/loggerUsecase.hpp"
#include "core/ipresenter.hpp"
#include "presenter/viewInterface/viewmodelRegistry.hpp"

#include <QObject>

template<>
struct Presenter<Logger> : public IPresenter<Logger>
{
    Presenter(std::unique_ptr<ControllerBoundary<Logger>> controller, ViewmodelRegistry &registry = ViewmodelRegistry::get());
    ~Presenter();

    virtual void update(const PresenterData<Logger>& pData) override final;

private:
    ViewmodelRegistry& registry;
};
