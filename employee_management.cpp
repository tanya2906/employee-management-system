//add 
//update
//delete
//search

//--employee details--
//employee id (primary key)
//name
//post(designation)
//department
//salary
//experience
// age

/*
#1 add record
#2 search employee using id
#3 see all employees in department
#4 update and delete 
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;
//--employee class--
class employee
{
private:
    /* --employee data-- */
    int employee_id;
    char employee_firstname[20],employee_lastname[20],designation[20],department[20];
    float salary;
    int experience;
    int year_of_birth;

public:
    
    void read_data();//this method is used to enter new employee data
    void display_data();//this method is used to diaplay employee data
    int employee_ID();// this method return employee id
    char* employee_department();//this method return employee department
    
};



void employee::read_data()
{
    cout<<endl;
    cout<<"----enter employee detail----"<<endl;
    cout<<"EMPLOYEE ID:";
    cin>>employee_id;
    cout<<"EMPLOYEE FIRST-NAME:";
    cin>>employee_firstname;
    cout<<"EMPLOYEE LAST-NAME:";
    cin>>employee_lastname;
    cout<<"DESIGNATION:";
    cin>>designation;
    cout<<"DEPARTMENT:";
    cin>>department;
    cout<<"SALARY:";
    cin>>salary;
    cout<<"EXPERIENCE:";
    cin>>experience;
    cout<<"YEAR OF BIRTH:";
    cin>>year_of_birth;
    cout<<endl;
}

void employee::display_data()
{
    cout<<endl; 
    cout<<setw(4)<<employee_id<<setw(20)<<employee_firstname<<setw(20)<<employee_lastname<<setw(20)<<designation<<setw(20)<<department<<setw(10)<<salary<<setw(10)<<experience<<setw(10)<<year_of_birth<<endl;
}

int employee::employee_ID()
{
    return employee_id;
}

char* employee::employee_department()
{
    return department;
}

//--employee class end--
int main()
{
    //--object creation--
    employee e,E;
    fstream file;//main file
    int valid;//valid id check
    int id;
    char depart[20];
    int count=0;
    int position;//during update used
    fstream temp;//temporary file
    file.open("employee_management_file.txt",ios::ate|ios::binary|ios::in|ios::out);
    cout<<"--------EMPLOYEE MANAGEMENT SYSTEM--------"<<endl;
    //---option selection---
    int option;
    do
    {
        cout<<"options"<<endl;
        cout<<"1 ADD NEW RECORD"<<endl;
        cout<<"2 SEARCH EMPLOYEE USING ID"<<endl;
        cout<<"3 EMPLOYEES OF PARTICULAR DEPARTMENT"<<endl;
        cout<<"4 ALL EMPLOYEE"<<endl;
        cout<<"5 UPDATE"<<endl;
        cout<<"6 DELETE"<<endl;
        cout<<"7 STOP"<<endl;
        cout<<"enter option:";
        cin>>option;
        switch(option){
            case 1:// enter new data
            e.read_data();
            file.seekg(0,ios::beg);
            valid=0;
            file.read((char*)&E,sizeof(E));
            while (!file.eof())
            {
                if(E.employee_ID()==e.employee_ID())
                {
                   // cout<<"----invalid data----"<<endl;
                    valid=1;
                    break;
                }
                file.read((char*)&E,sizeof(E));
            }
            if(valid==1){
                cout<<"----invalid data----"<<endl;
                break;
                }
            file.clear();
            file.seekp(0,ios::end);
            file.write((char*)&e,sizeof(e));
            break;
            
        case 2:

            /*2 SEARCH EMPLOYEE USING ID*/
            valid=0;
            cout<<"enter id:";
            cin>>id;
            file.seekg(0,ios::beg);
            file.read((char*)&E,sizeof(E));
            while (!file.eof())
            {
                if(E.employee_ID()==id)
                {
                    valid=1;
                    cout<<"----EMPLOYEES DETAIL----"<<endl;
                    cout<<setw(5)<<"EMP-ID"<<setw(20)<<"FIRST NAME"<<setw(20)<<"LAST NAME"<<setw(20)<<"DESIGNATION"<<setw(20)<<"DEPARTMENT"<<setw(10)<<"SALARY"<<setw(15)<<"EXPERIENCE"<<setw(15)<<"BIRTH YEAR"<<endl;
                    E.display_data();
                    break;
                }
                file.read((char*)&E,sizeof(E));
            }
            file.clear();
            if(valid==0)
            cout<<"----NOT FOUND----"<<endl;
            break;
        case 3:
        
            /*3 EMPLOYEES OF PARTICULAR DEPARTMENT*/
            cout<<"enter department:";
            cin>>depart;
            valid=0;
            file.seekg(0,ios::beg);
            file.read((char*)&E,sizeof(E));
            
                    
            cout<<"----EMPLOYEES DETAIL----"<<endl;
            cout<<setw(5)<<"EMP-ID"<<setw(20)<<"FIRST NAME"<<setw(20)<<"LAST NAME"<<setw(20)<<"DESIGNATION"<<setw(20)<<"DEPARTMENT"<<setw(10)<<"SALARY"<<setw(15)<<"EXPERIENCE"<<setw(15)<<"BIRTH YEAR"<<endl;
                    
            while (!file.eof())
            {
                if(strcmp(E.employee_department(),depart)==0)
                {
                    valid=1;
                    E.display_data();
                }
                file.read((char*)&E,sizeof(E));
            }
            file.clear();
            if(valid==0)
            cout<<"----NOT FOUND----"<<endl;
            break;
        case 4:
        
            //display
            file.clear();
            file.seekg(0,ios::beg);
            file.read((char*)&e,sizeof(e));
            
            cout<<"----EMPLOYEES DETAIL----"<<endl;
            cout<<setw(5)<<"EMP-ID"<<setw(20)<<"FIRST NAME"<<setw(20)<<"LAST NAME"<<setw(20)<<"DESIGNATION"<<setw(20)<<"DEPARTMENT"<<setw(10)<<"SALARY"<<setw(15)<<"EXPERIENCE"<<setw(15)<<"BIRTH YEAR"<<endl;
           
            while(!file.eof())
            {
               e.display_data();
               file.read((char*)&e,sizeof(e));

            }
            file.clear();
            cout<<endl;
            break;
        case 5:
        
            /*5 UPDATE*/
            count =0;
            valid=0;
            cout<<"enter id:";
            cin>>id;
            file.seekg(0,ios::beg);
            file.read((char*)&E,sizeof(E));
            while(!file.eof())
            {
                count++;
                if(E.employee_ID()==id)
                {
                    cout<<"----EMPLOYEES DETAIL----"<<endl;
                    cout<<setw(5)<<"EMP-ID"<<setw(20)<<"FIRST NAME"<<setw(20)<<"LAST NAME"<<setw(20)<<"DESIGNATION"<<setw(20)<<"DEPARTMENT"<<setw(10)<<"SALARY"<<setw(15)<<"EXPERIENCE"<<setw(15)<<"BIRTH YEAR"<<endl;
                    valid=1;
                    E.display_data();
                    break;
                }
                file.read((char*)&E,sizeof(E));
                
            }
            if(valid==0)
            {
                cout<<"----NOT FOUND----"<<endl;
                break;
            }
            file.clear();
            position=(count-1)*sizeof(e);
            
            e.read_data();
            
            file.seekg(0,ios::beg);
            valid=0;
            file.read((char*)&E,sizeof(E));
            while (!file.eof())
            {
                if(!E.employee_ID()==id){
                    if(E.employee_ID()==e.employee_ID())
                    {
                   // cout<<"----invalid data----"<<endl;
                        valid=1;
                        break;
                    }
                }
                file.read((char*)&E,sizeof(E));
            }
            if(valid==1){
                cout<<"----invalid data----"<<endl;
                break;
                }
            file.clear();
            
            file.seekp(position,ios::beg);
            file.write((char*)&e,sizeof(e));
            break;
        case 6:
            /*6 DELETE*/
            cout<<"enter id:";
            cin>>id;
            
            valid=0;
            
            file.seekg(0,ios::beg);
            file.read((char*)&E,sizeof(E));
            while(!file.eof())
            {
                if(E.employee_ID()==id)
                {
                    cout<<"----EMPLOYEES DETAIL----"<<endl;
                    cout<<setw(5)<<"EMP-ID"<<setw(20)<<"FIRST NAME"<<setw(20)<<"LAST NAME"<<setw(20)<<"DESIGNATION"<<setw(20)<<"DEPARTMENT"<<setw(10)<<"SALARY"<<setw(15)<<"EXPERIENCE"<<setw(15)<<"BIRTH YEAR"<<endl;
                    E.display_data();
                    valid=1;
                    break;
                }
                file.read((char*)&E,sizeof(E));
            }
            if(valid==0)
            {
                cout<<"----NOT FOUND----"<<endl;
                break;
            }
            
            file.clear();
            file.seekg(0,ios::beg);
            file.read((char*)&E,sizeof(E));
            temp.open("employee_management_tempfile.txt",ios::out|ios::binary);
            while(!file.eof())
            {
                if(E.employee_ID()!=id)
                {
                    temp.write((char*)&E,sizeof(E));
                }
                file.read((char*)&E,sizeof(E));
            }
            file.close();
            temp.close();
            file.open("employee_management_file.txt",ios::out|ios::binary);
            temp.open("employee_management_tempfile.txt",ios::in|ios::binary);
            temp.read((char*)&E,sizeof(E));
            while(!temp.eof())
            {
                file.write((char*)&E,sizeof(E));
                temp.read((char*)&E,sizeof(E));
            }
            temp.close();
            file.close();
            file.open("employee_management_file.txt",ios::ate|ios::in|ios::out|ios::binary);
            
            break;
        case 7:
        
            cout<<"EXIST"<<endl;
            break;
        default:  
        
            cout<<"enter valid option!!"<<endl;
            break;
        }
    } while (option!=7);
    file.close();
}