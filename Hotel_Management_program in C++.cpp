#include<iostream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
void showSelection();
void new_customer();
void payment(char n1[25],char date[15]);
void list();
void info(char date[20]);
struct file_info
{
       char nam[20];
       float paisa;
}ob;
struct order_type
{      char name[20];
       float total;
       struct order_type *next;
       }*S=NULL,*E=NULL;
struct ammount_type
{
      float ammount;
      struct order_type *order;
      };
struct customer
{     
      char name[25];
      struct ammount_type *detail; 
      struct customer *next;
      }*start=NULL,*end=NULL,*paid=NULL;
//Main program start
char date[30],date1[30];
int main()
{
int choice;
                     
                      system("cls");
                    //  system("color 15");
                 cout<<"\20*******************  WELCOME TO C++ RESTURANT **************************\20\n";
                 ofstream out;
                 cout<<"Date formate DD-MM-YY\n";
                  cout<<"Enter Today date: ";
                  fflush(stdin);
                  gets(date);
                  int l;
                  l=strlen(date);
                 date[l]='.';
                 date[l+1]='d';
                 date[l+2]='a';
                 date[l+3]='t';
                 date[l+4]='\0';
                 out.open(date,ios::out|ios::app);
                  main_menu:
                 system("cls");
                // system("color 24");
                 cout<<"\20*******************  WELCOME TO ANDHRA RESTURANT **************************\20\n";
                   showSelection();
                   cout<<"1.New Customer\n";
                   cout<<"2.Payment\n";
                    cout<<"3.customer list\n";
                    cout<<"4.Adminisrator\n";
                    cout<<"5.Exit\n";
                   cout<<"Enter your choice: ";
                   cin>>choice;
                 if(choice==1)
                  {
                  new_customer(); 
                  goto main_menu; 
                  }
             else if(choice==2)
                  {
            char temp_name[30];
           cout<<"Enter customer name: ";
           fflush(stdin);   
           gets(temp_name);
          payment(temp_name,date);
          getch();
          goto main_menu;
                 }
                 else if(choice==3)
                 {
                      list();
                      getch();
                      goto main_menu;
                 }
           else if(choice==4)
           {
                char username[20],password[20],d1[20];
                char p1[20]="pwd";
                char u1[20]="c++";
                ifstream in;
                in.open("login.txt",ios::in);
                in>>u1>>p1;
                  again:
                 system("cls");
                // system("color 4f");
                 cout<<"\20*******************  WELCOME TO c++ RESTURANT **************************\20\n";
                cout<<"Enter user name: ";
                fflush(stdin);
                gets(username);
                cout<<"Enter user password: ";
                fflush(stdin); 
                gets(password);
                if ( strcmp (username,u1) == 0 && strcmp (password,p1) == 0 )
                {
                     login:
                system("cls");
             //    system("color 4f");
                 cout<<"\20*******************  WELCOME TO 'c++' RESTURANT **************************\20\n";
                  cout<<"1.Today customer list\n";
                   cout<<"2.Other day\n";
                   cout<<"3.Main menu\n";
                    cout<<"Enter your choice: ";
                   cin>>choice;
                   switch(choice)
                   {
                   case 1:
                        info(date);
                   break;
                   case 2:
                     cout<<"Date formate DD-MM-YYYY\n";
                  cout<<"Enter Today date: ";
                  fflush(stdin);
                  gets(date1);
                  l=strlen(date1);
                 date1[l]='.';
                 date1[l+1]='d';
                 date1[l+2]='a';
                 date1[l+3]='t';
                 date1[l+4]='\0';
                 info(date1);
                  break;
                  case 3:
                        goto main_menu;
                  }
                   goto login;
                  }
                else
                {
                    cout<<"Username or password is wrong\nTry again\n";
                    getch();
                    goto again;
                }
                                
                
           }
           else if(choice==5)
                 {
                      exit(0);
                 }
getch();
}

//Main program End


void showSelection()
{
      printf(" \t\t\t Below is the menue:\20\n");
      printf(" \t\t\t MEALS\t\t\tPRICE:\n");
      printf(" \t\t\t \22*******************************\22\n");
      printf(" \t\t\t 1- Chowmin\t\tRs 35.80\n");
      printf(" \t\t\t 2- Spaghetti\t\tRs 50.50\n");
      printf(" \t\t\t 3- Chilly Chicken\tRs 100.00\n");
      printf(" \t\t\t 4- Chicken Chop\tRs 95.00\n");
      printf(" \t\t\t 5- Chicken Maryland\tRs 125.00\n");
      printf(" \t\t\t 6- Red Lobster\t\tRs 160.00\n");
      printf(" \t\t\t 7- Seafood Platter\tRs 120.00\n");
      printf(" \t\t\t 8- Milk shake\t\tRs 20.00\n");
      printf(" \t\t\t 9- Mocktails\t\tRs 50.00\n");
      printf(" \t\t\t10- Cheese Pizza\tRs 70.00\n\n\n");
      printf("\n");
}
void payment(char n1[30],char date[20])
{
   ofstream out1;
   out1.open(date,ios::app|ios::out);
    struct customer *t1,*te1;
    int flag=0;
    t1=start;
    te1=start;
    struct order_type *t3;
    while(t1!=NULL)
    {
       if(strcmp(t1->name,n1)==0)
       {
    
                           t3=t1->detail->order;
                                 system("cls");
                             //     system("color 3a");
                                  cout<<"\20*******************  WELCOME TO 'c++' RESTURANT **************************\20\n";
       cout<<"Customer name: "<<t1->name;
       strcpy(ob.nam,t1->name);
       ob.paisa=t1->detail->ammount;
      out1.write((char*)&ob,sizeof(ob));
       cout<<"\nBilling detail:-" ;
        cout<<"\nItem\t\t\tammount\n";
           while(t3!=NULL)
          {
          cout<<t3->name<<"\t\t"<<t3->total<<"\n";
          t3=t3->next;              
           } 
            
        cout<<"\n\nTotal ammount: "<<t1->detail->ammount<<"\n\t\tThanku for visiting........";
        if(start->next==NULL)
        {
        free(t1);
        start=NULL;
        end=NULL;
        }
        else if(strcmp(start->name,n1)==0)
        start=start->next;
        else
        {
          while(te1!=NULL)
          {
             if(te1->next!=NULL)
             {
             if(strcmp(te1->next->name,n1)==0)
             {
             te1->next=t1->next;
             if(t1==end)
             end=te1;
             } 
             }    
          te1=te1->next;        
         }  
      } 
        flag=1;                           
       }
       t1=t1->next;
       } 
   if(flag==0)
  cout<<"Invalid customer name";
  out1.close();
 }
 
 
 
void new_customer()            //Adding mew customer
{
     char I[11][20];
                   float p[11];
                   strcpy(I[1],"Chowmin");
                   strcpy(I[2],"Spaghetti");
                   strcpy(I[3],"Hilly Chicke");
                   strcpy(I[4],"Chicken Chop");
                   strcpy(I[5],"Chicken Maryland");
                   strcpy(I[6],"Red Lobster");
                   strcpy(I[7],"Seafood Platter");
                   strcpy(I[8],"Milk shake");
                   strcpy(I[9],"Mocktails");
                   strcpy(I[10],"Cheese Pizza");
                   p[1]= 35.80;
                   p[2]=50.50;
                   p[3]=100.00;
                   p[4]=95.00;
                   p[5]=125.00;
                   p[6]=160.00;
                   p[7]=120.00;
                   p[8]=20.00;
                   p[9]=50.00;
                   p[10]=70.00;
                           struct customer *temp1;
                               struct ammount_type *temp2;
                               struct order_type *temp3;
                               if(start==NULL&&end==NULL)
                               {
                                 temp1=(struct customer*)malloc(sizeof(struct customer));
                                 start=temp1;
                                 end=temp1;
                                 cout<<"Enter customer name: ";
                                 fflush(stdin);
                                 gets(end->name);   
                                 end->next=NULL;
                                 temp2=(struct ammount_type*)malloc(sizeof(struct ammount_type));
                                 end->detail=temp2;
                                 end->detail->ammount=0;
                                 temp3=(struct order_type*)malloc(sizeof(struct order_type));
                                 temp3->next=NULL;
                                 end->detail->order=temp3;
                                 S=temp3;
                                 E=temp3;
                                  int option,op,no;
                                  system("cls");
                                //  system("color 3a");
                                  cout<<"\20*******************  WELCOME TO ANDHRA RESTURANT **************************\20\n";
                                  showSelection();
                                  cout<<"Customer name: "<<end->name;
                                 cout<<"\n1.Order \n2.Done\n";
                                  cout<<"Enter choice: ";
                                 cin>>option;
                                 while(option==1)
                                 {
                                 system("cls");
                            //      system("color 3a");
                                  cout<<"\20*******************  WELCOME TO ANDHRA RESTURANT **************************\20\n";
                                 showSelection();
                                 cout<<"Your choice: ";
                                 cin>>op;
                                 cout<<"Quantity: ";
                                 cin>>no;
                                 if(end->detail->ammount==0)
                                 {
                                 strcpy(end->detail->order->name,I[op]);
                                 end->detail->order->total=p[op]*no;
                                 end->detail->ammount= end->detail->ammount+end->detail->order->total;
                                 E=end->detail->order;
                                 }
                                 else
                                 {
                                 struct order_type *temp4;
                                 temp4=(struct order_type*)malloc(sizeof(struct order_type));
                                 temp4->next=NULL;                           
                                 strcpy(temp4->name,I[op]);
                                 temp4->total=p[op]*no;                          
                                 end->detail->ammount= end->detail->ammount+temp4->total;
                                 E->next=temp4;
                                 E=E->next;
                                 }
                                 cout<<"\n1.Add more \n2.Done\n";
                                  cout<<"Enter choice: ";
                                  cin>>option;
                                 }       
                                 }
                               else
                               {
                                 temp1=(struct customer*)malloc(sizeof(struct customer));
                                 end->next=temp1;
                                 end=end->next; 
                                 cout<<"Enter customer name: ";
                                 fflush(stdin);
                                 gets(end->name);   
                                 end->next=NULL;
                                 temp2=(struct ammount_type*)malloc(sizeof(struct ammount_type));
                                 end->detail=temp2;
                                 end->detail->ammount=0;
                                 temp3=(struct order_type*)malloc(sizeof(struct order_type));
                                 temp3->next=NULL;
                                 end->detail->order=temp3;
                                 S=temp3;
                                 E=temp3;
                                  int option,op,no;
                                  system("cls");
                               //   system("color 3a");
                                  cout<<"\20*******************  WELCOME TO ANDHRA RESTURANT **************************\20\n";
                                  showSelection();
                                  cout<<"Customer name: "<<end->name;
                                 cout<<"\n1.Order \n2.Done\n";
                                  cout<<"Enter choice: ";
                                 cin>>option;
                                 while(option==1)
                                 {
                                 system("cls");
                              //    system("color 3a");
                                  cout<<"\20*******************  WELCOME TO ANDHRA RESTURANT **************************\20\n";
                                 showSelection();
                                 cout<<"Your choice: ";
                                 cin>>op;
                                 cout<<"Quantity: ";
                                 cin>>no;
                                 if(end->detail->ammount==0)
                                 {
                                 strcpy(end->detail->order->name,I[op]);
                                 end->detail->order->total=p[op]*no;
                                 end->detail->ammount= end->detail->ammount+end->detail->order->total;
                                 E=end->detail->order;
                                 }
                                 else
                                 {
                                 struct order_type *temp4;
                                 temp4=(struct order_type*)malloc(sizeof(struct order_type));
                                 temp4->next=NULL;                  
                                 strcpy(temp4->name,I[op]);
                                 temp4->total=p[op]*no;                                 
                                 end->detail->ammount= end->detail->ammount+temp4->total;
                                 E->next=temp4;
                                 E=E->next;
                                 }
                                 cout<<"\n1.Add more \n2.Done\n";
                                  cout<<"Enter choice: ";
                                  cin>>option;
                                  }
                                 }
}
void list()
{
float total=0;
   system("cls");
 //   system("color 3a");
    cout<<"\20*******************  WELCOME TO ANDHRA  RESTURANT **************************\20\n";
    cout<<"\nCustomer name\t\t\t\t\tammount\n";
    struct customer *t1;
    int flag=0;
    t1=start;
    while(t1!=NULL)
    {
          cout<<t1->name<<"\t\t\t\t\t"<<t1->detail->ammount<<"\n"; 
          total=total+t1->detail->ammount;
          t1=t1->next;           
    }
    cout<<"\nTotal ammount: "<<total;
 }
void info(char vd[30])
{
     struct file_info ob1;
     float total=0;
     ifstream in;
     in.open(vd,ios::in);
    if(!in)
    cout<<"Date you have enter is not in our list \n";
else
{
cout<<"\nCustomer name\t\t\t\t\tammount\n";
      while(in.read((char*)&ob1,sizeof(ob1)))
    {        
     
    cout<<ob1.nam<<"\t\t\t\t\t"<<ob1.paisa<<"\n";
    total=total+ob1.paisa;  
    }
   
     cout<<"\n\nTotal ammount: "<<total;
     
}
     in.close();
     getch();
}
