#include "usecase/serverUsecase.hpp"


ServerUsecase::ServerUsecase() : IUsecase<ServerUsecase>() {}


void ServerUsecase::handleControllerDataChanged(ControllerData<ServerUsecase> cData)
{
    PresenterData<ServerUsecase> pData{cData.data};
    presenter->update(pData);
}

void ServerUsecase::handlePresenterDataChanged(PresenterData<ServerUsecase> pData)
{
    ControllerData<ServerUsecase> cData{pData.data};
    controller->update(cData);
}

ServerUsecase::~ServerUsecase() = default;
