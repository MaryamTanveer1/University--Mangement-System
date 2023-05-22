#include <iostream>
#include <string>
using namespace std;
class user {
protected:
	string name;
	string password;
	string role;
public:
	virtual void login() = 0;

};
class student : public user
{
private:
	string enrollment;
public:
	student()
	{
		enrollment = "";
		name = "";
		password = "";
		role = "";
	}
	void login()
	{

		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << "                                      Enter the role                                      " << endl;
		cout << "------------------------------------------------------------------------------------------" << endl;
		cin >> role;
		if (role == "student" || role == "Student" || role == "STUDENT")
		{
			cout << "enter name: ";
			cin >> name;
			cout << "enter enrollment: ";
			cin >> enrollment;
			cout << "enter password: ";
			cin >> password;
			{
				if (name == "Maryam" && enrollment == "01-135211-045" && password == "m45")
				{

					cout << endl;
					cout << "--------------------Authorization Granted!----------------" << endl;

				}
				else if (name == "Fatima" && enrollment == "01-135211-029" && password == "f29")
				{
					cout << endl;
					cout << "--------------------Authorization Granted!----------------" << endl;

				}
				else if (name == "Shairyar" && enrollment == "01-135211-074" && password == "s74")
				{
					cout << endl;
					cout << "--------------------Authorization Granted!----------------" << endl;

				}
				else
				{
					cout << "Sorry, either username or password is wrong!....." << endl;
					exit(0);
				}
			}
		}
		else
		{
			cout << "                    ---------- E R R O R -----------             " << endl << endl;
			exit(0);
		}
	}
	void showstudentprofile()
	{
		cout << "name: " << name << endl;
		cout << "enrollment" << enrollment << endl;
	}
	bool matchstudent()
	{

		if (name == "Maryam")
			return true;
		else if (name == "Fatima")
			return true;
		else if (name == "Shairyar")
			return true;
		else
		{
			return false;
		}

	}
	void inputstudents()
	{

		cout << "       Enter name of Student:";
		cin >> name;
		cout << endl;
	}
	void displaystudents()
	{

		cout << name << "  ";
	}
};
class Project {
	string title;
	string deadline;

public:

	Project()
	{
		title = "";
		deadline = "";

	}
	void createProfile() {
		cout << endl << "Enter the project title:";
		cin >> title;
		cout << "Enter the deadline for project:";
		cin >> deadline;
		cout << endl;

	}
	void showprojectProfile() {
		cout << endl << "Project title: " << title << endl;
		cout << "Deadline:" << deadline << endl;
		cout << endl;
	}
};

class admin : public user {
private:
	Project* proj;
	int id;
public:
	class exception {};
	admin()
	{
		name = "";
		password = "";
		role = "";
		id = 0;
	}
	void login()
	{
		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << "                                      Enter the role                                      " << endl;
		cout << "------------------------------------------------------------------------------------------" << endl;
		cin >> role;
		if (role == "admin" || role == "Admin" || role == "ADMIN")
		{
			cout << endl;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter id: ";
			cin >> id;
			cout << "Enter password: ";
			cin >> password;

			if (name != "Maria" || id != 12 || password != "m123")
			{
				throw exception();
			}
			else
			{
				cout << endl;
				cout << "--------------------Authorization Granted!----------------" << endl;
			}
		}

		else
		{
			cout << endl;
			cout << "                 ---------- E R R O R -----------                " << endl;
		}

	}
	void Assignproject(Project* pr)
	{
		cout << "Enter the details of the project:" << endl;
		pr->createProfile();
	}
	void showProject()
	{
		proj->showprojectProfile();
	}
	void showadminprofile()
	{
		cout << "Name of admin: " << name << endl;
		cout << "ID: " << id << endl;
		cout << endl;
	}

};
template<class type>
class Result
{
private:
	type quizes;
	type assignments;
public:
	Result()
	{
		quizes = 0;
		assignments = 0;
	}
	void inputmarks()
	{
		cout << "qiuzes:";
		cin >> quizes;
		cout << "assignments:";
		cin >> assignments;
	}
	Result operator+(Result r)
	{
		Result temp;
		temp.quizes = quizes + r.quizes;
		temp.assignments = assignments + r.assignments;
		return temp;
	}
	void displayresult()
	{
		cout << "total marks of assignments: " << assignments << " , " << "total marks of quizes: " << quizes;
	}
};

int main()
{
	Result <int> r;
	user* user1;
	user* user2;
	student s;
	admin a;
	Project p;
	char ch, ch1, ch2;
	user1 = &s;
	user2 = &a;
	cout << "================================= W E L C O M E ===============================" << endl;
	cout << endl;
label1:
	cout << endl;
	cout << "                       Press A for Admin         " << endl;
	cout << "                       Press S for student       " << endl;
	cout << "                       Press X for terminate the program       " << endl;
	cout << "                       Enter your preference: ";
	cin >> ch1;
	switch (ch1)
	{
	case 'A':
	{
		{
			try {
				user2->login();
			}
			catch (admin::exception)
			{
				exit(0);
			}
		}
		a.showadminprofile();
		cout << endl;
		cout << "              Enter A for project module " << endl;
		cout << "              Enter B for entering marks " << endl;
		cout << "              Enter X for Exit " << endl;
		cout << "              Enter your preference: ";
		cin >> ch;
		switch (ch)
		{
		case 'A':
		{
			a.Assignproject(&p);
			student arr[3];
			for (int i = 0; i < 3; i++)
			{
				arr[i].inputstudents();
				arr[i].matchstudent();
			}
			cout << "Project assigned to:";
			for (int i = 0; i < 3; i++)
			{
				arr[i].displaystudents();
				cout << endl;
			}
			cout << "--------------------------------------------------------------------" << endl;
			break;
		}
		case 'B':
		{
			student arr[3];
			for (int i = 0; i < 3; i++)
			{
				arr[i].inputstudents();
				arr[i].matchstudent();
				Result<int> r1;
				r1.inputmarks();
				Result<int> r2;
				r2.inputmarks();
				Result<int> r3 = r1 + r2;
				r3.displayresult();
				cout << endl;
			}
			cout << "--------------------------------------------------------------------" << endl;

		}
		case 'X':
		{
			break;
		}
		}
		break;
	}
	case 'S':
	{

		user1->login();
		s.showstudentprofile();
		cout << endl;
		cout << "               Enter A for project module" << endl;
		cout << "               Enter X for exit" << endl;
		cout << "               Enter your preference: ";
		cin >> ch2;
		cout << "				...............................           " << endl;
		switch (ch2)
		{

			{
		case 'A':
		{
			p.showprojectProfile();
			break;
		}
		case 'X':
		{
			break;
		}
			}
			break;

		}

		break;
	}
	case'X':
		exit(0);
	}
	goto label1;

	system("pause");


}