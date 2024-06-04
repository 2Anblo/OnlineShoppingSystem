#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Login.h"
#include "Merchandise.h"
#include "mytime.h"
#include <iostream>
#include <cstring>
class Cart {
public:
	User user;
	Merchandise* goods;
	int* goodsAddCount;
	size_t goodsCount;
	Cart();
	Cart(User& my_user);
	Cart(User& my_user, Merchandise* my_goods,size_t my_count,int* my_goods_Count);
	~Cart();
	void ReadFromFile(std::vector<Cart>& carts);
	void WriteToFile(std::vector<Cart>& carts);
	void addgoods(Merchandise& good, int& goodCount);
	void exportgoods(Merchandise& good,int num);
	void printInfo();
	Cart& operator=(const Cart& other);
	friend std::ifstream& operator >> (std::ifstream& in, Cart& cart);
	friend std::ofstream& operator << (std::ofstream& out, Cart& cart);
};
class Bill {
public:
	User user;
	Merchandise goods;
	int goodsAddCount;
	double payforreal;
	int year;
	int month;
	int day;
	friend std::ifstream& operator >> (std::ifstream& in, Bill& bill);
	friend std::ofstream& operator << (std::ofstream& out, Bill& bill);
	void ReadFromFile(std::vector<Bill>& bills);
	void WriteToFile(std::vector<Bill>& bills);
	void printInfo();
	void WriteToAdminFile(std::vector<Bill>& bills);
	void ReadFromAdminFile(std::vector<Bill>& bills);
	Bill();
	Bill(User& my_user);
	Bill(User& my_user, Merchandise my_goods,int my_goods_Count,int my_year,int my_month,int my_day, double my_payforreal);
	~Bill(){}

};
void FindCart(Cart& cart);
void UpdateCart(Cart& cart);
void view_check_menu(Cart& cart);
void UpdateUser(User& user);
void UpdateMerchandise(Merchandise& merchandise);