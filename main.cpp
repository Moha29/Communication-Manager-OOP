#include "header.h"
//This program purpose is to help the user set up 3 different communication application, as many accounts as needed. The user will also be able to send messages through each account.

int main() {
  
  char name[MAX];//Staticallt allocated arrays to set up the classes object
  char email1[MAX]; 
  char workspace1[MAX];
  char title1[MAX];
  char body1[MAX];
  LLL my_LLL; //LLL class object
  int choice = 0; //user choice from the menu
  int acc = 0; //user's choice of account

  //Welcoming the user
  cout<<"Welcome! In this program you will be able to manage three different type of communication applications. You will be able to access:\n1)Discord.\n2)Email.\n3)Slack\n ";
  while(choice < 6){
    //Displaying menu
    cout<<"\n\nMENU\n1)Enter a new account.\n2)Send a message.\n3)Read a message.\n4)Remove a message.\n5)Display accounts.\n";
    cout<<"What do you want to do: ";
    cin>>choice;
    cin.ignore(100,'\n');

    if(choice == 1){//Enter a new account
      cout<<"\nWhat type of account to you want to enter:\n1)Discord\n2)Email\n3)Slack.\nPlease don't enter the same name twice.\nWhat type of account: ";
      cin>>acc;
      cin.ignore(100,'\n');
      if(acc==1){ //Discord
        cout<<"\nEnter the account username: ";
        cin.get(name,MAX,'\n');
        cin.ignore(100,'\n');
        discord * my_discord;
         my_discord = new discord(name); //setting a new object
        account * my_acc = my_discord; //Setting the account pointer to the object address
        my_LLL.add_wrapper(my_acc); //adding it to the list
        discord * d_ptr = dynamic_cast <discord*> (my_acc);
        if(d_ptr)
          d_ptr -> RTTI();

      }
      if(acc == 2){ //email
        cout<<"\nEnter the account name: ";
        cin.get(name,MAX,'\n');
        cin.ignore(100,'\n');
        cout<<"\nEnter the email address: ";
        cin.get(email1,MAX,'\n');
        cin.ignore(100,'\n');
        //calll email function
        email * my_email;
        my_email = new email(name,email1); //setting a new object
        account * my_acc = my_email;//Setting the account pointer to the object address
        my_LLL.add_wrapper(my_acc);//adding it to the list

      }
      if(acc == 3){
        cout<<"\nEnter the account username: ";
        cin.get(name,MAX,'\n');
        cin.ignore(100,'\n');
        cout<<"\nEnter the name of the workspace: ";
        cin.get(workspace1,MAX,'\n');
        cin.ignore(100,'\n');
    
        slack * my_slack;
        my_slack = new slack(name,workspace1);//setting a new object
        account * my_acc = my_slack;//Setting the account pointer to the object address
        my_LLL.add_wrapper(my_acc);//adding it to the list
      }
    }
    if(choice == 2){//Send a message
      //display all for the user to choose account
      my_LLL.display_wrapper(); 

      cout<<"\nWhich account do you want to send a message from: ";
      cin.get(name,MAX,'\n');
      cin.ignore(100,'\n');

      cout<<"\nEnter the title of the message: ";
      cin.get(title1,MAX,'\n');
      cin.ignore(100,'\n');

      cout<<"\nEnter the message: ";
      cin.get(body1,MAX,'\n');
      cin.ignore(100,'\n');

      msg * my_msg;
      my_msg = new msg(title1,body1);//creating msg class object
      my_LLL.add_new_message_wrapper(my_msg, name); //adding new message to the inner list

    }
    if(choice ==3){//read a message
      //Display accounts
      my_LLL.display_wrapper();
      cout<<"\nWhat is the name of the account you want to read the messages for: ";
      cin.get(name,MAX,'\n');
      cin.ignore(100,'\n');
      my_LLL.display_message_wrapper(name);
      
    }
    if(choice == 4){//remove a message
      //display all accounts
      my_LLL.display_wrapper();
      cout<<"\nWhat is the name of the account you want to delete a message from: ";
      cin.get(name,MAX,'\n');
      cin.ignore(100,'\n');
      my_LLL.display_message_wrapper(name);//Display the messages for a certain account
      
      cout<<"\nEnter the title of the message you want you want to delete: ";
      cin.get(title1,MAX,'\n');
      cin.ignore(100,'\n');
      //call remove message
      my_LLL.remove_wrapper(name,title1);

    }
    if(choice == 5){//Display accounts
      my_LLL.display_wrapper();
    }
  }

  return 0;
}
