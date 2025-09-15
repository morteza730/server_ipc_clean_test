#include "presenter/serverPresenter.hpp"
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
            "Description": "payid=1;title=نام",
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


Presenter<ServerUsecase>::Presenter(std::unique_ptr<ControllerBoundary<ServerUsecase> > controller)
    : IPresenter<ServerUsecase>(std::move(controller)),
    helper{std::make_unique<PresenterHelper>(*this)}
{
    qmlRegisterSingletonInstance<PresenterHelper>("Backend", 1, 0, "Presenter", helper.get());
}

Presenter<ServerUsecase>::~Presenter() = default;

void Presenter<ServerUsecase>::update(const PresenterData<ServerUsecase> &pData)
{
    helper->appendClientData(
        QString("mode is %1 and data is %2 \n").arg(QString::number(pData.mode)).arg(QString::fromStdString(pData.data))
        );
}

void Presenter<ServerUsecase>::send(std::string data)
{
    PresenterData<ServerUsecase> pData(0,data);
    this->presenterDataChanged(pData);
}

PresenterHelper::PresenterHelper(Presenter<ServerUsecase> &presenter)
    : presenter{presenter},
    m_serverData{QString::fromStdString(sample)},
    m_clientData{QString()}
{}

void PresenterHelper::send() {presenter.send(m_serverData.toStdString());}
