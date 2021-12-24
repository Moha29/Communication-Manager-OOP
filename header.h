#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


//This program purpose is to help the user set up 3 different communication application, as many accounts as needed. The user will also be able to send messages through each account.

//constant integer for the statically allocated arrays 
const int MAX = 100; 

//Abstract Base Class
class account{
    public:
      account();
      //virtual account(char *);
      //virtual account(const account &);
      virtual char * return_name();//Virtual functions for the derived classes
      virtual void display() = 0;
      virtual ~account();
      
    private:
      
};


//This class will hold the information of the communications done in each account
class msg {
    public:
      msg(); //Defult constructor
      msg(char *, char *); //Setting up an object
      msg(const msg &); //Copy constructor
      char * return_title(); //returning the title
      void display(); //display 
      ~msg(); //destructor
    private:
      char * title;
      char * body;
};

//type of communicatio apps
//Derived from account
class discord : public account{
    public:
      discord();
      discord(char *);
      discord(const discord &);
      void display();
      char * return_name();
      void RTTI();
      ~discord();
    private:
      char * username;
};
//type of communicatio apps
//Derived from account
class email : public account{
    public:
      email();
      email(char *, char *);
      email(const email &);
      void display();
      char * return_name();
      ~email();
    private:
      char * username;
      char * email_ad;

};
//type of communicatio apps
//Derived from account
class slack : public account{
    public:
      slack();
      slack(char*,char*);
      slack(const slack &);
      void display();
      char * return_name();
      ~slack();
    private:
    char * username;
    char * workspace;

};
//This node class will hold the messages information
class node2{
  public:
    node2();
    node2( msg *);
    node2 *& get_next2();
    void set_next2(node2 *);
    void display_node2();
    char *  get_title();
    
    ~node2();
  private:
    msg * data;
    node2 * next;
};

//This node class be act both a node and a LLL class.
//The node will hold the accounts
//The LLL will hold the messages
class node{
    public:
      node();
      node( account *);
      node *& get_next();
      void set_next(node *);
      void add_msg(msg *, node2*&);
      void add_msg_wrapper(msg *);
      void display_msg_wrapper();
      void display_msg(node2 * head);
      void display_node();
      char * get_name();
      void remove_msg(char * title1, node2 *& comm, node2 *& temp);
      void remove_msg_wrapper(char * title1);
      ~node();
    private:
        account * data;
        node * next;
        node2 * comm;
};

//LLL class to hold the accounts created in node
class LLL{
    public:
      LLL();
      void add_wrapper(account *);  //Adding new account
      void add(account *,node *& );
      void display_wrapper(); //Displaying account
      void displaylll(node * );
      void add_new_message_wrapper(msg *,char *); //Adding new message
      void add_new_message(msg*,char *,node *);
      void display_message_wrapper(char *); //Displaying the messages from an account
      void display_message(char *, node *);
      void remove_wrapper(char * name, char * title1); //Removing a message
      void remove(char * name, char * title1, node *& head);
      ~LLL();
    private:
        node * head;
};
