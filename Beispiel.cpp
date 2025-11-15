#include <iostream>
#include <thread>
#include "Thread.h"

// Ein einfacher Thread:
// Er gibt nur eine einzige Zeile aus.
class HelloThread : public Thread {
public:
    void run() override {
        std::cout << "Thread wurde gestartet!" << std::endl;
    }
};

int main() {
    HelloThread t;

    // Thread starten
    if (t.start()) {
        std::cout << "Thread laeuft im Hintergrund..." << std::endl;

        // Warten, bis er beendet ist
        t.join();
        std::cout << "Thread ist fertig." << std::endl;
    }
    else {
        std::cout << "Thread konnte nicht gestartet werden." << std::endl;
    }

    return 0;
}
