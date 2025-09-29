#pragma once

#include <QObject>
#include <QString>

#include "presenter/viewInterface/viewmodelRegistry.hpp"
#include "presenter/viewmodels/namedValue.hpp"

//====================================
// Create and hold all the viewmodels.
//====================================
class ViewmodelInterface: public QObject
{
    Q_OBJECT

    Q_PROPERTY(NamedValue *vasInfo READ vasInfo CONSTANT)
    Q_PROPERTY(NamedValue *logInfo READ logInfo CONSTANT)
    Q_PROPERTY(NamedValue *bcrRecuestState READ bcrRecuestState CONSTANT)
    Q_PROPERTY(NamedValue *bcrReceiveInfo READ bcrReceiveInfo CONSTANT)

public:
    ViewmodelInterface(ViewmodelRegistry& registry);

private:
    ViewmodelRegistry &registry;

    NamedValue *vasInfo() const { return m_vasInfo.get(); }
    NamedValue *logInfo() const { return m_logInfo.get(); }
    NamedValue *bcrRecuestState() const { return m_bcrRecuestState.get(); }
    NamedValue *bcrReceiveInfo() const { return m_bcrReceiveInfo.get(); }

    std::shared_ptr<NamedValue> m_vasInfo;
    std::shared_ptr<NamedValue> m_logInfo;
    std::shared_ptr<NamedValue> m_bcrRecuestState;
    std::shared_ptr<NamedValue> m_bcrReceiveInfo;
};
