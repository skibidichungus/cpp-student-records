#include "Student.h"


// Constructor
Student::Student(const std::string& name) : name(name) {}

void Student::addGrade(int grade)
{
	if (grade >= 0 && grade <= 100)
		grades.push_back(grade);
}

double Student::average() const
{
	if (grades.size() == 0)
		return -1;

	double sum = 0;

	for (int index = 0; index < grades.size(); index++)
		sum += grades[index];

	return sum / grades.size();
}

int Student::minGrade() const
{
	if (grades.size() == 0)
		return -1;

	int minNum = grades[0];

	for (int index = 1; index < grades.size(); index++)
		if (minNum > grades[index])
			minNum = grades[index];

	return minNum;
}

int Student::maxGrade() const
{
	if (grades.size() == 0)
		return -1;

	int maxNum = grades[0];

	for (int index = 0; index < grades.size(); index++)
		if (maxNum < grades[index])
			maxNum = grades[index];

	return maxNum;
}

char Student::letterGrade() const
{

	double averageGrade = average();

	if (averageGrade == -1)
		return 'N';

	char letterGrade;

	if (averageGrade > 89)
		letterGrade = 'A';
	else if (averageGrade > 79)
		letterGrade = 'B';
	else if (averageGrade > 69)
		letterGrade = 'C';
	else if (averageGrade > 59)
		letterGrade = 'D';
	else
		letterGrade = 'F';

	return letterGrade;
}