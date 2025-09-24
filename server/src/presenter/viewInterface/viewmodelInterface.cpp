#include "presenter/viewInterface/viewmodelInterface.hpp"

ViewmodelInterface::ViewmodelInterface(ViewmodelRegistry &registry)
    : registry{registry},
    m_vasInfo{nullptr},
    m_trxInfo{nullptr},
    m_bcrRecuestInfo{nullptr}
{
    // shared viewmodels with view
    m_vasInfo = registry.createViewmodel<NamedValue>("vas_info");
    m_trxInfo = registry.createViewmodel<NamedValue>("trx_info");
    m_bcrRecuestInfo = registry.createViewmodel<NamedValue>("bcr_request_info");
}
