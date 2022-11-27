#pragma once
#include <thread>
#include <windows.h>
using namespace std;

class Thread // Abstrakte Klasse
{
private:
	thread* p_thread;
public:
	Thread(void);
	~Thread(void);
	virtual void run() = 0 ; // virtuelle Funktion
	void test(){};
	virtual bool start(void);
};

