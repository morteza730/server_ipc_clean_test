#include "entryPoint.hpp"
#include "core/application.hpp"

int main(int argc, char *argv[])
{
    Application *app = getApplication(argc, argv);

    if (!app)
        return -1;

    app->initialize();
    int result = app->run();
    app->terminate();

    return result;
}
