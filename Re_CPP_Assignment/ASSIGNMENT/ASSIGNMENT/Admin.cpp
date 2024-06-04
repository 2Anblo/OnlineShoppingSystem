#include "Merchandise.h"
#include "Login.h"
#include "Cart.h"
Admin::Admin(char* my_username, char* my_password) :Person(my_username, my_password,2)
{

}
Admin::Admin() {

}

std::ifstream& operator >> (std::ifstream& in, Admin& admin)//Use template
{
	char user[50];
	char pass[50];

	in.read((char*)&user, sizeof(user));

	in.read((char*)&pass, sizeof(pass));
	if (in)
	{
		strcpy(admin.username, user);
		strcpy(admin.password, pass);
	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, Admin& admin)//Use template
{
	out.write((char*)&admin.username, sizeof(admin.username));
	out.write((char*)&admin.password, sizeof(admin.password));
	return out;
}
void Admin::ReadFromFile(std::vector<Admin>& admins)
{
	std::ifstream fin("Admin.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	Admin admin;
	double dis[9];
	for (int dis_count = 0; dis_count < 9; dis_count++)
	{
		fin.read((char*)&dis[dis_count], sizeof(dis[dis_count]));
		Admin::discount[dis_count] = dis[dis_count];
	}
	while (fin >> admin)
	{
		admins.push_back(admin);
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
void Admin::WriteToFile(std::vector<Admin>& admins)
{
	std::ofstream fout("Admin.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<Admin>::iterator it = admins.begin();
	for (int dis_count = 0; dis_count < 9; dis_count++)
	{
		fout.write((char*)&Admin::discount[dis_count], sizeof(Admin::discount[dis_count]));
	}
	for (; it != admins.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
void Admin::printUsername()
{
	std::cout << username << std::endl;
}
char* Admin::getusername()
{
	return username;
}
char* Admin::getpassword()
{
	return password;
}
void Admin::createUser()
{
	create_User_Menu();
}
void Admin::deleteUser()
{
	delete_User_Menu();
}
void Admin::modifyUser()
{
	clearScreen();
	char account[50];
	bool Found_User = false;//Found User flag
	std::cout << "*请输入要修改的用户名：" << std::endl;
	std::cin >> account;

	std::vector<User> users;
	User temp(account);
	temp.ReadFromFile(users);
	auto iter = users.begin();
	for (; iter != users.end(); iter++)
	{
		if (!strcmp(iter->getusername(), account))
		{
			Found_User = true;
			modify_User_Menu(*iter);
			std::vector<Cart> carts;
			Cart temp_cart;
			temp_cart.ReadFromFile(carts);
			for (auto it = carts.begin(); it != carts.end();)
			{
				if (!strcmp(it->user.getusername(), account))
				{
					Found_User = true;
					it->user = *iter;//After erase pointer point to the next iterator
					break;
				}
				else
				{
					it++;
				}
			}
			temp_cart.WriteToFile(carts);
			break;
		}
	}
	if (Found_User)
	{

		temp.WriteToFile(users);
		std::cout << "*成功修改用户！" << std::endl;
	}
	else
	{
		std::cout << "*修改用户失败,请重试！" << std::endl;
	}

	Sleep(1000);
	return;
}
void Admin::searchUser()
{
	clearScreen();
	char account[50];
	bool Found_User = false;//Found User flag
	std::cout << "*请输入要查找的用户名：" << std::endl;
	std::cin >> account;

	std::vector<User> users;
	User temp(account);
	temp.ReadFromFile(users);
	auto iter = users.begin();
	for (; iter != users.end(); iter++)
	{
		if (!strcmp(iter->getusername(), account))
		{
			Found_User = true;
			iter->printInfo();
			break;
		}
	}
	if (!Found_User)
	{
		std::cout << "*查找用户失败,请重试！" << std::endl;
		Sleep(1000);
	}
	return;
}
void Admin::rechargeUser()
{
	clearScreen();
	char account[50];
	bool Found_User = false;//Found User flag
	std::cout << "*请输入要充值的用户名：" << std::endl;
	std::cin >> account;

	std::vector<User> users;
	User temp(account);
	temp.ReadFromFile(users);
	auto iter = users.begin();
	for (; iter != users.end(); iter++)
	{
		if (!strcmp(iter->getusername(), account))
		{
			Found_User = true;
			iter->recharge();
			std::vector<Cart> carts;
			Cart temp_cart;
			temp_cart.ReadFromFile(carts);
			for (auto it = carts.begin(); it != carts.end();)
			{
				if (!strcmp(it->user.getusername(), account))
				{
					Found_User = true;
					it->user = *iter;//After erase pointer point to the next iterator
					break;
				}
				else
				{
					it++;
				}
			}
			temp_cart.WriteToFile(carts);
			break;
		}
	}
	if (!Found_User)
	{
		std::cout << "*用户充值失败,请重试！" << std::endl;
		Sleep(1000);
	}
	else
	{
		temp.WriteToFile(users);
	}
	return;
}
void Admin::createGoods()
{
	create_goods_Menu();
}
void Admin::showgoodsList()
{
	clearScreen();
	Book temp_book;
	Computer temp_computer;
	Beverage temp_beverage;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	temp_book.ReadFromFile(books);
	temp_computer.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);
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
	//std::cout << "*按任意键继续" << std::endl;
	//std::cin.ignore(100, '\n');
	//std::cin.get();

}
void Admin:: deleteGoods()
{
	delete_goods_Menu();
}
void Admin::delistGoods()
{
	delist_goods_Menu();
}
void Admin::listGoods()
{
	list_goods_Menu();
}
void Admin::showListedgoodsList()
{
	clearScreen();
	Book temp_book;
	Computer temp_computer;
	Beverage temp_beverage;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	temp_book.ReadFromFile(books);
	temp_computer.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);
	for (auto i : books)
	{
		if (i.getstatus() == "上架中")
		{
			i.printInfo();
		}
		
	}
	for (auto i : PCs)
	{
		if (i.getstatus() == "上架中")
		{
			i.printInfo();
		}
	}
	for (auto i : beverages)
	{
		if (i.getstatus() == "上架中")
		{
			i.printInfo();
		}
	}
}
void Admin::showDelistedgoodsList()
{
	clearScreen();
	Book temp_book;
	Computer temp_computer;
	Beverage temp_beverage;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	temp_book.ReadFromFile(books);
	temp_computer.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);
	for (auto i : books)
	{
		if (i.getstatus() == "已下架")
		{
			i.printInfo();
		}

	}
	for (auto i : PCs)
	{
		if (i.getstatus() == "已下架")
		{
			i.printInfo();
		}
	}
	for (auto i : beverages)
	{
		if (i.getstatus() == "已下架")
		{
			i.printInfo();
		}
	}
}
void Admin::createBooks()
{
	create_books_Menu();
}
void Admin::showbooksList()
{
	clearScreen();
	Book temp_book;
	std::vector<Book> books;
	temp_book.ReadFromFile(books);
	
	for (auto i : books)
	{
		i.printInfo();
	}
	

}
void Admin::deleteBooks()
{
	delete_books_Menu();
}
void Admin::delistBooks()
{
	delist_books_Menu();
}
void Admin::showListedbooksList()
{
	clearScreen();
	Book temp_book;
	
	std::vector<Book> books;
	
	temp_book.ReadFromFile(books);
	
	for (auto i : books)
	{
		if (i.getstatus() == "上架中")
		{
			i.printInfo();
		}

	}
}
void Admin::listBooks()
{
	list_books_Menu();
}
void Admin::manageBooks()
{
	int instruction;
	do
	{
		clearScreen();
		Admin admin;
		std::cout << "*欢迎进入书籍管理模块..." << std::endl;
		std::cout << "*1)增加书籍" << std::endl;
		std::cout << "*2)书籍列表" << std::endl;
		std::cout << "*3)删除书籍" << std::endl;
		std::cout << "*4)上架书籍" << std::endl;
		std::cout << "*5)下架书籍" << std::endl;
		std::cout << "*6)返回上一页" << std::endl;
		std::cout << "*请选择输入命令[1-6]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			admin.createBooks();
			break;
		case 2:
			admin.showbooksList();
			std::cout << "*按任意键继续" << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
			break;
		case 3:
			admin.deleteBooks();
			break;
		case 4:
			admin.listBooks();
			break;
		case 5:
			admin.delistBooks();
			break;
		case 6:
			break;
		default:
			break;
		}

	} while (instruction != 6);
}
//Use template
void Admin::showDelistedbooksList()
{
	clearScreen();
	Book temp_book;

	std::vector<Book> books;

	temp_book.ReadFromFile(books);

	for (auto i : books)
	{
		if (i.getstatus() == "已下架")
		{
			i.printInfo();
		}

	}

}
void Admin::managePCs()
{
	int instruction;
	do
	{
		clearScreen();
		Admin admin;
		std::cout << "*欢迎进入计算机管理模块..." << std::endl;
		std::cout << "*1)增加计算机" << std::endl;
		std::cout << "*2)计算机列表" << std::endl;
		std::cout << "*3)删除计算机" << std::endl;
		std::cout << "*4)上架计算机" << std::endl;
		std::cout << "*5)下架计算机" << std::endl;
		std::cout << "*6)返回上一页" << std::endl;
		std::cout << "*请选择输入命令[1-6]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			admin.createPCs();
			break;
		case 2:
			admin.showPCsList();
			std::cout << "*按任意键继续" << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
			break;
		case 3:
			admin.deletePCs();
			break;
		case 4:
			admin.listPCs();
			break;
		case 5:
			admin.delistPCs();
			break;
		case 6:
			break;
		default:
			break;
		}

	} while (instruction != 6);
}
void Admin::createPCs()
{
	create_PCs_Menu();
}
void Admin::showPCsList()
{
	clearScreen();
	Computer temp_computer;

	std::vector<Computer> PCs;

	temp_computer.ReadFromFile(PCs);

	for (auto i : PCs)
	{
		i.printInfo();
	}


}
void Admin::deletePCs()
{
	delete_PCs_Menu();
}
void Admin::listPCs()
{
	list_PCs_Menu();
}
void Admin::showDelistedPCsList()
{
	clearScreen();
	
	Computer temp_computer;
	
	std::vector<Computer> PCs;
	
	temp_computer.ReadFromFile(PCs);
	
	for (auto i : PCs)
	{
		if (i.getstatus() == "已下架")
		{
			i.printInfo();
		}
	}
}
void Admin::delistPCs()
{
	delist_PCs_Menu();
}
void Admin::showListedPCsList()
{
	clearScreen();
	Computer temp_computer;

	std::vector<Computer> PCs;

	temp_computer.ReadFromFile(PCs);


	for (auto i : PCs)
	{
		if (i.getstatus() == "上架中")
		{
			i.printInfo();
		}
	}
}
void Admin::manageBeverages()
{
	int instruction;
	do
	{
		clearScreen();
		Admin admin;
		std::cout << "*欢迎进入饮料管理模块..." << std::endl;
		std::cout << "*1)增加饮料" << std::endl;
		std::cout << "*2)饮料列表" << std::endl;
		std::cout << "*3)删除饮料" << std::endl;
		std::cout << "*4)上架饮料" << std::endl;
		std::cout << "*5)下架饮料" << std::endl;
		std::cout << "*6)返回上一页" << std::endl;
		std::cout << "*请选择输入命令[1-6]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			admin.createBeverages();
			break;
		case 2:
			admin.showbeveragesList();
			std::cout << "*按任意键继续" << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
			break;
		case 3:
			admin.deleteBeverages();
			break;
		case 4:
			admin.listBeverages();
			break;
		case 5:
			admin.delistBeverages();
			break;
		case 6:
			break;
		default:
			break;
		}

	} while (instruction != 6);
}
void Admin::createBeverages()
{
	create_Beverages_Menu();
}
void Admin::showbeveragesList()
{
	clearScreen();
	
	Beverage temp_beverage;
	
	std::vector<Beverage> beverages;
	
	temp_beverage.ReadFromFile(beverages);
	
	for (auto i : beverages)
	{
		i.printInfo();
	}

}
void Admin::deleteBeverages()
{
	delete_Beverages_Menu();
}
void Admin::listBeverages()
{
	list_Beverages_Menu();
}
void Admin::showDelistedbeveragesList()
{

	clearScreen();

	Beverage temp_beverage;

	std::vector<Beverage> beverages;

	temp_beverage.ReadFromFile(beverages);

	for (auto i : beverages)
	{
		if (i.getstatus() == "已下架")
		{
			i.printInfo();
		}
	}
}
void Admin::delistBeverages()
{
	delist_beverages_Menu();
}
void Admin::showListedbeveragesList()
{
	clearScreen();

	Beverage temp_beverage;

	std::vector<Beverage> beverages;

	temp_beverage.ReadFromFile(beverages);

	for (auto i : beverages)
	{
		if (i.getstatus() == "上架中")
		{
			i.printInfo();
		}
	}
}
void Admin::statistics()
{
	Bill bill_view;
	std::vector<Bill> bills;
	bill_view.ReadFromAdminFile(bills);
	bool FoundBill = false;
	
	for (auto i : bills)
	{
			i.printInfo();
			FoundBill = true;
	}
	if (!FoundBill)
	{
		std::cout << "*系统暂无订单生成" << std::endl;
	}
	else
	{
		std::cout << "*请选择您想要统计的销售额日期:(输入格式2024/04/12)" << std::endl;
		std::string dateStr;
		std::cin >> dateStr;
		std::istringstream dateStream(dateStr);
		int year, month, day;
		// 读取年份
		dateStream >> year;
		// 跳过斜杠，然后读取月份
		dateStream.ignore(1); // 忽略一个字符，即斜杠
		dateStream >> month;
		// 再次跳过斜杠，然后读取日期
		dateStream.ignore(1); // 忽略一个字符，即斜杠
		dateStream >> day;
		
		double sumup = 0;
		for (auto i : bills)
		{
			if (i.year == year && i.month == month && i.day == day)
			{
				sumup += (i.goods.getprice() * i.goodsAddCount * i.user.getdiscount(i.goods.gettype_num()));
			}
		}
		std::cout << year<<"年"<<month<<"月"<<day<<"日的销售额为:" <<std::setprecision(2)<<std::setiosflags(std::ios::fixed)<< sumup<<std::resetiosflags(std::ios::fixed)<<"元" << std::endl;

	}
	std::cout << "*按任意键继续" << std::endl;
	std::cin.ignore(100, '\n');
	std::cin.get();
}
void Admin::discountManage()
{
	std::vector<Admin> adminss;
	ReadFromFile(adminss);
	char decide_button;
	std::cout << "*1)普通用户" << std::endl;
	std::cout << "*2)VIP" << std::endl;
	std::cout << "*3)VVIP" << std::endl;
	std::cout << "*4)返回上一页" << std::endl;
	std::cout << "*请选择您要修改折扣的用户类型[1-4]" << std::endl;
	std::cin >> decide_button;
	switch (decide_button)
	{
	case '1':
	{
		clearScreen();
		std::cout << "*1)书籍" << std::endl;
		std::cout << "*2)计算机" << std::endl;
		std::cout << "*3)饮料" << std::endl;
		std::cout << "*4)返回上一页" << std::endl;
		std::cout << "*请选择您要修改折扣的商品类型[1-4]" << std::endl;
		int select_type;
		std::cin >> select_type;
		double modified_discount;

		do
		{
			clearScreen();
			std::cout << "*请输入您要修改折扣值:(区间0-1)" << std::endl;
			std::cin >> modified_discount;
			if(modified_discount > 0 && modified_discount <= 1)
			Admin::discount[select_type - 1] = modified_discount;
		} while (modified_discount < 0 || modified_discount > 1);
		std::cout << "*修改成功,按任意键继续！" << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
		break;
	}

	case '2':
	{
		clearScreen();
		std::cout << "*1)书籍" << std::endl;
		std::cout << "*2)计算机" << std::endl;
		std::cout << "*3)饮料" << std::endl;
		std::cout << "*4)返回上一页" << std::endl;
		std::cout << "*请选择您要修改折扣的商品类型[1-4]" << std::endl;
		int select_type;
		std::cin >> select_type;
		double modified_discount;

		do
		{
			clearScreen();
			std::cout << "*请输入您要修改折扣值:(区间0-1)" << std::endl;
			std::cin >> modified_discount;
			if (modified_discount > 0 && modified_discount <= 1)
				Admin::discount[select_type+2] = modified_discount;
		} while (modified_discount < 0 || modified_discount > 1);
		std::cout << "*修改成功,按任意键继续！" << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
		break;
	}

	case '3':
	{
		clearScreen();
		std::cout << "*1)书籍" << std::endl;
		std::cout << "*2)计算机" << std::endl;
		std::cout << "*3)饮料" << std::endl;
		std::cout << "*4)返回上一页" << std::endl;
		std::cout << "*请选择您要修改折扣的商品类型[1-4]" << std::endl;
		int select_type;
		std::cin >> select_type;
		double modified_discount;

		do
		{
			clearScreen();
			std::cout << "*请输入您要修改折扣值:(区间0-1)" << std::endl;
			std::cin >> modified_discount;
			if (modified_discount > 0 && modified_discount <= 1)
				Admin::discount[select_type +5] = modified_discount;
		} while (modified_discount < 0 || modified_discount > 1);
		std::cout << "*修改成功,按任意键继续！" << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
		break;
	}

	case '4':
	{
		break;
	}

	default:
		break;
	}
	WriteToFile(adminss);
}
double Admin::discount[] = { 1,1,1,0.88,0.88,0.88,0.66,0.66,0.66 };