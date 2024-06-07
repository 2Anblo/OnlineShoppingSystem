#include "Merchandise.h"
#include "Login.h"
User::User(char* my_username) :Person(my_username, 3)
{

}
User::User(char* my_username, char* my_password):Person(my_username,my_password,3)
{

}
User::User(char* my_username, char* my_password, char* my_contact, int my_level, double my_balance):Person(my_username, my_password, 3)
{
	strcpy(contact, my_contact);
	level = my_level;
	balance = my_balance;
}
User::User(char* my_contact, int my_level, double my_balance) 
{
	strcpy(contact, my_contact);
	level = my_level;
	balance = my_balance;
}
User::User()
{

}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		strcpy(username, other.username);
		strcpy(password, other.password);
		strcpy(contact, other.contact);
		level = other.level;
		balance = other.balance;
	}
	return *this;
}
std::ifstream& operator >> (std::ifstream& in, User& user)//Use template
{
	char user_i[50];
	char pass[50];
	char conta[20];
	int lev;
	double balanc;
	in.read((char*)&user_i, sizeof(user_i));
	in.read((char*)&pass, sizeof(pass));
	in.read((char*)&conta, sizeof(conta));
	in.read((char*)&lev, sizeof(lev));
	in.read((char*)&balanc, sizeof(balanc));

	if (in)
	{
		strcpy(user.username, user_i);
		strcpy(user.password, pass);
		strcpy(user.contact, conta);
		user.level = lev;
		user.balance = balanc;
	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, User& user)//Use template
{
	char user_i[50];
	char pass[50];
	char conta[20];
	int lev;
	double balanc;
	strcpy(user_i, user.username);
	strcpy(pass, user.password);
	strcpy(conta, user.contact);
	lev = user.level;
	balanc = user.balance;
	if (out)
	{
		out.write((char*)&user_i, sizeof(user_i));
		out.write((char*)&pass, sizeof(pass));
		out.write((char*)&conta, sizeof(conta));
		out.write((char*)&lev, sizeof(lev));
		out.write((char*)&balanc, sizeof(balanc));
	}
	return out;
}
void User::ReadFromFile(std::vector<User>& users)
{
	std::ifstream fin("User.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	User user;
	while (fin >> user)
	{
		users.push_back(user);
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
void User::WriteToFile(std::vector<User>& users)
{
	std::ofstream fout("User.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<User>::iterator it = users.begin();
	for (; it != users.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
std::string User::getlevel()
{
	std::string level_str;
	switch (level)
	{
	case 1:
		level_str="普通用户";
		break;
	case 2:
		level_str = "VIP";
		break;
	case 3:
		level_str= "VVIP";
		break;
	default:
		break;
	}
	return level_str;
}
void User::modify_level()
{
	char new_level;
	bool correct_input=false;
	do
	{
		clearScreen();
		std::cout << "*请输入您想要设置的新等级[1-3]：" << std::endl;
		std::cin >> new_level;
		switch (new_level)
		{
		case '1':
			level = new_level-'0';
			correct_input = true;
			break;
		case '2':
			level = new_level-'0';
			correct_input = true;
			break;
		case '3':
			level = new_level-'0';
			correct_input = true;
			break;
		default:
			correct_input = false;
			break;
		}
	} while (!correct_input);
}
void User::modify_contact()
{
	char new_contact[20];
	clearScreen();
	std::cout << "*请输入您想要设置的新联系方式：" << std::endl;
	std::cin >> new_contact;
	strcpy(contact, new_contact);
}
void User::modify_password()
{
	char new_password[50];
	clearScreen();
	std::cout << "*请输入您想要设置的新密码：" << std::endl;
	std::cin >> new_password;
	strcpy(password, new_password);
}
void User::printInfo()
{
	clearScreen();
	std::cout << "*用户名: " << getusername() << std::endl;
	std::cout << "*用户密码: " << getpassword() << std::endl;
	std::cout << "*用户等级: " << getlevel() << std::endl;
	std::cout << "*用户联系方式: " << contact << std::endl;
	std::cout << "*用户余额: "<<std::setprecision(2)<<std::setiosflags(std::ios::fixed) << balance << std::endl;
	std::cout << std::resetiosflags(std::ios::fixed) << std::setprecision(0);
	std::cout << "*按任意键继续" << std::endl;
	std::cin.ignore(100, '\n');
	std::cin.get();
}
void User::recharge()
{
	clearScreen();
	double append_money;
	std::cout << "*用户余额: " << std::setprecision(2) << std::setiosflags(std::ios::fixed) << balance << std::endl;
	std::cout << std::resetiosflags(std::ios::fixed) << std::setprecision(0);
	std::cout << "*请输入要充值的金额: "<< std::endl;
	std::cin >> append_money;
	balance = balance + append_money;
	std::cout << "*用户余额: " << std::setprecision(2) << std::setiosflags(std::ios::fixed) << balance << std::endl;
	std::cout << std::resetiosflags(std::ios::fixed) << std::setprecision(0);
	std::cout << "*按任意键继续" << std::endl;
	std::cin.ignore(100, '\n');
	std::cin.get();
}
void User::viewAllGoods()
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

	char Select[10];
	do
	{
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
		std::cout << "*输入商品编号进入详情页面或输入T返回..." << std::endl;
		std::cin >> Select;
		if (!strcmp(Select, "T"))
		{
			return;
		}
		bool Found = false;
		for (auto i : books)
		{
			if (!strcmp(i.getnumber(), Select))
			{
				Found = true;
				break;
			}

		}
		for (auto i : PCs)
		{
			if (!strcmp(i.getnumber(), Select))
			{
				Found = true;
				break;
			}
		}
		for (auto i : beverages)
		{
			if (!strcmp(i.getnumber(), Select))
			{
				Found = true;
				break;
			}
		}
		if (Found)
		{
			detailedPage(Select,*this);
		}
	
	} while (strcmp(Select, "T"));

}
double User::getbalance()
{
	return balance;
}
void User::modify_money(double money)
{
	balance = money;
}
int User::getlevelnum()
{
	return level;
}
void User::viewCarts()
{
	view_cart_menu(*this);

}
double User::getdiscount(int goodstype)
{
	
	double discount = 0;
	switch (level)
	{
	case 1:
	{
		switch (goodstype)
		{
		case 1:
			discount = Admin::discount[0];
			break;
		case 2:
			discount = Admin::discount[1];
			break;
		case 3:
			discount = Admin::discount[2];
			break;
		default:
			break;
		}
		break;
	}
		
	case 2:
	{
		switch (goodstype)
		{
		case 1:
			discount = Admin::discount[3];
			break;
		case 2:
			discount = Admin::discount[4];
			break;
		case 3:
			discount = Admin::discount[5];
			break;
		default:
			break;
		}
		break;
	}
	case 3:
	{
		switch (goodstype)
		{
		case 1:
			discount = Admin::discount[6];
			break;
		case 2:
			discount = Admin::discount[7];
			break;
		case 3:
			discount = Admin::discount[8];
			break;
		default:
			break;
		}
		break;
	}
	default:
		discount = 1;
		break;
	}
	return discount;
}
void User::spendmoney(double money)
{
	balance = balance - money;
}
void User::viewBills()
{
	view_bill_menu(*this);
}
void User::viewGoodsWithCategory()
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

	int instruction;
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
		case 1:
			viewBooks();
			break;
		case 2:
			viewPCs();
			break;
		case 3:
			viewBeverages();
			break;
		case 4:
			break;

		default:
			break;
		}

	} while (instruction != 4);

}
void User::viewBooks()
{
	Book temp_book;

	std::vector<Book> books;

	temp_book.ReadFromFile(books);

	char Select[10];
	do
	{
		clearScreen();
		for (auto i : books)
		{
			i.printInfo();
		}
		std::cout << "*输入商品编号进入详情页面或输入T返回..." << std::endl;
		std::cin >> Select;
		if (!strcmp(Select, "T"))
		{
			return;
		}
		bool Found = false;
		for (auto i : books)
		{
			if (!strcmp(i.getnumber(), Select))
			{
				Found = true;
				break;
			}

		}
		if (Found)
		{
			detailedPage(Select, *this);
		}

	} while (strcmp(Select, "T"));
}
void User::viewPCs()
{
	
	Computer temp_computer;

	std::vector<Computer> PCs;

	temp_computer.ReadFromFile(PCs);


	char Select[10];
	do
	{
		clearScreen();
		
		for (auto i : PCs)
		{
			i.printInfo();
		}
		
		std::cout << "*输入商品编号进入详情页面或输入T返回..." << std::endl;
		std::cin >> Select;
		if (!strcmp(Select, "T"))
		{
			return;
		}
		bool Found = false;
		for (auto i : PCs)
		{
			if (!strcmp(i.getnumber(), Select))
			{
				Found = true;
				break;
			}
		}
		if (Found)
		{
			detailedPage(Select, *this);
		}

	} while (strcmp(Select, "T"));
}
void User::viewBeverages()
{
	
	Beverage temp_beverage;
	
	std::vector<Beverage> beverages;

	temp_beverage.ReadFromFile(beverages);

	char Select[10];
	do
	{
		clearScreen();
		
		for (auto i : beverages)
		{
			i.printInfo();
		}
		std::cout << "*输入商品编号进入详情页面或输入T返回..." << std::endl;
		std::cin >> Select;
		if (!strcmp(Select, "T"))
		{
			return;
		}
		bool Found = false;
		
		for (auto i : beverages)
		{
			if (!strcmp(i.getnumber(), Select))
			{
				Found = true;
				break;
			}
		}
		if (Found)
		{
			detailedPage(Select, *this);
		}

	} while (strcmp(Select, "T"));
}
void User::viewGoods()
{
	char instruction;
	do
	{
		clearScreen();

		std::cout << "*欢迎进入商品浏览模块..." << std::endl;
		std::cout << "*1)浏览所有商品" << std::endl;
		std::cout << "*2)分类浏览商品" << std::endl;
		std::cout << "*3)返回上一页" << std::endl;
		std::cout << "*请选择输入命令[1-3]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case '1':
			viewAllGoods();
			break;
		case '2':
			viewGoodsWithCategory();
			break;
		case '3':
			break;
		default:
			break;
		}

	} while (instruction != '3');
}
void User::modify_level_direct(int my_level)
{
	level = my_level;
}
void User::modify_contact(char* my_contact)
{
	strcpy(contact, my_contact);
}
char* User::getcontact()
{
	return contact;
}