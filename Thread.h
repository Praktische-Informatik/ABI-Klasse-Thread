#pragma once
#include <thread>
#include <functional>
#include <atomic>

class Thread { // Abstrakte Klasse
private:
    std::thread p_thread;
    std::atomic<bool> running;

public:
    Thread() : running(false) {}
    virtual ~Thread() {
        if (running) {
            join(); // Sicherstellen, dass der Thread beendet wird
        }
    }

    virtual void run() = 0; // Virtuelle Funktion

    virtual bool start() { // Diese Methode sollte virtual sein
        if (running) return false; // Verhindern, dass der Thread mehrfach gestartet wird

        running = true;
        p_thread = std::thread(&Thread::threadFunction, this);
        return true;
    }

    void join() {
        if (p_thread.joinable()) {
            p_thread.join();
            running = false;
        }
    }

private:
    static void threadFunction(Thread* threadInstance) {
        threadInstance->run();
    }
};