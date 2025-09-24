#include "main/server.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "usecase/vasInfoUsecase.hpp"
#include "presenter/vasInfoPresenter.hpp"
#include "controller/vasInfoController.hpp"


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
    static std::unique_ptr<Presenter<VasInfoUsecase>> p = make_presenter<VasInfoUsecase>();
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
    qDebug() << "application terminated";
}
