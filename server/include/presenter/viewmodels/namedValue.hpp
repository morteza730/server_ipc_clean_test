#pragma once

#include <QQmlEngine>
#include <QObject>

#include "presenter/viewmodels/iViewmodel.hpp"


class NamedValue : public QObject, public IViewmodel
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameUpdated FINAL)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueUpdated FINAL)

public:
    explicit NamedValue(const QString &name = QString(), const QVariant& value = QVariant())
        : m_name{name},
        m_value{value}
    {
        static bool isRegistered = []()
        {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
            qRegisterMetaType<NamedValue*>("NamedValue*");
#endif
            int typeId = qmlRegisterUncreatableType<NamedValue>("NamedValue", 1, 0, "NamedValue", "Reference only");
            return (typeId > 0);
        }();
    }
    const QString &name() const { return m_name; }
    const QVariant &value() const { return m_value; }

    void setName(const QString &new_name)
    {
        m_name = new_name;
        nameUpdated();
    }

    void setValue(const QVariant &new_value)
    {
        m_value = new_value;
        valueUpdated();
    }

    template <typename TValue>
    TValue getValue() const
    {
        static_assert(std::is_default_constructible_v<TValue>, "TData must be default constructible");

        if (!m_value.isValid())
            return TValue();

        if (!m_value.canConvert<TValue>())
            throw std::bad_cast();
        
        return m_value.value<TValue>();
    }

private:
    QString m_name;
    QVariant m_value;

signals:
    void nameUpdated();
    void valueUpdated();
};

