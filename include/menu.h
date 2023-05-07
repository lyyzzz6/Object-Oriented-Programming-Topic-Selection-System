//
// Created by Lenovo on 2023/4/28.
//

#ifndef C__CLASSDESIGN_MENU_H
#define C__CLASSDESIGN_MENU_H

#include "tlist.h"
#include "Teacher.h"

class menu{
public:

    static int displayteamenu();

    static int displaystumenu();

    void displaylogin();

    static int displaywelcome();

    static int loginteacher(TList<Teacher> tea);

    static int stu2topic_Teacher();

    static int menu2stu_Teacher();

    static int match_Teacher();

    static int loginstudent(TList<Student> list);
};

#endif //C__CLASSDESIGN_MENU_H
