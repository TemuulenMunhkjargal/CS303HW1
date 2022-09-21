#pragma once
#include <vector>
using namespace std;

// Prints simple menu and returns user choice
int printMenu();

// Takes a vector by reference and adds values into the vector after reading integers from a file
void readFile(vector <int>&);

// Checks if an integer exists in the vector and returns the index of it, else returns -1
int findInteger(vector <int>, int);

// Changes the value of an integer in the vector by index and sends back both the old and new value
int changeValue(vector <int>&, int, int);

// Adds a new a integer to the end of the vector
void addInteger(vector <int>&, int);

// Removes an integer to the according index
void removeInteger(vector <int>&, int);



