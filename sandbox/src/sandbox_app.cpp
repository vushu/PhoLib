
#include "PhoLib/pholib.h"

class SandboxApp : public PhoLib::Application {
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
