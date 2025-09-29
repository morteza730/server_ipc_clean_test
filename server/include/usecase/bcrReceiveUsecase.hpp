#pragma once

#include "core/iusecase.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

struct BCRReceive;

//================================== ControllerData ======================================
struct BCRReceiveData
{
    std::string data = "";
};

template <>
struct ControllerData<BCRReceive>
{
    ControllerData(const BCRReceiveData &bcrData): bcrData{bcrData} {}

    const BCRReceiveData &get() const {return bcrData;}

private:
    BCRReceiveData bcrData;
};
//================================== PresenterData =======================================
struct BCRReceiveInfo
{
    std::string info = "";
};

template <>
struct PresenterData<BCRReceive>
{
    PresenterData(const BCRReceiveInfo &bcrInfo): bcrInfo{bcrInfo} {}

    const BCRReceiveInfo &get() const {return bcrInfo;}

private:
    BCRReceiveInfo bcrInfo;
};
//==================================== Usecase ==========================================
struct BCRReceive : public IUsecase<BCRReceive>
{
    BCRReceive() : IUsecase<BCRReceive>() {}

    virtual void handleControllerDataChanged(ControllerData<BCRReceive> cData) override {}

    virtual void handlePresenterDataChanged(PresenterData<BCRReceive> pData) override;
};
