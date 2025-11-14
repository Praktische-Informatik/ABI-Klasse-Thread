#pragma once
#include <thread>
#include <atomic>

class Thread {
private:
    std::thread p_thread;
    std::atomic<bool> running;
    std::atomic<bool> stopRequested;

public:
    Thread() : running(false), stopRequested(false) {}

    virtual ~Thread() {
        requestStop();
        if (p_thread.joinable()) {
            p_thread.join();
        }
    }

    // Muss von der Unterklasse implementiert werden
    virtual void run() = 0;

    // Startet den Thread
    virtual bool start() {
        if (running) return false;

        running = true;
        stopRequested = false;

        // threadFunction NICHT static, einfacher und modern
        p_thread = std::thread(&Thread::threadLoop, this);
        return true;
    }

    // Signalisiert dem Thread, dass er aufhoeren soll
    void requestStop() {
        stopRequested = true;
    }

    // Unterklassen koennen diese Methode abfragen:
    bool stopRequestedFlag() const {
        return stopRequested;
    }

    // Warten auf das Thread-Ende
    void join() {
        if (p_thread.joinable()) {
            p_thread.join();
        }
        running = false;
    }

private:
    // Thread-Hauptschleife
    void threadLoop() {
        run();          // Ausführung der Unterklasse
        running = false;
    }
};
