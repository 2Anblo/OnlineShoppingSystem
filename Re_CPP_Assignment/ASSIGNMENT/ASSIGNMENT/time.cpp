#define _CRT_SECURE_NO_WARNINGS
#include "mytime.h"

void dateToString(const Date& date, std::string& dateStr) {
    // 使用 stringstream 来格式化日期字符串
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << date.year<<"年"
        << std::setfill('0') << std::setw(2) << date.month<<"月"
        << std::setfill('0') << std::setw(2) << date.day << "日";
    dateStr = ss.str();
}

Date stringToDate(const std::string& dateStr) {
    Date date;
    std::sscanf(dateStr.c_str(), "%4d%2d%2d", &date.year, &date.month, &date.day);
    return date;
}

Date Get_Sys_Time() { // 返回当前系统时间
    std::time_t one = std::time(nullptr); // 获得系统时间
    std::tm today = *std::gmtime(&one); // 将 time_t 格式系统时间转换为 struct tm 格式

    Date now;
    now.year = today.tm_year + 1900; // tm_year是从1900开始的，所以需要加1900
    now.month = today.tm_mon + 1; // tm_mon是从0开始的
    now.day = today.tm_mday;
    return now;
}