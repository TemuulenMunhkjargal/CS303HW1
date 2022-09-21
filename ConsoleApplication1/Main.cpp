#include <iostream>
#include <vector>
#include "Functions.h"
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
		if (choice == 2) {
			cout << "\n Enter the index of the value you want to change: ";
			cin >> integer;
			cout << "Enter the value you want to change it with: ";
			cin >> value;
			tempValue1, tempValue2 = changeValue(vec, integer, value);

		}
		if (choice == 3) {
			cout << "\nEnter a number you want to add to the array: ";
			cin >> integer;
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
}

