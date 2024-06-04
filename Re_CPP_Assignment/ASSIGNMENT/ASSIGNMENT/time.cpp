#define _CRT_SECURE_NO_WARNINGS
#include "mytime.h"

void dateToString(const Date& date, std::string& dateStr) {
    // ʹ�� stringstream ����ʽ�������ַ���
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << date.year<<"��"
        << std::setfill('0') << std::setw(2) << date.month<<"��"
        << std::setfill('0') << std::setw(2) << date.day << "��";
    dateStr = ss.str();
}

Date stringToDate(const std::string& dateStr) {
    Date date;
    std::sscanf(dateStr.c_str(), "%4d%2d%2d", &date.year, &date.month, &date.day);
    return date;
}

Date Get_Sys_Time() { // ���ص�ǰϵͳʱ��
    std::time_t one = std::time(nullptr); // ���ϵͳʱ��
    std::tm today = *std::gmtime(&one); // �� time_t ��ʽϵͳʱ��ת��Ϊ struct tm ��ʽ

    Date now;
    now.year = today.tm_year + 1900; // tm_year�Ǵ�1900��ʼ�ģ�������Ҫ��1900
    now.month = today.tm_mon + 1; // tm_mon�Ǵ�0��ʼ��
    now.day = today.tm_mday;
    return now;
}