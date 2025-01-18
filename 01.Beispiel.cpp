#include <iostream>
#include "Thread.h"

class MyThread : public Thread {
public:
    void run() override {
        std::cout << "Thread laeuft!" << std::endl;
    }
};

//int main() {
//    MyThread myThread;
//    if (myThread.start()) {
//        myThread.join(); // Warten, bis der Thread abgeschlossen ist
//    }
//    else {
//        std::cout << "Thread konnte nicht gestartet werden." << std::endl;
//    }
//    return 0;
//}