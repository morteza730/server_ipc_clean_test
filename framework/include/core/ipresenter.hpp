#pragma once

#include <memory>
#include "iusecase.hpp"

template <typename TUsecase>
class IPresenter : public PresenterBoundary<TUsecase>
{
public:
	virtual ~IPresenter() = default;
	template <typename... Args>
	IPresenter(std::unique_ptr<ControllerBoundary<TUsecase>> controller, Args &&...args)
	{
		usecase = Usecase<TUsecase>::create();
		usecase->setDependencies(this, std::move(controller));
		usecase->subscribeCallbacks();
	}

	void presenterDataChanged(PresenterData<TUsecase> pData)
	{
		PresenterBoundary<TUsecase>::onDataChanged.invoke(pData);
	}

private:
	std::shared_ptr<Usecase<TUsecase>> usecase;
};

template <typename TUsecase>
class Presenter : public IPresenter<TUsecase> {
public:
    using IPresenter<TUsecase>::IPresenter; // inherit constructors
};