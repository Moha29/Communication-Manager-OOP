#include "header.h"
//This program purpose is to help the user set up 3 different communication application, as many accounts as needed. The user will also be able to send messages through each account.


//Adding a new message to the inner list
void node::add_msg_wrapper(msg * my_msg){
  //If list is empty
  if(!comm){
    comm = new node2(my_msg);
    comm -> set_next2(NULL);
    return;
  }
  
  add_msg(my_msg,comm);
}

void node::add_msg(msg * my_msg, node2 *& comm){
  //Adding at the end
  if(!comm){
    comm = new node2(my_msg);
    comm -> set_next2(NULL);
    return;
  }
  add_msg(my_msg,comm -> get_next2());
}

//Displaying messages
void node::display_msg_wrapper(){
  if(!comm)
    return;
  display_msg(comm);
}

void node::display_msg(node2 * comm){
  if(!comm)
    return;
  comm -> display_node2(); //Calling node2 function to display data
  return display_msg(comm -> get_next2()); 
}

//removeing a message

void node::remove_msg_wrapper(char * title1){
  if(!comm)
    return;
  if(strcmp(comm -> get_title(),title1)==0 && !comm -> get_next2()){ //If the list had only one node
    delete comm;
    comm = NULL;
    return;
  }
  node2 * temp = comm;
  remove_msg(title1,comm,temp);
}

void node::remove_msg(char * title1, node2 *& comm, node2 *& temp ){
  if(!comm)
    return;
  if(strcmp(comm -> get_title(),title1)==0){ //If the title of the message matches the one the user entered
    if(!comm -> get_next2()){
      delete comm;
      comm = NULL;
      temp -> set_next2(NULL);
      return;
    }
    if(comm -> get_next2()){
      temp -> set_next2(comm->get_next2());
      delete comm;
      comm = NULL;
    }
  }
  temp = comm;
  remove_msg(title1,comm->get_next2(),temp);
}
