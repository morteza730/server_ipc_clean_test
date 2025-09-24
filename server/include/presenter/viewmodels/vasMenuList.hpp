#pragma once

#pragma once

#include <QQmlEngine>
#include <QAbstractListModel>
#include "presenter/viewmodels/iViewmodel.hpp"
#include <string>
#include <vector>

class VasMenuList : public QAbstractListModel, public IViewmodel
{
    Q_OBJECT

public:
    enum ListRoles
    {
        NameDisplay = 0,
        CountDisplay = 1,
        PriceDisplay = 2,
        SelectedDisplay = 3,
        IsFixedPrice = 4,
        MaxCountDisplay = 5
    };

    VasMenuList()
        : QAbstractListModel(nullptr)
    {
        static bool isRegistered = []()
        {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
            qRegisterMetaType<VasMenuList*>("VasMenuList*");
#endif
            int typeId = qmlRegisterUncreatableType<VasMenuList>("VasMenuList", 1, 0, "VasMenuList", "Reference only");
            return (typeId > 0);
        }();
    }

    // TODO: declare a RangeValue viewmodel for count.
    void append(const std::string &name, std::size_t count, const std::string &price, std::size_t maxCount = 1)
    {
        names.push_back(QString::fromStdString(name));
        counts.push_back(count);
        prices.push_back(QString::fromStdString(price));
        maxCounts.push_back(maxCount);

        isFirsttPriceFixFuncs.push_back([price](){
            if (price.empty())
                return false;
            if (std::stod(price) == 0.0)
                return false;

            return true;
        });
    }

    void confirmDataChange()
    {
        beginResetModel();
        endResetModel();
    }

    void clean()
    {
        names.clear();
        counts.clear();
        prices.clear();
    }

    const std::vector<QString> &getNames() const {return names;}
    const std::vector<int> &getCounts() const {return counts;}
    const std::vector<QString> &getPrices() const {return prices;}
    const std::vector<std::size_t> &getSelectedRows() const {return selectedRows;}

    std::size_t size() const {return names.size();}

    void selectRow(int selectedIndex)
    {
        std::size_t selectedRow = selectedIndex % size();

        if (std::find(selectedRows.cbegin(),selectedRows.cend(),selectedRow) != selectedRows.cend())
        {
            selectedRows.erase(
                std::remove(selectedRows.begin(),selectedRows.end(),selectedRow),
                selectedRows.end());
        }
        else
            selectedRows.push_back(selectedRow);

        QModelIndex from = createIndex(selectedRow, 0);
        QModelIndex to = createIndex(selectedRow, 0);
        emit dataChanged(from, to);
    }

    template <typename TValue>
    bool update(int index, int role, TValue value)
    {
        QVariant varValue = QVariant::fromValue(value);
        QModelIndex modelIndex = this->index(index);
        return setData(modelIndex,varValue,role);
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role) override
    {
        if (!index.isValid())
            return 0;

        switch (role)
        {
        case (CountDisplay):
        {
            if (index.row() >= counts.size())
                return false;

            bool ok;
            counts[index.row()] = value.toInt(&ok);
            if (!ok)
                return false;
        } break;
        case (PriceDisplay):
        {
            if (index.row() >= prices.size())
                return false;

            prices[index.row()] = value.toString();
        } break;
        default:
            break;
        }

        emit dataChanged(index, index, {role});
        return true;
    }

    template <typename T>
    void setPrice(int rowNumber,T value)
    {
        QVariant varValue = QVariant::fromValue<T>(value);
        QModelIndex index = this->createIndex(rowNumber,0);
        setData(index,varValue,PriceDisplay);
    }

private:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        return names.size();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
        if (!index.isValid())
            return 0;

        switch (role)
        {
        case (NameDisplay):
        {
            if (index.row() < names.size())
                return names.at(index.row());

            return "";
        } break;
        case (CountDisplay):
        {
            if (index.row() < counts.size())
                return counts.at(index.row());

            return 0;
        } break;
        case (MaxCountDisplay):
        {
            if (index.row() < maxCounts.size())
                return maxCounts.at(index.row());

            return 0;
        } break;
        case (PriceDisplay):
        {
            if (index.row() < prices.size())
                return prices.at(index.row());

            return "0";
        } break;
        case (SelectedDisplay):
        {
            if (std::find(selectedRows.cbegin(),selectedRows.cend(),index.row()) == selectedRows.cend())
                return false;

            return true;
        } break;
        case (IsFixedPrice):
        {
            if (index.row() < isFirsttPriceFixFuncs.size())
                return isFirsttPriceFixFuncs.at(index.row())();

            return true;
        } break;
        default:
            break;
        }
        return QVariant();
    }

    Qt::ItemFlags flags(const QModelIndex &index) const override {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    }

    QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[NameDisplay] = "nameDisplay";
        roles[CountDisplay] = "countDisplay";
        roles[MaxCountDisplay] = "maxCountDisplay";
        roles[PriceDisplay] = "priceDisplay";
        roles[SelectedDisplay] = "selectedDisplay";
        roles[IsFixedPrice] = "isFixedPriceDisplay";
        return roles;
    }

    std::vector<QString> names;
    std::vector<int> counts;
    std::vector<QString> prices;
    std::vector<int> maxCounts;
    std::vector<std::function<bool()>> isFirsttPriceFixFuncs;

    std::vector<std::size_t> selectedRows;



};

