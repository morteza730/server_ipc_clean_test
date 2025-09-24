#include "presenter/vasInfoPresenter.hpp"
#include "presenter/viewmodels/namedValue.hpp"
#include <QQmlEngine>


inline std::string sample = R"json(
{
    "TerminalCardID": 105632,
    "ServiceTypeId": 15,
    "Title": "فروشگاه دهدار",
    "PAN": "1",
    "TerminalID": "31317014",
    "MerchantID": "1",
    "MerchantName": "تست امید نت",
    "Description": "...",
    "IsTwoReceipts": "false",
    "IsStraightToVAsMenu": false,
    "TitleEN": "CashDesk",
    "ServiceType": {
        "Id": 15,
        "Title": "CASHDESK",
        "Description": "صندوقی"
    },
    "Details": [
        {
            "TerminalCardID": 105632,
            "Name": "فروشگاه دهدار",
            "Price": 0,
            "Description": "payid=1;title=نام",
            "TypeName": "none",
            "Code": "000007000772"
        },
        {
            "TerminalCardID": 105634,
            "Name": "فروشگاه صادقی",
            "Price": 1000,
            "Description": "payid=1;title=نام;count=3;maxcount=5",
            "TypeName": "none",
            "Code": "000007000772"
        }
    ],
    "RegionID": 168,
    "WebServiceUrl": null,
    "EnTerminalGroupTitle": "Buy",
    "FaTerminalGroupTitle": "خرید",
    "TerminalGroupDescription": ""
}
)json";


Presenter<VasInfoUsecase>::Presenter(std::unique_ptr<ControllerBoundary<VasInfoUsecase> > controller, ViewmodelRegistry &registry)
    : IPresenter<VasInfoUsecase>(std::move(controller)),
    registry{registry},
    helper{std::make_unique<PresenterVasInfoHelper>(*this)}
{
    qmlRegisterSingletonInstance<PresenterVasInfoHelper>("Backend.Viewcontrol", 1, 0, "VasInfo", helper.get());

    std::shared_ptr<NamedValue> vasInfo = registry.loadViewmodel<NamedValue>("vas_info");
    vasInfo->setValue(QString::fromStdString(sample));
}

Presenter<VasInfoUsecase>::~Presenter() = default;

void Presenter<VasInfoUsecase>::update(const PresenterData<VasInfoUsecase> &pData)
{
    std::shared_ptr<NamedValue> trxInfo = registry.loadViewmodel<NamedValue>("trx_info");

    QString info;
    info += trxInfo->getValue<QString>();
    info += QString("data is %1 \n").arg(QString::fromStdString(pData.get().info));

    trxInfo->setValue(info);
}

void Presenter<VasInfoUsecase>::sendVasInfo()
{
    std::shared_ptr<NamedValue> vasInfo = registry.loadViewmodel<NamedValue>("vas_info");

    VASRawInfo rawInfo;
    rawInfo.info = vasInfo->getValue<QString>().toStdString();

    PresenterData<VasInfoUsecase> pData(rawInfo);
    this->presenterDataChanged(pData);
}
