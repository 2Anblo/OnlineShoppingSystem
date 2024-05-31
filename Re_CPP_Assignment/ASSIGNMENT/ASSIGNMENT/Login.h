#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string.h>
const std::string admin_token = "123456";
class Person {
protected:
	char username[50];
	char password[50];
	int type;//Person 1 Admin 2 User 3
public:
	Person(char* my_username, char* my_password,int type_t);
	Person();
	virtual ~Person(){}
	void ReadFromFile(std::vector<Person>people);
	void WriteToFile(std::vector<Person>people);
	friend std::ifstream& operator >> (std::ifstream& in, Person& person);
	friend std::ofstream& operator << (std::ofstream& out, Person& person);

};
class Admin :public Person {
public:
	Admin(char* my_username, char* my_password);
	Admin();
	virtual ~Admin() {}
	void ReadFromFile(std::vector<Admin>& admins);
	void WriteToFile(std::vector<Admin>& admins);
	void printUsername();//virtual
	char* getusername();//virtual
	char* getpassword();//virtual
	friend std::ifstream& operator >> (std::ifstream& in, Admin& admin);
	friend std::ofstream& operator << (std::ofstream& out, Admin& admin);

};
class User :public Person {
public:
	User(char* my_username, char* my_password);
	User();
	virtual ~User() {}
	void ReadFromFile(std::vector<User>& users);
	void WriteToFile(std::vector<User>& users);
	char* getusername();
	char* getpassword();
	friend std::ifstream& operator >> (std::ifstream& in, User& user);
	friend std::ofstream& operator << (std::ofstream& out, User& user);

};
void LoginMenu();
void clearScreen();//to clean up the console
void create_Menu();
void create_Admin_Menu();
void create_User_Menu();
void sub_LoginMenu();
void shoppingMenu();
void manageMenu(Admin&admin);
void ManageUsers(Admin& admin);