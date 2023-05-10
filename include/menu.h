//
// Created by Lenovo on 2023/4/28.
//

#ifndef C__CLASSDESIGN_MENU_H
#define C__CLASSDESIGN_MENU_H

#include "tlist.h"
#include "Teacher.h"

class menu{
public:

    static int DisplayTeaMenu();

    static int DisplayStuMenu();

    static int DisplayWelcome();

    static int LoginTeacher(TList<Teacher> tea);

    static int Stu2Topic_Teacher();

    static int Topic2Stu_Teacher();

    static int Match_Teacher();

    static int LoginStudent(TList<Student> list);
};

#endif //C__CLASSDESIGN_MENU_H
