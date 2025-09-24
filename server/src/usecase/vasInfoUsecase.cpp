#include "usecase/vasInfoUsecase.hpp"


VasInfoUsecase::VasInfoUsecase() : IUsecase<VasInfoUsecase>() {}


void VasInfoUsecase::handleControllerDataChanged(ControllerData<VasInfoUsecase> cData)
{
    VASRawInfo vasInfo;
    vasInfo.info = "vas info is: " + cData.get().data;
    PresenterData<VasInfoUsecase> pData{vasInfo};
    presenter->update(pData);
}

void VasInfoUsecase::handlePresenterDataChanged(PresenterData<VasInfoUsecase> pData)
{
    VASDetails details;
    details.data = pData.get().info;
    ControllerData<VasInfoUsecase> cData{details};
    controller->update(cData);
}

VasInfoUsecase::~VasInfoUsecase() = default;
