#include "usecase/vasInfoUsecase.hpp"


VASInfo::VASInfo() : IUsecase<VASInfo>() {}

void VASInfo::handlePresenterDataChanged(PresenterData<VASInfo> pData)
{
    VASDetails details;
    details.data = pData.get().info;
    ControllerData<VASInfo> cData{details};
    controller->update(cData);
}

VASInfo::~VASInfo() = default;
