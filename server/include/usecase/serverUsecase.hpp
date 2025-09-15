#pragma once

#include "core/iusecase.hpp"
#include <string>

struct ServerUsecase;

//================================== ControllerData ======================================
template <>
struct ControllerData<ServerUsecase>
{
    ControllerData(int mode,std::string data): mode{mode}, data{data} {}
    int mode;
    std::string data;
};
//================================== PresenterData =======================================
template <>
struct PresenterData<ServerUsecase>
{
    PresenterData(int mode,std::string data): mode{mode}, data{data} {}
    int mode;
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
