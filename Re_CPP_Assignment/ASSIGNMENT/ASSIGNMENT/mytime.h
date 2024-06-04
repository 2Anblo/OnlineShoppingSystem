#pragma once
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
struct Date { // 定义日期结构体
    int year, month, day;
};
void dateToString(const Date& date, std::string& dateStr);
Date stringToDate(const std::string& dateStr);
Date Get_Sys_Time();