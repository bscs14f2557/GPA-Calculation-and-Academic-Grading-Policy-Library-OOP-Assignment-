#include<iostream>
#include"headerfile.h"
using namespace std;
/*void show() {
	
}*/
int main()
{
	//show();
	cout << "\t\t GPA Calculation And Grading System \t\t" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "                       " << endl;
	int n;
	//taking number of students from user
	cout << "Enter number of students : ";
	cin >> n;
	cout << "                       " << endl;
	//creating array for students to manage large number of students
	Student students[50];
	//using loop
	for (int i = 0; i < n; i++) {
		string name, id;
		cout << "                    " << endl;
		cout << "Enter name of student " << i + 1 << " : ";
		cin >> name;
		cout << "Enter ID : ";
		cin >> id;
		students[i] = Student(name, id);//using parameterized constructor

		//for courses
		int c;
		cout << "Enter number of courses : ";
		cin >> c;
		for (int j = 0; j < c; j++) {
			string cname, code;
			float marks;
			int hrs;
			cout << "                " << endl;
			cout << "Course " << j + 1 << " Name : ";
			cin >> cname;
			cout << "Course Code : ";
			cin >> code;
			cout << "Marks : ";
			cin >> marks;
			cout << "Credit Hours : ";
			cin >> hrs;

			//we are using fnxn overloading , if credit hr =1 and  if greater than 1 
			if (hrs == 1) //credit hr=1
			{
				students[i].addcourse(cname, code, marks);
			}
			else
			{
				students[i].addcourse(cname, code, marks, hrs);
			}

		}
		//calculation of gpa for students
		students[i].calculategpa();
	}
	//displaying all data
	cout << "\t\t ALL STUDENTS\t\t" << endl;
	for (int i = 0; i < n; i++) {
		cout << "                        " << endl;
		students[i].show();
		cout << "                        " << endl;
	}

	//operator overloading

	if (n >= 2)
	{
		Student s3 = students[0] + students[1];
		cout <<  s3 << endl;
		cout << "                            " << endl;
		Student s4 = students[0] - students[1];
		cout << s4 << endl;
		cout << "                            " << endl;
		if (students[0] == students[1]) {
			cout << " Same GPA " << endl;
		}
		else
			cout << " Different GPA " << endl;


		// copy constructor
		cout << "                     " << endl;
		cout << "Copy Constructor : " << endl;
		cout << "                     " << endl;
		Student s2 = students[0];
		s2.show();



	}

	return 0;
}
