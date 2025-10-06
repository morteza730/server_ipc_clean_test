#include "usecase/verificationUsecase.hpp"

void Verification::handlePresenterDataChanged(PresenterData<Verification> pData)
{
    VerificationMessage message;

    if (pData.get().status)
        message.reserve = "0";
    else
        message.reserve = "-1";

    message.data = pData.get().details;

    ControllerData<Verification> cData(message);
    controller->update(cData);
}
