#include "presenter/viewInterface/viewmodelInterface.hpp"

ViewmodelInterface::ViewmodelInterface(ViewmodelRegistry &registry)
    : registry{registry},
    m_vasInfo{nullptr},
    m_logInfo{nullptr},
    m_bcrRecuestState{nullptr},
    m_bcrReceiveInfo{nullptr}
{
    // shared viewmodels with view
    m_vasInfo = registry.createViewmodel<NamedValue>("vas_info");
    m_logInfo = registry.createViewmodel<NamedValue>("log_info");
    m_bcrRecuestState = registry.createViewmodel<NamedValue>("bcr_request_state");
    m_bcrReceiveInfo = registry.createViewmodel<NamedValue>("bcr_receive_info");
}
