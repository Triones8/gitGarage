//
//  DATA.h
//  MySystemLibrary
//
//  Created by cbox on 2017/3/13.
//  Copyright © 2017年 cbox. All rights reserved.
//

#ifndef DATA_h
#define DATA_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
using namespace std;

static int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
class Date {
public:
    string date;
    int mon, day;
    Date(){}
    Date(string s) {
        date = s;
        mon = (date[0] - '0') * 10 + (date[1] - '0');
        day = (date[2] - '0') * 10 + (date[1] - '0');
    }
    int operator-(const Date a) {
        int temp = month[a.mon] - a.day;
        for (int i = a.mon+1; i <= mon; i++) {
            if (i == mon)
                mon += day;
            else
                temp += month[i];
        }
        return temp;
    }
};

//图书类
class Book{
private:
    bool is_borrowed=false;//是否借出
    string name;//图书名字
    string ISBN;//图书编码
    int no=1;//同一本书的第几本
    string writer;//作者
    string publishing_house;//出版社
    string introduction;//简介
    Date entry_date;//录入日期
    Date borrow_date;//借出日期
    vector <string> labels;//标签
    vector <string> booking_user;//预约队列
    double lending_rates;//借阅率
    string picture_address;//书籍封面图片位置
public:
    Book() {}
    //Book的构造函数，自动生成ISBN
    Book(string name,string writer,string publishing_house,string introduction,string entry_date,vector <string> labels);
    bool get_is_borrowed(){return is_borrowed;}
    string get_name(){return name;}
    string get_isbn(){return ISBN;}
    string get_writer(){return writer;}
    string get_publishing_house(){return publishing_house;}
    string get_introduction(){return introduction;}
    //借阅本图书
    void be_lended(Date lend_date){
        borrow_date=lend_date;
    }
    string getISBN(){
        return this->ISBN;
    }
};

//头像类
class Avatar {
private:
    string pic_name;//图片名字
public:
    void get_avatar();
};

//用户基类
class User{
protected:
    string name;//名字
    string idnum;//工作证号
    string password;//密码
    string password_question;//密保问题
    string password_answer;//密保答案
    Avatar user_ava;//用户头像
public:
    User(){}
    User(string _name,string _idnum,string _password,string _password_question,string _password_answer):name(_name),idnum(_idnum),password(_password),password_question(_password_question),password_answer(_password_answer){}
    ifstream& user_read(ifstream &in){
        in>>this->name>>this->idnum>>this->password>>this->password_question>>this->password_answer;
        return in;
    }
    ofstream &user_write(ofstream &out){
        out<<name<<endl<<idnum<<endl<<password<<endl<<password_question<<endl<<password_answer<<endl;
        return out;
    }
    void change_password(string new_password){
        password=new_password;
    }
    string get_name(){return name;}
    string get_idnum(){return idnum;}
    string get_password(){return password;}
    string get_password_question(){return password_question;}
    string get_password_answer(){return password_answer;}
    Avatar get_user_ava(){return user_ava;}
};


//学生以及老师类
class PublicUsers :public User{
private:
    bool is_teacher;//是否老师账户
    string academy;//学院
    int max_book_line;//借书数量
    int max_book_time;//每本书最长借书时间
    int book_num = 0;//已经借书数量
    int booking_num=0;//已预约数量
    int credit = 100;//信用额度
    int fine = 0;//罚款金额
    vector <string> lend_book;//已经借阅图书
    vector <string> booking_book;//已经预约图书
public:
    PublicUsers() {}
    PublicUsers(string _name,string _idnum,string _password,string _password_question,string _password_answer,bool _is_teacher,string _academy,int _max_book_line,int _max_book_time):User(_name,_idnum,_password,_password_question,_password_answer),is_teacher(_is_teacher),academy(_academy),max_book_line(_max_book_line),max_book_time(_max_book_line){}
    //读入用户信息
    ifstream& read(ifstream &in){
        user_read(in);
        in>>this->is_teacher>>this->academy>>this->max_book_line>>this->max_book_time>>this->book_num>>this->booking_num>>this->credit>>this->fine;
        for(int i=0;i<book_num;i++){
            string temp;
            in>>temp;
            this->lend_book.push_back(temp);
        }
        for(int i=0;i<booking_num;i++){
            string temp;
            in>>temp;
            this->booking_book.push_back(temp);
        }
        return in;
    }
    //输出用户信息
    ofstream& write(ofstream &out){
        user_write(out);
        out<<is_teacher<<endl<<academy<<endl<<max_book_line<<endl<<max_book_time<<endl<<book_num<<endl<<booking_num<<endl<<credit<<endl<<fine<<endl;
        for(int i=0;i<book_num;i++){
            out<<lend_book[i]<<endl;
        }
        for(int i=0;i<booking_num;i++){
            out<<booking_book[i]<<endl;
        }
        return out;
    }
    void do_lend_book(string p){
        lend_book.push_back(p);
    }
    bool get_is_teacher(){return is_teacher;}
    string get_academy(){return academy;}
    int get_book_num(){return book_num;}
    int get_booking_num(){return booking_num;}
    int get_max_book_line(){return max_book_line;}
    int get_max_book_time(){return max_book_time;}
    int get_credit(){return credit;}
    int get_fine(){return fine;}
};

//管理员类
class Administrator :public User {
public:
    Administrator(){}
    Administrator(string _name,string _idnum,string _password,string _password_question,string _password_answer):User(_name,_idnum,_password,_password_question,_password_answer){}
    ifstream& read(ifstream &in){
        user_read(in);
        return in;
    }
    ofstream& write(ofstream &out){
        user_write(out);
        return out;
    }
};





#endif /* DATA_h */
