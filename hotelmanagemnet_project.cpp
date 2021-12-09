#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <dos.h>
#include <windows.h>

using namespace std;

class hotel
{
int room_no;
char name[30];
char address[50];
char phone[10];
public:
void main_menu(); //to dispay the main menu
void add(); //to book a room
void display(); //to display the customer record
void rooms(); //to display alloted rooms
void edit(); //to edit the customer record
int check(int); //to check room status
void modify(int); //to modify the record
void DisplayRoomInfo();
void delete_rec(int); //to delete the record

};

void hotel::main_menu()
{
int choice;
while(choice!=5)
{
system("cls");
cout<<"\n\t\t\t\t*************";
cout<<"\n\t\t\t\t* MAIN MENU *";
cout<<"\n\t\t\t\t*************";
cout<<"\n\n\n\t\t\t 1.Book A Room";
cout<<"\n\t\t\t 2.Customer Record";
cout<<"\n\t\t\t 3.Rooms Allotted";
cout<<"\n\t\t\t 4.Edit Record";
cout<<"\n\t\t\t 5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;
switch(choice)
{
case 1: add();// Booking
break;
case 2: display();//Customer Record
break;
case 3: rooms(); // rooms alloted
break;
case 4: edit(); // edit record (modify or delete)
break;
case 5: break;
default:
{
cout<<"\n\n\t\t\tWrong choice!!!";
cout<<"\n\t\t\tPress any key to continue!!";
getch();
}
}
}
}

void hotel::add()
{
system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);
cout<<"\n Enter Customer Detalis";
cout<<"\n **********************";
cout<<"\n\n Room no: ";
cin>>r;
flag=check(r);
if(flag)
cout<<"\n Sorry..!!!Room is already booked";
else
{
room_no=r;
cout<<" Name: ";
 cin>>name;
            //gets(name);
cout<<" Address: ";
 cin>>address;         //gets(address);
cout<<" Phone No: ";
  cin>> phone;                //gets(phone);
fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked!!!";
}
cout<<"\n Press any key to continue!!";
getch();
fout.close();
}

void hotel::display()
{
system("cls");
ifstream fin("Record.dat",ios::in);
int r,flag;
cout<<"\n Enter room no: ";
cin>>r;
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
system("cls");
cout<<"\n Cusromer Details";
cout<<"\n ****************";
cout<<"\n\n Room no: "<<room_no<<endl;
cout<<"\n Name: "<<name<<endl;
cout<<"\n Address: "<<address<<endl;
cout<<"\n Phone no: "<<phone<<endl;
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant!!";
cout<<"\n\n Press any key to continue!!";
getch();
fin.close();
}

void hotel::rooms()
{
system("cls");
ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t List Of Rooms Allotted";
cout<<"\n\t\t\t *********************";
cout<<"\n\n Room No.\t\t Name \t\t Address \t\t Phone No.\n";
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t\t"<<name<<"\t";
cout<<"\t\t"<<address<<"\t\t"<<phone;
}
cout<<"\n\n\n\t\t\t Press any key to continue!!";
getch();
fin.close();
}

void hotel::edit()
{
system("cls");
int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n *********";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n Enter your choice: ";
cin>>choice;
system("cls");
cout<<"\n Enter room no: ";
cin>>r;
switch(choice)
{
case 1: modify(r);
break;
case 2: delete_rec(r);
break;
default: cout<<"\n Wrong Choice!!";
}
cout<<"\n Press any key to continue!!!";
getch();
}

int hotel::check(int r)
{
int flag=0;
ifstream fin("Record.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}
fin.close();
return(flag);
}

void hotel::modify(int r)
{
long pos,flag=0;
fstream file("Record.dat",ios::in|ios::out|ios::binary);
while(!file.eof())
{
pos=file.tellg();
file.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Enter New Details";
cout<<"\n *****************";
cout<<"\n Name: ";
 cin>>name;             //gets(name);
cout<<" Address: ";
  cin>> address;             //gets(address);
cout<<" Phone no: ";
 cin>> phone;          //gets(phone);
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified!!";
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant!!";
file.close();
}

void hotel::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;
if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;
}
else
fout.write((char*)this,sizeof(hotel));
}
fin.close();
fout.close();
if(flag==0)
cout<<"\n Sorry room no. not found or vacant!!";
else
{
remove("Record.dat");
rename("temp.dat","Record.dat");
}
}

int main()
{
hotel h;
//textmode(C80);
//textbackground(WHITE);
//textcolor(RED);
system("cls");
system("color 3F");
cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
cout<<"\n\t\t\t****************************";
//delay(2);
cout<<"\n\n\n\n\t\tMade By:";
//sleep(2);
cout<<" Farhat Mir";
//sleep(2);
cout << "\n\n\n\n\n\n\n\n \t\t\t\t\t\t\t\t\t\t Submitted to: ";
cout<<"HOD NISAR SIR"<<endl;
cout<<"\n\n\n\n\n\t\t\t\t Press any key to continue!!";
getch();
system("color 3F");
h.main_menu();
return 0;
}

