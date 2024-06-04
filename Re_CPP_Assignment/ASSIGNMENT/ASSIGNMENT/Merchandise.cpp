#include "Merchandise.h"
#include "Login.h"
Merchandise::Merchandise(){}
Merchandise::Merchandise(char* my_number, char* my_name, double my_price, int my_storage, bool my_status, int my_type)
{
	strcpy(number, my_number);
	strcpy(name, my_name);
	price = my_price;
	storage = my_storage;
	status = my_status;
	type=my_type;
}
double Merchandise::getprice()
{
	return price;
}
void Merchandise::printInfo()
{
	std::cout << "*��Ʒ��ţ�" << number << std::endl;

	std::cout << "*��Ʒ���ƣ�" << name << std::endl;
	std::cout << "*��Ʒ���ࣺ" <<gettype() << std::endl;

	std::cout << "*��Ʒ�۸�" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << price << std::endl;
	std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);

	std::cout << "*��Ʒ��棺" << storage << std::endl;

	std::cout << "*״̬��" << getstatus() << std::endl;
	//std::cout << std::endl;
}
char*  Merchandise::getnumber()
{
	return number;
}
std::string Merchandise:: getstatus()
{
	std::string temp;
	if(status==true)
	{
		temp = "�ϼ���";
	}
	else
	{
		temp = "���¼�";
	}
	return temp;
}
void Merchandise::modifystatus()
{

}
char* Merchandise::getname()
{
	return name;
}
Merchandise& Merchandise::operator=(const Merchandise& other)
{
	if (this != &other)
	{
		strcpy(number,other.number);
		strcpy(name,other.name);

		price=other.price;
		storage=other.storage;
		status=other.status;
		type=other.type;
	}
	return *this;
}
std::ifstream& operator >> (std::ifstream& in, Merchandise& goods)
{
	char my_number[10];
	char my_name[50];
	double my_price;
	int my_storage;
	bool my_status;
	int my_type;


	in.read((char*)&my_number, sizeof(my_number));
	in.read((char*)&my_name, sizeof(my_name));
	in.read((char*)&my_price, sizeof(my_price));
	in.read((char*)&my_storage, sizeof(my_storage));
	in.read((char*)&my_status, sizeof(my_status));
	in.read((char*)&my_type, sizeof(my_type));

	if (in)
	{
		strcpy(goods.number, my_number);
		strcpy(goods.name, my_name);
		goods.price = my_price;
		goods.storage = my_storage;
		goods.status = my_status;
		goods.type = my_type;
	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, Merchandise& goods)
{
	out.write((char*)&goods.number, sizeof(goods.number));
	out.write((char*)&goods.name, sizeof(goods.name));
	out.write((char*)&goods.price, sizeof(goods.price));
	out.write((char*)&goods.storage, sizeof(goods.storage));
	out.write((char*)&goods.status, sizeof(goods.status));
	out.write((char*)&goods.type, sizeof(goods.type));
	
	return out;
}
std::string Merchandise::gettype()
{
	std::string type_str;
	switch (type)
	{
	case 1:
		type_str = "�鼮";
		break;
	case 2:
		type_str = "�����";
		break;
	case 3:
		type_str = "����";
		break;
	default:
		break;
	}
	return type_str;
}
void Merchandise::sold(int soldnumber)
{
	storage = storage - soldnumber;
}
int Merchandise::gettype_num()
{
	return type;
}
int Merchandise:: getstorage()
{
	return storage;
}
void Merchandise::changestorage(int newstorage)
{
	storage = newstorage;
}