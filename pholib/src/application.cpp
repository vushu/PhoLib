#include "PhoLib/application.h"
#include "PhoLib/log.h"
//#include ""
namespace PhoLib {

    Application::Application() {
        Log::init();
    }

    Application::~Application() {
    }

    void Application::run() {
        Log::getCoreLogger()->info("Running Game");
        while (true) {

        }
    }

}



