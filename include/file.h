//
// Created by Lenovo on 2023/4/30.
//

#ifndef C__CLASSDESIGN_FILE_H
#define C__CLASSDESIGN_FILE_H
#include <string>
#include <fstream>
#include "tlist.h"
#include "Teacher.h"

class File{
private:
    std::string path;
    std::string filetype;
    std::string classes;
public:
    File(std::string, std::string, std::string);

    template<typename T>
    void init(TList<T>& list);

    template<typename T>
    void change(TList<T>& list);
};

File::File(const std::string p, const std::string c, const std::string t) {
    path = p;
    filetype = t;
    classes = c;
}

template<typename T>
void File::change(TList<T> &list) {
    std::ofstream out;
    out.open(path + classes + ".temp", std::ios::app);
    if(!out.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    ListNode<T> *ptr = list.GetHead()->GetNext();
    if(ptr) {
        out << ptr->GetAddress();
        ptr = ptr->GetNext();
    }
    while(ptr) {
        out << std::endl << ptr->GetAddress();
        ptr = ptr->GetNext();
    }
    out.close();
    remove((path + classes + filetype).c_str());
    rename((path + classes + ".temp").c_str(), (path + classes + filetype).c_str());
}

template<typename T>
void File::init(TList<T>& list) {
    std::ifstream in;
    in.open(path + classes + filetype, std::ios::in);
    if(!in.is_open()) {
        std::ofstream out;
        out.open(path + classes + filetype, std::ios::out | std::ios::app);
        out.close();
        in.open(path + classes + filetype, std::ios::in);
    }
    while(!in.eof()) {
        list.AddNode(in);
    }
    in.close();
}


#endif //C__CLASSDESIGN_FILE_H
