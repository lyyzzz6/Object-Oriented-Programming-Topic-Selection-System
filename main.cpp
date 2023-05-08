#include <iostream>
#include <filesystem>
#include <random>
#include "include/student.h"
#include "include/tlist.h"
#include "include/menu.h"
#include "include/file.h"
#include "include/Teacher.h"

namespace fs = std::filesystem;

void loadstudent(TList<Student> stu){
    fs::path test_file("../data/student");
    int x=1;
    fs::path temp=test_file;
    temp+=std::to_string(x);
    temp+=".txt";
    while(fs::exists(temp)){
        File file("../data/student",std::to_string(x),".txt");
        file.init(stu);
        temp=test_file;
        x++;
        temp+=std::to_string(x);
        temp+=".txt";
    }
}

void loadstudent(TList<Student>&stu, int c){
    File file("../data/student",std::to_string(c),".txt");
    file.init(stu);
}

void savestudent(TList<Student>&stu, int c){
    File file("../data/student",std::to_string(c),".txt");\
    file.change(stu);
}

void loadTopic(TList<Topic>&topic, int c){
    File file("../data/topic",std::to_string(c),".txt");
    file.init(topic);
}

void saveTopic(TList<Topic>&topic, int c){
    File file("../data/topic",std::to_string(c),".txt");
    file.change(topic);
}

void testlist(){
    TList<Student> stu;
    Student s1("lyz","2","1",2);
    Student s2("lyz1","1","2",2);
    auto *stu2 = new ListNode<Student>;
    stu2->SetAddress(s2);
    //测试无参 加节点
    stu.AddNode(stu2);
    auto *stu1 = new ListNode<Student>;
    stu1->SetAddress(s1);
    //测试有参 加节点
    stu.AddNode(stu1,1);
    stu.display();
    //测试删除尾节点
    stu.DeleteNode(2);
    stu.display();
}

void testdirectory(){
    TList<Teacher> tea;
    fs::path test_file("../data/teacher");
    int x=1;
    fs::path temp=test_file;
    temp+=std::to_string(x);
    temp+=".txt";
    while(fs::exists(temp)){
        File file("../data/teacher",std::to_string(x),".txt");
        file.init(tea);
        temp=test_file;
        x++;
        temp+=std::to_string(x);
        temp+=".txt";
    }
    tea.display();

}

void testfile(){
    File file("../data/teacher","1",".txt");
    TList<Teacher> tea;
    file.init(tea);
    auto *t = new ListNode<Teacher>;
    Teacher t1("123","123123",5);
    t->SetAddress(t1);
    tea.AddNode(t);
    file.change(tea);
    tea.display();
}

int main() {
    menu menu;
    int usertype = menu::displaywelcome();
    TList<Teacher> teachers;
    File file("../data/teacher", "1", ".txt");
    file.init(teachers);
    bool ex0 = false;
    while (!ex0) {
        switch (usertype) {
            case 1: {
                int index = menu::loginteacher(teachers);
                if(index == 0) break;
                if (index != 0) std::cout << "登陆成功！" << std::endl;
                TList<Student> stuList;
                loadstudent(stuList, teachers[index].GetAddress().GetClass());
                TList<Topic> topicList;
                loadTopic(topicList, teachers[index].GetAddress().GetClass());
                int operationtype = menu::displayteamenu();
                bool ex1 = false;
                while(!ex1){
                    switch (operationtype) {
                        case 1: {
                            int stu_opration_Teacher = menu::stu2topic_Teacher();
                            bool ex2= false;
                            while(!ex2){
                                switch (stu_opration_Teacher) {
                                    case 1: {
                                        Student stu;
                                        stu.SetClass(teachers[index].GetAddress().GetClass());
                                        std::cin >> stu;
                                        auto *temp = new ListNode<Student>;
                                        temp->SetAddress(stu);
                                        stuList.AddNode(temp);
                                        break;
                                    }
                                    case 2: {
                                        std::string stuid;
                                        std::cout << "请输入想删除学生账号" << std::endl;
                                        std::cin >> stuid;
                                        int stuindex = 0;
                                        for (int i = 1; i <= stuList.GetSize(); ++i) {
                                            if(stuList[i].GetAddress().GetId()==stuid) {
                                                stuindex = i;
                                                break;
                                            }
                                        }
                                        if(stuindex==0) {
                                            std::cout << "账号不存在！" << std::endl;
                                            break;
                                        }
                                        if(stuList[stuindex].GetAddress().GetTopicId()!=0){
                                            std::cout << "该学生已选择题目，需要取消和题目之间的关联才能删除，请问是否取消关联？[y/n]" << std::endl;
                                            std::string answer;std::cin >> answer;
                                            if(answer=="n") break;
                                            int topicid = stuList[stuindex].GetAddress().GetTopicId();
                                            for (int i = 1; i <= topicList.GetSize(); ++i) {
                                                if(topicList[i].GetAddress().GetId()==topicid) {
                                                    topicList[i].GetAddress().SetStuId("0");
                                                    break;
                                                }
                                            }
                                        }
                                        stuList.DeleteNode(stuindex);
                                        break;
                                    }
                                    case 3: {
                                        std::string stuid;
                                        std::cout << "请输入想修改学生账号" << std::endl;
                                        std::cin >> stuid;
                                        int stuindex = 0;
                                        for (int i = 1; i <= stuList.GetSize(); ++i) {
                                            if(stuList[i].GetAddress().GetId()==stuid) {
                                                stuindex = i;
                                                break;
                                            }
                                        }
                                        if(stuindex==0) {
                                            std::cout << "账号不存在！" << std::endl;
                                            break;
                                        }
                                        Student stu;
                                        std::cin >> stu;
                                        stu.SetClass(teachers[index].GetAddress().GetClass());
                                        stu.SetTopicId(stuList[stuindex].GetAddress().GetTopicId());
                                        stu.SetChangeNum(stuList[stuindex].GetAddress().GetChangeNum());
                                        auto *temp = new ListNode<Student>;
                                        int topicid = stuList[stuindex].GetAddress().GetTopicId();
                                        if(topicid!=0){
                                            for (int i = 1; i <= topicList.GetSize(); ++i) {
                                                if(topicList[i].GetAddress().GetId()==topicid){
                                                    topicList[i].GetAddress().SetStuId(stu.GetId());
                                                    break;
                                                }
                                            }
                                        }
                                        temp->SetAddress(stu);
                                        stuList.AddNode(temp, stuindex - 1);
                                        stuList.DeleteNode(stuindex+1);
                                        break;
                                    }
                                    case 4: {
                                        stuList.display();
                                        break;
                                    }
                                    case 5: {
                                        std::cout << "请输入学生的默认密码 " << std::endl;
                                        std::string psw;std::cin >> psw;std::cout << std::endl;
                                        for (int i = 1; i <= stuList.GetSize(); ++i) {
                                            stuList[i].GetAddress().SetPassword(psw);
                                        }
                                        std::cout << "设置成功！" << std::endl;
                                        break;
                                    }
                                    case 6:{
                                        ex2 = true;
                                    }
                                    default:;
                                }
                                if(!ex2) stu_opration_Teacher = menu::stu2topic_Teacher();
                            }
                            savestudent(stuList,teachers[index].GetAddress().GetClass());
                            saveTopic(topicList,teachers[index].GetAddress().GetClass());
                            break;
                        }
                        case 2: {
                            int topic_opration_Teacher = menu::menu2stu_Teacher();
                            bool ex2 = false;
                            while(!ex2){
                                switch (topic_opration_Teacher) {
                                    case 1: {
                                        Topic topic;
                                        std::cin >> topic;
                                        auto *temp = new ListNode<Topic>;
                                        temp->SetAddress(topic);
                                        topicList.AddNode(temp);
                                        break;
                                    }
                                    case 2: {
                                        int topicid;
                                        std::cout << "请输入想删除题目编号" << std::endl;
                                        std::cin >> topicid;
                                        int topicindex = 0;
                                        for (int i = 1; i <= topicList.GetSize(); ++i) {
                                            if(topicList[i].GetAddress().GetId()==topicid) {
                                                topicid = i;
                                                break;
                                            }
                                        }
                                        if(topicid==0) {
                                            std::cout << "账号不存在！" << std::endl;
                                            break;
                                        }
                                        if(topicList[topicindex].GetAddress().GetStudentId()!="0"){
                                            std::cout << "该题目已被学生选择，需要取消和学生之间的关联才能删除，请问是否取消关联？[y/n]" << std::endl;
                                            std::string answer;std::cin >> answer;
                                            if(answer=="n") break;
                                            std::string stuid = topicList[topicindex].GetAddress().GetStudentId();
                                            for (int i = 1; i <= stuList.GetSize(); ++i) {
                                                if(stuList[i].GetAddress().GetId()==stuid) {
                                                    stuList[i].GetAddress().SetTopicId(0);
                                                    break;
                                                }
                                            }
                                        }
                                        topicList.DeleteNode(topicindex);
                                        break;
                                    }
                                    case 3: {
                                        int topicid;
                                        std::cout << "请输入想修改题目编号 " << std::endl;
                                        std::cin >> topicid;
                                        int topicindex = 0;
                                        for (int i = 1; i <= topicList.GetSize(); ++i) {
                                            if(topicList[i].GetAddress().GetId()==topicid){
                                                topicindex = i;
                                                break;
                                            }
                                        }
                                        if(topicindex==0){
                                            std::cout << "题目编号不存在！" << std::endl;
                                            break;
                                        }
                                        Topic topic;
                                        std::cin >> topic;
                                        topic.SetStuId(topicList[topicindex].GetAddress().GetStudentId());
                                        if(topicList[topicindex].GetAddress().GetStudentId()!="0"){
                                            for (int i = 1; i <= stuList.GetSize(); ++i) {
                                                if(stuList[i].GetAddress().GetId()==topicList[topicindex].GetAddress().GetStudentId()){
                                                    stuList[i].GetAddress().SetTopicId(topic.GetId());
                                                    break;
                                                }
                                            }
                                        }
                                        auto *temp = new ListNode<Topic>;
                                        temp->SetAddress(topic);
                                        topicList.DeleteNode(topicindex);
                                        topicList.AddNode(temp, topicindex - 1);
                                        break;
                                    }
                                    case 4: {
                                        topicList.display();
                                        break;
                                    }
                                    case 5: {
                                        ex2 = true;
                                        break;
                                    }
                                    default: {
                                        std::cout << "输入有误，请重新输入" << std::endl;
                                        std::cout << ">";
                                    }
                                }
                                if(!ex2) topic_opration_Teacher = menu::menu2stu_Teacher();
                            }
                            savestudent(stuList,teachers[index].GetAddress().GetClass());
                            saveTopic(topicList,teachers[index].GetAddress().GetClass());
                            break;
                        }
                        case 3:{
                            int match_operation_Teacher = menu::match_Teacher();
                            bool ex2 = false;
                            while(!ex2){
                                switch(match_operation_Teacher){
                                    case 1:{
                                        std::cout << "下面是您的全部学生: " << std::endl;
                                        stuList.display();
                                        std::cout<< "下面是您的全部题目: " << std::endl;
                                        topicList.display();
                                        bool match_stu_topic = true;
                                        while(match_stu_topic){
                                            std::cout << "请输入您想分配学生的编号: " << std::endl;
                                            std::string stuid;std::cin >> stuid;
                                            std::cout << "请输入您想分配的题目编号: " << std::endl;
                                            int topicid;std::cin >> topicid;
                                            for (int i = 0; i <= stuList.GetSize(); ++i) {
                                                if(stuList[i].GetAddress().GetId()==stuid){
                                                    stuList[i].GetAddress().SetTopicId(topicid);
                                                    break;
                                                }
                                            }
                                            for (int i = 0; i <= topicList.GetSize(); ++i) {
                                                if(topicList[i].GetAddress().GetId()==topicid){
                                                    topicList[i].GetAddress().SetStuId(stuid);
                                                    break;
                                                }
                                            }
                                            std::cout << "是否需要继续输入[y/n]" << std::endl;
                                            std::string answer;std::cin >> answer;
                                            if(answer=="n") match_stu_topic = false;
                                        }
                                        break;
                                    }
                                    case 2:{
                                        std::cout<< "下面是您的全部题目: " << std::endl;
                                        topicList.display();
                                        std::cout << "下面是您的全部学生: " << std::endl;
                                        stuList.display();
                                        bool match_stu_topic = true;
                                        while(match_stu_topic){
                                            std::cout << "请输入您想分配的题目编号: " << std::endl;
                                            int topicid;std::cin >> topicid;
                                            std::cout << "请输入您想分配学生的编号: " << std::endl;
                                            std::string stuid;std::cin >> stuid;
                                            for (int i = 0; i <= stuList.GetSize(); ++i) {
                                                if(stuList[i].GetAddress().GetId()==stuid){
                                                    stuList[i].GetAddress().SetTopicId(topicid);
                                                    break;
                                                }
                                            }
                                            for (int i = 0; i <= topicList.GetSize(); ++i) {
                                                if(topicList[i].GetAddress().GetId()==topicid){
                                                    topicList[i].GetAddress().SetStuId(stuid);
                                                    break;
                                                }
                                            }
                                            std::cout << "是否需要继续输入[y/n]" << std::endl;
                                            std::string answer;std::cin >> answer;
                                            if(answer=="n") match_stu_topic = false;
                                        }
                                        break;
                                    }
                                    case 3:{
                                        ex2 = true;
                                        break;
                                    }
                                    default:;
                                }
                                if(!ex2) match_operation_Teacher = menu::match_Teacher();
                            }
                            savestudent(stuList,teachers[index].GetAddress().GetClass());
                            saveTopic(topicList,teachers[index].GetAddress().GetClass());
                            break;
                        }
                        case 4:{
                            ex1 = true;
                            break;
                        }
                        default:;
                    }
                    if(!ex1) operationtype = menu::displayteamenu();
                }
                break;
            }
            case 2:{
                std::cout << "请输入你的班级编号: " << std::endl;
                int classid;std::cin >> classid;
                TList<Student> stuList;
                loadstudent(stuList,classid);
                TList<Topic> topicList;
                loadTopic(topicList,classid);
                int index = menu::loginstudent(stuList);
                if(index == 0) break;
                if (index != 0) std::cout << stuList[index].GetAddress().GetName() << "登陆成功！" << std::endl;
                int operationtype = menu::displaystumenu();
                bool ex1 = false;
                while(!ex1){
                    switch (operationtype){
                        case 1:{
                            int choice = stuList[index].GetAddress().GetChangeNum();
                            if(choice==0){
                                std::cout << "您的可刷新次数为0 无法进行再次选择" << std::endl;
                                break;
                            }
                            std::cout << "您的可刷新次数为" << choice << "次 是否进行选题[y/n]" << std::endl;
                            stuList[index].GetAddress().DeclineChangeNum();
                            std::string answer;std::cin >> answer;
                            if(answer=="y"){
                                if(stuList[index].GetAddress().GetTopicId()==0){
                                    std::cout << "您还未选择题目" << std::endl;
                                }else{
                                    std::cout << "您的已选择题目为" << stuList[index].GetAddress().GetTopicId() << std::endl;
                                }
                                std::default_random_engine e;
                                std::uniform_int_distribution<unsigned> u(1, topicList.GetSize());
                                int num = 0;int ed[3]={0};bool empty = true;
                                for (int i = 1; i <= topicList.GetSize(); ++i) {
                                    if(topicList[i].GetAddress().GetStudentId()=="0"){
                                        empty = false;
                                        break;
                                    }
                                }
                                while(num<3&&!empty){
                                    int i = u(e);
                                    if(topicList[i].GetAddress().GetStudentId()=="0"&&i!=ed[0]&&i!=ed[1]&&i!=ed[2]){
                                        std::cout << "编号: " << topicList[i].GetAddress().GetId() << " 名称: " << topicList[i].GetAddress().GetTitle() << std::endl;
                                        std::cout << "任务要求: " << topicList[i].GetAddress().GetDescription() << std::endl;
                                        std::cout << "完成时间: ";
                                        topicList[i].GetAddress().GetTime();
                                        ed[num]=i;
                                        num++;
                                    }
                                    empty = true;
                                    for (int j = 1; j < topicList.GetSize(); ++j) {
                                        if(topicList[j].GetAddress().GetStudentId()=="0"&&j!=ed[0]&&j!=ed[1]&&j!=ed[2]){
                                            empty = false;
                                            break;
                                        }
                                    }
                                }
                                std::cout << "请输入你要选择的题目编号 若都不想要 请输入-1"<< std::endl;int topicid;std::cin >> topicid;
                                while(topicid!=-1&&(topicid!=ed[0]&&ed[0]!=0)&&(topicid!=ed[1]&&ed[1]!=0)&&(topicid!=ed[2]&&ed[2]!=0)){
                                    std::cout << "输入错误 请重新输入";std::cin >> topicid;
                                }
                                if(topicid==-1){
                                    break;
                                }else{
                                    for (int i = 1; i <= topicList.GetSize(); ++i) {
                                        if(topicList[i].GetAddress().GetStudentId()==stuList[index].GetAddress().GetId()){
                                            topicList[i].GetAddress().SetStuId("0");
                                            break;
                                        }
                                    }
                                    stuList[index].GetAddress().SetTopicId(topicid);
                                    for (int i = 1; i <= topicList.GetSize(); ++i) {
                                        if(topicList[i].GetAddress().GetId()==topicid){
                                            topicList[i].GetAddress().SetStuId(stuList[index].GetAddress().GetId());
                                            break;
                                        }
                                    }
                                }
                            }else{
                                break;
                            }
                            break;
                        }
                        case 2:{
                            std::cout << "请输入原密码" << std::endl;
                            std::string psw;std::cin >> psw;
                            if(psw==stuList[index].GetAddress().GetPassword()){
                                std::cout << "请输入新密码" << std::endl;std::cin >> psw;
                                stuList[index].GetAddress().SetPassword(psw);
                                std::cout << "修改成功" << std::endl;
                            }else{
                                std::cout << "原密码错误" << std::endl;
                                break;
                            }
                            break;
                        }
                        case 3:{
                            int topicid = stuList[index].GetAddress().GetTopicId();int topicindex;
                            if(topicid==0){
                                std::cout << "您还未选择题目" << std::endl;
                                break;
                            }else{
                                for (int i = 1; i <= topicList.GetSize(); ++i) {
                                    if(topicList[i].GetAddress().GetId()==topicid){
                                        topicindex=i;
                                        break;
                                    }
                                }
                            }
                            std::cout << "您的已选择题目为";
                            std::cout << "编号: " << topicList[topicindex].GetAddress().GetId() << " 名称: " << topicList[topicindex].GetAddress().GetTitle() << std::endl;
                            std::cout << "任务要求: " << topicList[topicindex].GetAddress().GetDescription() << std::endl;
                            std::cout << "完成时间: ";
                            topicList[topicindex].GetAddress().GetTime();
                            break;
                        }
                        case 4:{
                            ex1 = true;
                            break;
                        }
                        default:;
                    }
                    if(!ex1) operationtype = menu::displaystumenu();
                    savestudent(stuList,classid);
                    saveTopic(topicList,classid);
                }
                break;
            }
            case 3:{
                ex0 = true;
            }
            default:;
            }
        if(!ex0) usertype = menu::displaywelcome();
    }
    file.change(teachers);
}