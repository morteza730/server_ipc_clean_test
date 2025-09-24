#pragma once

#include "core/iusecase.hpp"
#include <string>

struct VasInfoUsecase;

//================================== ControllerData ======================================
struct VASDetails
{
    std::string data = "";
};

template <>
struct ControllerData<VasInfoUsecase>
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
struct PresenterData<VasInfoUsecase>
{
    PresenterData(const VASRawInfo &info): info{info} {}
    const VASRawInfo &get() const {return info;}

private:
    VASRawInfo info;
};
//==================================== Usecase ==========================================
struct VasInfoUsecase : public IUsecase<VasInfoUsecase>
{
    VasInfoUsecase();
    ~VasInfoUsecase();

    virtual void handleControllerDataChanged(ControllerData<VasInfoUsecase> cData) override;

    virtual void handlePresenterDataChanged(PresenterData<VasInfoUsecase> pData) override;
};
