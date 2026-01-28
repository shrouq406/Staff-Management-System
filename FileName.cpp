#include <iostream>
#include <vector>
#include <string>
#include <fstream> //للملفات
using namespace std;



struct Department
{
	int De_number;
	string De_name;
};

struct Staff
{
	int depNo;
	string s_department;
	string s_name;
	int s_age;
	string s_sex;
	double s_phone;
	string s_education;
	float s_salary;
	string s_address;
	int s_number;
	
};

//Global storage                     //يقدر اي حد يعدل فيها

vector<Department>departments;
vector<Staff>staffList;


//واجهه بسيطه سهلة الاستخدام(a)

void menu()
{
	cout << "*****staff information Management*****" << endl;
	cout << "1: Enter  Department" << endl;
	cout << "2: Display Departments" << endl;
	cout << "3:Delete Departments" << endl;
	cout << "4:Modify Department" << endl; 
	cout << "5: Display staff" << endl;
	cout << "6: Delete staff" << endl;
	cout << "7: Modify staff" << endl;
	cout << "8: Add staff" << endl;
	cout << "9:Save information staff" << endl;
	cout << "10: search in staff" << endl;
	cout << "enter 0 to out" << endl;
}
//==============================================================================================

//انشاء 3 اقسام مبدئيه(b)

void CreateInitializeDepart()
{
	departments.push_back({ 1,"manager" });                
	departments.push_back({ 2, "HR" });
	departments.push_back({ 3, "IT" });
}

//=====================================================================================================

//ادخل معلومات القسم

void EnterDepart()
{
	cout << "(***) Add Depart function:" << endl;
	Department d;
	cout << "enter the Depart number:" ;
	cin >> d.De_number;
	cout << "enter the  Depart  name:" ;
	cin.ignore();
	getline(cin, d.De_name);
	departments.push_back(d);

}
//==========================================================================================================

//عرض معلومات القسم(c)

void DisplayDepart()
{
	cout << "(***) Display Depart function : " << endl;
	for (auto d : departments)
	{
		cout << "depart number:" << d.De_number << endl << "depart name:" << d.De_name << endl;
	}
}

//====================================================================================================

//حذف معلومات القسم(d)

void DeleteDepart()
{
	cout << "(***) Deleting Depart Function:" << endl;
	int Num;
	cout << "enter the depart number to delete:" ;
	cin >> Num;
	for (int i =0; departments.size(); i++)
	{
		if (departments[i].De_number==Num)
		{
			departments.erase(departments.begin() + i);       //remove using index
			cout << "the number of department  is deleted" << endl;
			return;
		}
	}
	cout << "the number is not found to delete" << endl;
	cout << "number of Depart:" << Num << endl;
	
	string name ;
	cout << "enter the depart name to delete:";
	cin >> name;
	for (int i = 0; departments.size(); i++)
	{
		if (departments[i].De_name == name)
		{
			departments.erase(departments.begin() + i);       //remove using index
			cout << "the name of department  is deleted" << endl;
			return;
		}
	}
	cout << "the name is not found to delete" << endl;
	cout << "name of Depart:" << name << endl;


}


//============================================================================================================

//تعديل معلومات القسم(e)


void ModifyDepart()
{
	cout << "(***) Modify Depart function:" << endl;
	string Name;
	cout << "enter the name to modify:" ;
	cin >> Name;
	for(auto& d:departments)
	{
		if (d.De_name == Name)
		{
			cout << "enter new name :" ;
			cin.ignore();                        //متهتمش للمسافات
			getline(cin, d.De_name);
			return;
		}
	}
	cout << "the name not found to modify" << endl;
}

//=================================================================================================================

//اضافة قسم جديد(m)
//
//void AddDepart()
//{
//	EnterDepart();
//}

//===================================================================================================================

//ادخال معلومات الموظفين(f)

void AddStaff()
{
	cout << "(***) Add staff function:" << endl;

	Staff s;

		cout << "enter name:" ;
		cin.ignore();
		getline(cin , s.s_name);
		cout << "enter id:" ;
		cin >>s.s_number;
		cout << "enter sex:";
		//getline(cin ,s.s_sex);
		cin >> s.s_sex;
		cout << "enter salary:" ;
		cin >> s.s_salary;
		cout << "enter department:" ;
		cin >> s.s_department;
		cout << "enter age:";
		cin >> s.s_age;
		cout << "enter phone:" ;
		cin >>s.s_phone;
		cout << "enter address:" ;
		cin >> s.s_address;                
		cout << "enter education:";  
		cin.ignore();
		getline(cin , s.s_education);
	

		staffList.push_back(s);
}

//==============================================================================================================

//عرض معلومات الموظفين(g)

void DisplayStaff()
{
	cout << "(****) Display staff function:" << endl;
	for (auto s : staffList)
	{
		cout << "staff Number:" << s.s_number << endl << "staff name:" << s.s_name << endl << "staff sex:" << s.s_sex << endl;
		cout << "staff age:" << s.s_age << endl << "staff education:" << s.s_education << endl << "staff salary:" << s.s_salary << endl;
		cout << "staff phone:" << s.s_phone << endl << "staff address:" << s.s_address << endl;
	}
}

//===================================================================================================================================

//حذف معلومات الموظفين(h)

void DeleteStaff()
{
	cout << "(***) Deleting Staff Function:" << endl;
	string N;
	cout << "enter the staff name to delete:";
	cin >> N;
	for(int i=0;staffList.size(); i++)
	{
		if(staffList[i].s_name==N)
		{
		  staffList.erase(staffList.begin()+i);       //remove using index
			cout << "the name is deleted" << endl;
			return;
		}
	}
	cout << "the name is not found to delete" << endl;

}

//======================================================================================================================

//تعديل معلومات الموظف (k)

void ModifyStaff()
{
	cout << "(***) Modify staff function:" << endl;
	string  No;
	cout << "enter the name of staff to modify:";
	cin >> No;
	for (auto& s : staffList)
	{
		if (s.s_name ==No)
		{
			cout << "enter new name:";
			cin.ignore();
			getline(cin, s.s_name);
		
			return;
		}
	}
	cout << "the number of staff not found to modify";

}
///===================================================================================================================
//اضافة موظف(L)

//void EnterStaff()
//{
//	AddStaff();
//}

//=================================================================================================================

//حفظ الملفات لمختلف الاقسام(j)

void SaveStaffByDepartment()
{
	
	for (const auto& dep : departments)      //& علشان مياخدش مساحه ومش عايزه اللي جوه الفانكشن ميتعدلش عليها  
	{
		
		string fileName = "department_" + to_string(dep.De_number) + ".txt";         //اسم الملف حسب رقم القسم
		
		ofstream file(fileName);         //لفتح ملف للكتابه    
		
		if (file.is_open())              //التاكد من فتح ملف قبل الكتابه
		{
			file << "Department Number:" << dep.De_number << endl;
			file << "Department Name:" << dep.De_name << endl;                  //نكتب معلومات القسم في بداية الملف كعنوان

			file << "==========================================" << endl;
			bool found = false;                                                //متغير تستخدمه لمعرفة اذا كان هناك موظفون ينتمون لهذا القسم
			for (const auto& s : staffList)
			{
				if (s.depNo== dep.De_number)
				{
					found = true;
					file << "staff Number:" << s.s_number << endl;
					file << "staff Name:" << s.s_name << endl;
					file << "staff Age:" << s.s_age << endl;
					file << "staff Salary:" << s.s_salary << endl;
					file << "staff Department:" << s.s_department << endl;
					file << "staff Education:" << s.s_education << endl;
					file << "staff Phone:" << s.s_phone << endl;
					file << "staff Sex:" << s.s_sex << endl;
				}

			}
			if (!found)
				file << "staff department not found" << endl;
			file.close();                    //غلق الملف بعد الكتابه
		}
		else
			cout << "Error Writing File for  Department" << dep.De_number << endl;
	}
	cout << "staff information saved by department" << endl;

}

//=================================================================================================================================================

//عرض معلومات الموظف عن طريق اختيار رقم الموظف او اسم الموظف او القسم 

void Search_staff()
{
	int search;
	
	cout << "1.Staff Number" << endl;
	cout << "=================================================================" << endl;
	cout << "2.Staff Name" << endl;
	cout << "==================================================================" << endl;
	cout << "3.Department Number" << endl;
	cout << "====================================================================" << endl;
	cout << "enter number (1,2,3):     ";
	cin >> search;

	bool found = false;
	if (search == 1)
	{
		int Number;
		cout << "Enter staff number:";
		cin >> Number;
		for (const auto& s : staffList)
		{
			if (s.s_number == Number)
			{
				found = true;
				cout << "Staff Number:" << s.s_number << endl;
				cout << "staff Name:" << s.s_name << endl;
				cout << "staff Sex:" << s.s_sex << endl;
				cout << "staff Age:" << s.s_age << endl;
				cout << "staff Education:" << s.s_education << endl;
				cout << "staff Salary:" << s.s_salary << endl;
				cout << "staff Address:" << s.s_address << endl;
				cout << "staff Phone:" << s.s_phone << endl;
				cout << "staff departNo:" << s.depNo << endl;
			}
		}
	}
	else if (search == 2)
	{
		string name;
		cout << "enter the name of staff:";
		cin.ignore();
		getline(cin, name);
		for (const auto& s : staffList)
		{
			if (s.s_name == name)
			{
				found = true;
				cout << "Staff Number:" << s.s_number << endl;
				cout << "staff Name:" << s.s_name << endl;
				cout << "staff Sex:" << s.s_sex << endl;
				cout << "staff Age:" << s.s_age << endl;
				cout << "staff Education:" << s.s_education << endl;
				cout << "staff Salary:" << s.s_salary << endl;
				cout << "staff Address:" << s.s_address << endl;
				cout << "staff Phone:" << s.s_phone << endl;
				cout << "staff departNo:" << s.depNo << endl;


			}
		}
	}
	else if (search == 3)
	{
		int deNo;
		cout << "enter the depart number:";
		cin >> deNo;
		for (const auto& s : staffList)
		{
			if (s.depNo == deNo)
			{
				found = true;
				cout << "Staff Number:" << s.s_number << endl;
				cout << "staff Name:" << s.s_name << endl;
				cout << "staff Sex:" << s.s_sex << endl;
				cout << "staff Age:" << s.s_age << endl;
				cout << "staff Education:" << s.s_education << endl;
				cout << "staff Salary:" << s.s_salary << endl;
				cout << "staff Address:" << s.s_address << endl;
				cout << "staff Phone:" << s.s_phone << endl;
				cout << "staff departNo:" << s.depNo << endl;
			}
		}
	}
	else
	{
		cout << "invalid search" << endl;
		return;
	}
	if (!found)
		cout << "No staff found" << endl;

}



int main()
{
	CreateInitializeDepart();
	int ch;
	 menu();
	
	do
	{
		cout << "================================================================================" << endl;
		cout << "ch=";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "================================================================================" << endl;
			EnterDepart();
			break;
		case 2:
			cout << "=================================================================================" << endl;
			DisplayDepart();
			break;
		case 3:
			cout << "==================================================================================" << endl;
			DeleteDepart();
			break;
		case 4:
			cout << "===================================================================================" << endl;
			ModifyDepart();
			break;
		/*case 5:
			cout << "===================================================================================" << endl;
			AddDepart();*/
		/*case 6:
			cout << "===================================================================================" << endl;
			EnterStaff();
			break;*/
		case 5:
			cout << "===================================================================================" << endl;
			DisplayStaff();
			break;
		case 6:
			cout << "===================================================================================" << endl;
			DeleteStaff();
			break;
		case 7:
			cout << "====================================================================================" << endl;
			ModifyStaff();
			break;
	
		case 8:
			cout << "=====================================================================================" << endl;
			AddStaff();
			break;
		case 9:
			cout << "======================================================================================" << endl;
			SaveStaffByDepartment();
			break;

		case 10:
			Search_staff();
			break;
		case 0:
			cout << "=======================================================================================" << endl;
			cout << "out" << endl;
			break;
		default:
			cout << "invalid" << endl;
		}
	} while (ch != 0);
	

	return 0;
}