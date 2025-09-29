#pragma once

#include "core/iusecase.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

struct BCRRequest;

//================================== ControllerData ======================================
struct BCRRequestFlag
{
    std::string status = "";
};

template <>
struct ControllerData<BCRRequest>
{
    ControllerData(const BCRRequestFlag &bcrFlag): bcrFlag{bcrFlag} {}

    const BCRRequestFlag &get() const {return bcrFlag;}

private:
    BCRRequestFlag bcrFlag;
};
//================================== PresenterData =======================================
struct BCRRequestState
{
    std::string data = "";
};

template <>
struct PresenterData<BCRRequest>
{
    PresenterData(const BCRRequestState &bcrState): bcrState{bcrState} {}

    const BCRRequestState &get() const {return bcrState;}

private:
    BCRRequestState bcrState;
};
//==================================== Usecase ==========================================
struct BCRRequest : public IUsecase<BCRRequest>
{
    BCRRequest() : IUsecase<BCRRequest>() {}

    virtual void handleControllerDataChanged(ControllerData<BCRRequest> cData) override;

    virtual void handlePresenterDataChanged(PresenterData<BCRRequest> pData) override;
};
