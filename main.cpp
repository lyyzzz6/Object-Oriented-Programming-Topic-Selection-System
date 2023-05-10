#include <iostream>
#include <filesystem>
#include <random>
#include "include/student.h"
#include "include/tlist.h"
#include "include/menu.h"
#include "include/file.h"
#include "include/Teacher.h"

namespace fs = std::filesystem;

void LoadStudentMutiplyFile(TList<Student> stu){
    fs::path test_file("../data/student");
    int x=1;
    fs::path temp=test_file;
    temp+=std::to_string(x);
    temp+=".txt";
    while(fs::exists(temp)){
        File file("../data/student",std::to_string(x),".txt");
        file.Init(stu);
        temp=test_file;
        x++;
        temp+=std::to_string(x);
        temp+=".txt";
    }
}

void LoadStudent(TList<Student>&stu, int c){
    File file("../data/student",std::to_string(c),".txt");
    file.Init(stu);
}

void SaveStudent(TList<Student>&stu, int c){
    File file("../data/student",std::to_string(c),".txt");\
    file.Change(stu);
}

void LoadTopic(TList<Topic>&topic, int c){
    File file("../data/topic",std::to_string(c),".txt");
    file.Init(topic);
}

void SaveTopic(TList<Topic>&topic, int c){
    File file("../data/topic",std::to_string(c),".txt");
    file.Change(topic);
}

void TestList(){
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
    stu.Display();
    //测试删除尾节点
    stu.DeleteNode(2);
    stu.Display();
}

void TestDirectory(){
    TList<Teacher> tea;
    fs::path test_file("../data/teacher");
    int x=1;
    fs::path temp=test_file;
    temp+=std::to_string(x);
    temp+=".txt";
    while(fs::exists(temp)){
        File file("../data/teacher",std::to_string(x),".txt");
        file.Init(tea);
        temp=test_file;
        x++;
        temp+=std::to_string(x);
        temp+=".txt";
    }
    tea.Display();

}

void TestFile(){
    File file("../data/teacher","1",".txt");
    TList<Teacher> tea;
    file.Init(tea);
    auto *t = new ListNode<Teacher>;
    Teacher t1("123","123123",5);
    t->SetAddress(t1);
    tea.AddNode(t);
    file.Change(tea);
    tea.Display();
}

int main() {
    menu menu;
    int usertype = menu::DisplayWelcome();
    TList<Teacher> TeaList;
    File file("../data/teacher", "1", ".txt");
    file.Init(TeaList);
    bool ex0 = false;
    while (!ex0) {
        switch (usertype) {
            case 1: {
                int index = menu::LoginTeacher(TeaList);
                if(index == 0) break;
                if (index != 0) std::cout << "登陆成功！" << std::endl;
                TList<Student> StuList;
                LoadStudent(StuList, TeaList[index].GetAddress().GetClass());
                TList<Topic> TopicList;
                LoadTopic(TopicList, TeaList[index].GetAddress().GetClass());
                int OperationType = menu::DisplayTeaMenu();
                bool ex1 = false;
                while(!ex1){
                    switch (OperationType) {
                        case 1: {
                            int StuOperation_Teacher = menu::Stu2Topic_Teacher();
                            bool ex2= false;
                            while(!ex2){
                                switch (StuOperation_Teacher) {
                                    case 1: {
                                        Student stu;
                                        stu.SetClass(TeaList[index].GetAddress().GetClass());
                                        std::cin >> stu;
                                        auto *temp = new ListNode<Student>;
                                        temp->SetAddress(stu);
                                        StuList.AddNode(temp);
                                        break;
                                    }
                                    case 2: {
                                        std::string StuId;
                                        std::cout << "请输入想删除学生账号" << std::endl;
                                        std::cin >> StuId;
                                        int StuIndex = 0;
                                        for (int i = 1; i <= StuList.GetSize(); ++i) {
                                            if(StuList[i].GetAddress().GetId() == StuId) {
                                                StuIndex = i;
                                                break;
                                            }
                                        }
                                        if(StuIndex == 0) {
                                            std::cout << "账号不存在！" << std::endl;
                                            break;
                                        }
                                        if(StuList[StuIndex].GetAddress().GetTopicId() != 0){
                                            std::cout << "该学生已选择题目，需要取消和题目之间的关联才能删除，请问是否取消关联？[y/n]" << std::endl;
                                            std::string answer;std::cin >> answer;
                                            if(answer=="n") break;
                                            int TopicId = StuList[StuIndex].GetAddress().GetTopicId();
                                            for (int i = 1; i <= TopicList.GetSize(); ++i) {
                                                if(TopicList[i].GetAddress().GetId() == TopicId) {
                                                    TopicList[i].GetAddress().SetStuId("0");
                                                    break;
                                                }
                                            }
                                        }
                                        StuList.DeleteNode(StuIndex);
                                        break;
                                    }
                                    case 3: {
                                        std::string StuId;
                                        std::cout << "请输入想修改学生账号" << std::endl;
                                        std::cin >> StuId;
                                        int StuIndex = 0;
                                        for (int i = 1; i <= StuList.GetSize(); ++i) {
                                            if(StuList[i].GetAddress().GetId() == StuId) {
                                                StuIndex = i;
                                                break;
                                            }
                                        }
                                        if(StuIndex == 0) {
                                            std::cout << "账号不存在！" << std::endl;
                                            break;
                                        }
                                        Student stu;
                                        std::cin >> stu;
                                        stu.SetClass(TeaList[index].GetAddress().GetClass());
                                        stu.SetTopicId(StuList[StuIndex].GetAddress().GetTopicId());
                                        stu.SetChangeNum(StuList[StuIndex].GetAddress().GetChangeNum());
                                        auto *temp = new ListNode<Student>;
                                        int TopicId = StuList[StuIndex].GetAddress().GetTopicId();
                                        if(TopicId != 0){
                                            for (int i = 1; i <= TopicList.GetSize(); ++i) {
                                                if(TopicList[i].GetAddress().GetId() == TopicId){
                                                    TopicList[i].GetAddress().SetStuId(stu.GetId());
                                                    break;
                                                }
                                            }
                                        }
                                        temp->SetAddress(stu);
                                        StuList.AddNode(temp, StuIndex - 1);
                                        StuList.DeleteNode(StuIndex + 1);
                                        break;
                                    }
                                    case 4: {
                                        StuList.Display();
                                        break;
                                    }
                                    case 5: {
                                        std::cout << "请输入学生的默认密码 " << std::endl;
                                        std::string psw;std::cin >> psw;std::cout << std::endl;
                                        for (int i = 1; i <= StuList.GetSize(); ++i) {
                                            StuList[i].GetAddress().SetPassword(psw);
                                        }
                                        std::cout << "设置成功！" << std::endl;
                                        break;
                                    }
                                    case 6:{
                                        ex2 = true;
                                    }
                                    default:;
                                }
                                if(!ex2) StuOperation_Teacher = menu::Stu2Topic_Teacher();
                            }
                            SaveStudent(StuList, TeaList[index].GetAddress().GetClass());
                            SaveTopic(TopicList, TeaList[index].GetAddress().GetClass());
                            break;
                        }
                        case 2: {
                            int TopicOperation_Teacher = menu::Topic2Stu_Teacher();
                            bool ex2 = false;
                            while(!ex2){
                                switch (TopicOperation_Teacher) {
                                    case 1: {
                                        Topic topic;
                                        std::cin >> topic;
                                        auto *temp = new ListNode<Topic>;
                                        temp->SetAddress(topic);
                                        TopicList.AddNode(temp);
                                        break;
                                    }
                                    case 2: {
                                        int TopicId;
                                        std::cout << "请输入想删除题目编号" << std::endl;
                                        std::cin >> TopicId;
                                        int TopicIndex = 0;
                                        for (int i = 1; i <= TopicList.GetSize(); ++i) {
                                            if(TopicList[i].GetAddress().GetId() == TopicId) {
                                                TopicId = i;
                                                break;
                                            }
                                        }
                                        if(TopicId == 0) {
                                            std::cout << "账号不存在！" << std::endl;
                                            break;
                                        }
                                        if(TopicList[TopicIndex].GetAddress().GetStudentId() != "0"){
                                            std::cout << "该题目已被学生选择，需要取消和学生之间的关联才能删除，请问是否取消关联？[y/n]" << std::endl;
                                            std::string answer;std::cin >> answer;
                                            if(answer=="n") break;
                                            std::string StuId = TopicList[TopicIndex].GetAddress().GetStudentId();
                                            for (int i = 1; i <= StuList.GetSize(); ++i) {
                                                if(StuList[i].GetAddress().GetId() == StuId) {
                                                    StuList[i].GetAddress().SetTopicId(0);
                                                    break;
                                                }
                                            }
                                        }
                                        TopicList.DeleteNode(TopicIndex);
                                        break;
                                    }
                                    case 3: {
                                        int TopicId;
                                        std::cout << "请输入想修改题目编号 " << std::endl;
                                        std::cin >> TopicId;
                                        int TopicIndex = 0;
                                        for (int i = 1; i <= TopicList.GetSize(); ++i) {
                                            if(TopicList[i].GetAddress().GetId() == TopicId){
                                                TopicIndex = i;
                                                break;
                                            }
                                        }
                                        if(TopicIndex == 0){
                                            std::cout << "题目编号不存在！" << std::endl;
                                            break;
                                        }
                                        Topic topic;
                                        std::cin >> topic;
                                        topic.SetStuId(TopicList[TopicIndex].GetAddress().GetStudentId());
                                        if(TopicList[TopicIndex].GetAddress().GetStudentId() != "0"){
                                            for (int i = 1; i <= StuList.GetSize(); ++i) {
                                                if(StuList[i].GetAddress().GetId() == TopicList[TopicIndex].GetAddress().GetStudentId()){
                                                    StuList[i].GetAddress().SetTopicId(topic.GetId());
                                                    break;
                                                }
                                            }
                                        }
                                        auto *temp = new ListNode<Topic>;
                                        temp->SetAddress(topic);
                                        TopicList.DeleteNode(TopicIndex);
                                        TopicList.AddNode(temp, TopicIndex - 1);
                                        break;
                                    }
                                    case 4: {
                                        TopicList.Display();
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
                                if(!ex2) TopicOperation_Teacher = menu::Topic2Stu_Teacher();
                            }
                            SaveStudent(StuList, TeaList[index].GetAddress().GetClass());
                            SaveTopic(TopicList, TeaList[index].GetAddress().GetClass());
                            break;
                        }
                        case 3:{
                            int match_operation_Teacher = menu::Match_Teacher();
                            bool ex2 = false;
                            while(!ex2){
                                switch(match_operation_Teacher){
                                    case 1:{
                                        std::cout << "下面是您的全部学生: " << std::endl;
                                        StuList.Display();
                                        std::cout<< "下面是您的全部题目: " << std::endl;
                                        TopicList.Display();
                                        bool match_stu_topic = true;
                                        while(match_stu_topic){
                                            std::cout << "请输入您想分配学生的编号: " << std::endl;
                                            std::string StuId;std::cin >> StuId;
                                            std::cout << "请输入您想分配的题目编号: " << std::endl;
                                            int TopicId;std::cin >> TopicId;
                                            for (int i = 0; i <= StuList.GetSize(); ++i) {
                                                if(StuList[i].GetAddress().GetId() == StuId){
                                                    StuList[i].GetAddress().SetTopicId(TopicId);
                                                    break;
                                                }
                                            }
                                            for (int i = 0; i <= TopicList.GetSize(); ++i) {
                                                if(TopicList[i].GetAddress().GetId() == TopicId){
                                                    TopicList[i].GetAddress().SetStuId(StuId);
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
                                        TopicList.Display();
                                        std::cout << "下面是您的全部学生: " << std::endl;
                                        StuList.Display();
                                        bool match_stu_topic = true;
                                        while(match_stu_topic){
                                            std::cout << "请输入您想分配的题目编号: " << std::endl;
                                            int TopicId;std::cin >> TopicId;
                                            std::cout << "请输入您想分配学生的编号: " << std::endl;
                                            std::string StuId;std::cin >> StuId;
                                            for (int i = 0; i <= StuList.GetSize(); ++i) {
                                                if(StuList[i].GetAddress().GetId() == StuId){
                                                    StuList[i].GetAddress().SetTopicId(TopicId);
                                                    break;
                                                }
                                            }
                                            for (int i = 0; i <= TopicList.GetSize(); ++i) {
                                                if(TopicList[i].GetAddress().GetId() == TopicId){
                                                    TopicList[i].GetAddress().SetStuId(StuId);
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
                                if(!ex2) match_operation_Teacher = menu::Match_Teacher();
                            }
                            SaveStudent(StuList, TeaList[index].GetAddress().GetClass());
                            SaveTopic(TopicList, TeaList[index].GetAddress().GetClass());
                            break;
                        }
                        case 4:{
                            ex1 = true;
                            break;
                        }
                        default:;
                    }
                    if(!ex1) OperationType = menu::DisplayTeaMenu();
                }
                break;
            }
            case 2:{
                std::cout << "请输入你的班级编号: " << std::endl;
                int ClassId;std::cin >> ClassId;
                TList<Student> stuList;
                LoadStudent(stuList, ClassId);
                TList<Topic> topicList;
                LoadTopic(topicList, ClassId);
                int index = menu::LoginStudent(stuList);
                if(index == 0) break;
                if (index != 0) std::cout << stuList[index].GetAddress().GetName() << "登陆成功！" << std::endl;
                int OperationType = menu::DisplayStuMenu();
                bool ex1 = false;
                while(!ex1){
                    switch (OperationType){
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
                                std::cout << "请输入你要选择的题目编号 若都不想要 请输入-1"<< std::endl;int TopicId;std::cin >> TopicId;
                                while(TopicId != -1 && (TopicId != ed[0] && ed[0] != 0) && (TopicId != ed[1] && ed[1] != 0) && (TopicId != ed[2] && ed[2] != 0)){
                                    std::cout << "输入错误 请重新输入";std::cin >> TopicId;
                                }
                                if(TopicId == -1){
                                    break;
                                }else{
                                    for (int i = 1; i <= topicList.GetSize(); ++i) {
                                        if(topicList[i].GetAddress().GetStudentId()==stuList[index].GetAddress().GetId()){
                                            topicList[i].GetAddress().SetStuId("0");
                                            break;
                                        }
                                    }
                                    stuList[index].GetAddress().SetTopicId(TopicId);
                                    for (int i = 1; i <= topicList.GetSize(); ++i) {
                                        if(topicList[i].GetAddress().GetId() == TopicId){
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
                            int TopicId = stuList[index].GetAddress().GetTopicId();int TopicIndex;
                            if(TopicId == 0){
                                std::cout << "您还未选择题目" << std::endl;
                                break;
                            }else{
                                for (int i = 1; i <= topicList.GetSize(); ++i) {
                                    if(topicList[i].GetAddress().GetId() == TopicId){
                                        TopicIndex=i;
                                        break;
                                    }
                                }
                            }
                            std::cout << "您的已选择题目为";
                            std::cout << "编号: " << topicList[TopicIndex].GetAddress().GetId() << " 名称: " << topicList[TopicIndex].GetAddress().GetTitle() << std::endl;
                            std::cout << "任务要求: " << topicList[TopicIndex].GetAddress().GetDescription() << std::endl;
                            std::cout << "完成时间: ";
                            topicList[TopicIndex].GetAddress().GetTime();
                            break;
                        }
                        case 4:{
                            ex1 = true;
                            break;
                        }
                        default:;
                    }
                    if(!ex1) OperationType = menu::DisplayStuMenu();
                    SaveStudent(stuList, ClassId);
                    SaveTopic(topicList, ClassId);
                }
                break;
            }
            case 3:{
                ex0 = true;
            }
            default:;
            }
        if(!ex0) usertype = menu::DisplayWelcome();
    }
    file.Change(TeaList);
}