#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name;
	double grade[3];
};

void AddStudent(Student*& students, int& count, string& name, double grade1, double grade2, double grade3)
{
		Student* newstudents = new Student[count + 1];
		for (int i = 0; i < count; i++) 
		{
			newstudents[i] = students[i];
		}
		delete[] students;
		students = newstudents;
		students[count].name = name;
		students[count].grade[0] = grade1;
		students[count].grade[1] = grade2;
		students[count].grade[2] = grade3;
		count++;
		//delete[] newstudents;

}

void DeleteStudent(Student* students, int& count, string& name)
{
	bool f = false;
	Student* newstudents = new Student[count-1];
	for (int i = 0; i < count; i++)
	{
		if (students[i].name == name)
		{
			f = true;
		}
		else
		{
			newstudents[i] = students[i];
		}
	}
	if (f)
	{
		delete[] students;
		students = newstudents;
		count--;
	}
	else
	{
		cout << "Student is not found" << endl;
	}
	//delete[] newstudents;
}

double AverageGrade(Student*& students, int& count, string& name)
{
	bool f = false;
	for (int i = 0; i < count; i++)
	{
		if (students[i].name == name)
		{
			f = true;
			return ((students[i].grade[0] + students[i].grade[1] + students[i].grade[2]) / 3.0);
		}
	}
	if (!f)
	{
		cout << "Student is not found" << endl;
		return 0;
	}
}

void ShowAll(Student* students, int& count)
{
	if (count == 0) 
	{
		cout << "No students";
		return;
	}
	cout << "List of students:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Name: " << students[i].name << endl;
		cout << "Math: " << students[i].grade[0] << endl;
		cout << "Ukr. languahe: " << students[i].grade[1] << endl;
		cout << "Programming: " << students[i].grade[2] << endl;
		cout << " " << endl;
	}
}

int main()
{
	Student* students = nullptr;
	int counting = 0;

	int choice;
	do {
		cout << "Menu:" << endl;
		cout << "1. Add student" << endl;
		cout << "2. Delete student" << endl;;
		cout << "3. Calculate the avarage grade" << endl;
		cout << "4. Show all students" << endl;
		cout << "5. Exit" << endl;
		cout << "Choose the action: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string name;
			double grade1, grade2, grade3;

			cout << "Name: ";
			cin >> name;
			cout << "Math: ";
			cin >> grade1;
			cout << "Ukr. language: ";
			cin >> grade2;
			cout << "Programming: ";
			cin >> grade3;
			AddStudent(students, counting, name, grade1, grade2, grade3);
			break;
		}
		case 2:
		{
			string name;
			cout << "Name: ";
			cin >> name;
			DeleteStudent(students, counting, name);
			break;
		}
		case 3:
		{
			string name;
			cout << "Name: ";
			cin >> name;
			double S = AverageGrade(students, counting, name);
			if (S != 0)
			{
				cout << "The Avarage grade of " << name << " is " << S << endl;
			}
			break;
		}
		case 4:
		{
			ShowAll(students, counting);
			break;
		}
		case 5:
		{
			cout << "Exiting the program" << endl;
			break;
		}
		default:
		{
			cout << "Invalid" << endl;
		}
		}
	} while (choice != 5);
	delete[] students;
	return 0;
}