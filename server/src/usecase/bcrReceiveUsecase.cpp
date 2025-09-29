#include "usecase/bcrReceiveUsecase.hpp"

void BCRReceive::handlePresenterDataChanged(PresenterData<BCRReceive> pData)
{
    BCRReceiveData receivedData;
    receivedData.data = pData.get().info;
    ControllerData<BCRReceive> cData{receivedData};
    controller->update(cData);
}
