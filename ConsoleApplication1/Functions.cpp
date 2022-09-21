#include "Functions.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int printMenu() {
		cout << "1. Check for integer (returns index).\n"
			<< "2. Change integer value by index (returns old and new values).\n"
			<< "3. Add new integer to the end of the array.\n"
			<< "4. Remove integer through index.\n"
			<< "5. Quit.\n"
			<< "\n Enter your option: ";
		int choice;
		try {
			cin >> choice;
			if (cin.fail() || choice > 5) {
				cin.clear();
				cin.ignore();
				throw(505);
			}
			else {
				return choice;
			}
		}
		catch (...) {
			cout << "\n\nINPUT ERROR\n\n";
			cin.clear();
		}
}

void readFile(vector <int>& vec) {
	ifstream inFile;
	inFile.open("test.txt");
	if (!inFile.is_open()) {
		cout << "COULD NOT FIND TEXT FILE TO OPEN\n";
	}
	int temp;
	while (inFile >> temp) {
		vec.push_back(temp);
	}
	inFile.close();
}




int findInteger(vector <int> vec, int num) {
	for (int i = 0; i < vec.size(); i++) {
		if(vec.at(i) == num){
			cout << "Found integer " << vec.at(i) << " at index " << i << endl << endl;
			return i;
		}
	}
	cout << "\nERROR: Integer not found\n";
	return -1;
}

int changeValue(vector<int>& vec, int index, int tempVal) {
	int oldNum;
	for (int i = 0; i < vec.size(); i++) {
		if (i == index) {
			cout << "\nInteger " << vec.at(i) << " found at index " << i;
			oldNum = vec.at(i);
			vec.at(i) = tempVal;
			cout << "\nOld value: " << oldNum << " <--> New value: " << vec.at(i) << endl << endl;
			return oldNum, vec.at(i);
		}
	}
	cout << "\nERROR: Number at index not found\n";
	return -1;
}

void addInteger(vector<int>& vec, int val) {
	cout << "Value " << val << " added to the array.\n\n";
	vec.push_back(val);
}

void removeInteger(vector<int>& vec, int index) {
	for (int i = 0; i < vec.size(); i++) {
		if (i == index) {
			cout << "Integer " << vec.at(i) << " removed at index " << index << endl << endl;
			vec.erase(vec.begin() + index);
			return;
		}
	}
	cout << "\nERROR: Index not found\n";
}
