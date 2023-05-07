//
// Created by Lenovo on 2023/4/27.
//

#ifndef C__CLASSDESIGN_TEACHER_H
#define C__CLASSDESIGN_TEACHER_H
#include <string>
#include "Topic.h"
#include "student.h"
#include "tlist.h"

class Teacher{
private:
    std::string id;
    std::string password;
    std::string defaultstupasswd;
    int Class;
    bool registered;//是否登陆过 登陆过为0
public:
    TList<Topic> topics;
    TList<Student> stu;
    Teacher(std::string id, std::string password, int Class);
    Teacher();
    std::string Getid();
    std::string Getpassword();
    int GetClass();
    friend std::istream& operator>> (std::istream& in, Teacher& x);
    friend std::ostream& operator<< (std::ostream& out, Teacher& x);
};
#endif //C__CLASSDESIGN_TEACHER_H
