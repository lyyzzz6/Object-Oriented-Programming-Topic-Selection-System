//
// Created by Lenovo on 2023/4/27.
//

#include <utility>

#include "../include/Teacher.h"

Teacher::Teacher(std::string id, std::string password, int Class){
    (*this).id = std::move(id);
    (*this).password = std::move(password);
    (*this).Class = Class;
    registered = false;
    defaultstupasswd = "";
}

std::istream &operator>>(std::istream &in, Teacher &x) {
    in >> x.id >> x.Class >> x.password >> x.defaultstupasswd >> x.registered;
    return in;
}

std::ostream &operator<<(std::ostream &out, Teacher &x) {
    if(typeid(out) == typeid(std::cout)) {
        out << "id: " << x.id << "class: "<< x.Class;
    }else{
        out << x.id <<" "<< x.Class << " " << x.password << " " << x.defaultstupasswd << " " << x.registered;
    }
    return out;
}

std::string Teacher::Getid() {
    return id;
}

std::string Teacher::Getpassword() {
    return password;
}

int Teacher::GetClass() {
    return Class;
}

Teacher::Teacher() = default;
