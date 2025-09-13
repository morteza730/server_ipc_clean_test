#pragma once

#include "iusecase.hpp"
#include "ipresenter.hpp"
#include "icontroller.hpp"

template <typename TUsecase>
std::unique_ptr<Presenter<TUsecase>> make_presenter()
{
    static_assert(std::is_base_of_v<IUsecase<TUsecase>,TUsecase>, "TUsecase must drive from IUsecase.");

    std::unique_ptr<ControllerBoundary<TUsecase>> controller = std::make_unique<Controller<TUsecase>>();
    return std::make_unique<Presenter<TUsecase>>(std::move(controller));
}

class Application
{
public:
    virtual ~Application() = default;
    void initialize() { initializeInternal(); }
    int run() { return runInternal(); }
    void terminate() { terminateInternal(); }

private:
    virtual void initializeInternal() = 0;
    virtual int runInternal() = 0;
    virtual void terminateInternal() = 0;
};
