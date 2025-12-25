#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Student.h"

using namespace std;

int main()
{
	vector<Student> students;		// Vector to hold student objects
	string line;					// Holds line of .txt

	ifstream inFile;
	inFile.open("students.txt");

	/*
	or
	ifstream infile("students.txt");
	*/

	if (!inFile.is_open())
	{
		cerr << "Error opening file!" << endl;
		return 1;
	}

	int index = 0;
	while (getline(inFile, line))
	{

		stringstream ss(line);		// Creates a stream once per line

		string name;		// variable to hold name
		ss >> name;		// reads name first

		students.push_back(Student(name));

		int grade;
		while(ss >> grade)
		{
			students[index].addGrade(grade);
		}

		index++;
	}

	for (int i = 0; i < students.size(); i++)
	{
		cout << "Student " << i
			<< ": Average = " << students[i].average()
			<< " Grade = " << students[i].letterGrade()
			<< endl;
	}


	return 0;
 }