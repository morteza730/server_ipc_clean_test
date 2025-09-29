#include "presenter/vasInfoPresenter.hpp"
#include "presenter/viewmodels/namedValue.hpp"
#include <QQmlEngine>


inline std::string vasInfoSample = R"json(
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
            "Description": "payid=1;title=نام;multiple=1",
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


Presenter<VASInfo>::Presenter(std::unique_ptr<ControllerBoundary<VASInfo> > controller, ViewmodelRegistry &registry)
    : IPresenter<VASInfo>(std::move(controller)),
    registry{registry},
    helper{std::make_unique<PresenterVASInfoHelper>(*this)}
{
    qmlRegisterSingletonInstance<PresenterVASInfoHelper>("Backend.Viewcontrol", 1, 0, "VASInfo", helper.get());

    std::shared_ptr<NamedValue> vasInfo = registry.loadViewmodel<NamedValue>("vas_info");
    vasInfo->setValue(QString::fromStdString(vasInfoSample));
}

Presenter<VASInfo>::~Presenter() = default;

void Presenter<VASInfo>::sendVASInfo()
{
    std::shared_ptr<NamedValue> vasInfo = registry.loadViewmodel<NamedValue>("vas_info");

    VASRawInfo rawInfo;
    rawInfo.info = vasInfo->getValue<QString>().toStdString();

    PresenterData<VASInfo> pData(rawInfo);
    this->presenterDataChanged(pData);
}
