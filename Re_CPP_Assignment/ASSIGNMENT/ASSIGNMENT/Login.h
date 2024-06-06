#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include "Merchandise.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include <string.h>
class Cart;
const std::string admin_token = "123456";
class Person {
protected:
	char username[50];
	char password[50];
	int type;//Person 1 Admin 2 User 3 SuperUser4
public:
	Person(char* my_username, char* my_password,int type_t);
	Person(char* my_username, int type_t);

	Person();
	virtual ~Person(){}
	virtual void printInfo();
	void ReadFromFile(std::vector<Person>people);
	void WriteToFile(std::vector<Person>people);
	char* getusername();
	char* getpassword();
	int gettype();
	friend std::ifstream& operator >> (std::ifstream& in, Person& person);
	friend std::ofstream& operator << (std::ofstream& out, Person& person);
	friend class Cart;
};

class Admin :virtual public Person {
public:
	Admin(char* my_username, char* my_password);
	Admin();
	static double discount[9];
	virtual ~Admin() {}
	void ReadFromFile(std::vector<Admin>& admins);
	void WriteToFile(std::vector<Admin>& admins);
	void printUsername();//virtual
	virtual void printInfo();
	void createUser();
	void deleteUser();
	void modifyUser();
	void searchUser();
	void rechargeUser();
	void createGoods();
	void showgoodsList();
	void deleteGoods();
	void delistGoods();
	void listGoods();
	void showListedgoodsList();
	void showListedbooksList();
	void showListedPCsList();
	void showListedbeveragesList();
	void showDelistedgoodsList();
	void showDelistedbooksList();
	void showDelistedPCsList();
	void showDelistedbeveragesList();
	void manageBooks();
	void managePCs();
	void manageBeverages();
	void createBooks();
	void createPCs();
	void createBeverages();
	void showbooksList();
	void showbeveragesList();
	void deleteBooks();
	void deletePCs();
	void deleteBeverages();
	void delistBooks();
	void delistPCs();
	void delistBeverages();
	void listBooks();
	void listPCs();
	void listBeverages();
	void showPCsList();
	void statistics();
	void discountManage();
	void ManageGoodsWithCategory();
	void ManageGoods();
	void ManageUsers();
	friend std::ifstream& operator >> (std::ifstream& in, Admin& admin);
	friend std::ofstream& operator << (std::ofstream& out, Admin& admin);

};

class Tourist :public Person {
public:
	Tourist();
	void viewGoods();
	void viewGoodsWithCategory();
};

class User :virtual public Person {
protected:
	char contact[20];
	int level;//1 normal 2 VIP 3 VVIP
	double balance;
	
public:
	User& operator=(const User& other);
	User(char* my_contact, int my_level, double my_balance);
	User(char* my_username, char* my_password,char* my_contact,int my_level,double my_balance);
	User(char* my_username, char* my_password);
	User(char* my_username);
	User();
	virtual ~User() {}
	void ReadFromFile(std::vector<User>& users);
	void WriteToFile(std::vector<User>& users);
	void modify_money(double money);
	void modify_level_direct(int my_level);
	void modify_contact(char* my_contact);
	double getdiscount(int goodstype);
	int getlevelnum();
	double getbalance();
	char* getcontact();
	std::string getlevel();
	void modify_level();
	void modify_contact();
	void modify_password();
	virtual void printInfo();
	void recharge();
	void viewAllGoods();
	void viewBills();
	void viewCarts();
	void viewBooks();
	void viewPCs();
	void viewBeverages();
	void spendmoney(double money);
	void viewGoodsWithCategory();
	void viewGoods();
	friend std::ifstream& operator >> (std::ifstream& in, User& user);
	friend std::ofstream& operator << (std::ofstream& out, User& user);
	friend class Cart;

};

class SuperUser :public Admin, public User {
public:
	SuperUser(char* my_username, char* my_password, char* my_contact, int my_level, double my_balance);
	SuperUser(char* my_username, char* my_password);
	SuperUser();
	virtual ~SuperUser(){}
	virtual void printInfo();
	void ReadFromFile(std::vector<SuperUser>& superusers);
	void WriteToFile(std::vector<SuperUser>& superusers);
	friend std::ifstream& operator >> (std::ifstream& in, SuperUser& superuser);
	friend std::ofstream& operator << (std::ofstream& out, SuperUser& superuser);
};

void LoginMenu();
void tourist_menu();
void clearScreen();//to clean up the console
void create_Menu();
void create_Admin_Menu();
void create_User_Menu();
void sub_LoginMenu();
void shoppingMenu(User& user);
void manageMenu(Admin&admin);
void ManageUsers(Admin& admin);
void ManageGoods(Admin& admin);
void ManageGoodsWithCategory(Admin& admin);
void modify_User_Menu(User& user);
void create_goods_Menu();
void delete_goods_Menu();
void delist_goods_Menu();
void list_goods_Menu();
void create_books_Menu();
void delete_books_Menu();
void delist_books_Menu();
void list_books_Menu();
void create_PCs_Menu();
void delete_PCs_Menu();
void list_PCs_Menu();
void delist_PCs_Menu();
void showListedPCsList();
void create_Beverages_Menu();
void delete_Beverages_Menu();
void list_Beverages_Menu();
void delist_beverages_Menu();
void viewGoods(User& user);
void detailedPage(char* Select,User& user);
void AddToCart(char* Select, User& user);
void view_cartdelete_menu(Cart& cart);
void view_cart_menu(User& user);
void delete_User_Menu(Admin& admin);
void view_bill_menu(User& user);
bool checkGoodsNumber(char* goodsnumber);
bool checkUsersName(char* username);
void create_SuperUser_Menu();
void superMenu(SuperUser& superuser);
void UpdateSuperUser(User& user);