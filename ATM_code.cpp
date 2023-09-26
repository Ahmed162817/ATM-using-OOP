#include<iostream>
#include<cstring>
using namespace std;
int display=1 ;                //the display variable control the printing message in the insert card number function
class ATM {
private :
    char acc_name[100];
    int card_no[10];
    float amount;
public:
    ATM();
    void create_new_acc(int fodder[10]);
    void deposit();
    void withdrawal();
    void transfer(ATM &user);
    void print_acc_data();
    void get_card(int tempo[10]);        // to copy the card number of a user into a temporary array
};
ATM :: ATM(){amount=0;}                 //constructor to initialize the amount
void ATM :: create_new_acc(int fodder[10]){
    amount=0; // we found out after many wrong inputs that the amount go wrong even in the presence of a constructor !!!
    int space=32;                  //variable store the ASCII code of space
      cin.ignore();
 p:
cout<<"please enter the account name : ";
      gets(acc_name);
      if(strlen(acc_name)==0)
      {
          cout<<"you have not enter any character.....please try again"<<endl;
          goto p;
      }
      for(int i=0;i<strlen(acc_name);i++)
      {
          if(((acc_name[i]>='a'&&acc_name[i]<='z')||(acc_name[i]>='A'&&acc_name[i]<='Z')))
                continue;
                else
            {
            cout<<"Error,account name should contain only letters .....please try again"<<endl;
          goto p;}
      }
      if(strlen(acc_name)>100)
      {
          cout<<"Error, you have entered more than 100 characters ....please try again"<<endl;
          goto p;
      }
  k:
cout<<"Please enter the account number(10 numbers each separated by space) : ";
for(int i=0;i<10;i++)
    cin>>card_no[i];
for(int i=0;i<10;i++)
if(card_no[i]<0||card_no[i]>9){
  cout<<"Invalid input,you should enter only one positive number at a space please try again ......"<<endl<<endl;
        goto k;
     }
     for(int i=0;i<10;i++){
    if(!cin){ cout<<"Error, as the card number contain symbol!!"<<endl;      //function to remove any character from buffer
            cin.clear();
            cin.ignore(256,'\n');
        goto k;}
     }
        for(int i=0;i<10;i++){
    if(cin.peek()!='\n'){ cout<<"Error, you insert more than 10 integers...please try again"<<endl;
            cin.clear();
            cin.ignore(256, '\n');
        goto k;}}
     int i;
     for( i=1;i<10;i++)
     {
         if(card_no[i]==card_no[i-1])
            continue;
         else
            break;
     }
     if(i==10)
     {
         cout<<" this account is easy to be stolen as this card number is very easy.....please try again "<<endl;
         goto k;
     }
     for(int i=0;i<10;i++)
     fodder[i]=card_no[i];
}
void ATM :: deposit(){
float deposit_value;
 g:
cout<<"Please enter the amount to be deposited : ";
cin>>deposit_value;
     if((!cin)||(cin.peek()!='\n')){ cout<<"Error, as the deposit value contain symbol!!....please try again"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
        goto g;}
   if(deposit_value<=0)
   {
       cout<<"error the amount to be deposit must be greater than zero...please try again "<<endl;
       goto g;
   }
amount+=deposit_value+0.01*deposit_value;
 print_acc_data();
}
void ATM :: withdrawal(){
    int navigate;                       //it is used in switch statement to determine the choice of user upon error

    if(amount==0) {cout<<"Invalid operation, you don't have money in the account. please try again ....."<<endl;
        return ;}
float withdrawal_value=0;
 f:
cout<<"Please enter the amount to be withdrawn : ";
cin>>withdrawal_value;
   if((!cin)||(cin.peek()!='\n')){ cout<<"Error, as the withdrawal value contain symbol!!....please try again"<<endl;
            cin.clear();                     //clear the extraction error
            cin.ignore(256,'\n');
        goto f;}
 if(withdrawal_value<=0)
   {
       cout<<"error the amount to be withdrawal must be greater than zero...please try again "<<endl;
       goto f;
   }
withdrawal_value+=0.03*withdrawal_value;
if(withdrawal_value>amount){
    cout<<"Error,The withdrawn amount is bigger than your amount & its taxes ....."<<endl;
    cout<<"\t 1........ return to main menu"<<endl<<"\t 2........ continue the operation"<<endl;
    cout<<"Enter your choice : "; cin>>navigate;
    switch(navigate){
         case(1): return;
         case(2): goto f;
        default: {cout<<"Invalid choice "<<endl;
        return;}
    }

}
amount-=withdrawal_value;
 print_acc_data();
}
void ATM :: transfer(ATM &user){
int error_option;                      //it is used in switch statement to determine the choice of user upon error
float transfer_value;
float transfer_value_user;         // to check the overall value deducted from the user;
w:
if(amount==0){
    cout<<"The sending account does not have any money "<<endl<<endl;
    return;
}
cout<<" please enter the amount to be transferred : ";
cin>>transfer_value;
 if((!cin)||(cin.peek()!='\n')){ cout<<"Error, as the transfer value contain symbol!!.... try again"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
        goto w;}
if(transfer_value<=0)
{
    cout<<"The transfer value must be greater than 0 !!! .. try again "<<endl;
    goto w;
}
  transfer_value_user=transfer_value+0.015*transfer_value;
  if(transfer_value_user>amount)
{
    cout<<"The transfer value + its taxes are bigger than the amount of sending account"<<endl;
    cout<<"\t 1........ return to main menu"<<endl<<"\t 2........ continue the operation"<<endl;
    cout<<"Enter your choice : "; cin>>error_option;
    switch(error_option){
         case(1): return;
         case(2): goto w;
        default:{ cout<<"Invalid choice "<<endl; return; }       }
}
amount-=transfer_value_user;
user.amount+=transfer_value-0.015*transfer_value;
cout<<"Sending account : "<<endl;
print_acc_data();
cout<<"receiving account : "<<endl;
user.print_acc_data();
}
void ATM :: print_acc_data(){
cout<<"Name : ";
cout<<acc_name;
cout<<endl;
cout<<"Card number : ";
for(int i=0;i<10;i++)
cout<<card_no[i];
cout<<endl;
cout<<"Amount : "<<amount<<endl;
}
void ATM :: get_card(int tempo[10]){
    for(int i=0;i<10;i++)
        tempo[i]=card_no[i];
}
void insert_card_no(int code[10],int option){     // to obtain the code from the user
k:
    switch(option){
    case 2:cout<<"Please enter the account number(10 numbers each separated by space) : ";
    break;
    case 3:cout<<"Please enter the account number(10 numbers each separated by space) : ";
    break;
    case 4:{if(display%2==1)
    cout<<"please enter the number of the sending account(10 numbers each separated by space) : ";
    else
    cout<<"please enter the number of the receiving account(10 numbers each separated by space) : ";
    display++;
    }
    break;
    }
for(int i=0;i<10;i++)
    cin>>code[i];
for(int i=0;i<10;i++)
if(code[i]<0||code[i]>9){
  cout<<"Invalid input ,you should enter only one positive number at a space,please try again ......"<<endl<<endl;
        display--;
        goto k;
}
}
int user_search(ATM users[100],int temp[10]){      // to find the user whose code is the inserted in the previous function
int i,j;              // i is the order of the user in the data base
int code[10];         // temporary array holds the account number(tempo[10])
for(i=0;i<100;i++){
    users[i].get_card(code);
for(j=0;j<10;j++){
    if(code[j]==temp[j])
        continue;
    else break;
}

 if(j==10) return i;
}
return -1;
}
int main()
{   int code_num [10];
    int choice;
    int user_order1,user_order2,user_order;     //for any operation
   ATM user[100];
   int user_orderc=0;      //for creating new account function
   while(true)
   {
       cout<<"\t 1---- create new account "<<endl;
       cout<<"\t 2---- Deposit"<<endl;
       cout<<"\t 3---- withdrawal "<<endl;
       cout<<"\t 4---- transfer to another account "<<endl;
       cout<<"\t 5---- exit  "<<endl<<endl;
       cout<<"Please enter the number of operation : ";
   cin>>choice;
   if(!cin){cout<<" Invalid choice!! "<<endl;
    cin.clear();
    cin.ignore(256, '\n');            //clear all the residues in the buffer
   continue;}
   switch(choice)
   {
       case 1: { if(user_orderc==100){cout<<"You have exceeded your maximum limit of creating accounts"<<endl;
       continue;}
            e:
           user[user_orderc].create_new_acc(code_num); // user_orderc used to find memory in our database
           if(user_search(user,code_num)==user_orderc)
            user[user_orderc].print_acc_data();
           else{
            cout<<"This code was already taken,please try again......."<<endl<<endl;
            goto e;
           }
       user_orderc++;}
       break;
       case 2:{ b:
           insert_card_no(code_num,choice); // user_order to navigate across the data base to perform any task
       if(user_search(user,code_num)!=-1)
       user_order=user_search(user,code_num);
       else { cout<<"This account doesn't exist,try again....."<<endl;
       goto b;}
       user[user_order].deposit(); }
       break;
       case 3:{ u:
           insert_card_no(code_num,choice);
        if(user_search(user,code_num)!=-1)
        user_order=user_search(user,code_num);
       else { cout<<"This account doesn't exist,try again......"<<endl;
       goto u;}
       user[user_order].withdrawal(); }
       break;
       case 4:{int navigate;
       r:
           insert_card_no(code_num,choice);
        if(user_search(user,code_num)!=-1){
       user_order1=user_search(user,code_num);}
       else { cout<<"This account doesn't exist,try again"<<endl;
       display--;
       goto r;}
       insert_card_no(code_num,choice);
        if(user_search(user,code_num)!=-1){
       user_order2=user_search(user,code_num);}
       else { cout<<"This account doesn't exist,try again"<<endl;
       display--;
       goto r;}
       if(user_order1==user_order2){cout<<"Error,You're transferring to yourself !!!....try again"<<endl;
       cout<<"\t 1........ return to main menu"<<endl<<"\t 2........ continue the operation"<<endl;
    cout<<"Enter your choice : "; cin>>navigate;
    switch(navigate){
         case(1): continue;
         case(2): goto r;
        default: cout<<"Invalid choice "<<endl;
       }
       }
       user[user_order1].transfer(user[user_order2]);
       }
       break;
       case 5: return 0;
       default: cout<<" Invalid choice!! "<<endl;
   }
   }
 }
