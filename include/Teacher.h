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
    std::string Id;
    std::string Password;
    std::string DefaultStuPassword;
    int Class;
    bool registered;//是否登陆过 登陆过为0
public:
    Teacher(std::string id, std::string password, int Class);

    Teacher();

    std::string GetId();

    std::string GetPassword();

    int GetClass() const;

    friend std::istream& operator>> (std::istream& in, Teacher& x);

    friend std::ostream& operator<< (std::ostream& out, Teacher& x);

    void SetPassword(std::string psw);

    void SetId(std::string i);
};
#endif //C__CLASSDESIGN_TEACHER_H
