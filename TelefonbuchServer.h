#pragma once
#include <iostream>
#include "Thread.h"

using namespace std; 

class TelefonbuchServer : public Thread {
    // Ein einfacher Thread:
    // Er gibt nur eine einzige Zeile aus.
    public:
        void run() override {
            cout << "Thread wurde gestartet!" << endl;
        }

        void nichts() {
            cout << "Ich mache nichts." << endl;
        }
};

