#include"Thread.h"
#include <string>
#include <iostream>
using namespace std;

class MyThread : public Thread
{
private:
	string name;

public:
	MyThread(string n) {
		name = n;
	};

	virtual void run() { // "Was soll der Thread ausführen?"
		for (int i = 0; i < 10; i++)
		{
			cout << name << endl; 
			Sleep(100);
		}
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

	MyThread tmp1("Peter");
	tmp1.start();

	MyThread tmp2("Mueller");
	tmp2.start();

	cout << "Test2" << endl;
	Sleep(500);
	cout << "Test3" << endl;
	Sleep(500);

	return 0;
}

