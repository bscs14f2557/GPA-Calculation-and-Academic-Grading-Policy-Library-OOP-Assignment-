#pragma once
#include<iostream>
#include<string>
using namespace std;
// class for storing all information about a course
class Course {
	string cname;
	string code;
	float marks;
	int credithrs;

public:
	//default constructor
	Course() {
		cname = "";
		code = "";
		marks = 0.0;
		credithrs = 0;
	}

	//parameterized constructor
	Course(string n, string c, float m, int hrs) {
		cname = n;
		code = c;
		marks = m;
		credithrs = hrs;
	}

	// copy constructor
	Course(const Course& c) {
		cname = c.cname;
		code = c.code;
		marks = c.marks;
		credithrs = c.credithrs;
	}

	// Displaying course details using a function
	void display() const {
		cout << cname << " - (" << code << ") - "
			<< marks << " - " << credithrs << endl;
	}

	//  using Getter
	float get_marks() const {  //FOR USING MARKS outside class
		return marks;
	}

	int get_credithrs() const {   //for using hours outside class
		return credithrs;
	}


};
// class for student's particulars
class Student {
	string name;
	string ID;
	Course courses[10];
	int totalcourses; //for seeing how many courses are we taking if 10 or less
	float gpa;

public:
	//default constructor
	Student()
	{
		name = "";
		ID = "";
		totalcourses = 0;
		gpa = 0.0;

	}
	//parameterized constructor
	Student(string sname) {
		name = sname;
		ID = "";
		totalcourses = 0;
		gpa = 0.0;
	}

	//parameterized constructor
	Student(string sname, string id)
	{
		name = sname;
		ID = id;
		totalcourses = 0;
		gpa = 0.0;

	}
	//copy constructor
	Student(const Student& s) {
		name = s.name;
		ID = s.ID;
		totalcourses = s.totalcourses;
		gpa = s.gpa;
		//loop for copying a students all courses to other student's courses one by one
		for (int i = 0; i < s.totalcourses; i++) {
			courses[i] = s.courses[i];
		}
	}
	//fnxn for adding course object directlly
	void addcourse(Course c) {
		if (totalcourses < 10) {
			courses[totalcourses] = c;
			totalcourses++;
		}
	}

	

	//fnxn overloading for courses with credit hour 1
	void addcourse(string n, string c, float m) {
		if (totalcourses < 10) {
			courses[totalcourses] = Course(n, c, m, 1);
			totalcourses++;
		}
	}

	// fnxn overloading for courses with credit hr greater than 1
	void addcourse(string n, string c, float m, int hrs)
	{
		if (totalcourses < 10) {
			courses[totalcourses] = Course(n, c, m, hrs);
			totalcourses++;
		}
	}

	//fnxn for calculating gpa by using all courses
	void calculategpa() {
		float totalpoints = 0;
		int totalcredit_hr = 0;

		for (int i = 0; i < totalcourses; i++) {
			float m = courses[i].get_marks();
			int c = courses[i].get_credithrs();

			float gp;
			//convert marks to gradepoints(gp)
			if (m >= 85) gp = 4;
			else if (m >= 75) gp = 3;
			else if (m >= 65) gp = 2;
			else if (m >= 50) gp = 1;
			else gp = 0;

			totalpoints += gp * c;
			totalcredit_hr += c;
		}
		//finall gpa calculation
		if (totalcredit_hr != 0)
			gpa = totalpoints / totalcredit_hr;
	}

	//grade of every course
	char getgrade(float m) {
		if (m >= 85) return 'A';
		else if (m >= 75) return 'B';
		else if (m >= 65) return 'C';
		else if (m >= 50) return 'D';
		else return 'F';
	}

	//overall grade
	char getoverallgrade()const {
		if (gpa >= 3.5) return 'A';
		else if (gpa >= 3.0) return 'B';
		else if (gpa >= 2.5) return 'C';
		else if (gpa >= 2.0) return 'D';
		else return 'F';
	}

	//displaying  all data of students
	void show() {
		cout << " Student Name: " << name << endl;
		cout << " Student ID: " << ID << endl;
		cout << "Student GPA: " << gpa << endl;
		cout << "Student Grade: " << getoverallgrade() << endl;

		//displaying courses with its particular grade
		cout << "Courses : " << endl;
		for (int i = 0; i < totalcourses; i++) {
			courses[i].display();
			cout << "GRADE : " << getgrade(courses[i].get_marks()) << endl;
		}
	}

	// + operator overloading(combining two gpas average nikali)
	Student operator+(const Student& s) {
		Student temp;
		temp.name = "Combine";
		temp.gpa = (gpa + s.gpa) / 2;//cuz add kr k average value of both students
		return temp;
	}
	// - operator overloading(difference of two gpas)
	Student operator-(const Student& s) {
		Student temp;
		temp.name = "Difference";
		temp.gpa = (gpa - s.gpa);
		return temp;
	}
	//== operator overloading(comparing gpas)
	bool operator==(const Student& s) const {
		return this->gpa == s.gpa;
	}
	//output(operator overloading) -- 
	friend ostream& operator<<(ostream& out, const Student& s) {
		out << "Name: " << s.name << endl;
		out << "GPA: " << s.gpa << endl;
		//out << "Overall Grade : " << s.getoverallgrade() << endl;

		for (int i = 0; i < s.totalcourses; i++) {
			s.courses[i].display();
		}

		return out;
	}
};
