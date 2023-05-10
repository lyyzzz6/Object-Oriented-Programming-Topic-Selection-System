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
    in >> x.Id >> x.Class >> x.Password >> x.DefaultStuPassword >> x.registered;
    return in;
}

std::ostream &operator<<(std::ostream &out, Teacher &x) {
    if(typeid(out) == typeid(std::cout)) {
        out << "Id: " << x.Id << "class: " << x.Class;
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

Teacher::Teacher() = default;
