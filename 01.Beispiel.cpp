#include <iostream>
#include <thread>
#include "Thread.h"

class MyThread : public Thread {
public:
    void run() override {
        for (int i = 0; i < 5; i++) {
            std::cout << "Thread laeuft... Schritt " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }
};

int main() {
    MyThread myThread;

    if (myThread.start()) {
        std::cout << "Thread wurde gestartet." << std::endl;
        myThread.join();
        std::cout << "Thread ist fertig." << std::endl;
    }
    else {
        std::cout << "Thread konnte nicht gestartet werden." << std::endl;
    }

    return 0;
}
