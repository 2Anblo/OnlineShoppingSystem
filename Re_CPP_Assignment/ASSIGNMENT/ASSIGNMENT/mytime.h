#pragma once
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
struct Date { // �������ڽṹ��
    int year, month, day;
};
void dateToString(const Date& date, std::string& dateStr);
Date stringToDate(const std::string& dateStr);
Date Get_Sys_Time();