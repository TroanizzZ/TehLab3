#include <iostream>
#include "Worker.h"
#include "WorkerHour.h"
#include "WorkerState.h"
#include "WorkerPercent.h"

int main()
{
	Worker* obj = nullptr;
	int callback;
	while (true)
	{
		system("cls");
		cout << "Perform payroll calculation : " << endl
			<< "1. Hourly wage worker" << endl
			<< "2. State employee" << endl
			<< "3. Percent worker" << endl
			<< "0. Output" << endl;
		cin >> callback;
		switch (callback)
		{
		case 1:
			if (!obj)
				delete obj;
			obj = new WorkerHour;
			cout << obj->cash() << endl;
			break;
		case 2:
			if (!obj)
				delete obj;
			obj = new WorkerState;
			cout << obj->cash() << endl;
			break;
		case 3:
			if (!obj)
				delete obj;
			obj = new WorkerPercent;
			cout << obj->cash() << endl;
			break;
		case 0:
			delete obj;
			return 0;
		default:
			break;
		}
		system("pause");
	}
	return 0;
}
