//
// Created by Lenovo on 2023/4/28.
//
#include <iostream>
#include "../include/menu.h"
#include "../include/admin.h"

int menu::DisplayWelcome() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "欢迎使用面向对象程序设计选题系统" << std::endl;
    std::cout << "请选择登录身份" << std::endl;
    std::cout << "1: 教师" << std::endl;
    std::cout << "2: 学生" << std::endl;
    std::cout << "3: 管理员" << std::endl;
    std::cout << "4: 退出" << std::endl;
    std::cout << ">";
    std::string type;
    while(std::cin >> type) {
        if(type=="1"||type=="2"||type=="3"||type=="4") return std::stoi(type);
        else{
            std::cout << "输入有误，请重新输入" << std::endl;
            std::cout << ">";
        }
    }
}


int menu::LoginTeacher(TList<Teacher> tea) {
    std::cout << "请输入账号" << std::endl;
    std::string count;
    std::cin >> count;
    std::string psw;
    std::cout << "请输入密码" << std::endl;
    std::cin >> psw;
    int size = tea.GetSize();
    int index;
    bool found = false;
    for (int i = 1; i <= size; ++i) {
        if(tea[i].GetAddress().GetId() == count){
            index = i;
            found = true;
            break;
        }
    }
    if(found){
        if(tea[index].GetAddress().GetPassword() == psw){
            return index;
        }else{
            std::cout << "密码错误 请重新操作" << std::endl;
            return 0;
        }
    }else {
        std::cout << "账号错误 请重新操作" << std::endl;
        return 0;
    }
}

bool menu::LoginAdmin(){
    std::cout << "请输入账号" << std::endl;
    std::string account;
    std::cin >> account;
    std::string psw;
    std::cout << "请输入密码" << std::endl;
    std::cin >> psw;
    if(account == AdminAccount){
        if(psw == AdminPassword){
            return true;
        }else{
            std::cout << "密码错误 请重新操作" << std::endl;
            return false;
        }
    }else {
        std::cout << "账号错误 请重新操作" << std::endl;
        return false;
    }
}

int menu::DisplayTeaMenu() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "请选择您要执行的操作" << std::endl;
    std::cout << "1: 关于学生操作" << std::endl;
    std::cout << "2: 关于题目操作" << std::endl;
    std::cout << "3: 关于学生和题目匹配" << std::endl;
    std::cout << "4: 修改密码" << std::endl;
    std::cout << "5: 退出" << std::endl;
    std::string type;
    while(std::cin >> type) {
        if(type=="1"||type=="2"||type=="3"||type=="4"||type=="5") return std::stoi(type);
        else{
            std::cout << "输入有误，请重新输入" << std::endl;
            std::cout << ">";
        }
    }
}

int menu::Stu2Topic_Teacher() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "请选择您要执行的操作" << std::endl;
    std::cout << "1: 增加学生" << std::endl;
    std::cout << "2: 删除学生" << std::endl;
    std::cout << "3: 修改学生数据" << std::endl;
    std::cout << "4: 展示所有学生" << std::endl;
    std::cout << "5: 设置学生默认密码" << std::endl;
    std::cout << "6: 退出" << std::endl;
    std::string type;
    while(std::cin >> type) {
        if(type=="1"||type=="2"||type=="3"||type=="4"||type=="5"||type=="6") return std::stoi(type);
        else{
            std::cout << "输入有误，请重新输入" << std::endl;
            std::cout << ">";
        }
    }
}

int menu::Topic2Stu_Teacher() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "请选择您要执行的操作" << std::endl;
    std::cout << "1: 增加题目" << std::endl;
    std::cout << "2: 删除题目" << std::endl;
    std::cout << "3: 修改题目数据" << std::endl;
    std::cout << "4: 展示所有题目" << std::endl;
    std::cout << "5: 退出" << std::endl;
    std::string type;
    while(std::cin >> type) {
        if(type=="1"||type=="2"||type=="3"||type=="4"||type=="5") return std::stoi(type);
        else{
            std::cout << "输入有误，请重新输入" << std::endl;
            std::cout << ">";
        }
    }
}

int menu::Match_Teacher() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "请选择您要执行的操作" << std::endl;
    std::cout << "1: 为学生分配题目" << std::endl;
    std::cout << "2: 为题目分配学生" << std::endl;
    std::cout << "3: 自动分配题目给学生" << std::endl;
    std::cout << "4: 退出" << std::endl;
    std::string type;
    while(std::cin >> type) {
        if(type=="1"||type=="2"||type=="3"||type=="4") return std::stoi(type);
        else{
            std::cout << "输入有误，请重新输入" << std::endl;
            std::cout << ">";
        }
    }
}

int menu::DisplayStuMenu() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "请选择您要执行的操作" << std::endl;
    std::cout << "1: 选择题目" << std::endl;
    std::cout << "2: 修改密码" << std::endl;
    std::cout << "3: 查看已选择题目" << std::endl;
    std::cout << "4: 退出" << std::endl;
    std::string type;
    while(std::cin >> type) {
        if(type=="1"||type=="2"||type=="3"||type=="4") return std::stoi(type);
        else{
            std::cout << "输入有误，请重新输入" << std::endl;
            std::cout << ">";
        }
    }
}

int menu::LoginStudent(TList<Student> stu) {
    std::cout << "请输入账号" << std::endl;
    std::string count;
    std::cin >> count;
    std::string psw;
    std::cout << "请输入密码" << std::endl;
    std::cin >> psw;
    int size = stu.GetSize();
    int index;
    bool found = false;
    for (int i = 1; i <= size; ++i) {
        if(stu[i].GetAddress().GetId()==count){
            index = i;
            found = true;
            break;
        }
    }
    if(found){
        if(stu[index].GetAddress().GetPassword()==psw){
            return index;
        }else{
            std::cout << "密码错误 请重新操作" << std::endl;
            return 0;
        }
    }else {
        std::cout << "账号错误 请重新操作" << std::endl;
        return 0;
    }
}

int menu::DisplayAdminMenu() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "请选择您要执行的操作" << std::endl;
    std::cout << "1: 增加老师" << std::endl;
    std::cout << "2: 修改老师数据" << std::endl;
    std::cout << "3: 展示所有老师" << std::endl;
    std::cout << "4: 退出" << std::endl;
    std::string type;
    while(std::cin >> type) {
        if(type=="1"||type=="2"||type=="3"||type=="4") return std::stoi(type);
        else{
            std::cout << "输入有误，请重新输入" << std::endl;
            std::cout << ">";
        }
    }
}
