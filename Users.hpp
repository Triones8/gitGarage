//
//  Users.hpp
//  MySystemLibrary
//
//  Created by cbox on 2017/3/13.
//  Copyright © 2017年 cbox. All rights reserved.
//

#ifndef Users_hpp
#define Users_hpp
#include "DATA.h"


//注册普通账户
void RegisterPublicUsers(bool is_teacher,string name,string idnum,string password,string password_question,string password_answer,string academy);
//注册管理员账户
void RegisterAdministrator(string name,string idnum,string password,string password_question,string password_answer);
//借阅图书,需要传入借阅人以及借阅图书的ISBN
int LendBook(PublicUsers &Users,string BookIsbn);
//从文件中读取用户信息
int LoadPublicUsers();
//从文件中读取管理员信息
int LoadAdministrator();
//输出用户信息到文件
int PrintPublicUsers();
//输出管理员信息到文件
int PrintAdministrator();
//修改密码,需要输入用户名或者学号，密保问题，密保答案，新密码
int ChangePassWord();
//登录账号
bool login(string ID,string password);
//登出当前账户
void logout();
//修改密码，通过ID返回密保答案
int GetPassWordQuestion(string ID,string &PassWordQuestion);
//返回1代表密保答案不对，返回2代表没有找到这个用户
int ChangePassWord(string ID,string PassWordAnswer,string NewPassWord);
#endif /* Users_hpp */
