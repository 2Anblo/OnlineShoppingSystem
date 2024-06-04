#include "Merchandise.h"
#include "Login.h"
Computer::Computer() { type = 2; }
Computer::Computer(char* my_number, char* my_name, double my_price, int my_storage, bool my_status,char* my_graphiccard, char* my_CPU, char* my_RAM, char* my_SSD, char* my_motherboard, char* my_power):
	Merchandise(my_number,my_name, my_price,my_storage,my_status,2),
	acc(my_graphiccard, my_CPU, my_RAM, my_SSD, my_motherboard, my_power)
{

}
PC_accessory::PC_accessory(){}
PC_accessory::PC_accessory(char* my_graphiccard, char* my_CPU, char* my_RAM, char* my_SSD, char* my_motherboard, char* my_power)
{
	strcpy(graphic_card,my_graphiccard);
	strcpy(CPU,my_CPU);
	strcpy(RAM, my_RAM);
	strcpy(SSD, my_SSD);
	strcpy(motherboard, my_motherboard);
	strcpy(power, my_power);
}
PC_accessory& PC_accessory::operator=(const PC_accessory& other)
{
	if (this != &other)
	{
		strcpy(graphic_card, other.graphic_card);
		strcpy(CPU, other.CPU);
		strcpy(RAM, other.RAM);
		strcpy(SSD, other.SSD);
		strcpy(motherboard, other.motherboard);
		strcpy(power, other.power);

	}
	return *this;
}
std::ifstream& operator >> (std::ifstream& in, Computer& PC)//Use template
{
	char my_number[10];
	char my_name[50];
	double my_price;
	int my_storage;
	bool my_status;
	int my_type;
	char my_graphiccard[50];
	char my_CPU[15];
	char my_RAM[50];
	char my_SSD[50];
	char my_motherboard[50];
	char my_power[50];

	in.read((char*)&my_number, sizeof(my_number));
	in.read((char*)&my_name, sizeof(my_name));
	in.read((char*)&my_price, sizeof(my_price));
	in.read((char*)&my_storage, sizeof(my_storage));
	in.read((char*)&my_status, sizeof(my_status));
	in.read((char*)&my_type, sizeof(my_type));
	in.read((char*)&my_graphiccard, sizeof(my_graphiccard));
	in.read((char*)&my_CPU, sizeof(my_CPU));
	in.read((char*)&my_RAM, sizeof(my_RAM));
	in.read((char*)&my_SSD, sizeof(my_SSD));
	in.read((char*)&my_motherboard, sizeof(my_motherboard));
	in.read((char*)&my_power, sizeof(my_power));
	if (in)
	{
		strcpy(PC.number,my_number);
		strcpy(PC.name,my_name);
		PC.price = my_price;
		PC.storage = my_storage;
		PC.status = my_status;
		PC.type = my_type;
		//my_graphiccard, my_CPU, my_RAM, my_SSD, my_motherboard, my_power
		//Deep Copy
		strcpy(PC.acc.CPU, my_CPU);
		strcpy(PC.acc.graphic_card, my_graphiccard);
		strcpy(PC.acc.RAM, my_RAM);
		strcpy(PC.acc.SSD, my_SSD);
		strcpy(PC.acc.motherboard, my_motherboard);
		strcpy(PC.acc.power, my_power);

	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, Computer& PC)//Use template
{
	out.write((char*)&PC.number, sizeof(PC.number));
	out.write((char*)&PC.name, sizeof(PC.name));
	out.write((char*)&PC.price, sizeof(PC.price));
	out.write((char*)&PC.storage, sizeof(PC.storage));
	out.write((char*)&PC.status, sizeof(PC.status));
	out.write((char*)&PC.type, sizeof(PC.type));
	out.write((char*)&PC.acc.graphic_card, sizeof(PC.acc.graphic_card));
	out.write((char*)&PC.acc.CPU, sizeof(PC.acc.CPU));
	out.write((char*)&PC.acc.RAM, sizeof(PC.acc.RAM));
	out.write((char*)&PC.acc.SSD, sizeof(PC.acc.SSD));
	out.write((char*)&PC.acc.motherboard, sizeof(PC.acc.motherboard));
	out.write((char*)&PC.acc.power, sizeof(PC.acc.power));
	return out;
}
void Computer::ReadFromFile(std::vector<Computer>& PCs)
{
	std::ifstream fin("PC.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	Computer PC;
	while (fin >> PC)
	{
		PCs.push_back(PC);
	}
	if (fin.eof())
	{
		//std::cout << "*�ļ���ȡ��ϣ�" << std::endl;
	}
	else if (fin.fail())
	{
		std::cout << "Fail to read the file!" << std::endl;
	}
	fin.close();
}
void Computer::WriteToFile(std::vector<Computer>& PCs)
{
	std::ofstream fout("PC.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<Computer>::iterator it = PCs.begin();
	for (; it != PCs.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
void add_Computer()
{
	clearScreen();
	char my_number[10];
	char my_name[50];
	double my_price;
	int my_storage;
	bool my_status=1;
	char my_graphiccard[50];
	char my_CPU[15];
	char my_RAM[50];
	char my_SSD[50];
	char my_motherboard[50];
	char my_power[50];

		std::cout << "*��������Ʒ��ţ�" << std::endl;
		std::cin >> my_number;
		std::cout << "*��������Ʒ���ƣ�" << std::endl;
		std::cin >> my_name;
		std::cout << "*��������Ʒ�۸�" << std::endl;
		std::cin >> my_price;
		std::cout << "*��������Ʒ��棺" << std::endl;
		std::cin >> my_storage;
		std::cout << "*�������Կ��ͺţ�" << std::endl;
		std::cin >> my_graphiccard;
		std::cout << "*������CPU�ͺţ�" << std::endl;
		std::cin >> my_CPU;
		std::cout << "*�������ڴ��ͺţ�" << std::endl;
		std::cin >> my_RAM;
		std::cout << "*�������̬Ӳ���ͺţ�" << std::endl;
		std::cin >> my_SSD;
		std::cout << "*�����������ͺţ�" << std::endl;
		std::cin >> my_motherboard;
		std::cout << "*�������Դ�ͺţ�" << std::endl;
		std::cin >> my_power;

		std::vector<Computer> PCs;
		Computer temp( my_number,  my_name, my_price, my_storage ,my_status,  my_graphiccard, my_CPU,  my_RAM,  my_SSD, my_motherboard, my_power);
		temp.ReadFromFile(PCs);
		PCs.push_back(temp);
		
		temp.WriteToFile(PCs);
		std::cout << "�����ɹ���" << std::endl;
		Sleep(1000);
		return;
	

}
void Computer::printInfo()
{

	std::cout << "*��Ʒ��ţ�" <<number<< std::endl;

	std::cout << "*��Ʒ���ƣ�" << name<<std::endl;

	std::cout << "*��Ʒ�۸�" <<std::setprecision(2)<<std::setiosflags(std::ios::fixed)<<price<< std::endl;
	std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);

	std::cout << "*��Ʒ��棺" << storage<<std::endl;

	std::cout << "*�����ͺţ�" << acc.motherboard << std::endl;

	std::cout << "*�Կ��ͺţ�" << acc.graphic_card<<std::endl;

	std::cout << "*CPU�ͺţ�" << acc.CPU<<std::endl;

	std::cout << "*�ڴ��ͺţ�" << acc.RAM<<std::endl;

	std::cout << "*��̬Ӳ���ͺţ�" << acc.SSD<<std::endl;

	std::cout << "*��Դ�ͺţ�" << acc.power<<std::endl;

	std::cout << "*״̬��" << getstatus() << std::endl;

	std::cout << std::endl;

}
char* Computer::getnumber()
{
	return number;
}
std::string Computer::getstatus()
{
	std::string temp;
	if (status == true)
	{
		temp = "�ϼ���";
	}
	else
	{
		temp = "���¼�";
	}
	return temp;
}
void Computer::modifystatus()
{
	status = !status;
}
char* Computer::getname()
{
	return name;
}
Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		strcpy(number, other.number);
		strcpy(name, other.name);
		price = other.price;
		storage = other.storage;
		status = other.status;
		acc = other.acc;
	}
	return *this;
}