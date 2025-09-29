#include "controller/loggerController.hpp"

inline const QString clientUID = "client";

Controller<Logger>::Controller()
    : IController<Logger>(),
    ipcVisitor{std::make_unique<IPCVisitor<Logger>>(this)}
{}

Controller<Logger>::~Controller() = default;

void Controller<Logger>::receiveData(ipc::IPCMessage serverMessage)
{
    LogDetails details;
    details.data = serverMessage.data().toStdString();

    switch (serverMessage.mode()) {
    case CommandMode::Info: {details.mode = "Info";}break;
    case CommandMode::VasType: {details.mode = "VasType";}break;
    case CommandMode::Trx: {details.mode = "Trx";}break;
    case CommandMode::Verify: {details.mode = "Verify";}break;
    case CommandMode::Print: {details.mode = "Print";}break;
    case CommandMode::TimeOut: {details.mode = "TimeOut";}break;
    case CommandMode::Inquiry: {details.mode = "Inquiry";}break;
    case CommandMode::Online: {details.mode = "Online";}break;
    case CommandMode::CInquiry: {details.mode = "CInquiry";}break;
    case CommandMode::C2C_Trx: {details.mode = "C2C_Trx";}break;
    case CommandMode::VasLanguage: {details.mode = "VasLanguage";}break;
    case CommandMode::TMSError: {details.mode = "TMSError";}break;
    case CommandMode::TMSMessage: {details.mode = "TMSMessage";}break;
    case CommandMode::AFC: {details.mode = "AFC";}break;
    case CommandMode::TMSVersion: {details.mode = "TMSVersion";}break;
    case CommandMode::BCR: {details.mode = "BCR";}break;
    case CommandMode::Reg: {details.mode = "Reg";}break;
    case CommandMode::Dereg: {details.mode = "Dereg";}break;
    default:{}break;
    }
    ControllerData<Logger> cData(details);
    this->controllerDataChanged(cData);
}

