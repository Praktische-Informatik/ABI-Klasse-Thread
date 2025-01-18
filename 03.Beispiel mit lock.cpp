#include "Thread.h"
#include <string>
#include <iostream>
#include <atomic> // Für atomare Variablen
#include <thread> // Für std::this_thread::sleep_for

using namespace std;

class MyThread : public Thread {
private:
    string name; // Name des Threads
    atomic<bool>* lock; // Atomare Variable für die Sperre

public:
    MyThread(string n, atomic<bool>* l) : name(n), lock(l) {}

    virtual void run() override {
        while (*lock) { // Warten, bis die Sperre aufgehoben wird
            cout << ".";
            std::this_thread::sleep_for(std::chrono::milliseconds(30)); // Pause für 30 Millisekunden
        }

        *lock = true; // Sperre setzen, um andere Threads zu blockieren
        for (int i = 0; i < 10; i++) {
            cout << name << endl; // Ausgabe des Namens
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause für 100 Millisekunden
        }
        *lock = false; // Sperre aufheben
    }

    virtual bool start() override {
        return Thread::start(); // Aufruf der Start-Methode der Basisklasse
    }
};

int main() {
    cout << "Test1" << endl;

    atomic<bool> l(false); // Zugriff erlaubt
    MyThread tmp1("Peter", &l);
    tmp1.start();

    MyThread tmp2("Mueller", &l);
    tmp2.start();

    cout << "Test2" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Pause für 1000 Millisekunden
    cout << "Test3" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Pause für 1000 Millisekunden

    return 0;
}