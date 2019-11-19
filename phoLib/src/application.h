#ifndef APPLICATION_H
#define APPLICATION_H

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
#endif /* ifndef APPLICATION_H */
