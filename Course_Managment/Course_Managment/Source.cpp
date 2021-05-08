#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
//============================================
struct Student
{
	char ID[30], Name[30], Year[30];
};
struct Course
{
	char ID[30], Name[30], Instructor[30], Place[30];
};
struct Enroll
{
	char CID[30], SID[30], CName[30], SName[30], Grade[30];
};
//============================================
void Add_New_Course();
void Add_New_Student();
void Search_Course();
void Search_Student();
void Edit_Course();
void Edit_Student();
void Edit_Grades();
void Enroll_Student();
void Unenroll_student();
void Display_All_Courses(bool f);
void Delete_Course();
void Delete_Student();
void complete_deletion(char InID[30], bool f);
//=========================================================================
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string ans;
	do {
		cout << "///////////////////////////////////////////////////////////////////////////////////////////";
		cout << "\n\n\t\t\t" << "Welcome To The Course Managment System\n\n";
		cout << "///////////////////////////////////////////////////////////////////////////////////////////";
		cout << "\n\nPlease Choose The Desired Operation :-\n\n";
		cout << "1-> Add a New Course\t\t";       cout << "2-> Add a New Student\n\n";
		cout << "3-> Search For a Course\t\t";    cout << "4-> Search For a Student\n\n";
		cout << "5-> Display All Courses\t\t";    cout << "6-> Enroll Student To a Course\n\n";
		cout << "7-> Edit a Course info\t\t";     cout << "8-> Edit a Student Info\n\n";
		cout << "9-> Delete a Course\t\t";        cout << "10-> Delete a Student\n\n";
		cout << "11-> Edit Grades of Students\t"; cout << "12-> Unenroll student\n\n";
		cout << "\n" << "Please Enter The Chosen Number: ";
		int op;
		cin >> op;
		switch (op)
		{
		case 1:
			Add_New_Course();
			break;
		case 2:
			Add_New_Student();
			break;
		case 3:
			Search_Course();
			break;
		case 4:
			Search_Student();
			break;
		case 5:
			Display_All_Courses(0);
			break;
		case 6:
			Enroll_Student();
			break;
		case 7:
			Edit_Course();
			break;
		case 8:
			Edit_Student();
			break;
		case 9:
			Delete_Course();
			break;
		case 10:
			Delete_Student();
			break;
		case 11:
			Edit_Grades();
			break;
		case 12:
			Unenroll_student();
			break;
		default:
			cout << "Sorry The Number You Have Entered Is Incorrect!\n";
		}
		cout << "\nDo You Want To Perform Another Operation ?\n";
		cin >> ans;
		transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
		system("CLS");
	} while (ans == "yes");
	cout << "\t\tThank You\n";
	system("pause");
	return 0;
}
//=========================================================================
void Add_New_Course()
{
	cin.ignore();
	Course obj;
	fstream file, tmp;
	/*
	int cnt = 0, a;
	char InID[30];
	string s;
	file.open("IDGenerator.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{
	file >> s;
	int a = stoi(s) + 1;
	s = to_string(a);
	if (cnt == 0)
	obj.ID = a , cnt++;
	tmp << s << "\n";
	}
	tmp.close();
	file.close();
	file.open("course.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!tmp.eof())
	{
	tmp >> s;
	file << s << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
	*/
	cout << "\nEnter The Course ID : ";
	cin.getline(obj.ID, 30);

	cout << "Please Enter The Course Name : ";
	cin.getline(obj.Name, 30);
	cout << "Please Enter The Instructor Name : ";
	cin.getline(obj.Instructor, 30);
	cout << "Please Enter The Place Of The Course : ";
	cin.getline(obj.Place, 30);
	file.open("course.txt", ios::app);
	file << obj.ID << '|' << obj.Name << '|' << obj.Instructor << '|' << obj.Place << "\n";
	file.close();
	cout << "The Course Is Added Successfully !\n";
	cout << "Your Course ID Is : " << obj.ID << "\n";
}
//=========================================================================
void Add_New_Student()
{
	cin.ignore();
	Student obj;
	fstream file, tmp;
	/*
	int cnt = 0, a;
	char InID[30];
	string s;
	file.open("IDGenerator.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{
	file >> s;
	int a = stoi(s) + 1;
	s = to_string(a);
	if (cnt == 1)
	obj.ID = a , cnt++;
	tmp << s << "\n";
	}
	tmp.close();
	file.close();
	file.open("course.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!tmp.eof())
	{
	tmp >> s;
	file << s << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
	*/
	cout << "\nEnter The Student ID : ";
	cin.getline(obj.ID, 30);

	cout << "Please Enter The Student Name : ";
	cin.getline(obj.Name, 30);
	cout << "Please Enter The Student Year : ";
	cin.getline(obj.Year, 30);
	file.open("student.txt", ios::app);
	file << obj.ID << '|' << obj.Name << '|' << obj.Year << "\n";
	file.close();
	cout << "\nThe Student Is Added Successfully !";
	cout << "\nThe Student ID Is : " << obj.ID;

	char InID[30];
	cout << "\n\nHere You Are All The Courses :-\n";
	Display_All_Courses(1);
	cout << "\nPlease Enter The ID Of The Desired Course :-\n";
	cout << "ID : ";  cin.getline(InID, 30);
	bool exist = 0;
	Course object;
	file.open("course.txt", ios::in);
	while (!file.eof())
	{
		file.getline(object.ID, 30, '|');
		file.getline(object.Name, 30, '|');
		file.getline(object.Instructor, 30, '|');
		file.getline(object.Place, 30);
		if (strcmp(InID, object.ID) == 0)
		{
			exist = 1; break;
		}
	}
	file.close();
	if (!exist)
		cout << "ERROR There Is No Course With That ID !\n";
	else
	{
		file.open("enroll.txt", ios::app);
		file << InID << '|' << obj.ID << '|' << object.Name << '|' << obj.Name << '|' << '-' << "\n";
		file.close();
		cout << "The Student Have been Enrolled Successfully\n";
	}
}
//=========================================================================
void Display_All_Courses(bool f)
{
	if (f == 0)cin.ignore();
	Course obj;
	ifstream file;
	file.open("course.txt", ios::in);
	while (!file.eof())
	{
		file.getline(obj.ID, 30, '|');
		file.getline(obj.Name, 30, '|');
		file.getline(obj.Instructor, 30, '|');
		file.getline(obj.Place, 30);
		string s(obj.ID);
		if (s.empty())
			continue;
		cout << "Course With ID : ( " << obj.ID << " )";
		cout << "\nThe Course Name Is : " << obj.Name;
		cout << "\nThe Instructor Name Is : " << obj.Instructor;
		cout << "\nThe Place Of The Course Is : " << obj.Place;
		cout << "\n_______________________________________\n\n";
	}
	file.close();
}
//=========================================================================
void Search_Course()
{
	cin.ignore();
	char InID[30];
	bool exist = 0;
	Course obj;
	cout << "\nPlease Enter The ID Or The Name Of The Course : ";
	cin.getline(InID, 30);
	ifstream file;
	file.open("course.txt", ios::in);
	while (!file.eof())
	{
		file.getline(obj.ID, 30, '|');
		file.getline(obj.Name, 30, '|');
		file.getline(obj.Instructor, 30, '|');
		file.getline(obj.Place, 30);
		if (strcmp(InID, obj.ID) == 0 || strcmp(InID, obj.Name) == 0)
		{
			if (strcmp(InID, obj.ID) == 0)
				cout << "\nThe Course Name Is : " << obj.Name;
			else
				cout << "\nThe Course ID Is : " << obj.ID;
			cout << "\nThe Instructor Name Is : " << obj.Instructor;
			cout << "\nThe Place Of The Course Is : " << obj.Place;
			exist = 1; break;
		}
	}
	file.close();
	cout << "\n";
	if (!exist)
		cout << "The Course Name Or ID You Have Entered Is Incorrect !\n";
	else
	{
		exist = 0;
		int cnt = 1;
		Enroll object;
		file.open("Enroll.txt", ios::in);
		while (!file.eof())
		{
			file.getline(object.CID, 30, '|');
			file.getline(object.SID, 30, '|');
			file.getline(object.CName, 30, '|');
			file.getline(object.SName, 30, '|');
			file.getline(object.Grade, 30);
			string s(object.CID);
			if (s.empty())
				continue;
			if (strcmp(obj.ID, object.CID) == 0)
			{
				cout << cnt << ") " << object.SName << " => ( " << object.Grade << " )\n";
				exist = 1;
			}
		}
		file.close();
		if (!exist)
			cout << "There Is No Student Enrolled In This Course Yet !\n";
	}
}
//=========================================================================
void Search_Student()
{
	cin.ignore();
	char InID[30];
	bool exist = 0;
	Student obj;
	cout << "Please Enter The ID Or The Name Of The Student : ";
	cin.getline(InID, 30);
	ifstream file;
	file.open("student.txt", ios::in);
	while (!file.eof())
	{
		file.getline(obj.ID, 30, '|');
		file.getline(obj.Name, 30, '|');
		file.getline(obj.Year, 30);
		if (strcmp(InID, obj.ID) == 0 || strcmp(InID, obj.Name) == 0)
		{
			if (strcmp(InID, obj.ID) == 0)
				cout << "\nThe Student Name Is : " << obj.Name;
			else
				cout << "\nThe Student ID Is : " << obj.ID;
			cout << "\nThe Student Year Is : " << obj.Year;
			exist = 1; break;
		}
	}
	file.close();
	cout << "\n";
	if (!exist)
		cout << "The Student ID You Have Entered Is Incorrect !\n";
	else
	{
		bool exist = 0;
		int cnt = 1;
		Enroll object;
		file.open("Enroll.txt", ios::in);
		while (!file.eof())
		{
			file.getline(object.CID, 30, '|');
			file.getline(object.SID, 30, '|');
			file.getline(object.CName, 30, '|');
			file.getline(object.SName, 30, '|');
			file.getline(object.Grade, 30);
			string s(object.CID);
			if (s.empty())
				continue;
			if (strcmp(obj.ID, object.SID) == 0)
			{
				cout << cnt << ") " << object.CName << " => ( " << object.Grade << " )\n";
				exist = 1;
			}
		}
		file.close();
		if (!exist)
			cout << "There Student didn't enroll in any Course Yet !\n";
	}
}
//=========================================================================
void Edit_Course()
{
	cin.ignore();
	char InID[30];
	cout << "\nPlease Enter The ID Or The Name Of The Course To Be Editted : ";
	cin.getline(InID, 30);
	bool exist = 0;
	Course obj;
	fstream file, tmp;
	file.open("course.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{
		file.getline(obj.ID, 30, '|');
		file.getline(obj.Name, 30, '|');
		file.getline(obj.Instructor, 30, '|');
		file.getline(obj.Place, 30);
		if (strcmp(InID, obj.ID) == 0 || strcmp(InID, obj.Name) == 0)
		{
			cout << "Please Enter The New Data :-\n";
			cout << "\nThe Instructor Name Is : ";
			cin >> obj.Instructor;
			cout << "The Place Of The Course Is : ";
			cin >> obj.Place;
			exist = 1;
		}
		tmp << obj.ID << '|' << obj.Name << '|' << obj.Instructor << '|' << obj.Place << "\n";
	}
	tmp.close();
	file.close();
	file.open("course.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!tmp.eof())
	{
		tmp.getline(obj.ID, 30, '|');
		tmp.getline(obj.Name, 30, '|');
		tmp.getline(obj.Instructor, 30, '|');
		tmp.getline(obj.Place, 30);
		file << obj.ID << '|' << obj.Name << '|' << obj.Instructor << '|' << obj.Place << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
	if (exist)
		cout << "The Course Is Updated Successfully\n";
	else
		cout << "ERROR The ID You Have Entered Is Not Correct !\n";
}
//=========================================================================
void Edit_Student()
{
	cin.ignore();
	char InID[30];
	cout << "Please Enter The ID Or The Name Of The Student To Be Editted : ";
	bool exist = 0;
	cin.getline(InID, 30);
	Student obj;
	fstream file, tmp;
	file.open("student.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{
		file.getline(obj.ID, 30, '|');
		file.getline(obj.Name, 30, '|');
		file.getline(obj.Year, 30);
		if (strcmp(InID, obj.ID) == 0 || strcmp(InID, obj.ID) == 0)
		{
			cout << "Please Enter The New Data :-";
			cout << "\nPlease Enter The Student Year : ";
			cin >> obj.Year;
			exist = 1;
		}
		tmp << obj.ID << '|' << obj.Name << '|' << obj.Year << "\n";
	}
	tmp.close();
	file.close();
	file.open("student.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!tmp.eof())
	{
		tmp.getline(obj.ID, 30, '|');
		tmp.getline(obj.Name, 30, '|');
		tmp.getline(obj.Year, 30);
		file << obj.ID << '|' << obj.Name << '|' << obj.Year << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
	if (exist)
		cout << "The Student Info Updated Successfully\n";
	else
		cout << "The ID You Have Entered Is Incorrect !\n";
}
//=========================================================================
void Edit_Grades()
{
	cin.ignore();
	int f;
	char InCID[30], InSID[30];
	cout << "Please Enter The Course ID : ";
	cin >> InCID;
	cout << "Do You Want To Change A single Student Grade Or All Students' Grades In The Course : ";
	cout << "\n1- Single\t 2-All\n";
	cout << "Please Enter The Number : ";
	cin >> f;
	if (f == 1)
	{
		cout << "Please Enter The Student ID : ";
		cin >> InSID;
	}
	Enroll obj;
	fstream file, tmp;
	file.open("enroll.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{
		file.getline(obj.CID, 30, '|');
		file.getline(obj.SID, 30, '|');
		file.getline(obj.CName, 30, '|');
		file.getline(obj.SName, 30, '|');
		file.getline(obj.Grade, 30);
		if (f == 1)
		{
			if (strcmp(InCID, obj.CID) == 0 && strcmp(InSID, obj.SID) == 0)
			{
				cout << "Please Enter The Grade : ";
				cin >> obj.Grade;
			}
		}
		if (f == 2)
		{
			if (strcmp(InCID, obj.CID) == 0)
			{
				cout << "Please Enter The New Grade Of " << obj.SName << " : ";
				cin >> obj.Grade;
			}
		}
		tmp << obj.CID << '|' << obj.SID << '|' << obj.CName << '|' << obj.SName << '|' << obj.Grade << "\n";
	}
	tmp.close();
	file.close();
	file.open("enroll.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!tmp.eof())
	{
		tmp.getline(obj.CID, 30, '|');
		tmp.getline(obj.SID, 30, '|');
		tmp.getline(obj.CName, 30, '|');
		tmp.getline(obj.SName, 30, '|');
		tmp.getline(obj.Grade, 30);
		file << obj.CID << '|' << obj.SID << '|' << obj.CName << '|' << obj.SName << '|' << obj.Grade << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
	if (f == 1)
		cout << "The Student Grade Updated Successfully\n";
	else cout << "The Students' Grades Updated Successfully\n";
}
//=========================================================================
void Enroll_Student()
{
	cin.ignore();
	fstream file;
	Enroll obj;
	cout << "Please Enter The Course ID : ";
	cin >> obj.CID;
	cout << "Please Enter The Student ID : ";
	cin >> obj.SID;
	bool exist = 0;
	Course object;
	file.open("course.txt", ios::in);
	while (!file.eof())
	{
		file.getline(object.ID, 30, '|');
		file.getline(object.Name, 30, '|');
		file.getline(object.Instructor, 30, '|');
		file.getline(object.Place, 30);
		if (strcmp(obj.CID, object.ID) == 0)
		{
			exist = 1; break;
		}
	}
	file.close();
	if (!exist)
		cout << "ERROR There Is No Course With That ID !\n";
	else
	{
		exist = 0;
		Student objec;
		file.open("student.txt", ios::in);
		while (!file.eof())
		{
			file.getline(objec.ID, 30, '|');
			file.getline(objec.Name, 30, '|');
			file.getline(objec.Year, 30);
			if (strcmp(obj.SID, objec.ID) == 0)
			{
				exist = 1; break;
			}
		}
		file.close();
		if (!exist)
			cout << "ERROR There Is No Student With That ID !\n";
		else
		{
			file.open("enroll.txt", ios::app);
			file << obj.CID << '|' << obj.SID << '|' << object.Name << '|' << objec.Name << '|' << '-' << "\n";
			file.close();
			cout << "\nThe Student Enrolled In The Course Successfully\n";
		}
	}
}
//=========================================================================
void Unenroll_student()
{
	cin.ignore();
	fstream file, tmp;
	Enroll obj;
	char InCID[30], InSID[30];
	cout << "Please Enter The Course ID : ";
	cin >> InCID;
	cout << "Please Enter The Student ID : ";
	cin >> InSID;
	bool exist = 0;
	file.open("enroll.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{
		file.getline(obj.CID, 30, '|');
		file.getline(obj.SID, 30, '|');
		file.getline(obj.CName, 30, '|');
		file.getline(obj.SName, 30);
		if (strcmp(obj.CID, InCID) == 0 && strcmp(obj.SID, InSID) == 0)
		{
			exist = 1;
		}
		else
		{
			tmp << obj.CID << '|' << obj.SID << '|' << obj.CName << '|' << obj.SName << "\n";
		}
	}
	tmp.close();
	file.close();
	file.open("enroll.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!file.eof())
	{
		tmp.getline(obj.CID, 30, '|');
		tmp.getline(obj.SID, 30, '|');
		tmp.getline(obj.CName, 30, '|');
		tmp.getline(obj.SName, 30);
		file << obj.CID << '|' << obj.SID << '|' << obj.CName << '|' << obj.SName << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
	if (!exist)
		cout << "ERROR !";
	else
		cout << "the Student Is Unenrolled Successfully\n";
}
//=========================================================================
void Delete_Course()
{
	cin.ignore();
	char InID[30];
	cout << "Please Enter The ID Or The Name Of The Course To Be deleted : ";
	cin.getline(InID, 30);
	Course obj;
	fstream file, tmp;
	file.open("course.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{
		file.getline(obj.ID, 30, '|');
		file.getline(obj.Name, 30, '|');
		file.getline(obj.Instructor, 30, '|');
		file.getline(obj.Place, 30);
		if (strcmp(InID, obj.ID) == 0 || strcmp(InID, obj.Name) == 0)
			continue;
		else
			tmp << obj.ID << '|' << obj.Name << '|' << obj.Instructor << '|' << obj.Place << "\n";
	}
	tmp.close();
	file.close();
	file.open("course.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!tmp.eof())
	{
		tmp.getline(obj.ID, 30, '|');
		tmp.getline(obj.Name, 30, '|');
		tmp.getline(obj.Instructor, 30, '|');
		tmp.getline(obj.Place, 30);
		file << obj.ID << '|' << obj.Name << '|' << obj.Instructor << '|' << obj.Place << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
	complete_deletion(InID, 1);
	cout << "The Course Is Deleted Successfully\n";
}
//=========================================================================
void Delete_Student()
{
	cin.ignore();
	char InID[30];
	cout << "Please Enter The ID Or The Name Of The Student To Be Deleted : ";
	cin.getline(InID, 30);
	Student obj;
	fstream file, tmp;
	file.open("student.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{

		file.getline(obj.ID, 30, '|');
		file.getline(obj.Name, 30, '|');
		file.getline(obj.Year, 30);
		if (strcmp(InID, obj.ID) == 0 || strcmp(InID, obj.ID) == 0)
			continue;
		else
			tmp << obj.ID << '|' << obj.Name << '|' << obj.Year << "\n";
	}
	tmp.close();
	file.close();
	file.open("student.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!tmp.eof())
	{
		tmp.getline(obj.ID, 30, '|');
		tmp.getline(obj.Name, 30, '|');
		tmp.getline(obj.Year, 30);
		file << obj.ID << '|' << obj.Name << '|' << obj.Year << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
	complete_deletion(InID, 0);
	cout << "The Student Is Deleted Successfully\n";
}
//=========================================================================
void complete_deletion(char InID[30], bool f)
{
	Enroll obj;
	fstream file, tmp;
	file.open("enroll.txt", ios::in);
	tmp.open("tmp.txt", ios::out);
	while (!file.eof())
	{
		file.getline(obj.CID, 30, '|');
		file.getline(obj.SID, 30, '|');
		file.getline(obj.CName, 30, '|');
		file.getline(obj.SName, 30, '|');
		file.getline(obj.Grade, 30);
		if (f == 1)
		{
			if (strcmp(InID, obj.CID) == 0 || strcmp(InID, obj.CName) == 0)
				continue;
			else
				tmp << obj.CID << '|' << obj.SID << '|' << obj.CName << '|' << obj.SName << '|' << obj.Grade << "\n";
		}
		if (f == 0)
		{
			if (strcmp(InID, obj.SID) == 0 || strcmp(InID, obj.SName) == 0)
				continue;
			else
				tmp << obj.CID << '|' << obj.SID << '|' << obj.CName << '|' << obj.SName << '|' << obj.Grade << "\n";
		}
	}
	tmp.close();
	file.close();
	file.open("enroll.txt", ios::out);
	tmp.open("tmp.txt", ios::in);
	while (!tmp.eof())
	{
		tmp.getline(obj.CID, 30, '|');
		tmp.getline(obj.SID, 30, '|');
		tmp.getline(obj.CName, 30, '|');
		tmp.getline(obj.SName, 30, '|');
		tmp.getline(obj.Grade, 30);
		file << obj.CID << '|' << obj.SID << '|' << obj.CName << '|' << obj.SName << '|' << obj.Grade << "\n";
	}
	tmp.close();
	file.close();
	remove("tmp.txt");
}
//=========================================================================