#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Student
{

	string name, sex;
	int age;
	float math, physic, chemistry, average;
	float averagePoint()
	{
		this->average = (math + physic + chemistry) / 3;
		return average;
	}
};


Student input(Student student)
{
	cout<<"name: ";
	fflush(stdin);
	getline(cin,student.name);
	
	cout<<"sex: ";
	cin>>student.sex;
	cout<<"age: ";
	cin>>student.age;
	cout<<"math: ";
	cin>>student.math;
	cout<<"physic: ";
	cin>>student.physic;
	cout<<"chemistry: ";
	cin>>student.chemistry;
	return student;
}

void output(vector<Student> listStudent)
{
	for (int i = 0; i < listStudent.size(); ++i)
	{
		cout<<"information of student "<<i + 1<<" :"<<endl;
		cout<<"name: "<<listStudent[i].name<<endl;
		cout<<"sex: "<<listStudent[i].sex<<endl;
		cout<<"age: "<<listStudent[i].age<<endl;
		cout<<"math: "<<listStudent[i].math<<endl;
		cout<<"physic: "<<listStudent[i].physic<<endl;
		cout<<"chemistry: "<<listStudent[i].chemistry<<endl<<endl;
	}

}

void orderAveragePoint(vector<Student> listStudent)
{
	int i, j, min;
	Student temp;
	for(i = 0; i < listStudent.size() - 1; ++ i)
	{
		min = listStudent[i].averagePoint();
		for (j = i + 1; j < listStudent.size(); ++j)
		{
			if (min > listStudent[j].averagePoint())
			{
				min = listStudent[j].averagePoint();
				temp = listStudent[i];
				listStudent[i] = listStudent[j];
				listStudent[j] = temp;
			}
		}
	}
	output(listStudent);
}

void writeFile(vector<Student> listStudent)
{
	ofstream fout;
	fout.open("List_student.txt");
	for (int i = 0; i < listStudent.size(); i++)
	{
		fout<<"information of student "<<i + 1<<" :"<<endl;
		fout<<"name: "<< listStudent[i].name << endl;
		fout<<"sex: "<<listStudent[i].sex<<endl;
		fout<<"age: "<<listStudent[i].age<<endl;
		fout<<"math: "<<listStudent[i].math<<endl;
		fout<<"physic: "<<listStudent[i].physic<<endl;
		fout<<"chemistry: "<<listStudent[i].chemistry<<endl<<endl;
	}
	

	fout.close();
}

void orderName(vector<Student> listStudent)
{
	int i, j; 
	string min;
	Student temp;

	for(i = 0; i < listStudent.size() - 1; ++ i)
	{
		min = listStudent[i].name;
		for (j = i + 1; j < listStudent.size(); ++j)
		{
			int res = listStudent[j].name.compare(min);
			if (res < 0)
			{
				min = listStudent[j].name;
				temp = listStudent[i];
				listStudent[i] = listStudent[j];
				listStudent[j] = temp;
			}
		}
	}
	output(listStudent);
}

void readFile()
{	
	ifstream fin;
	string line;
	fin.open("List_student.txt");
	while (fin) {
 
        getline(fin, line);
        cout << line << endl;
    }

    fin.close();
}

void menu()
{
	int mainChoice, inChoice;
	vector<Student> arrayStudent;

	while(1)
	{
		system("CLS");
		cout<<"----------------------List Student--------------------------"<<endl;
		cout<<"----------1. enter information of student        -----------"<<endl;
		cout<<"----------2. export list of student              -----------"<<endl;
		cout<<"----------3. export average point of 3 subjects  -----------"<<endl;
		cout<<"----------4. export order list of student (point)-----------"<<endl;
		cout<<"----------5. export order list of student (name) -----------"<<endl;
		cout<<"----------6. save to file                        -----------"<<endl;
		cout<<"----------7. read from file                        -----------"<<endl;
		cout<<"----------8. exit			         -----------"<<endl;
		cout<<"enter your choice: ";
		cin>>mainChoice;
		switch (mainChoice)
		{
			case 1:
			{
				system("CLS");
				cout<<"1. enter infor: "<<endl;
				cout<<"2. Back" <<endl;
				cin>>inChoice;
				if (inChoice == 1)
				{
					system("CLS");
					Student student;
					student = input(student);
					arrayStudent.push_back(student);
				}
				else if (inChoice == 0)
				{
					break;
				}	
				break;
			}
			case 2:
			{
				system("CLS");
				output(arrayStudent);
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
			case 3:
			{
				for(int i = 0; i < arrayStudent.size(); ++i)
				{
					cout<<"student name: "<<arrayStudent[i].name<<endl;
					cout<<"average point: "<<arrayStudent[i].averagePoint()<<endl<<endl;
				}
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
			case 4:
			{
				orderAveragePoint(arrayStudent);
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
			case 5:
			{
				orderName(arrayStudent);
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
			case 6:
			{
				writeFile(arrayStudent);
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
			case 7:
			{
				readFile();
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
				

		}
		if(mainChoice == 8)
		{
			break;
		}	
	}
	
}

int main()
{
	menu();
	return 0;
}
