#pragma once

#include "core/iusecase.hpp"
#include <string>

struct VASInfo;

//================================== ControllerData ======================================
struct VASDetails
{
    std::string data = "";
};

template <>
struct ControllerData<VASInfo>
{
    ControllerData(const VASDetails &details): details{details} {}
    const VASDetails &get() const {return details;}

private:
    VASDetails details;
};
//================================== PresenterData =======================================
struct VASRawInfo
{
    std::string info = "";
};

template <>
struct PresenterData<VASInfo>
{
    PresenterData(const VASRawInfo &info): info{info} {}
    const VASRawInfo &get() const {return info;}

private:
    VASRawInfo info;
};
//==================================== Usecase ==========================================
struct VASInfo : public IUsecase<VASInfo>
{
    VASInfo();
    ~VASInfo();

    virtual void handleControllerDataChanged(ControllerData<VASInfo> cData) override {}

    virtual void handlePresenterDataChanged(PresenterData<VASInfo> pData) override;
};
