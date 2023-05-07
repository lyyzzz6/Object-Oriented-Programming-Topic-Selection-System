//
// Created by Lenovo on 2023/4/27.
//

#include "../include/student.h"
#include <string>
#include <utility>

Student::Student (std::string name,std::string id,std::string password ,int Class) {
    (*this).name = std::move(name);
    (*this).id = std::move(id);
    (*this).password = std::move(password);
    (*this).Class = Class;
    ChosenTopicId = 0;
    ChangeNum = 3;
}

Student::Student() = default;

std::string Student::GetId() const{
    return id;
}

std::string Student::GetName () const{
    return name;
}

std::string Student::GetPassword () const{
    return password;
}

void Student::SetPassword(const std::string& psw) {
    (*this).password = psw;
}

void Student::ChangeChosenTopicId(int TopicId) {
    (*this).ChosenTopicId = TopicId;
}

void Student::DeclineChangeNum() {
    if(ChangeNum != 0) ChangeNum--;
}

std::ostream &operator<<(std::ostream &out, Student& x) {
    if(typeid(out) == typeid(std::cout)) {
        out << "账号: " << x.id << " ";
        out << "姓名: " << x.name << " ";
        out << "密码: " << x.password << " ";
        out << "选择题目编号: " << x.ChosenTopicId << " ";
        out << "可刷新次数: " << x.ChangeNum << std::endl;
    }else{
        out << " " << x.Class << " " << x.name << " " << x.id << " " << x.password;
        out << " " << x.ChosenTopicId << " " << x.ChangeNum;
    }
    return out;
}

void Student::SetId(std::string i) {
    (*this).id = std::move(i);
}

void Student::SetName(std::string n) {
    (*this).name = std::move(n);
}

std::istream &operator>>(std::istream &in, Student &x) {
    if(typeid(in) == typeid(std::cin)){
        std::cout << "请输入学生账号";std::cin >> x.id;
        std::cout << "请输入学生姓名";std::cin >> x.name;
        std::cout << "请输入学生密码";std::cin >> x.password;
        x.ChosenTopicId = 0;
        x.ChangeNum = 3;
    }else{
        in >> x.Class >> x.name >> x.id >> x.password;
        in >> x.ChosenTopicId >> x.ChangeNum;
    }
    return in;
}

void Student::SetClass(int C) {
    (*this).Class = C;
}

void Student::SetTopicId(int i) {
    (*this).ChosenTopicId = i;
}

int Student::GetChangeNum() const {
    return ChangeNum;
}

int Student::GetTopicId() const {
    return ChosenTopicId;
}








