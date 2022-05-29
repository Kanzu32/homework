#include <iostream>
#include <iomanip>

using namespace std;

struct Aviasales
{
	string destination, flight_num, full_name, date;
	Aviasales *next;
	Aviasales(string destination, string flight_num,
			  string full_name, string date) : destination(destination), flight_num(flight_num),
											   full_name(full_name), date(date), next(nullptr) {}
};

void Cancel(Aviasales *passengers, int n, string date, string flight_num);

int main()
{
	string destination, flight_num, full_name, initials, date;
	int n;
	cout << "Enter the number of applications: ";
	cin >> n;
	cout << "Destination" << setw(15) << "Flight number" << setw(13) << "Full name" << setw(18) << "day.month.year" << setw(10) << endl;
	cin >> destination >> flight_num >> full_name >> initials >> date;
	Aviasales *head = new Aviasales(destination, flight_num, full_name, date), *prev;
	prev = head;
	for (int i = 1, Aviasales; i < n; i++)
	{
		cin >> destination >> flight_num >> full_name >> initials >> date;
		full_name += " " + initials;
		prev->next = new Aviasales(destination, flight_num, full_name, date);
		prev = prev->next;
	}
	cout << endl
		 << "Enter date and flight number to delete: ";
	cin >> date >> flight_num;
	Cancel(head, n, date, flight_num);
	return 0;
}

void Delete(Aviasales *passengers, int i)
{
	cout << i << endl;
}

void Cancel(Aviasales *Next, int n, string date, string flight_num)
{
	Aviasales *prev = Next;
	for (int i = 0; i < n; i++)
	{
		if (Next->date == date && Next->flight_num == flight_num)
		{
			Delete(Next, i);
		}
		else
		{
			cout << endl
				 << Next->destination << setw(15)
				 << Next->flight_num << setw(13)
				 << Next->full_name << setw(18)
				 << Next->date << setw(10);
			Next = Next->next;
		}
	}
	cout << endl;
}