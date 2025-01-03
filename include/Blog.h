//
// Created by zhuyi on 2024/12/20.
//

#ifndef BLOG_H
#define BLOG_H

#include <iostream>
#include "Block.h"
#include "Book.h"
#include "Error.h"
#include "Finance.h"
#include "Tokenscanner.h"
#include "User.h"
#include "MemoryRiver.h"


class Information {
    friend class Blog;
private:
    char UserID[71] = {'\0'};
    char behave[200] = {'\0'};
    int level = 0;

public:
    Information() = default;
    explicit Information(const char* User_ID , const char* Behave , int Level ):level(Level) {
        strcpy(UserID, User_ID);
        strcpy(behave , Behave);
    }
};


class Blog {
    friend class Book;
    friend class User;
private:
    MemoryRiver<Information , 1> blog;
public:
    Blog();
    ~Blog() = default;

    int BlogCount();

    //读取员工工作报告
    void ReadWorker(User& UserManage);

    //读取全部信息
    void ReadAll(Finance& financeManage , User& UserManage);
};

#endif //BLOG_H
