#include "Merchandise.h"
#include "Login.h"
#include "Cart.h"
Admin::Admin(char* my_username, char* my_password) :Person(my_username, my_password,2)
{

}
Admin::Admin() {

}
void Admin::printInfo()
{
	clearScreen();
	std::cout << "*����Ա��: " << getusername() << std::endl;
	std::cout << "*����Ա����: " << getpassword() << std::endl;

	std::cout << "*�����������" << std::endl;
	std::cin.ignore(100, '\n');
	std::cin.get();
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
		if (dis[dis_count]>0&& dis[dis_count]<=1)
		Admin::discount[dis_count] = dis[dis_count];
	}
	while (fin >> admin)
	{
		admins.push_back(admin);
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

void Admin::createUser()
{
	create_User_Menu();
}
void Admin::deleteUser()
{
	delete_User_Menu(*this);
}
void Admin::modifyUser()
{
	clearScreen();
	char account[50];
	bool Found_User = false;//Found User flag
	bool Found_SuperUser = false;//Found SuperUser flag
	std::cout << "*������Ҫ�޸ĵ��û�����" << std::endl;
	std::cin >> account;

	std::vector<User> users;
	std::vector<SuperUser> superusers;
	User temp(account);
	SuperUser temp_superuser;
	temp.ReadFromFile(users);
	temp_superuser.ReadFromFile(superusers);
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
	auto iter1 = superusers.begin();
	for (; iter1 != superusers.end(); iter1++)
	{
		if (!strcmp(iter1->getusername(), account))
		{
			Found_SuperUser = true;
			modify_User_Menu(*iter1);
			std::vector<Cart> carts;
			Cart temp_cart;
			temp_cart.ReadFromFile(carts);
			for (auto it = carts.begin(); it != carts.end();)
			{
				if (!strcmp(it->user.getusername(), account))
				{
					Found_SuperUser = true;
					it->user = *iter1;//After erase pointer point to the next iterator
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
		std::cout << "*�ɹ��޸��û���" << std::endl;
	}
	else if (Found_SuperUser)
	{

		temp_superuser.WriteToFile(superusers);
		std::cout << "*�ɹ��޸��û���" << std::endl;
	}

	else
	{
		std::cout << "*�޸��û�ʧ��,�����ԣ�" << std::endl;
	}

	Sleep(1000);
	return;
}
void Admin::searchUser()
{
	clearScreen();
	char account[50];
	bool Found_User = false;//Found User flag
	bool Found_SuperUser = false;//Found SuperUser Flag
	std::cout << "*������Ҫ���ҵ��û�����" << std::endl;
	std::cin >> account;

	std::vector<User> users;
	std::vector<SuperUser> superusers;
	User temp(account);
	SuperUser temp_superuser;
	temp.ReadFromFile(users);
	temp_superuser.ReadFromFile(superusers);

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

	auto iter1 = superusers.begin();
	for (; iter1 != superusers.end(); iter1++)
	{
		if (!strcmp(iter1->getusername(), account))
		{
			Found_SuperUser = true;
			iter1->printInfo();
			break;
		}
	}
	if (!Found_User&&!Found_SuperUser)
	{
		std::cout << "*�����û�ʧ��,�밴�����������" << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
	}
	return;
}
void Admin::rechargeUser()
{
	clearScreen();
	char account[50];
	bool Found_User = false;//Found User flag
	bool Found_SuperUser = false;//Found SuperUser flag
	std::cout << "*������Ҫ��ֵ���û�����" << std::endl;
	std::cin >> account;

	std::vector<SuperUser>superusers;
	std::vector<User> users;
	User temp(account);
	SuperUser temp_superuser;
	temp.ReadFromFile(users);
	temp_superuser.ReadFromFile(superusers);
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
	auto superiter = superusers.begin();
	for (; superiter != superusers.end(); superiter++)
	{
		if (!strcmp(superiter->getusername(), account))
		{
			Found_SuperUser = true;
			superiter->recharge();
			std::vector<Cart> carts;
			Cart temp_cart;
			temp_cart.ReadFromFile(carts);
			for (auto it = carts.begin(); it != carts.end();)
			{
				if (!strcmp(it->user.getusername(), account))
				{
					Found_SuperUser = true;
					it->user = *superiter;//After erase pointer point to the next iterator
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
	if (!Found_User&&!Found_SuperUser)
	{
		std::cout << "*�û���ֵʧ��,�����ԣ�" << std::endl;
		Sleep(1000);
	}
	else if(Found_User)
	{
		temp.WriteToFile(users);
	}
	else if (Found_SuperUser)
	{
		temp_superuser.WriteToFile(superusers);
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
	//std::cout << "*�����������" << std::endl;
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
		if (i.getstatus() == "�ϼ���")
		{
			i.printInfo();
		}
		
	}
	for (auto i : PCs)
	{
		if (i.getstatus() == "�ϼ���")
		{
			i.printInfo();
		}
	}
	for (auto i : beverages)
	{
		if (i.getstatus() == "�ϼ���")
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
		if (i.getstatus() == "���¼�")
		{
			i.printInfo();
		}

	}
	for (auto i : PCs)
	{
		if (i.getstatus() == "���¼�")
		{
			i.printInfo();
		}
	}
	for (auto i : beverages)
	{
		if (i.getstatus() == "���¼�")
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
		if (i.getstatus() == "�ϼ���")
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
		std::cout << "*��ӭ�����鼮����ģ��..." << std::endl;
		std::cout << "*1)�����鼮" << std::endl;
		std::cout << "*2)�鼮�б�" << std::endl;
		std::cout << "*3)ɾ���鼮" << std::endl;
		std::cout << "*4)�ϼ��鼮" << std::endl;
		std::cout << "*5)�¼��鼮" << std::endl;
		std::cout << "*6)������һҳ" << std::endl;
		std::cout << "*��ѡ����������[1-6]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			admin.createBooks();
			break;
		case 2:
			admin.showbooksList();
			std::cout << "*�����������" << std::endl;
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
		if (i.getstatus() == "���¼�")
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
		std::cout << "*��ӭ������������ģ��..." << std::endl;
		std::cout << "*1)���Ӽ����" << std::endl;
		std::cout << "*2)������б�" << std::endl;
		std::cout << "*3)ɾ�������" << std::endl;
		std::cout << "*4)�ϼܼ����" << std::endl;
		std::cout << "*5)�¼ܼ����" << std::endl;
		std::cout << "*6)������һҳ" << std::endl;
		std::cout << "*��ѡ����������[1-6]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			admin.createPCs();
			break;
		case 2:
			admin.showPCsList();
			std::cout << "*�����������" << std::endl;
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
		if (i.getstatus() == "���¼�")
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
		if (i.getstatus() == "�ϼ���")
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
		std::cout << "*��ӭ�������Ϲ���ģ��..." << std::endl;
		std::cout << "*1)��������" << std::endl;
		std::cout << "*2)�����б�" << std::endl;
		std::cout << "*3)ɾ������" << std::endl;
		std::cout << "*4)�ϼ�����" << std::endl;
		std::cout << "*5)�¼�����" << std::endl;
		std::cout << "*6)������һҳ" << std::endl;
		std::cout << "*��ѡ����������[1-6]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			admin.createBeverages();
			break;
		case 2:
			admin.showbeveragesList();
			std::cout << "*�����������" << std::endl;
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
		if (i.getstatus() == "���¼�")
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
		if (i.getstatus() == "�ϼ���")
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
		std::cout << "*ϵͳ���޶�������" << std::endl;
	}
	else
	{
		std::cout << "*��ѡ������Ҫͳ�Ƶ����۶�����:(�����ʽ2024/04/12)" << std::endl;
		std::string dateStr;
		std::cin >> dateStr;
		std::istringstream dateStream(dateStr);
		int year, month, day;
		// ��ȡ���
		dateStream >> year;
		// ����б�ܣ�Ȼ���ȡ�·�
		dateStream.ignore(1); // ����һ���ַ�����б��
		dateStream >> month;
		// �ٴ�����б�ܣ�Ȼ���ȡ����
		dateStream.ignore(1); // ����һ���ַ�����б��
		dateStream >> day;
		if (year < 1900 ||year>2200|| month>12 || month < 1 || day>31 || day < 1)
		{
			std::cout << "*�밴����ȷ��ʽ���룡�����������..." << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
			return;
		}
		double sumup = 0;
		for (auto i : bills)
		{
			if (i.year == year && i.month == month && i.day == day)
			{
				sumup += (i.goods.getprice() * i.goodsAddCount * i.user.getdiscount(i.goods.gettype_num()));
			}
		}
		std::cout << year<<"��"<<month<<"��"<<day<<"�յ����۶�Ϊ:" <<std::setprecision(2)<<std::setiosflags(std::ios::fixed)<< sumup<<std::resetiosflags(std::ios::fixed)<<"Ԫ" << std::endl;

	}
	std::cout << "*�����������" << std::endl;
	std::cin.ignore(100, '\n');
	std::cin.get();
}
void Admin::discountManage()
{
	std::vector<Admin> adminss;
	ReadFromFile(adminss);
	char decide_button;
	std::cout << "*1)��ͨ�û�" << std::endl;
	std::cout << "*2)VIP" << std::endl;
	std::cout << "*3)VVIP" << std::endl;
	std::cout << "*4)������һҳ" << std::endl;
	std::cout << "*��ѡ����Ҫ�޸��ۿ۵��û�����[1-4]" << std::endl;
	std::cin >> decide_button;
	switch (decide_button)
	{
	case '1':
	{
		clearScreen();
		std::cout << "*1)�鼮" << std::endl;
		std::cout << "*2)�����" << std::endl;
		std::cout << "*3)����" << std::endl;
		std::cout << "*4)������һҳ" << std::endl;
		std::cout << "*��ѡ����Ҫ�޸��ۿ۵���Ʒ����[1-4]" << std::endl;
		int select_type;
		std::cin >> select_type;
		double modified_discount;

		do
		{
			clearScreen();
			std::cout << "*��������Ҫ�޸��ۿ�ֵ:(����0-1)" << std::endl;
			std::cin >> modified_discount;
			if(modified_discount > 0 && modified_discount <= 1)
			Admin::discount[select_type - 1] = modified_discount;
		} while (modified_discount < 0 || modified_discount > 1);
		std::cout << "*�޸ĳɹ�,�������������" << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
		break;
	}

	case '2':
	{
		clearScreen();
		std::cout << "*1)�鼮" << std::endl;
		std::cout << "*2)�����" << std::endl;
		std::cout << "*3)����" << std::endl;
		std::cout << "*4)������һҳ" << std::endl;
		std::cout << "*��ѡ����Ҫ�޸��ۿ۵���Ʒ����[1-4]" << std::endl;
		int select_type;
		std::cin >> select_type;
		double modified_discount;

		do
		{
			clearScreen();
			std::cout << "*��������Ҫ�޸��ۿ�ֵ:(����0-1)" << std::endl;
			std::cin >> modified_discount;
			if (modified_discount > 0 && modified_discount <= 1)
				Admin::discount[select_type+2] = modified_discount;
		} while (modified_discount < 0 || modified_discount > 1);
		std::cout << "*�޸ĳɹ�,�������������" << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
		break;
	}

	case '3':
	{
		clearScreen();
		std::cout << "*1)�鼮" << std::endl;
		std::cout << "*2)�����" << std::endl;
		std::cout << "*3)����" << std::endl;
		std::cout << "*4)������һҳ" << std::endl;
		std::cout << "*��ѡ����Ҫ�޸��ۿ۵���Ʒ����[1-4]" << std::endl;
		int select_type;
		std::cin >> select_type;
		double modified_discount;

		do
		{
			clearScreen();
			std::cout << "*��������Ҫ�޸��ۿ�ֵ:(����0-1)" << std::endl;
			std::cin >> modified_discount;
			if (modified_discount > 0 && modified_discount <= 1)
				Admin::discount[select_type +5] = modified_discount;
		} while (modified_discount < 0 || modified_discount > 1);
		std::cout << "*�޸ĳɹ�,�������������" << std::endl;
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
void Admin::ManageGoodsWithCategory()
{
	char instruction;
	do
	{
		clearScreen();

		std::cout << "*��ӭ������Ʒ�������ģ��..." << std::endl;
		std::cout << "*1)�鼮" << std::endl;
		std::cout << "*2)�����" << std::endl;
		std::cout << "*3)����" << std::endl;
		std::cout << "*4)������һҳ" << std::endl;
		std::cout << "*��ѡ��Ҫ�������Ʒ����[1-4]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case '1':
			manageBooks();
			break;
		case '2':
			managePCs();
			break;
		case '3':
			manageBeverages();
			break;
		case '4':
			break;

		default:
			break;
		}

	} while (instruction != '4');
}
void Admin::ManageGoods()
{
	int instruction;
	do
	{
		clearScreen();

		std::cout << "*��ӭ������Ʒ����ģ��..." << std::endl;
		std::cout << "*1)������Ʒ" << std::endl;
		std::cout << "*2)��Ʒ�б�" << std::endl;
		std::cout << "*3)ɾ����Ʒ" << std::endl;
		std::cout << "*4)�ϼ���Ʒ" << std::endl;
		std::cout << "*5)�¼���Ʒ" << std::endl;
		std::cout << "*6)������һҳ" << std::endl;
		std::cout << "*��ѡ����������[1-6]" << std::endl;
		std::string instruction_str;
		std::cin >> instruction_str;
		std::istringstream ins(instruction_str);
		ins >> instruction;
		switch (instruction)
		{
		case 1:
			createGoods();
			break;
		case 2:
			showgoodsList();
			std::cout << "*�����������" << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
			break;
		case 3:
			deleteGoods();
			break;
		case 4:
			listGoods();
			break;
		case 5:
			delistGoods();
			break;
		case 6:
			break;
		default:
			break;
		}

	} while (instruction != 6);
}
void Admin::ManageUsers()
{
	int instruction;
	do
	{
		clearScreen();
		std::cout << "*1)����һ���û�" << std::endl;
		std::cout << "*2)ɾ��һ���û�" << std::endl;
		std::cout << "*3)�޸��û���Ϣ" << std::endl;
		std::cout << "*4)�����û�" << std::endl;
		std::cout << "*5)�û���ֵ" << std::endl;
		std::cout << "*6)������һҳ" << std::endl;
		std::cout << "*��ѡ����������[1-6]" << std::endl;
		std::string instruction_str;
		std::cin >> instruction_str;
		std::istringstream ins(instruction_str);
		ins >> instruction;
		switch (instruction)
		{
		case 1:
			createUser();
			break;
		case 2:
			deleteUser();
			break;
		case 3:
			modifyUser();
			break;
		case 4:
			searchUser();
			break;
		case 5:
			rechargeUser();
			break;
		case 6:
			break;
		default:
			break;
		}

	} while (instruction != 6);

}
double Admin::discount[] = { 1,1,1,0.88,0.88,0.88,0.66,0.66,0.66 };