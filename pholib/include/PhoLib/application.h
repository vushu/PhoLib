#ifndef APPLICATION_H
#define APPLICATION_H
#include "core.h"

namespace PhoLib {

    class Application {
        public:
            // constructors, asssignment, destructor
            Application();
            Application(const Application&);
            Application& operator=(const Application&);
            virtual ~Application();

            void run();

        private:

    };
    // to be defined in client
    Application* createApplication();
}

#endif /* ifndef APPLICATION_H */
