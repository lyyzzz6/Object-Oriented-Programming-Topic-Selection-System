//
// Created by Lenovo on 2023/4/27.
//

#include <utility>
#include <string>
#include <iostream>
#include "../include/Topic.h"

Topic::Topic() = default;

std::string Topic::GetTitle() const {
    return title;
}

int Topic::GetId() const {
    return id;
}

void Topic::SetId(int i) {
    (*this).id = i;
}

void Topic::SetTitle(std::string t) {
    title = std::move(t);
}

void Topic::SetTime(int y, int m, int d, int h, int min) {
    year = y;
    month = m;
    day = d;
    hour = h;
    minute = min;
}

std::istream &operator>>(std::istream &in, Topic &x) {
    if(typeid(in) == typeid(std::cin)){
        std::cout << "请输入题目编号 ";std::cin >> x.id;
        std::cout << "请输入题目标题 ";std::cin >> x.title;
        std::cout << "请输入题目描述（请以逗号句号为中断，结束请按回车）";std::cin >> x.description;
        std::cout << "请输入题目完成时间（以y m d h m为格式，空格分开不同数据）";
        std::cin >> x.year >> x.month >> x.day >> x.hour >> x.minute;
        x.studentid = "0";
    }else{
        in >> x.Class >> x.id >> x.title >> x.description >> x.studentid;
        in >> x.year >> x.month >> x.day >> x.hour >> x.minute;
    }
    return in;
}

std::ostream &operator<<(std::ostream& out, Topic &x) {
    if(typeid(out)==typeid(std::cout)) {
        out << "编号: " << x.id << " 名称: " << x.title << std::endl;
        out << "任务要求: " << x.description << std::endl;
        out << "被选择学生编号: " << x.studentid << std::endl;
        out << "完成时间: " << x.year << ":" << x.month << ":" << x.day << " " << x.hour << ":" << x.minute << std::endl;
    }else{
        out << x.Class << " " << x.id << " " << x.title << " " << x.description << " " << x.studentid << " ";
        out << x.year << " " << x.month << " " << x.day << " " << x.hour << " " << x.minute;
    }
}

void Topic::SetStuId(std::string s) {
    studentid = s;
}

std::string Topic::GetStudentId() {
    return studentid;
}

std::string Topic::GetDescription() {
    return description;
}

void Topic::GetTime() const{
    std::cout << year << ":" << month << ":" << day << " " << hour << ":" << minute << std::endl;
}