#include "header.h"

//Mohamed AL-zadjali
//This program purpose is to help the user set up 3 different communication application, as many accounts as needed. The user will also be able to send messages through each account.

//Adding new account
void LLL::add_wrapper(account * my_acc){
  //If list was empty
  if(!head){
    head = new node(my_acc);
    head -> set_next(NULL);
    return;
  }

  add(my_acc,head);
}

void LLL::add(account * my_acc, node *& head){
  //Adding at the end
  if(!head){
    head = new node(my_acc);
    head -> set_next(NULL);
    return;
  }
  //Moving to the next pointer
  add(my_acc,head -> get_next());
}

//Adding a new message to the inner list
void LLL::add_new_message_wrapper(msg * my_msg, char * name){
//If list is empty
  if(!head)
    return;
  add_new_message(my_msg,name,head);
}
void LLL::add_new_message(msg * my_msg, char * name,node * head){
  if(!head){
    cout<<"\nNo match found!\n";
    return;
  }
  if(strcmp(head -> get_name(),name)==0){//Checking if the account the user entered exist
    head -> add_msg_wrapper(my_msg);//Call the node function to add to the inner list
    return;
  }
  return add_new_message(my_msg,name,head -> get_next());

}

//Display messages for a single account
void LLL::display_message_wrapper(char * name){
  if(!head)
    return;
  display_message(name,head);
}

void LLL::display_message(char * name, node * head){
  if(!head)
    return;
  if(strcmp(head->get_name(),name)==0){//Displaying for the account user entered
    head -> display_msg_wrapper();
  }
  return display_message(name,head->get_next());
}

//Displaying the accounts
void LLL::display_wrapper(){
  if(!head)
    return;
  displaylll(head);
}

void LLL::displaylll(node * head){
  if(!head)
    return;
  head -> display_node();
  return displaylll(head -> get_next()); 
}

//Removing a message

void LLL::remove_wrapper(char * name, char * title1){
  if(!head)
    return;
  remove(name,title1,head);
}

void LLL::remove(char * name,char * title1, node *& head){
  if(!head){
    cout<<"\nNo match found!\n";
    return;
  }
  if(strcmp(head->get_name(),name)==0){//Access the node that has the account name
    head -> remove_msg_wrapper(title1);//Accessing the inner list to access the message
  }
  return remove(name,title1,head->get_next());
}
