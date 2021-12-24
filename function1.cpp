#include "header.h"

//This program purpose is to help the user set up 3 different communication application, as many accounts as needed. The user will also be able to send messages through each account.

void discord::RTTI(){
  cout<<"\nYou have used RTTI!\n";
}


//Virtual 
void account::display(){

}

//Display 
void msg::display(){
  cout<<"\nTitle: "<<title<<"\nMessage: "<<body;
}

void discord::display(){
  cout<<"\n(Discord)\nAccount: "<<username;
}

void email::display(){
  cout<<"\n(Email)\nAccount: "<<username<<"\nEmail Address: "<<email_ad;
}

void slack::display(){
  cout<<"\n(Slack)\nAccount: "<<username<<"\nWorkspace: "<<workspace;
}

//getting data to compare
char * msg::return_title(){
  return title;
}
char * account::return_name(){
  return NULL;
}

char * discord::return_name(){
  return username;
}

char * email::return_name(){
  return username;
}

char * slack::return_name(){
  return username;
}

//getting the next pointer
node *& node::get_next(){
  return next;
}

//setting next pointer
void node::set_next(node * new_next){
  next = new_next;
}

//Call the display functions
void node::display_node(){
  data->display();
}

//Getting data to compare
char * node::get_name(){
  return data -> return_name();
}

char * node2::get_title(){
  return data -> return_title();
}

//getting next pointer
node2 *& node2::get_next2(){
  return next;
}

//Setting next pointer
void node2::set_next2(node2 * new_next){
  next = new_next;
}

//display function
void node2::display_node2(){
  data->display();
}
