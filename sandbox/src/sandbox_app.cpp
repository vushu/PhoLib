
#include "pholib/pholib.h"

class SandboxApp : public pholib::Application {
    public:
        // constructors, asssignment, destructor
        SandboxApp() {}

        ~SandboxApp() {}


};


int main () {
    SandboxApp* sandbox = new SandboxApp();
    sandbox->run();
    delete sandbox;
}
