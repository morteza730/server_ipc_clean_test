#include "presenter/viewInterface/viewmodelInterface.hpp"

ViewmodelInterface::ViewmodelInterface(ViewmodelRegistry &registry)
    : registry{registry},
    m_vasInfo{nullptr},
    m_logInfo{nullptr},
    m_bcrRecuestState{nullptr},
    m_bcrReceiveInfo{nullptr},
    m_verificationState{nullptr},
    m_verificationInfo{nullptr}
{
    // shared viewmodels with view
    m_vasInfo = registry.createViewmodel<NamedValue>("vas_info");
    m_logInfo = registry.createViewmodel<NamedValue>("log_info");
    m_bcrRecuestState = registry.createViewmodel<NamedValue>("bcr_request_state");
    m_bcrReceiveInfo = registry.createViewmodel<NamedValue>("bcr_receive_info");
    m_verificationState = registry.createViewmodel<NamedValue>("verification_state");
    m_verificationInfo = registry.createViewmodel<NamedValue>("verification_info");
}
