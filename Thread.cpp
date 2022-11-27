#include "Thread.h"

static DWORD WINAPI ThreadFunktion(LPVOID param) { // Wird mit der Methode start() aktiviert und startet die run(). >> statische Methode 
	Thread* p_tmp= (Thread*) param;
    p_tmp->run();
	return 0;
}
  

Thread::Thread(void)
{
}


Thread::~Thread(void)
{
}


bool Thread::start(void)
{

	DWORD threadId = 0; 
    HANDLE threadHandle = CreateThread(0, // keine Security 
                                       0, // default-Stack 
                                       ThreadFunktion, 
                                       this, // kein Parameter 
                                       0, // normal erzeugen 
                                       &threadId // threadId 
                                       );

	return false;
}
