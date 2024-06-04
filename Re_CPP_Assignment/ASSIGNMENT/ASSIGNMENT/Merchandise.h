#pragma once
//#include "Login.h"
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
class Merchandise {
protected:
	char number[10];
	char name[50];
	double price;
	int storage;
	bool status;
	int type;
public:
	Merchandise();
	Merchandise(char *my_number,char* my_name,double my_price,int my_storage,bool my_status,int my_type);
	virtual ~Merchandise(){}
	int getstorage();
	virtual void printInfo();
	virtual char* getnumber();
	virtual std::string getstatus();
	virtual void modifystatus();
	virtual char* getname();
	virtual std::string gettype();
	virtual int gettype_num();
	virtual double getprice();
	void sold(int soldnumber);
	void changestorage(int newstorage);
	friend std::ifstream& operator >> (std::ifstream& in, Merchandise& goods);
	friend std::ofstream& operator << (std::ofstream& out, Merchandise& goods);
	Merchandise& operator=(const Merchandise& other);
};
class PC_accessory {
public:
	char graphic_card[50];
	char CPU[15];
	char RAM[50];
	char SSD[50];
	char motherboard[50];
	char power[50];
public:
	PC_accessory();
	PC_accessory(char* my_graphiccard, char* my_CPU, char* my_RAM,char* my_SSD,char* my_motherboard,char* my_power);
	PC_accessory& operator=(const PC_accessory& other);
};
class Book:public Merchandise {
protected:
	char writer[50];
	char publish[50];
public:
	Book();
	Book(char* my_number, char* my_name, double my_price, int my_storage, bool my_status, char*my_writer, char*my_publish);
	friend std::ifstream& operator >> (std::ifstream& in, Book& book);
	friend std::ofstream& operator << (std::ofstream& out, Book& book);
	void ReadFromFile(std::vector<Book>& books);
	void WriteToFile(std::vector<Book>& books);
	virtual ~Book(){}
	virtual void printInfo();
	virtual char* getnumber();
	virtual std::string getstatus();
	virtual void modifystatus();
	virtual char* getname();

	Book& operator=(const Book& other);
};
class Computer :public Merchandise {
protected:
	PC_accessory acc;
public:
	Computer();
	Computer(char* my_number, char* my_name, double my_price, int my_storage, bool my_status,char* my_graphiccard, char* my_CPU, char* my_RAM, char* my_SSD, char* my_motherboard, char* my_power);
	virtual ~Computer() {}
	friend std::ifstream& operator >> (std::ifstream& in, Computer& PC);
	friend std::ofstream& operator << (std::ofstream& out, Computer& PC);
	void ReadFromFile(std::vector<Computer>& PCs);
	void WriteToFile(std::vector<Computer>& PCs);
	virtual std::string getstatus();
	virtual void printInfo();
	virtual char* getnumber();
	virtual void modifystatus();
	virtual char* getname();
	Computer& operator=(const Computer& other);
};
class Beverage :public Merchandise {
protected:
	char volume[20];
public:
	Beverage();
	Beverage(char* my_number, char* my_name, double my_price, int my_storage, bool my_status,char* my_volume);
	virtual ~Beverage() {}
	friend std::ifstream& operator >> (std::ifstream& in, Beverage& beverage);
	friend std::ofstream& operator << (std::ofstream& out, Beverage& beverage);
	void ReadFromFile(std::vector<Beverage>& beverages);
	void WriteToFile(std::vector<Beverage>& beverages);
	virtual void printInfo();
	virtual char* getnumber();
	virtual std::string getstatus();
	virtual void modifystatus();
	virtual char* getname();
};
void add_Book();
void add_Computer();
void add_Beverage();
