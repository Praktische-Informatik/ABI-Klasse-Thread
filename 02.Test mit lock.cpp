#include"Thread.h"
#include <string>
#include <iostream>
using namespace std;

class MyThread : public Thread
{
private:
	string name;
	bool* lock;

public:
	MyThread(string n, bool* l) {
		name = n;
		lock = l;
	};

	virtual void run() { 
		while (*lock == true) { // Ist die run-Methode schon in Benutzung bzw. "gelockt"?
			// '*' Dereferenzierungs-Operator (auch: Inhaltsoperator) 
			cout << "."; 
			Sleep(30); // 130
		}

		*lock = true; // Sperre für andere run-Methoden 
		for (int i = 0; i < 10; i++) // und schreibe 10x deinen Namen.
		{
			cout << name << endl;
			Sleep(100);				// lass dir Zeit dabei ;) Aber wenn du dir zu viel Zeit läßt (500) wird der Vater-Thread dich vorzeitig löschen.
	
		}
		*lock = false; // Sperre aufheben
	};

	virtual bool start() // erzeugt einen Thread und startet die run-Methode
	{
		Thread::start();
		return true;
	}
};


int main()
{
	cout << "Test1" << endl;

	bool l = false; // Zugriff erlaubt
	MyThread tmp1("Peter", &l);
	tmp1.start();

	MyThread tmp2("Mueller", &l);
	tmp2.start();

	cout << "Test2" << endl;
	Sleep(1000);
	cout << "Test3" << endl;
	Sleep(1000);

	return 0; 
}

