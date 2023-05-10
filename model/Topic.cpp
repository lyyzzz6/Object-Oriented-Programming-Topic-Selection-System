//
// Created by Lenovo on 2023/4/27.
//

#include <utility>
#include <string>
#include <iostream>
#include "../include/Topic.h"

Topic::Topic() = default;

std::string Topic::GetTitle() const {
    return Title;
}

int Topic::GetId() const {
    return Id;
}

void Topic::SetId(int i) {
    (*this).Id = i;
}

void Topic::SetTitle(std::string t) {
    Title = std::move(t);
}

void Topic::SetTime(int y, int m, int d, int h, int min) {
    Year = y;
    Month = m;
    Day = d;
    Hour = h;
    Minute = min;
}

std::istream &operator>>(std::istream &in, Topic &x) {
    if(typeid(in) == typeid(std::cin)){
        std::cout << "请输入题目编号 ";std::cin >> x.Id;
        std::cout << "请输入题目标题 ";std::cin >> x.Title;
        std::cout << "请输入题目描述（请以逗号句号为中断，结束请按回车）";std::cin >> x.Description;
        std::cout << "请输入题目完成时间（以y m d h m为格式，空格分开不同数据）";
        std::cin >> x.Year >> x.Month >> x.Day >> x.Hour >> x.Minute;
        x.StudentId = "0";
    }else{
        in >> x.Class >> x.Id >> x.Title >> x.Description >> x.StudentId;
        in >> x.Year >> x.Month >> x.Day >> x.Hour >> x.Minute;
    }
    return in;
}

std::ostream &operator<<(std::ostream& out, Topic &x) {
    if(typeid(out)==typeid(std::cout)) {
        out << "编号: " << x.Id << " 名称: " << x.Title << std::endl;
        out << "任务要求: " << x.Description << std::endl;
        out << "被选择学生编号: " << x.StudentId << std::endl;
        out << "完成时间: " << x.Year << ":" << x.Month << ":" << x.Day << " " << x.Hour << ":" << x.Minute << std::endl;
    }else{
        out << x.Class << " " << x.Id << " " << x.Title << " " << x.Description << " " << x.StudentId << " ";
        out << x.Year << " " << x.Month << " " << x.Day << " " << x.Hour << " " << x.Minute;
    }
}

void Topic::SetStuId(std::string s) {
    StudentId = s;
}

std::string Topic::GetStudentId() {
    return StudentId;
}

std::string Topic::GetDescription() {
    return Description;
}

void Topic::GetTime() const{
    std::cout << Year << ":" << Month << ":" << Day << " " << Hour << ":" << Minute << std::endl;
}