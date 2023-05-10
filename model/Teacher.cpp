//
// Created by Lenovo on 2023/4/27.
//

#include <utility>

#include "../include/Teacher.h"

Teacher::Teacher(std::string id, std::string password, int Class){
    (*this).Id = std::move(id);
    (*this).Password = std::move(password);
    (*this).Class = Class;
    registered = false;
    DefaultStuPassword = "";
}

std::istream &operator>>(std::istream &in, Teacher &x) {
    if(typeid(in) == typeid(std::cin)) {
        std::cout << "请输入老师班级";std::cin >> x.Class;
        std::cout << "请输入老师账号";std::cin >> x.Id;
        std::cout << "请输入老师密码";std::cin >> x.Password;
        x.registered = false;
        x.DefaultStuPassword = "0";
    }else{
        in >> x.Id >> x.Class >> x.Password >> x.DefaultStuPassword >> x.registered;
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, Teacher &x) {
    if(typeid(out) == typeid(std::cout)) {
        out << "账号: " << x.Id << " 密码: " << x.Password << " 班级: " << x.Class << std::endl;
    }else{
        out << x.Id << " " << x.Class << " " << x.Password << " " << x.DefaultStuPassword << " " << x.registered;
    }
    return out;
}

std::string Teacher::GetId() {
    return Id;
}

std::string Teacher::GetPassword() {
    return Password;
}

int Teacher::GetClass() const {
    return Class;
}

void Teacher::SetPassword(std::string psw) {
    Password = std::move(psw);
}

void Teacher::SetId(std::string i) {
    Id = std::move(i);
}

Teacher::Teacher() = default;
