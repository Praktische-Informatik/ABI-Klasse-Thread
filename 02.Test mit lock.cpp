#include"Thread.h"
#include <string>
#include <iostream>
using namespace std;

class MyThread : public CThread
{
private:
	string name;
	bool* lock; // alternativ static

public:
	MyThread(string n, bool* l) {
		name = n;
		lock = l;
	};

	virtual void run() { 
		while ((*lock) == true) {
			cout << "."; 
			Sleep(30); // 130
		}

		(*lock) = true;
		for (int i = 0; i < 10; i++)
		{
			cout << name << endl;
			Sleep(100);
	
		}
		(*lock) = false;


	};

	virtual bool start() // erzeugt einen Thread und startet die run-Methode
	{
		CThread::start();
		return true;
	}
};


//int main()
//{
//	cout << "Test1" << endl;
//
//	bool l = false; // Zugriff erlaubt
//	MyThread tmp1("Peter", &l);
//	tmp1.start();
//
//	MyThread tmp2("Mueller", &l);
//	tmp2.start();
//
//	cout << "Test2" << endl;
//	Sleep(1000);
//	cout << "Test3" << endl;
//	Sleep(1000);
//
//	return 0;
//}

