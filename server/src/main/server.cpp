#include "main/server.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "usecase/vasInfoUsecase.hpp"
#include "presenter/vasInfoPresenter.hpp"
#include "controller/vasInfoController.hpp"

#include "usecase/bcrRequestUsecase.hpp"
#include "presenter/bcrRequestPresenter.hpp"
#include "controller/bcrRequestController.hpp"

#include "usecase/bcrReceiveUsecase.hpp"
#include "presenter/bcrReceivePresenter.hpp"
#include "controller/bcrReceiveController.hpp"

#include "usecase/loggerUsecase.hpp"
#include "presenter/loggerPresenter.hpp"
#include "controller/loggerController.hpp"

#include "usecase/verificationUsecase.hpp"
#include "presenter/verificationPresenter.hpp"
#include "controller/verificationController.hpp"

Application *getApplication(int &argc, char **argv)
{
    static Server instance(argc, argv);
    return &instance;
}

Server::Server(int &argc, char **argv)
    : app{new QGuiApplication(argc,argv)},
    qmlEngine{new QQmlApplicationEngine{}}
{
}

Server::~Server() = default;

void Server::initializeInternal()

{
    initPresenters();
    initQMLEngine();
}

void Server::initPresenters()
{
    static std::unique_ptr<Presenter<VASInfo>> vasInfo = make_presenter<VASInfo>();
    static std::unique_ptr<Presenter<BCRRequest>> bcrRecuest = make_presenter<BCRRequest>();
    static std::unique_ptr<Presenter<BCRReceive>> bcrReceive = make_presenter<BCRReceive>();
    static std::unique_ptr<Presenter<Logger>> logger = make_presenter<Logger>();
    static std::unique_ptr<Presenter<Verification>> verification = make_presenter<Verification>();
}

void Server::initQMLEngine()
{
    const QUrl url(QStringLiteral("qrc:/view/form/Main.qml"));

    connect(qmlEngine.get(),&QQmlApplicationEngine::objectCreated,this,[url](QObject *obj, const QUrl &objUrl){
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    qmlEngine->addImportPath("qrc:/");
    qmlEngine->load(url);
}

int Server::runInternal()
{
    return app->exec();
}

void Server::terminateInternal()
{
    std::cout << "application terminated" << std::endl;
}
