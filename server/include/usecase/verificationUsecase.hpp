#pragma once

#include "core/iusecase.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

struct Verification;

//================================== ControllerData ======================================
struct VerificationMessage
{
    std::string data = "";
    std::string reserve = "";
};

template <>
struct ControllerData<Verification>
{
    ControllerData(const VerificationMessage &message): message{message} {}

    const VerificationMessage &get() const {return message;}

private:
    VerificationMessage message;
};
//================================== PresenterData =======================================
struct VerificationInfo
{
    bool status = false;
    std::string details = "";
};

template <>
struct PresenterData<Verification>
{
    PresenterData(const VerificationInfo &info): info{info} {}

    const VerificationInfo &get() const {return info;}

private:
    VerificationInfo info;
};
//==================================== Usecase ==========================================
struct Verification : public IUsecase<Verification>
{
    Verification() : IUsecase<Verification>() {}

    virtual void handleControllerDataChanged(ControllerData<Verification> cData) override {}

    virtual void handlePresenterDataChanged(PresenterData<Verification> pData) override;
};
