#include "usecase/bcrRequestUsecase.hpp"

void BCRRequest::handleControllerDataChanged(ControllerData<BCRRequest> cData)
{
    int statue = 0;

    try {
        statue = std::stoi(cData.get().status);
    }
    catch (...) {
        std::cerr << "Error: Invalid value" << std::endl;
        return;
    }

    std::string data = "false";

    if (statue > 0)
        data = "true";


    BCRRequestState bcrRequestState;
    bcrRequestState.data = data;

    PresenterData<BCRRequest> pData(bcrRequestState);
    presenter->update(pData);
}

void BCRRequest::handlePresenterDataChanged(PresenterData<BCRRequest> pData)
{
    BCRRequestFlag bcrRequestFlag;
    bcrRequestFlag.status = pData.get().data;

    ControllerData<BCRRequest> cData(bcrRequestFlag);
    controller->update(cData);
}
