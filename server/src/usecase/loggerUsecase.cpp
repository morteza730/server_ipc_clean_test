#include "usecase/loggerUsecase.hpp"

Logger::Logger() : IUsecase<Logger>() {}

Logger::~Logger() = default;

void Logger::handleControllerDataChanged(ControllerData<Logger> cData)
{
    LogInfo vasInfo;
    vasInfo.info = "mode = " + cData.get().mode + "    data = " + cData.get().data;
    PresenterData<Logger> pData{vasInfo};
    presenter->update(pData);
}
