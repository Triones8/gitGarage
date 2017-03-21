//
//  Book.cpp
//  MySystemLibrary
//
//  Created by cbox on 2017/3/13.
//  Copyright © 2017年 cbox. All rights reserved.
//

#include "Book.hpp"


vector<Book> BOOK;
map <string,int> PublishingToNum;//出版社对应的ISBN
map <string,int> BookNameToNum;//书名对应的ISBN
map <string,int> BookCntToNum;//这一本书的第几本
int PublishingCnt=0;//出版社数量
int BookNum=0;//图书数量

Book::Book(string name,string writer,string publishing_house,string introduction,string entry_date,vector <string> labels):name(name),writer(writer),publishing_house(publishing_house),introduction(introduction),entry_date(entry_date),labels(labels){
    if(PublishingToNum[publishing_house]==0){
        PublishingToNum[publishing_house]=++PublishingCnt;
        ISBN=to_string(PublishingCnt)+'-';
    }else{
        ISBN=to_string(PublishingToNum[publishing_house])+'-';
    }
    if(BookNameToNum[name]==0){
        BookNameToNum[name]=++BookNum;
        ISBN=ISBN+to_string(BookNum)+'-';
    }else{
        ISBN=ISBN+to_string(BookNameToNum[name])+'-';
    }
    int ok=0;
    for(int i=(int)BOOK.size()-1;i>=0;i--){
        if(BOOK[i].name==name&&BOOK[i].publishing_house==publishing_house){
            no=BOOK[i].no+1;
            ok=1;
            break;
        }
    }
    if(ok){
        ISBN=ISBN+to_string(no);
    }else{
        ISBN=ISBN+'1';
    }
}
