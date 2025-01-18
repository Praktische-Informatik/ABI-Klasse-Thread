#include "Thread.h" // Einbinden der Thread-Klasse
#include <string>
#include <iostream>
#include <chrono> // F�r std::chrono::milliseconds
#include <thread>  // F�r std::this_thread::sleep_for

using namespace std;

class MyThread : public Thread {
private:
    string name; // Name des Threads

public:
    // Konstruktor, der den Namen des Threads initialisiert
    MyThread(string n) : name(n) {}

    // Virtuelle Funktion, die definiert, was der Thread ausf�hren soll
    virtual void run() override {
        for (int i = 0; i < 10; i++) {
            cout << name << endl; // Ausgabe des Namens
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause f�r 100 Millisekunden
        }
    }

    // Start-Methode, die den Thread startet
    virtual bool start() override {
        return Thread::start(); // Aufruf der Start-Methode der Basisklasse
    }
};

//int main() {
//    cout << "Test1" << endl;
//
//    // Erstellen und Starten des ersten Threads
//    MyThread tmp1("Peter");
//    tmp1.start();
//
//    // Erstellen und Starten des zweiten Threads
//    MyThread tmp2("Mueller");
//    tmp2.start();
//
//    cout << "Test2" << endl;
//
//    // Hauptthread pausiert f�r 500 Millisekunden
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    cout << "Test3" << endl;
//
//    // Warten, bis die Threads abgeschlossen sind
//    tmp1.join();
//    tmp2.join();
//
//    return 0;
//}