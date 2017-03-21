//
//  Users.cpp
//  MySystemLibrary
//
//  Created by cbox on 2017/3/13.
//  Copyright © 2017年 cbox. All rights reserved.
//

#include "Users.hpp"
class PublicUsers;
class Administrator;
//现在的时间
Date DATE;
vector <PublicUsers> USERS;
vector <Administrator> ADMINISTRATOR;
extern vector <Book> BOOK;
int Logined=0;
PublicUsers *CurrentPublicUsers=new PublicUsers();
Administrator *CurrentAdministrator=new Administrator();

//从文件中读取用户信息
int LoadPublicUsers(){
    ifstream InPublicUsers("/Users/cbox/cbox/LibrarySystem/MySystemLibrary/Documents/PublicUsers.txt");
    if(!InPublicUsers.is_open()){
        return 1;
    }
    while(!InPublicUsers.eof()){
        PublicUsers temp;
        temp.read(InPublicUsers);
        USERS.push_back(temp);
    }
    return 0;
}

//从文件中读取管理员信息
int LoadAdministrator(){
    ifstream InAdministrator("/Users/cbox/cbox/LibrarySystem/MySystemLibrary/Documents/Administrator.txt");
    if(!InAdministrator.is_open()){
        return 1;
    }
    while(!InAdministrator.eof()){
        Administrator temp;
        temp.read(InAdministrator);
        ADMINISTRATOR.push_back(temp);
    }
    return 0;
}
//输出用户信息到文件
int PrintPublicUsers(){
    ofstream OutPublicUsers("/Users/cbox/cbox/LibrarySystem/MySystemLibrary/Documents/PublicUsers.txt");
    if(!OutPublicUsers.is_open())
        return 1;
    for(int i=0;i<USERS.size();i++){
        USERS[i].write(OutPublicUsers);
    }
    return 0;
}
//输出管理员信息到文件
int PrintAdministrator(){
    ofstream OutAdministrator("/Users/cbox/cbox/LibrarySystem/MySystemLibrary/Documents/Administrator.txt");
    if(!OutAdministrator.is_open()){
        return 1;
    }
    for(int i=0;i<ADMINISTRATOR.size();i++){
        ADMINISTRATOR[i].write(OutAdministrator);
    }
    return 0;
}

//注册普通账户
void RegisterPublicUsers(bool is_teacher,string name,string idnum,string password,string password_question,string password_answer,string academy){
    if(is_teacher)
        USERS.push_back(PublicUsers(name,idnum,password,password_question,password_answer,true,academy,10,45));
    else
        USERS.push_back(PublicUsers(name,idnum,password,password_question,password_answer,false,academy,5,30));
}

//注册管理员账户
void RegisterAdministrator(string name,string idnum,string password,string password_question,string password_answer){
    ADMINISTRATOR.push_back(Administrator(name,idnum,password,password_question,password_answer));
}



//登录账号
bool login(string ID,string password){
    for(int i=0;i<USERS.size();i++){
        if(USERS[i].get_name()==ID||USERS[i].get_idnum()==ID){
            if(password!=USERS[i].get_password()){
                break;
            }
            CurrentPublicUsers=&USERS[i];
            Logined=1;
            break;
        }
    }
    if(Logined)
        return true;
    for(int i=0;i<ADMINISTRATOR.size();i++){
        if(ADMINISTRATOR[i].get_name()==ID||ADMINISTRATOR[i].get_idnum()==ID){
            if(password!=USERS[i].get_password()){
                break;
            }
            CurrentAdministrator=&ADMINISTRATOR[i];
            Logined=2;
            break;
        }
    }
    if(!Logined)
        return false;
    return true;
}

//登出当前账户
void logout(){
    if(Logined==1){
        CurrentPublicUsers=nullptr;
    }else if(Logined==2){
        CurrentAdministrator=nullptr;
    }
    Logined=0;
}

//修改密码
int GetPassWordQuestion(string ID,string &PassWordQuestion){
    for(int i=0;i<USERS.size();i++){
        if(USERS[i].get_name()==ID||USERS[i].get_idnum()==ID){
            PassWordQuestion=USERS[i].get_password_question();
            return 0;
        }
    }
    for(int i=0;i<ADMINISTRATOR.size();i++){
        if(ADMINISTRATOR[i].get_name()==ID||ADMINISTRATOR[i].get_idnum()==ID){
            PassWordQuestion=ADMINISTRATOR[i].get_password_question();
            return 0;
        }
    }
    return 1;
}
//返回1代表密保答案不对，返回2代表没有找到这个用户
int ChangePassWord(string ID,string PassWordAnswer,string NewPassWord){
    for(int i=0;i<USERS.size();i++){
        if(USERS[i].get_name()==ID||USERS[i].get_idnum()==ID){
            if(PassWordAnswer!=USERS[i].get_password_answer())
                return 1;
            USERS[i].change_password(NewPassWord);
            return 0;
        }
    }
    for(int i=0;i<ADMINISTRATOR.size();i++){
        if(ADMINISTRATOR[i].get_name()==ID||ADMINISTRATOR[i].get_idnum()==ID){
            if(PassWordAnswer!=ADMINISTRATOR[i].get_password_answer())
                return 1;
            ADMINISTRATOR[i].change_password(NewPassWord);
            return 0;
        }
    }
    return 2;
}


//借阅图书,需要传入借阅人以及借阅图书的ISBN
int LenBook(PublicUsers &Users,string BookIsbn){
    //已经达到最大借书数量
    if(Users.get_book_num()==Users.get_max_book_line()){
        return 1;
    }
    for(int i=0;i<BOOK.size();i++){
        if(BOOK[i].getISBN()==BookIsbn){
            Users.do_lend_book(BookIsbn);
            BOOK[i].be_lended(DATE);
            return 0;
        }
    }
    return 0;
}
