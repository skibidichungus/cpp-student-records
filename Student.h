#pragma once

#include <string>
#include <vector>

class Student
{
private:
	std::string name;
	std::vector<int> grades;

public:
	Student(const std::string& name);

	void addGrade(int grade);
	double average() const;
	int minGrade() const;
	int maxGrade() const;
	char letterGrade() const;
};