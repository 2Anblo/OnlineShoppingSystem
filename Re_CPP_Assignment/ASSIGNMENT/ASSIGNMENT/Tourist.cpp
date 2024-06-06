#include "Login.h"
#include "Merchandise.h"
Tourist::Tourist()
{

}
void Tourist::viewGoods()
{
	Book temp_book;
	Computer temp_computer;
	Beverage temp_beverage;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	temp_book.ReadFromFile(books);
	temp_computer.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);

	
		clearScreen();
		for (auto i : books)
		{
			i.printInfo();
		}
		for (auto i : PCs)
		{
			i.printInfo();
		}
		for (auto i : beverages)
		{
			i.printInfo();
		}
		std::cout << "*��Ϊ��չʾ������Ʒ�������������һҳ..." << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();

}
void Tourist::viewGoodsWithCategory()
{
	Book temp_book;
	Computer temp_computer;
	Beverage temp_beverage;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	temp_book.ReadFromFile(books);
	temp_computer.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);

	char instruction;
	do
	{
		clearScreen();

		std::cout << "*��ӭ����������ģ��..." << std::endl;
		std::cout << "*1)�鼮" << std::endl;
		std::cout << "*2)�����" << std::endl;
		std::cout << "*3)����" << std::endl;
		std::cout << "*4)������һҳ" << std::endl;
		std::cout << "*��ѡ��Ҫ�������Ʒ����[1-4]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case '1':
		{
			clearScreen();
			for (auto i : books)
			{
				i.printInfo();
			}
			std::cout << "*��Ϊ��չʾ�����鼮�������������һҳ..." << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
			break;
		}
			
		case '2':
		{
			clearScreen();
			for (auto i : PCs)
			{
				i.printInfo();
			}
			std::cout << "*��Ϊ��չʾ���м�����������������һҳ..." << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
			break;
		}
		case '3':
		{
			clearScreen();
			for (auto i : beverages)
			{
				i.printInfo();
			}
			std::cout << "*��Ϊ��չʾ�������ϰ������������һҳ..." << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
			break;
		}
		case '4':
			break;

		default:
			break;
		}

	} while (instruction != '4');
}