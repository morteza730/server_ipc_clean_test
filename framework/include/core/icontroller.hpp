#pragma once

#include <typeindex>
#include "iusecase.hpp"

template <typename TUsecase>
class IController : public ControllerBoundary<TUsecase>
{
public:
	virtual ~IController() = default;

	void controllerDataChanged(ControllerData<TUsecase> &cData)
	{
		ControllerBoundary<TUsecase>::onDataChanged.invoke(cData);
	}
};

template <typename TUsecase>
class Controller : public IController<TUsecase> {
public:
    using IController<TUsecase>::IController; 
};