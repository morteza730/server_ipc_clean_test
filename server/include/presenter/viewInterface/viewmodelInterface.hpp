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
    Q_PROPERTY(NamedValue *trxInfo READ trxInfo CONSTANT)
    Q_PROPERTY(NamedValue *bcrRecuestInfo READ bcrRecuestInfo CONSTANT)

public:
    ViewmodelInterface(ViewmodelRegistry& registry);

private:
    ViewmodelRegistry &registry;

    NamedValue *vasInfo() const { return m_vasInfo.get(); }
    NamedValue *trxInfo() const { return m_trxInfo.get(); }
    NamedValue *bcrRecuestInfo() const { return m_bcrRecuestInfo.get(); }

    std::shared_ptr<NamedValue> m_vasInfo;
    std::shared_ptr<NamedValue> m_trxInfo;
    std::shared_ptr<NamedValue> m_bcrRecuestInfo;
};
