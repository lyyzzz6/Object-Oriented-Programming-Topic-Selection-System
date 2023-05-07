//
// Created by Lenovo on 2023/4/27.
//

#ifndef C__CLASSDESIGN_TOPIC_H
#define C__CLASSDESIGN_TOPIC_H
#include <string>
class Topic{
private:
    int Class;
    int id;
    std::string title;
    std::string description;
    std::string studentid;
    int year;
    int month;
    int day;
    int hour;
    int minute;
public:
    Topic();

    [[nodiscard]] std::string GetTitle() const;

    void SetTitle(std::string);

    [[nodiscard]] int GetId() const;

    void SetId(int);

    void SetTime(int year,int month,int day,int hour,int minute);

    friend std::ostream& operator<< (std::ostream& out, Topic& x);

    friend std::istream& operator>> (std::istream& in, Topic& x);

    void SetStuId(std::string stuid);

    std::string GetStudentId();

    std::string GetDescription();

    void GetTime() const;
};
#endif //C__CLASSDESIGN_TOPIC_H
