#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

//I have created this Main menu to uplaod the text file.
class Mainmenu
{
public:
    string line;
    
    void UploadFile(string** arr)
    {
        char* filename = new char;
        cout<< "enter the file name and path:" << endl;
        cin >> filename ;//filename variable will store the name of the file
        ifstream readfile(filename);//with the help of ifstream the file given by user will be read.
        int idx = 0;
        if(readfile.is_open())
        {
            while(getline(readfile,line))//using getline we will read the data line by line into the line variable
            {
                arr[idx] = new string(line);//the data will be passed into an arr.
                cout<< *arr[idx] << endl;//it will print the arr to the console. so that all the data is visbile line by line.
                idx++;
                
            }
            readfile.close();
            
        }
        delete filename;//this line deletes the variable which was using the heap memory.
        
    }
    
};


class ScheduledAppointments : public Mainmenu
{
public:
    void addbooking()
    {
        //this variables defined below are used to store the data in colomns so that we can perform add operation.
        char Bookingid[25],ContactNo[25],totcostofrepair[25];
        char Appointment_date[25],CustomerName[25];
        char Makeofthecar[25],Modelofthecar[25];
        char Mechanicname[25],statusofthecar[25];
        
        char* safile = new char;//this variable again is used to store file name.
        
        cout<< "enter the file name and path:" << endl;
        cin >> safile ;
        
        fstream addfile;
        addfile.open(safile, ios::app);
        cin.ignore();
        //the below cout will prompt the user to input the data and the getline function will fetch that data and will be stored in the specificvariable. 
        cout << " \n Bookingid : ";
        cin.getline(Bookingid,25);
        cout << " \n Appointment_date : ";
        cin.getline(Appointment_date,25);
        cout << " \n Customer Name : ";
        cin.getline(CustomerName,25);
        cout << " \n Contact No : ";
        cin.getline(ContactNo,25);
        cout << " \n Make of the car : ";
        cin.getline(Makeofthecar,25);
        cout << " \n Model of the car : ";
        cin.getline(Modelofthecar,25);
        cout << " \n Mechanic Name : ";
        cin.getline(Mechanicname,25);
        cout << " \n status of the car : ";
        cin.getline(statusofthecar,25);
        cout << " \n total cost of repair : ";
        cin.getline(totcostofrepair,25);
        
        //later all the variables will be added to the file one by one and seperated by identifier.
        addfile << Bookingid <<'|'<< Appointment_date <<'|'<< CustomerName << '|' << ContactNo << '|' << Makeofthecar <<'|' << Modelofthecar << '|' << Mechanicname << '|' << statusofthecar << '|' << totcostofrepair <<'\n';
        addfile.close();
        cout<<"Appointment Booked successfully";
        delete safile;
        
    }
    
    void update_status()
    {
        //this variables defined below are used to store the data in columns so that we can perform update operation.
        string  t2;//this variable is used to fetch the string which user wants to search or update.
        fstream temp;
        string sbookingid,sContactNo,stotcostofrepair;
        string sAppointment_date,sCustomerName;
        string sMakeofthecar,sModelofthecar;
        string sMechanicname,sstatusofthecar;
        fstream status;
       
        char* saupfile = new char;//this variable again is used to store file name.
        cout << "Enter the filename" << endl;
        cin >> saupfile;
        cout << "Enter the BookingID to update the status of the car"<< endl;
        cin >> t2;
        
        
        status.open(saupfile, ios::in);
        temp.open("temp.txt",ios::out);
        while(getline(status,line)) 
        {
            stringstream sdata(line);//stringstream is used to divide a line into columns
            getline(sdata,sbookingid,'|');
            getline(sdata,sAppointment_date,'|');
            getline(sdata,sCustomerName,'|');
            getline(sdata,sContactNo,'|');
            getline(sdata,sMakeofthecar,'|');
            getline(sdata,sModelofthecar,'|');
            getline(sdata,sMechanicname,'|');
            getline(sdata,sstatusofthecar,'|');
            getline(sdata,stotcostofrepair,'\n');
            
            if (sbookingid == t2)//this condition will see if the given string matches the record already present in the system or not and if it string matches it will ask user to add to new data 
            {
                cout<<" \n\tenter new value of record  \n ";
                cout<<" \n bookingid : ";
                cin >> sbookingid ;
                cout<<" \n Appointment_date : ";
                cin >> sAppointment_date ;
                cout<<" \n CustomerName : ";
                cin >> sCustomerName ;
                cout<<" \n ContactNo : ";
                cin >> sContactNo ;
                cout<<" \n Makeofthecar : ";
                cin >> sMakeofthecar ;
                cout<<" \n Modelofthecar : ";
                cin >> sModelofthecar ;
                cout<<" \n Mechanicname : ";
                cin >> sMechanicname ;
                cout<<" \n statusofthecar : ";
                cin >> sstatusofthecar ;
                cout<<" \n totcostofrepair : ";
                cin >> stotcostofrepair ;
                temp<<sbookingid<<'|'<<sAppointment_date<<'|'<<sCustomerName<<'|'<<sContactNo<<'|'<<sMakeofthecar<<'|'<<sModelofthecar<<'|'<< sMechanicname<<'|'<<sstatusofthecar<<'|'<<stotcostofrepair <<'\n';
                cout<<"\n Status updated !!! \n";
            }
            else //if the given string does not match the record already present the data will be stored in an temp file.
            {
                temp<<sbookingid<<'|'<<sAppointment_date<<'|'<<sCustomerName<<'|'<<sContactNo<<'|'<<sMakeofthecar<<'|'<<sModelofthecar<<'|'<< sMechanicname<<'|'<<sstatusofthecar<<'|'<<stotcostofrepair <<'\n';
               
            }
        }
        temp.close();
        status.close();
        status.open(saupfile,ios::out);
        temp.open("temp.txt",ios::in);
        while(getline(temp,line))//in this part the data stored in temp file will be again written back to the original file with the updated data and then it will delete the temp file.
        {
            stringstream sdata(line);
            getline(sdata,sbookingid,'|');
            getline(sdata,sAppointment_date,'|');
            getline(sdata,sCustomerName,'|');
            getline(sdata,sContactNo,'|');
            getline(sdata,sMakeofthecar,'|');
            getline(sdata,sModelofthecar,'|');
            getline(sdata,sMechanicname,'|');
            getline(sdata,sstatusofthecar,'|');
            getline(sdata,stotcostofrepair,'\n');
            status<<sbookingid<<'|'<<sAppointment_date<<'|'<<sCustomerName<<'|'<<sContactNo<<'|'<<sMakeofthecar<<'|'<<sModelofthecar<<'|'<<sMechanicname<<'|'<<sstatusofthecar<<'|'<<stotcostofrepair <<'\n';
            
        }
        temp.close();
        status.close();
        remove("temp.txt");
        cout <<"\n You will be redirected to Main menu \n" ;
        delete saupfile;
    }
    
    void delete_record()
    {
        //this variables defined below are used to store the data in columns so that we can perform update operation.
        string d2;//this variable is used to fetch the string which user wants to delete.
        string dbookingid,dContactNo,dtotcostofrepair;
        string dAppointment_date,dCustomerName;
        string dMakeofthecar,dModelofthecar;
        string dMechanicname,dstatusofthecar;
        
        fstream del;
        fstream del_temp;
        
        char* sadelfile = new char;//this variable again is used to store file name.
        
        cout << "Enter the filename" << endl;
        cin >> sadelfile ;
        int i = 0;
        cout << "Enter the BookingID to Delete the record"<< endl;
        cin >> d2;
        
        del.open(sadelfile, ios::in);
        del_temp.open("del_temp.txt",ios::out);
        while(getline(del,line)) 
        {
            stringstream ddata(line);//stringstream is used to divide a line into columns
            getline(ddata,dbookingid,'|');
            getline(ddata,dAppointment_date,'|');
            getline(ddata,dCustomerName,'|');
            getline(ddata,dContactNo,'|');
            getline(ddata,dMakeofthecar,'|');
            getline(ddata,dModelofthecar,'|');
            getline(ddata,dMechanicname,'|');
            getline(ddata,dstatusofthecar,'|');
            getline(ddata,dtotcostofrepair,'\n');
            
            if (dbookingid == d2)//if the given string is matched then the line with that specific line will be deleted.
            {
               cout<<"Record Deleted Successfully" ;
                continue;
               
            }
            else//if the given string does not match the record already present the data will be stored in an temp file.
            {
                del_temp<<dbookingid<<'|'<<dAppointment_date<<'|'<<dCustomerName<<'|'<<dContactNo<<'|'<<dMakeofthecar<<'|'<<dModelofthecar<<'|'<<dMechanicname<<'|'<<dstatusofthecar<<'|'<<dtotcostofrepair <<'\n';
                
            }
            

    }
    del_temp.close();
    del.close();
    del.open(sadelfile,ios::out);
    del_temp.open("del_temp.txt",ios::in);
    while(getline(del_temp,line))//in this part the data stored in temp file will be again written back to the original file with the updated data and then it will delete the temp file.
    {
        stringstream ddata(line);
        getline(ddata,dbookingid,'|');
        getline(ddata,dAppointment_date,'|');
        getline(ddata,dCustomerName,'|');
        getline(ddata,dContactNo,'|');
        getline(ddata,dMakeofthecar,'|');
        getline(ddata,dModelofthecar,'|');
        getline(ddata,dMechanicname,'|');
        getline(ddata,dstatusofthecar,'|');
        getline(ddata,dtotcostofrepair,'\n');
        del<<dbookingid<<'|'<<dAppointment_date<<'|'<<dCustomerName<<'|'<<dContactNo<<'|'<<dMakeofthecar<<'|'<<dModelofthecar<<'|'<< dMechanicname<<'|'<<dstatusofthecar<<'|'<<dtotcostofrepair <<'\n';
        
    }
    del_temp.close();
    del.close();
    remove("del_temp.txt");
    cout <<"\n You will be redirected to Main menu \n" ;
    delete sadelfile;
        
    }
    
};

//the same functions are used in other three classes to perform add,update and delete.
class empdetails : public Mainmenu  {

public:
    void eaddbooking()
    {
        //this variables defined below are used to store the data in columns so that we can perform add operation.
        char empid[25],empname[25],birthdate[25];
        char joining_date[25],Bloodgrp[25];
        char contactno[25],emailid[25];
        char Department[25];
        
        char* empfile = new char;//this variable again is used to store file name.
            
        cout<< "enter the file name and path:" << endl;
        cin >> empfile ;
            
        fstream emp;
        emp.open(empfile, ios::app);
        cin.ignore();
        cout << " \n Employee ID : ";
        cin.getline(empid,25);
        cout << " \n Employee Name : ";
        cin.getline(empname,25);
        cout << " \n Birthdate : ";
        cin.getline(birthdate,25);
        cout << " \n Joining Date : ";
        cin.getline(joining_date,25);
        cout << " \n Blood Group : ";
        cin.getline(Bloodgrp,25);
        cout << " \n contact No : ";
        cin.getline(contactno,25);
        cout << " \n Email ID : ";
        cin.getline(emailid,25);
        cout << " \n Department : ";
        cin.getline(Department,25);
        emp << empid <<'|'<< empname <<'|'<< birthdate << '|' << joining_date << '|' << Bloodgrp <<'|' << contactno << '|' << emailid << '|' << Department <<'\n';
        emp.close();
        cout<<"Employee Added successfully";
        delete empfile; 
        
    }
    
    void eupdate_status()
    {
        string  t2;
        fstream temp;
        string sempid,sempname,sbirthdate;
        string sjoining_date,sBloodgrp;
        string scontactno,semailid;
        string sDepartment;
        fstream status;
        char* eupfile = new char;
        
        cout<< "enter the file name and path:" << endl;
        cin >> eupfile ;
        cout << "Enter the Employee id to update the Employ record"<< endl;
        cin >> t2;
        
        
        status.open(eupfile, ios::in);
        temp.open("temp.txt",ios::out);
        while(getline(status,line)) 
        {
            stringstream sdata(line);
            getline(sdata,sempid,'|');
            getline(sdata,sempname,'|');
            getline(sdata,sbirthdate,'|');
            getline(sdata,sjoining_date,'|');
            getline(sdata,sBloodgrp,'|');
            getline(sdata,scontactno,'|');
            getline(sdata,semailid,'|');
            getline(sdata,sDepartment,'\n');
            
            if (sempid == t2)
            {
                cout<<" \n\tenter new value of record  \n ";
                cout<<" \n Employee ID : ";
                cin >> sempid ;
                cout<<" \n Employee Name : ";
                cin >> sempname ;
                cout<<" \n Birthdate : ";
                cin >> sbirthdate ;
                cout<<" \n Joining Date : ";
                cin >> sjoining_date ;
                cout<<" \n Blood Group : ";
                cin >> sBloodgrp ;
                cout<<" \n Contact No : ";
                cin >> scontactno ;
                cout<<" \n Email Id : ";
                cin >> semailid ;
                cout<<" \n Department : ";
                cin >> sDepartment ;
                temp<<sempid<<'|'<<sempname<<'|'<<sbirthdate<<'|'<<sjoining_date<<'|'<<sBloodgrp<<'|'<<scontactno<<'|'<< semailid<<'|'<<sDepartment <<'\n';
                cout<<"\n Record updated !!! \n";
            }
            else 
            {
                temp<<sempid<<'|'<<sempname<<'|'<<sbirthdate<<'|'<<sjoining_date<<'|'<<sBloodgrp<<'|'<<scontactno<<'|'<< semailid<<'|'<<sDepartment <<'\n';
               
            }
        }
        
        temp.close();
        status.close();
        status.open(eupfile,ios::out);
        temp.open("temp.txt",ios::in);
        
        while(getline(temp,line))
        {
            stringstream sdata(line);
            getline(sdata,sempid,'|');
            getline(sdata,sempname,'|');
            getline(sdata,sbirthdate,'|');
            getline(sdata,sjoining_date,'|');
            getline(sdata,sBloodgrp,'|');
            getline(sdata,scontactno,'|');
            getline(sdata,semailid,'|');
            getline(sdata,sDepartment,'\n');
            status<<sempid<<'|'<<sempname<<'|'<<sbirthdate<<'|'<<sjoining_date<<'|'<<sBloodgrp<<'|'<<scontactno<<'|'<<semailid<<'|'<<sDepartment <<'\n';
            
        }

        temp.close();
        status.close();
        remove("temp.txt");
        cout <<"\n You will be redirected to Main menu \n" ;
        delete eupfile;
        
    }
    
    void edelete_record()
    {
        string d2;
        string dempid,dempname,dbirthdate;
        string djoining_date,dBloodgrp;
        string dcontactno,demailid;
        string dDepartment;
        fstream del;
        fstream del_temp;
        char* edelfile = new char;
        
        cout<< "enter the file name and path:" << endl;
        cin >> edelfile ;
       
        int i = 0;
        cout << "Enter the Employee ID to Delete the record"<< endl;
        cin >> d2;
        
        del.open(edelfile, ios::in);
        del_temp.open("del_temp.txt",ios::out);
        while(getline(del,line)) 
        {
            stringstream ddata(line);
            getline(ddata,dempid,'|');
            getline(ddata,dempname,'|');
            getline(ddata,dbirthdate,'|');
            getline(ddata,djoining_date,'|');
            getline(ddata,dBloodgrp,'|');
            getline(ddata,dcontactno,'|');
            getline(ddata,demailid,'|');
            getline(ddata,dDepartment,'\n');
            
            if (dempid == d2)
            {
                continue;
                cout<<"Record Deleted Successfully" ; 
            }
            else
            {
                del_temp<<dempid<<'|'<<dempname<<'|'<<dbirthdate<<'|'<<djoining_date<<'|'<<dBloodgrp<<'|'<<dcontactno<<'|'<<demailid<<'|'<< dDepartment <<'\n';
                
            }
            
        }
        del_temp.close();
        del.close();
        del.open(edelfile,ios::out);
        del_temp.open("del_temp.txt",ios::in);
        while(getline(del_temp,line))
        {
            stringstream ddata(line);
            getline(ddata,dempid,'|');
            getline(ddata,dempname,'|');
            getline(ddata,dbirthdate,'|');
            getline(ddata,djoining_date,'|');
            getline(ddata,dBloodgrp,'|');
            getline(ddata,dcontactno,'|');
            getline(ddata,demailid,'|');
            getline(ddata,dDepartment,'\n');
            del<<dempid<<'|'<<dempname<<'|'<<dbirthdate<<'|'<<djoining_date<<'|'<<dBloodgrp<<'|'<<dcontactno<<'|'<< demailid<<'|'<<dDepartment<<'\n'; 
            
        }
        del_temp.close();
        del.close();
        remove("del_temp.txt");
        cout <<"\n You will be redirected to Main menu \n" ;
        delete edelfile;
        
    }
    
};

class inventory : public Mainmenu {

public :
    void iaddbooking()
    {
        char id[25],invtname[25],qty[25];
        char* ifile = new char;
        cout<< "enter the file name and path:" << endl;
        cin >> ifile ;
        fstream myfile;
        myfile.open(ifile, ios::app);
        cin.ignore();
        cout << " \n Inventory ID : ";
        cin.getline(id,25);
        cout << " \n inventory Name : ";
        cin.getline(invtname,25);
        cout << " \n Quantity : ";
        cin.getline(qty,25);
        
        myfile << id <<'|'<< invtname <<'|'<< qty <<'\n';
        myfile.close();
        cout<<"Inventory Added successfully";
        delete ifile;
        
    }
    
    
    
    void iupdate_status()
    {
        string  t2;
        fstream temp;
        string sid,sinvtname,sqty;
        fstream status;
        char* iupfile = new char;
        cout<< "enter the file name and path:" << endl;
        cin >> iupfile ;
       
        cout << "Enter the Inventory Id to update the status of the car"<< endl;
        cin >> t2;
        
        status.open(iupfile, ios::in);
        temp.open("temp.txt",ios::out);
        while(getline(status,line)) 
        {
            stringstream sdata(line);
            getline(sdata,sid,'|');
            getline(sdata,sinvtname,'|');
            getline(sdata,sqty,'\n');
            if (sid == t2)
            {
                cout<<" \n\tenter new value of record  \n ";
                cout<<" \n Inventory ID : ";
                cin >> sid ;
                cout<<" \n Inventory Name : ";
                cin >> sinvtname ;
                cout<<" \n Quantity : ";
                cin >> sqty ;
                
                temp<<sid<<'|'<<sinvtname<<'|'<<sqty <<'\n';
                cout<<"\n Record updated !!! \n";
                
            }
            
            else
            {
                temp<<sid<<'|'<<sinvtname<<'|'<<sqty <<'\n';
                
            }
        }
        
        temp.close();
        status.close();
        status.open(iupfile,ios::out);
        temp.open("temp.txt",ios::in);
        while(getline(temp,line))
        {
            stringstream sdata(line);
            getline(sdata,sid,'|');
            getline(sdata,sinvtname,'|');
            getline(sdata,sqty,'\n');
            status<<sid<<'|'<<sinvtname<<'|'<<sqty <<'\n';
            
        }
        temp.close();
        status.close();
        remove("temp.txt");
        cout <<"\n You will be redirected to Main menu \n" ;
        delete iupfile;
    }
    
    void idelete_record()
    {
        string d2;
        string sid,sinvtname,sqty;
        fstream del;
        fstream del_temp;
        char* idelfile = new char;
        cout<< "enter the file name and path:" << endl;
        cin >> idelfile ;
        
        int i = 0;
        cout << "Enter the Inventory Id to Delete the record"<< endl;
        cin >> d2;
        
        del.open(idelfile, ios::in);
        del_temp.open("del_temp.txt",ios::out);
        while(getline(del,line)) 
        {
            stringstream ddata(line);
            getline(ddata,sid,'|');
            getline(ddata,sinvtname,'|');
            getline(ddata,sqty,'\n');
            
            if (sid == d2)
            {
                continue;
                cout<<"Record Deleted Successfully" ; 
            }
            else
            {
                del_temp<<sid<<'|'<<sinvtname<<'|'<<sqty <<'\n';
                
            }
            
        }
        del_temp.close();
        del.close();
        del.open(idelfile,ios::out);
        del_temp.open("del_temp.txt",ios::in);
        while(getline(del_temp,line))
        {
            stringstream ddata(line);
            getline(ddata,sid,'|');
            getline(ddata,sinvtname,'|');
            getline(ddata,sqty,'\n');
            del<<sid<<'|'<<sinvtname<<'|'<<sqty <<'\n';
            
        }
        del_temp.close();
        del.close();
        remove("del_temp.txt");
        cout <<"\n You will be redirected to Main menu \n" ;
        delete idelfile;
        
    }
    
};

class totcars : public Mainmenu {
    
public:

    //this function is used to count the total number of cars present in the garage.
    void countcars()
    {
         //this variables defined below are used to store the data in colomns so that we can perform add operation.
        string sbookingid,sContactNo,stotcostofrepair;
        string sAppointment_date,sCustomerName;
        string sMakeofthecar,sModelofthecar;
        string sMechanicname,sstatusofthecar;
        
        int count  = 0;
        int ccount = 0;
        int pcount = 0;
        fstream tot;
        
        char* totfile = new char;//this variable again is used to store file name.
        cout << "Enter the filename" << endl;
        cin >> totfile;
        tot.open(totfile, ios::in);
        
        while(getline(tot,line))//this function will read the line one by one 
        {
            stringstream sdata(line);//again stringstream is used to split data into columns.
            getline(sdata,sbookingid,'|');
            getline(sdata,sAppointment_date,'|');
            getline(sdata,sCustomerName,'|');
            getline(sdata,sContactNo,'|');
            getline(sdata,sMakeofthecar,'|');
            getline(sdata,sModelofthecar,'|');
            getline(sdata,sMechanicname,'|');
            getline(sdata,sstatusofthecar,'|');
            getline(sdata,stotcostofrepair,'\n');
            
            if (sstatusofthecar == "completed")//if status is equal to completed the counter name ccount will be incremented
            {
                ccount++;
            }
            else //else if the status is equal to pending the counter name pcount will be incremented
            {
                pcount++;
            }
            count++;
            
        }
        cout << "The Total Cars in the Garage Are :" << count << endl;//it will return the total number of cars in the garage.
        cout << "The Total Completed Cars in the Garage Are :" << ccount << endl;//it will return the total number of cars completed their servicing.
        cout << "The Total Pending Cars in the Garage Are :" << pcount <<endl;//it will return the total number of cars pending for servicing.
        delete totfile;
        
    }
    
};


int main ()
    {
        bool flag=true;
        int choice;
        Mainmenu mm;
        ScheduledAppointments sa;
        empdetails emp;
        inventory inv;
        totcars tot;
        string* arr[40];
        int selection;
        while (flag)
        {
            cout <<endl;
            cout << "     Welcome to the Garage Kindly select any one option from the below Mentioned Menu No from (1-5)." <<endl;
            cout <<endl;
            cout <<"                                            Menu                                                          "<<endl;
            cout <<"--------------------------------------------------------------------------------------------------"<<endl;
            cout <<"Scheduled Appointments(1) |"<<"Total Number of Cars(2) |" <<"Employee's Details(3) |" <<" Inventory(4) |"<<"EXIT (5)" << endl;
            cout <<"--------------------------------------------------------------------------------------------------"<<endl;
            cin  >> selection;
            
            if (selection == 1)
            {
                cout <<"-------------------------------------------------------"<<endl;
                cout<<"                Scheduled Appointments                  "<< endl;
                cout <<"-------------------------------------------------------"<<endl;
                
                sa.UploadFile(arr);
                
                cout << '\n';
                cout<< "Enter 1 to Add New Booking" << endl;
                cout<< "Enter 2 to Update Status of the car" << endl;
                cout<< "Enter 3 to delete the record" << endl;
                cout<< "Enter 4 to return to Mainmenu" << endl;
                cout << '\n';
                
                cin >> choice ;
                if(choice == 1)
                {
                    sa.addbooking();
                    
                }
                else if (choice == 2)
                {
                    sa.update_status();
                    
                }
                else if(choice == 3)
                {
                    sa.delete_record();
                    
                }
                
            }
            
            else if (selection == 2){
                cout << '\n';
                tot.countcars();
                cout << '\n';
                
                cout<< "Enter 4 to return to Mainmenu" << endl;
                cout << '\n';
                
                cin >> choice ;
                
            }
            else if (selection == 3){
                cout <<"-------------------------------------------------------"<<endl;
                cout<<"                Employee Details                  "<< endl;
                cout <<"-------------------------------------------------------"<<endl;
                
                sa.UploadFile(arr);
                
                cout << '\n';
                cout<< "Enter 1 to Add New Employee" << endl;
                cout<< "Enter 2 to Update Employee Information" << endl;
                cout<< "Enter 3 to Delete the Employee record" << endl;
                cout<< "Enter 4 to return to Mainmenu" << endl;
                cout << '\n';
                
                cin >> choice ;
                if(choice == 1)
                {
                    emp.eaddbooking();
                    
                }
                else if (choice == 2)
                {
                    emp.eupdate_status();
                    
                }
                else if(choice == 3)
                {
                    emp.edelete_record();
                    
                }
                
            }
            
            else if (selection == 4)
            {
                cout <<"-------------------------------------------------------"<<endl;
                cout<<"                Inventory  Details                  "<< endl;
                cout <<"-------------------------------------------------------"<<endl;
                
                sa.UploadFile(arr);
                
                cout << '\n';
                cout<< "Enter 1 to Add New Booking" << endl;
                cout<< "Enter 2 to Update Status of the car" << endl;
                cout<< "Enter 3 to delete the record" << endl;
                cout<< "Enter 4 to return to Mainmenu" << endl;
                cout << '\n';
                
                cin >> choice ;
                
                if(choice == 1)
                {
                    inv.iaddbooking();
                    
                }
                else if (choice == 2)
                {
                    inv.iupdate_status();
                    
                }
                else if(choice == 3)
                {
                    inv.idelete_record();
                    
                }
                
            }
            else if (selection == 5)
            {
                flag = false;
                
            }
            else
            {
                cout <<"The Selected option not availabe" <<endl;
                
            }
            
        }
        
    }
