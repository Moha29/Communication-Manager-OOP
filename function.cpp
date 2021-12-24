#include "header.h"


//This program purpose is to help the user set up 3 different communication application, as many accounts as needed. The user will also be able to send messages through each account.


//Constructor
account::account(){

}

//Destructor
account::~account(){

}

//Constructor
msg::msg():title(NULL),body(NULL){

}

//Setting new object
msg::msg(char *title1, char *body1){
    title = new char [strlen(title1)+1];
    strcpy(title,title1);
    body = new char [strlen(body1)+1];
    strcpy(body,body1);

}

//Copy constructor
msg::msg(const msg & source){
    title = new char [strlen(source.title)+1];
    strcpy(title,source.title);
    body = new char [strlen(source.body)+1];
    strcpy(body,source.body);
}

//Destructor
msg::~msg(){
    if(title){
        delete title;
        title = NULL;
    }
    if(body){
        delete body;
        body = NULL;
    }
}

//Constructor
discord::discord():username(NULL){

}

//Setting new object
discord::discord(char * name){
    username = new char[strlen(name)+1];
    strcpy(username,name);

}
//Copy constructor
discord::discord(const discord & source){
    username = new char[strlen(source.username)+1];
    strcpy(username,source.username);
}

//Destructor
discord::~discord(){
    if(username){
        delete username;
        username = NULL;
    }
}
//Constructor
email::email():username(NULL),email_ad(NULL){

}

//Setting new object
email::email(char*name, char*email1){
    username = new char [strlen(name)+1];
    strcpy(username,name);
    email_ad = new char[strlen(email1)+1];
    strcpy(email_ad,email1);
}
//Copy constructor
email::email(const email & source){
    username = new char [strlen(source.username)+1];
    strcpy(username,source.username);
    email_ad = new char[strlen(source.email_ad)+1];
    strcpy(email_ad,source.email_ad);
}
//Destructor
email::~email(){
    if(username){
        delete username;
        username = NULL;
    }
    if(email_ad){
        delete email_ad;
        email_ad = NULL;
    }

}
//Constructor
slack::slack():username(NULL),workspace(NULL){

}
//Setting new object
slack::slack(char * name,char *workspace1){
    username = new char[strlen(name)];
    strcpy(username,name);
    workspace = new char[strlen(workspace1)+1];
    strcpy(workspace,workspace1);
}
//Copy constructor
slack::slack(const slack & source){
    username = new char[strlen(source.username)];
    strcpy(username,source.username);
    workspace = new char[strlen(source.workspace)+1];
    strcpy(workspace,source.workspace);
}
//Destructor
slack::~slack(){
    if(username){
        delete username;
        username = NULL;
    }
    if(workspace){
        delete workspace;
        workspace = NULL;
    }
}

node2::node2():data(NULL),next(NULL){

}

//Setting data to pointer
node2::node2(msg * my_msg){
    data = new msg;
    data = my_msg;
}

node2::~node2(){
    if(data){
        delete data;
        data = NULL;
    }
    if(next){
        delete next;
        next = NULL;
    }
}

node::node():data(NULL),next(NULL){

}

//Setting account pointer
node::node(account * my_acc){
    data = my_acc;
}

node::~node(){
    if(data){
        delete data;
        data = NULL;
    }
    if(comm){
        delete comm;
        comm = NULL;
    }
    if(next){
        delete next;
        next = NULL;
    }
}

LLL::LLL():head(NULL){

}

LLL::~LLL(){
    if(head){
        delete head;
        head = NULL;
    }
}
