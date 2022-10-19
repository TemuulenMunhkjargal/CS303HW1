#include <iostream>
#include <vector>
#include "Functions.h"
#include "Classes.h"
#include <iomanip>
using namespace std;

/*
* Functions.h is the header file and Functions.cpp includes all the logic for the functions.
* I have included a test.txt file which has integers in a 10x10 format, and the readFile function is set to open that text file name only for now.
* You can plugin your own text file and change  the parameter in the readFile function as it is a simple function that reads all integers until eof.
* There is no error checking implemented for when you enter the value for which numbers to find or index and such in the while loop here in the main.cpp file.
*/



int main(){
	vector <int> vec;
	readFile(vec);
	if (vec.size() == 0) {
		return 0;
	}
	int choice, integer, value, tempValue1, tempValue2;
	while (true) {
		cin.clear();
		choice = printMenu();
		if (choice == 1) {
			cout << "\nEnter the value you want to find: ";
			cin >> integer;
			findInteger(vec, integer);
		}
		/*
		* This is where the try catch segment for the function that finds a value by index and 
		* changes it is located, in Main.cpp
		*/
		if (choice == 2) {
			cout << "\n Enter the index of the value you want to change: ";					
			try {
				cin >> integer;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					throw ("Input error");
				}
			}
			catch(...){
				cout << "\n\nINPUT ERROR\n\n";
				cin.clear();
				continue;
			}
			cout << "Enter the value you want to change it with: ";
			try {
				cin >> value;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					throw("Input error");
				}
			}
			catch (...) {
				cout << "\n\nINPUT ERROR\n\n";
				cin.clear();
				continue;
			}
			tempValue1, tempValue2 = changeValue(vec, integer, value);

		}
		/*
		* This is where the second throw catch block is implemented in the function
		* that adds an integer to the end of the array. In Main.cpp
		*/
		if (choice == 3) {
			cout << "\nEnter a number you want to add to the array: ";
			try {
				cin >> integer;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					throw("Input error");
				}
			}
			catch(...){
				cout << "\n\nINPUT ERROR\n\n";
				cin.clear();
				continue;
			}
			addInteger(vec, integer);
		}
		if (choice == 4) {
			cout << "\nEnter an index to remove the according value: ";
			cin >> integer;
			removeInteger(vec, integer);
		}
		if (choice == 5) {
			cout << "\nGoodbye.\n";
			break;
		}
	}
	/*
	When initializing either a professional or non professional employee, the parameters orders will be
	annual insurance amount -> company % of contribution to healthcare -> annual vacation hours or days (both in hour format i.e 1 day = 24) ->
	-> salary; monthly(pro), hourly(non-pro) 
	The function VacationEarned needs a parameter, which will need to be the annual vacation hours
	*/
	Professional employee1(12000, 80, 120, 6000);
	cout << "\nPROFESSIONAL EMPLOYEE\n" << "Healthcare Contribution: " << fixed << setprecision(2)
		<< employee1.HealthCareContribution() << "$\nPaid time off earned per week: "
		<< employee1.VacationEarned(120) << "\nWeekly Salary: " 
		<< employee1.WeeklySalary() << "$\n";
	NonProfessional employee2(10000, 70, 24, 32);
	cout << "\nNON-PROFESSIONAL EMPLOYEE\n" << "Healthcare Contribution: " << fixed << setprecision(2)
		<< employee2.HealthCareContribution() << "$\nPaid time off earned per week: "
		<< employee2.VacationEarned(24) << "\nWeekly Salary: "
		<< employee2.WeeklySalary() << "$\n";
}

