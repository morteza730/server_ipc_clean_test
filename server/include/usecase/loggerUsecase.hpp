#pragma once

#include "core/iusecase.hpp"
#include <string>

struct Logger;

//================================== ControllerData ======================================
struct LogDetails
{
    std::string mode = "";
    std::string data = "";
};

template <>
struct ControllerData<Logger>
{
    ControllerData(const LogDetails &details): details{details} {}
    const LogDetails &get() const {return details;}

private:
    LogDetails details;
};
//================================== PresenterData =======================================
struct LogInfo
{
    std::string info = "";
};

template <>
struct PresenterData<Logger>
{
    PresenterData(const LogInfo &info): info{info} {}
    const LogInfo &get() const {return info;}

private:
    LogInfo info;
};
//==================================== Usecase ==========================================
struct Logger : public IUsecase<Logger>
{
    Logger();
    ~Logger();

    virtual void handleControllerDataChanged(ControllerData<Logger> cData) override;

    virtual void handlePresenterDataChanged(PresenterData<Logger> pData) override {}
};
