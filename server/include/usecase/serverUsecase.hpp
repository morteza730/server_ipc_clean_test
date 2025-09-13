#pragma once

#include "core/iusecase.hpp"
#include <string>

struct ServerUsecase;

//================================== ControllerData ======================================
template <>
struct ControllerData<ServerUsecase>
{
    ControllerData(std::string data): data{data} {}
    std::string data;
};
//================================== PresenterData =======================================
template <>
struct PresenterData<ServerUsecase>
{
    PresenterData(std::string data): data{data} {}
    std::string data;
};
//==================================== Usecase ==========================================
struct ServerUsecase : public IUsecase<ServerUsecase>
{
    ServerUsecase();
    ~ServerUsecase();

    virtual void handleControllerDataChanged(ControllerData<ServerUsecase> cData) override;

    virtual void handlePresenterDataChanged(PresenterData<ServerUsecase> pData) override;
};
