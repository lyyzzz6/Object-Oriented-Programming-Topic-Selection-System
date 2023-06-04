//
// Created by Lenovo on 2023/4/27.
//

#ifndef C__CLASSDESIGN_STUDENT_H
#define C__CLASSDESIGN_STUDENT_H
#include <string>
#include <iostream>
#include "listnode.h"

class Student {
private:
    std::string Name;
    std::string Id;
    std::string Password;
    int Class;
    int ChosenTopicId; //已选中的题目id 未选中为0
    int ChangeNum; //可供抽取选题的次数

public:
    Student();
    
    Student (std::string name,std::string id,std::string password ,int Class);

    [[nodiscard]] std::string GetId() const;

    void SetId(std::string id);

    [[nodiscard]] std::string GetName () const;

    void SetName(std::string name);

    [[nodiscard]] std::string GetPassword () const;

    void SetPassword (const std::string& password);

    void SetClass(int Class);

    void ChangeChosenTopicId (int TopicId);

    void DeclineChangeNum ();

    friend std::ostream& operator<< (std::ostream& out, Student& x);

    friend std::istream& operator>> (std::istream& in, Student& x);

    void SetTopicId(int i);

    [[nodiscard]] int GetChangeNum() const;

    [[nodiscard]] int GetTopicId() const;

    void SetChangeNum(int i);
};

#endif //C__CLASSDESIGN_STUDENT_H

