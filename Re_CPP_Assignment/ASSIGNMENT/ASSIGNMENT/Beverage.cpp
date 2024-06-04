#include "Merchandise.h"
#include "Login.h"
Beverage::Beverage() { type = 3; }
Beverage::Beverage(char* my_number, char* my_name, double my_price, int my_storage, bool my_status,char* my_volume) :Merchandise(my_number, my_name, my_price, my_storage, my_status, 3)
{
	strcpy(volume, my_volume);
}
std::ifstream& operator >> (std::ifstream& in, Beverage& beverage)
{
	char my_number[10];
	char my_name[50];
	double my_price;
	int my_storage;
	bool my_status = true;
	int my_type;
	char my_volume[20];
	

	in.read((char*)&my_number, sizeof(my_number));
	in.read((char*)&my_name, sizeof(my_name));
	in.read((char*)&my_price, sizeof(my_price));
	in.read((char*)&my_storage, sizeof(my_storage));
	in.read((char*)&my_status, sizeof(my_status));
	in.read((char*)&my_type, sizeof(my_type));
	in.read((char*)&my_volume, sizeof(my_volume));

	if (in)
	{
		strcpy(beverage.number, my_number);
		strcpy(beverage.name, my_name);
		beverage.price = my_price;
		beverage.storage = my_storage;
		beverage.status = my_status;
		beverage.type = my_type;
		strcpy(beverage.volume, my_volume);
	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, Beverage& beverage)
{
	out.write((char*)&beverage.number, sizeof(beverage.number));
	out.write((char*)&beverage.name, sizeof(beverage.name));
	out.write((char*)&beverage.price, sizeof(beverage.price));
	out.write((char*)&beverage.storage, sizeof(beverage.storage));
	out.write((char*)&beverage.status, sizeof(beverage.status));
	out.write((char*)&beverage.type, sizeof(beverage.type));
	out.write((char*)&beverage.volume, sizeof(beverage.volume));
	return out;
}
void Beverage::ReadFromFile(std::vector<Beverage>& beverages)
{
	std::ifstream fin("Beverage.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	Beverage beverage;
	while (fin >> beverage)
	{
		beverages.push_back(beverage);
	}
	if (fin.eof())
	{
		//std::cout << "*文件读取完毕！" << std::endl;
	}
	else if (fin.fail())
	{
		std::cout << "Fail to read the file!" << std::endl;
	}
	fin.close();
}
void Beverage::WriteToFile(std::vector<Beverage>& beverages)
{
	std::ofstream fout("Beverage.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<Beverage>::iterator it = beverages.begin();
	for (; it != beverages.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
void add_Beverage()
{
	clearScreen();
	char my_number[10];
	char my_name[50];
	double my_price;
	int my_storage;
	bool my_status = 1;
	char my_volume[20];

	std::cout << "*请输入商品编号：" << std::endl;
	std::cin >> my_number;
	std::cout << "*请输入商品名称：" << std::endl;
	std::cin >> my_name;
	std::cout << "*请输入商品价格：" << std::endl;
	std::cin >> my_price;
	std::cout << "*请输入商品库存：" << std::endl;
	std::cin >> my_storage;
	std::cout << "*请输入容量：" << std::endl;
	std::cin >> my_volume;

	std::vector<Beverage> beverages;
	Beverage temp(my_number, my_name, my_price, my_storage, my_status,my_volume);
	temp.ReadFromFile(beverages);
	beverages.push_back(temp);

	temp.WriteToFile(beverages);
	std::cout << "创建成功！" << std::endl;
	Sleep(1000);
	return;
}
void Beverage::printInfo()
{

	std::cout << "*商品编号：" << number << std::endl;

	std::cout << "*商品名称：" << name << std::endl;

	std::cout << "*商品价格：" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << price << std::endl;
	std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);

	std::cout << "*商品库存：" << storage << std::endl;

	std::cout << "*容量：" << volume << std::endl;

	std::cout << "*状态：" << getstatus() << std::endl;

	std::cout << std::endl;

}
char* Beverage::getnumber()
{
	return number;
}
std::string Beverage::getstatus()
{
	std::string temp;
	if (status == true)
	{
		temp = "上架中";
	}
	else
	{
		temp = "已下架";
	}
	return temp;
}
void Beverage::modifystatus()
{
	status = !status;
}
char* Beverage::getname()
{
	return name;
}