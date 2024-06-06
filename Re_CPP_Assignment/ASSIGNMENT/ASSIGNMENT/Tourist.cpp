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
		std::cout << "*已为您展示所有商品按任意键返回上一页..." << std::endl;
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

		std::cout << "*欢迎进入分类浏览模块..." << std::endl;
		std::cout << "*1)书籍" << std::endl;
		std::cout << "*2)计算机" << std::endl;
		std::cout << "*3)饮料" << std::endl;
		std::cout << "*4)返回上一页" << std::endl;
		std::cout << "*请选择要浏览的商品种类[1-4]" << std::endl;
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
			std::cout << "*已为您展示所有书籍按任意键返回上一页..." << std::endl;
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
			std::cout << "*已为您展示所有计算机按任意键返回上一页..." << std::endl;
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
			std::cout << "*已为您展示所有饮料按任意键返回上一页..." << std::endl;
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