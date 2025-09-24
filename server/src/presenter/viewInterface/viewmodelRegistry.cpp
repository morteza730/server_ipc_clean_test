#include "presenter/viewInterface/viewmodelRegistry.hpp"
#include "presenter/viewInterface/viewmodelInterface.hpp"

#include <QQmlEngine>

std::size_t IViewmodel::nextId = 0;
ViewmodelRegistry::~ViewmodelRegistry() = default;

ViewmodelRegistry::ViewmodelRegistry()
    : interface{std::make_unique<ViewmodelInterface>(*this)}
{
    qmlRegisterSingletonInstance<ViewmodelInterface>("Backend.Viewmodel", 1, 0, "ViewmodelInterface", interface.get());
}
