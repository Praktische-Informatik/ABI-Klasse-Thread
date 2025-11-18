#include <iostream>
#include <thread>
#include "Thread.h"
#include "TelefonbuchServer.h"

using namespace std;

int main() {
    TelefonbuchServer ts;

    // Thread starten
    if (ts.start()) {
        cout << "Thread laeuft im Hintergrund..." << endl;

        // Warten, bis er beendet ist
        ts.join();
        cout << "Thread ist fertig." << endl;
    }
    else {
        cout << "Thread konnte nicht gestartet werden." << endl;
    }

    return 0;
}
