#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;

class Employee
{
	int ID,dd,mm,yy;
	char name[20],address[50],designation[20],phone[11];
	char grade,HRA,conveyance;
	float basic;
	
	public:
		void newEmployee(int);
		void modify();
		void deletion();
		void display();
		void list();
		void salarySlip();
};
void Employee::newEmployee(int code)
{
//	system("cls");
	
//	cout<<"\nEnter Employee ID :  ";
//	cin>>ID;
	ID=code;
	while(1)
	{
		string name ;
		cout<<"\nEnter Employee name :  ";
		cin.ignore();
		getline(cin,name);
		
		if(name.length()>20)
		{
			cout<<"\nEnter length b/w range 1-20";
		}
		else
		{
			strcpy(this->name,name.c_str());
			break;
		}
	}
	
	while(1)
	{
		string address;
		cout<<"\nEnter Employee address: ";
	//	cin.ignore();
		getline(cin,address);
		
		if(address.length()>50)
		{
			cout<<"\nEnter length b/w range 1-50";
		}
		else
		{
			strcpy(this->address,address.c_str());
			break;
		}
	}
	
	
	
	while(1)
	{
		string designation;
		cout<<"\nEnter Designation:  ";
	//	cin.ignore();
		getline(cin,designation);
	
		if(designation.length()>50)
		{
			cout<<"\nEnter length b/w range 1-50";
		}
		else
		{
			strcpy(this->designation,designation.c_str());
			break;
		}
	}
	
	//cin.ignore();
		top1:
		
		cout<<"\nEnter mobile no. :  ";
		string mob;
		getline(cin,mob);
		if(mob.length()!=10)
		{
			cout<<"\nInvalid mobile no.\nTry again";
			goto top1;
		}
		else
		{
		
			strcpy(phone,mob.c_str());
		//	emp.phone[10]='\0';
		}
	
	
	top:
		
	cout<<"\nEnter joining date dd-mm-yy:  ";
	int d,m,y,valid=1;
	scanf("%d-%d-%d",&d,&m,&y);
	
		if (d>31 || d<1)
            valid = 0 ;
         if (y%100!=0)
		{
			if(((y%4)!=0 && m==2 && d>28) || ((y%4)==0 && m==2 && d>29))
            valid = 0 ;
		}
		if(y%100==0)
		{
			if(((y%400)!=0 && m==2 && d>28) || ((y%400)==0 && m==2 && d>29))
            valid = 0 ;
		}
         if ((m==4 || m==6 || m==9 || m==11) && d>30)
            valid = 0 ;
        if (y<1990 || y>2020)
            valid = 0 ;
        if(m>12 || m<1)
        	valid=0;
        
        if(valid)
        {
        	dd=d;
        	mm=m;
        	yy=y;
		}
		else
		{
			cout<<"\nEnter valid date";
			goto top;
		}
		
		
		
		cout<<"\nEnter Grade:  ";
		cin>>grade;
		cout<<"\nEnter Basic salary: ";
		cin>>basic;
		
		char ch;
		while(1)
		{
		cout<<"\nHRA(y/n) :  ";
		cin>>ch;
		ch=toupper(ch);
		if(ch=='Y' || ch=='N')
		{
			HRA=ch;
			break;
		}
		else
		{
			cout<<"\nTry again\n";
		}
		}
	
		
		while(1)
		{
		cout<<"\nConveyance(y/n) :  ";
		cin>>ch;
		ch=toupper(ch);
		if(ch=='Y' || ch=='N')
		{
			conveyance=ch;
			break;
		}
		else
		{
			cout<<"\nTry again\n";
		}
		}
	
}

void Employee :: display()
{
	system("cls");
	//Employee emp;
	int code,flag=0;
	cout<<"\nEnter Employee ID : ";
	cin>>code;
	
	fstream fin;
	fin.open("Payroll.dat",ios::in);
//	fin.seekg(0,ios::beg) ;

		while(fin.read((char*) this, sizeof(Employee)))
		{
			if(ID==code)
				{
					flag=1;
					cout<<"\n--------Employee detail-------"<<endl;
					cout<<"\nName : "<<name<<endl;
					cout<<"\nAddress : "<<address<<endl;
					cout<<"\nMobile No."<<phone<<endl;
					cout<<"\n\nJoining date: "<<endl;
					cout<<"DD/MM/YYYY : "<<dd<<"/"<<mm<<"/"<<yy<<endl;
					cout<<"\nDesignation : "<<designation<<endl;
					cout<<"\nGrade : "<<grade<<endl;
					cout<<"\nHRA (y/n) : "<<HRA<<endl;
					cout<<"Conveyance(y/n) : "<<conveyance<<endl;
					cout<<"Basic Salary : "<<basic<<endl;
					break;
				}
		}
	if(flag==0)
	{
		system("cls");
		cout<<"Record Not found..............."<<endl;
	}
	fin.close();
}

void Employee::deletion()
{
	system("cls");
	Employee emp;
	cout<<"Enter EMPLOYEE ID WHICH YOU WANT TO DELETE:  ";
	int code,flag=0;
	cin>>code;
	
	fstream fin;
	fin.open("Payroll.dat",ios::in);
	
	fstream temp;
	temp.open("temp.dat",ios::out);
	while(fin.read((char*) &emp, sizeof(Employee)))
		{
			if(emp.ID!=code)
				{
					
					temp.write((char *) &emp,sizeof(Employee));
				}
				else
				{
					flag=1;
				}
		}
		
	fin.close();
	temp.close();
	
	if(flag==0)
	{
		system("cls");
		cout<<"Record Not found..............."<<endl;
	}
	
	else
	{
		
		int i=remove("Payroll.dat");
		rename("temp.dat","Payroll.dat");
	}
	
}

void Employee :: list()
	{
		system("cls");
		cout<<setw(7)<<"Emp_ID"<<setw(20)<<"NAME"<<setw(20)<<"PHONE";
		cout<<setw(20)<<"DESIGNATION"<<setw(20)<<"GRADE"<<setw(20)<<"SALARY"<<endl<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		
		fstream file;
		file.open("Payroll.dat",ios::in);
		
		while(file.read((char*) this,sizeof(Employee)))
			{
				cout<<setw(7)<<ID<<setw(20)<<name<<setw(20)<<phone;
				cout<<setw(20)<<designation<<setw(20)<<grade<<setw(20)<<basic<<endl;
			}
		
		cout<<endl;
			
		file.close();
	}

void Employee::modify()
{
	system("cls");
	Employee emp;
	cout<<"Enter EMPLOYEE ID WHICH YOU WANT TO MODIFY:  ";
	int code,flag=0;
	cin>>code;
	
	fstream fin;
	fin.open("Payroll.dat",ios::in);
	
	fstream temp;
	temp.open("temp.dat",ios::out);
	while(fin.read((char*) &emp, sizeof(Employee)))
		{
			if(emp.ID!=code)
				{
					temp.write((char *) &emp,sizeof(Employee));
				}
				else
				{
					flag=1;
					cout<<"QWWQQ";
					Employee etemp;
					etemp.newEmployee(code);
					temp.write((char *) &etemp,sizeof(Employee));
				}
		}
		
	fin.close();
	temp.close();
	
	if(flag==0)
	{
		system("cls");
		cout<<"Record Not found..............."<<endl;
	}
	
	else
	{
		
		int i=remove("Payroll.dat");
		rename("temp.dat","Payroll.dat");
	}
	
}

void Employee :: salarySlip()
	{
		system("cls");
		int ecode;
		char ch='N';
		float hra=0.0,cony=0.0,TDS=0.0,pf=0.0;
		float all_total,ded_total;
		cout<<"\nEnter Employee ID : ";
		cin>>ecode;
		system("cls");
		
		cout<<endl<<endl;
		cout<<setw(60)<<"SALARY SLIP"<<endl;
		cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
		
		fstream file;
		file.open("Payroll.dat",ios::in);
		
		while(file.read((char*) this,sizeof(Employee)))
			{
				if(ID == ecode)
					{
						cout<<std::fixed;
						cout<<setw(15)<<"Name : "<<name<<setw(70)<<"Grade : "<<grade<<endl;
						cout<<setw(15)<<"Designation : "<<designation<<endl;
						cout<<setw(15)<<"Mobile No. : " <<phone<<endl;
						cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
						
						cout<<setw(30)<<"Basic Salary : "<<setprecision(4) <<basic<<endl;
						cout<<endl<<setw(30)<<"ALLOWANCE "<< endl << endl;
						
						 if(HRA == 'Y')
						 	{
						 		cout << setw(27) << "HRA : ";
						 		hra = ((float)40/100)*basic;
								cout << setprecision(4) << hra << endl;	
							}
						else
							cout<<setw(27)<< "HRA : " << basic*0 <<endl;
							
						if(conveyance == 'Y')
							{
								cout<< setw(27) << "Conveyance : ";
								cony = ((float)5/100)*basic;
								cout << setprecision(4) << cony;
							}
						else
						  cout << setw(27) << "Conveyance : " << basic*0;  
						  
						all_total=hra+cony;
						cout << setw(50) << " Total : " <<all_total<<endl<<endl;
 					    
						cout<< setw(30) << "DEDUCTION " << endl<<endl;
						
						if(basic<=20000)
								TDS=0;
						else
							TDS=((float)5/100)*(basic+all_total);
						
						cout << setw(27) << "TDS : " << TDS <<endl;
						
						pf=((float)2/100)*basic;
						cout << setw(27) << "PF : " <<pf;
						
						ded_total=TDS+pf;
						cout << setw(51) << " Total : " <<ded_total<<endl<<endl;
						cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
						cout<<endl<<std::fixed<<setw(85)<<"Net salary : "<<setprecision(4)<<(basic+all_total-ded_total)<<endl;
 					    
					}
			}
			cout<<endl<<endl;
		file.close();
		
	}
	

int main(void)
	{
		int ch;
		while(1)
			{
			//	system("cls");
				cout<<"****************PAYROLL MANAGEMENT SYSTEM******************"<<endl;
				cout<<"\n1.NEW EMPLOYEE\n2.MODIFY\n3.DELETEION\n4.LIST\n5.DISPLAY\n6.SALARY SLIP\n7.Exit"<<endl;
				cout<<"\nEnter the choice : ";
				cin>>ch;
				Employee emp;
				fstream file;
				switch(ch)
					{
						case 1:
								int ID;
								cout<<"\nEnter Employee ID :  ";
								cin>>ID;
								emp.newEmployee(ID);
								
								
								file.open("Payroll.dat",ios::app);
								file.write((char *) &emp,sizeof(Employee));
								file.close();
								break;
						
						case 2: emp.modify();
								break;
						
						case 3: emp.deletion();
								break;
								
						case 4: emp.list();
								break;
							
						case 5: emp.display();
								break;
								
						case 6: emp.salarySlip();
								break;
						
						case 7: exit(0);
						
						default: cout<<"\nYou have not choose any option";				
					}	
			}
	}
