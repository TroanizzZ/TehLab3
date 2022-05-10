#include "WorkerPercent.h"

WorkerPercent::WorkerPercent()
{
	string initfile = "WorkerPercent.txt";
	ifstream in;
	ofstream out;
	string callback;
	int flag, c;
	cout << "Enter manually or load from file?" << endl;
	cout << "1 - Manually" << endl;
	cout << "0 - Load from file" << endl;
	cout << "--> ";
	cin >> flag;
	if (!flag)
	{
		in.open(initfile);
		if (!in || is_empty(in))
		{
			cout << "File Empty" << endl;
			system("pause");
			flag = 1;
		}
	}
	if (flag)
	{
			system("cls");
			cout << "Enter name" << endl;
			cin >> callback;
			setData(1, callback);
			cout << "Enter Last Name" << endl;
			cin >> callback;
			setData(2, callback);
			cout << "Enter Phone" << endl;
			cin >> callback;
			setData(3, callback);
			cout << "Enter Address" << endl;
			cin >> callback;
			setData(4, callback);
			cout << "Enter monthly sales" << endl;
			cin >> mounthSells;
			cout << "Enter percentage of sales" << endl;
			cin >> percent;
			cout << "Do you want to overwrite the file with new data?" << endl;
			cout << "1 - Yes" << endl;
			cout << "2 - No" << endl;
			cout << "--> ";
			cin >> c;

			in.close();
			switch (c)
			{
			case 1:
				out.open(initfile);
				if (!out)
				{
					cout << "File opening error!" << endl;
					exit(1);
				}
				out << getData(1) << "\n" << getData(2) << "\n" << getData(3) << "\n" << getData(4) << "\n" << mounthSells << "\n" << percent;
				out.close();
				cout << "Data recorded!" << endl;
				break;
			case 2:
				break;
			default:
				break;
			}
	}
	else
	{
		in >> callback;
		
		cout << "Name: " << callback << endl;
		setData(1, callback);
		in >> callback;
		cout << "Surname: " << callback << endl;
		setData(2, callback);
		in >> callback;
		cout << "Telephone: " << callback << endl;
		setData(3, callback);
		in >> callback;
		cout << "Address: " << callback << endl;
		setData(4, callback);
		in >> mounthSells >> percent;
		in.close();
		cout << "Monthly Sales: " << mounthSells << endl;
		cout << "Percent: " << percent << endl;
		cout << "Delete data?" << endl;
		cout << "1 - Yes" << endl;
		cout << "2 - No" << endl;
		cout << "--> ";
		cin >> c;
		switch (c)
		{
		case 1: 
			out.open(initfile);
			if (!out)
			{
				cout << "File opening error!" << endl;
				exit(1);
			}
			cout << "Deleted" << endl;
			out.close();
			break;
		case 2:
			break;
		default:
			break;
		}
		
		
	}

	
}

WorkerPercent::~WorkerPercent()
{
	
}

int WorkerPercent::cash()
{
	cout << "Cash: " ;
	return mounthSells / 100 * percent;
}
