#include "Merchandise.h"
#include "Login.h"
#include "Cart.h"
#include "mytime.h"
void clearScreen()
{
	system("cls");
}
bool checkGoodsNumber(char* goodsnumber)
{
	bool Pass = true;
	Book temp_book;
	Computer temp_PC;
	Beverage temp_beverage;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	temp_book.ReadFromFile(books);
	temp_PC.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);
	for (auto i : books)
	{
		if (!strcmp(i.getnumber(), goodsnumber))
		{
			Pass = false;
			break;
		}
	}
	for (auto i : PCs)
	{
		if (!strcmp(i.getnumber(), goodsnumber))
		{
			Pass = false;
			break;
		}
	}
	for (auto i : beverages)
	{
		if (!strcmp(i.getnumber(), goodsnumber))
		{
			Pass = false;
			break;
		}
	}
	if (!Pass)
	{
		std::cout << "*������ѡ����Ʒ���,�ñ���ѱ�ռ�ã�" << std::endl;
		std::cout << "�����������..." << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
	}
	
	return Pass;
}
void delist_beverages_Menu()
{
	clearScreen();
	Admin temp;
	char delist_number[10];


	clearScreen();
	temp.showListedbeveragesList();
	std::cout << "*������Ҫ�¼ܵ����ϱ�ţ�" << std::endl;

	std::cin >> delist_number;

	Beverage temp_beverage;

	std::vector<Beverage> beverages;

	temp_beverage.ReadFromFile(beverages);

	bool Found_Beverage = false;


	for (auto iter = beverages.begin(); iter != beverages.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "�ϼ���"))
		{
			Found_Beverage = true;
			iter->modifystatus();//After erase pointer point to the next iterator
			break;
		}
		else
		{
			iter++;
		}
	}

	if (Found_Beverage)
	{
		temp_beverage.WriteToFile(beverages);
	}

	if (!Found_Beverage)
	{
		std::cout << "*��ƥ������ϱ��,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void list_Beverages_Menu()
{

	Admin temp;
	char delist_number[10];


	clearScreen();
	temp.showDelistedbeveragesList();
	std::cout << "*������Ҫ�ϼܵ����ϱ�ţ�" << std::endl;

	std::cin >> delist_number;

	Beverage temp_beverage;

	std::vector<Beverage> beverages;

	temp_beverage.ReadFromFile(beverages);

	bool Found_Beverage = false;

	for (auto iter = beverages.begin(); iter != beverages.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "���¼�"))
		{
			Found_Beverage = true;
			iter->modifystatus();//After erase pointer point to the next iterator
			break;
		}
		else
		{
			iter++;
		}
	}

	if (Found_Beverage)
	{
		temp_beverage.WriteToFile(beverages);
	}

	if (!Found_Beverage)
	{
		std::cout << "*��ƥ������ϱ��,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void delete_Beverages_Menu()
{
	clearScreen();
	Admin temp;
	char delete_number[10];
	temp.showbeveragesList();
	std::cout << "*������Ҫɾ�������ϱ�ţ�" << std::endl;

	std::cin >> delete_number;

	Beverage temp_beverage;

	std::vector<Beverage> beverages;

	temp_beverage.ReadFromFile(beverages);

	bool Found_Beverage = false;

	for (auto iter = beverages.begin(); iter != beverages.end();)
	{
		if (!strcmp(iter->getnumber(), delete_number))
		{
			Found_Beverage = true;
			iter = beverages.erase(iter);//After erase pointer point to the next iterator
			break;
		}
		else
		{
			iter++;
		}
	}

	if (Found_Beverage)
	{
		temp_beverage.WriteToFile(beverages);
	}

	if (!Found_Beverage)
	{
		std::cout << "*��ƥ������ϱ��,�����ԣ�" << std::endl;
		Sleep(750);
	}

}
void create_Beverages_Menu()
{
	clearScreen();
	add_Beverage();
}
void delist_PCs_Menu()
{
	clearScreen();
	Admin temp;
	char delist_number[10];

	temp.showListedPCsList();
	std::cout << "*������Ҫ�¼ܵļ������ţ�" << std::endl;

	std::cin >> delist_number;
	
	Computer temp_computer;
	
	std::vector<Computer> PCs;
	
	temp_computer.ReadFromFile(PCs);
	
	bool Found_Computer = false;
	
	for (auto iter = PCs.begin(); iter != PCs.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "�ϼ���"))
		{
			iter->modifystatus();//After erase pointer point to the next iterator
			Found_Computer = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	
	
	if (Found_Computer)
	{
		temp_computer.WriteToFile(PCs);
	}
	if (!Found_Computer)
	{
		std::cout << "*��ƥ��ļ�������,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void list_PCs_Menu()
{
	Admin temp;
	char delist_number[10];


	clearScreen();
	temp.showDelistedPCsList();
	std::cout << "*������Ҫ�ϼܵļ������ţ�" << std::endl;

	std::cin >> delist_number;
	
	Computer temp_computer;

	std::vector<Computer> PCs;

	temp_computer.ReadFromFile(PCs);

	bool Found_Computer = false;

	
	for (auto iter = PCs.begin(); iter != PCs.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "���¼�"))
		{
			iter->modifystatus();//After erase pointer point to the next iterator
			Found_Computer = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	
	
	if (Found_Computer)
	{
		temp_computer.WriteToFile(PCs);
	}
	if (!Found_Computer)
	{
		std::cout << "*��ƥ��ļ�������,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void delete_PCs_Menu()
{
	clearScreen();
	Admin temp;
	char delete_number[10];

	temp.showPCsList();
	std::cout << "*������Ҫɾ������Ʒ��ţ�" << std::endl;

	std::cin >> delete_number;
	Computer temp_computer;

	std::vector<Computer> PCs;

	temp_computer.ReadFromFile(PCs);

	bool Found_Computer = false;

	for (auto iter = PCs.begin(); iter != PCs.end();)
	{
		if (!strcmp(iter->getnumber(), delete_number))
		{
			iter = PCs.erase(iter);//After erase pointer point to the next iterator
			Found_Computer = true;
			break;
		}
		else
		{
			iter++;
		}
	}

	if (Found_Computer)
	{
		temp_computer.WriteToFile(PCs);
	}
	if (!Found_Computer)
	{
		std::cout << "*��ƥ�����Ʒ���,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void create_PCs_Menu()
{
	clearScreen();
	add_Computer();
}
void list_books_Menu()
{
	clearScreen();
	Admin temp;
	char delist_number[10];


	clearScreen();
	temp.showDelistedbooksList();
	std::cout << "*������Ҫ�ϼܵ��鼮��ţ�" << std::endl;

	std::cin >> delist_number;
	Book temp_book;

	std::vector<Book> books;
	
	temp_book.ReadFromFile(books);

	bool Found_Book = false;

	for (auto iter = books.begin(); iter != books.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "���¼�"))
		{
			iter->modifystatus();//After erase pointer point to the next iterator
			Found_Book = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	if (Found_Book)
	{
		temp_book.WriteToFile(books);
	}

	if (!Found_Book)
	{
		std::cout << "*��ƥ�����Ʒ���,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void delist_books_Menu()
{
	clearScreen();
	Admin temp;
	char delist_number[10];


	clearScreen();
	temp.showListedbooksList();
	std::cout << "*������Ҫ�¼ܵ��鼮��ţ�" << std::endl;

	std::cin >> delist_number;
	Book temp_book;
	
	std::vector<Book> books;
	
	temp_book.ReadFromFile(books);
	
	bool Found_Book = false;
	
	for (auto iter = books.begin(); iter != books.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "�ϼ���"))
		{
			iter->modifystatus();//After erase pointer point to the next iterator
			Found_Book = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	
	if (Found_Book)
	{
		temp_book.WriteToFile(books);
	}
	
	if (!Found_Book )
	{
		std::cout << "*��ƥ�����Ʒ���,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void delete_books_Menu()
{
	clearScreen();
	Admin temp;
	char delete_number[10];


	clearScreen();
	temp.showbooksList();
	std::cout << "*������Ҫɾ�����鼮��ţ�" << std::endl;

	std::cin >> delete_number;
	Book temp_book;
	
	std::vector<Book> books;

	temp_book.ReadFromFile(books);

	bool Found_Book = false;
	
	for (auto iter = books.begin(); iter != books.end();)
	{
		if (!strcmp(iter->getnumber(), delete_number))
		{
			iter = books.erase(iter);//After erase pointer point to the next iterator
			Found_Book = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	
	if (Found_Book)
	{
		temp_book.WriteToFile(books);
	}
	
	if (!Found_Book)
	{
		std::cout << "*��ƥ����鼮���,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void create_books_Menu()
{
	clearScreen();
	add_Book();
}
void delist_goods_Menu()
{
	clearScreen();
	Admin temp;
	char delist_number[10];


	clearScreen();
	temp.showListedgoodsList();
	std::cout << "*������Ҫ�¼ܵ���Ʒ��ţ�" << std::endl;

	std::cin >> delist_number;
	Book temp_book;
	Computer temp_computer;
	Beverage temp_beverage;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	temp_book.ReadFromFile(books);
	temp_computer.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);
	bool Found_Book = false;
	bool Found_Computer = false;
	bool Found_Beverage = false;
	for (auto iter = books.begin(); iter != books.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number)&&(iter->getstatus() == "�ϼ���"))
		{
			iter ->modifystatus();//After erase pointer point to the next iterator
			Found_Book = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	for (auto iter = PCs.begin(); iter != PCs.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "�ϼ���"))
		{
			iter->modifystatus();//After erase pointer point to the next iterator
			Found_Computer = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	for (auto iter = beverages.begin(); iter != beverages.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "�ϼ���"))
		{
			Found_Beverage = true;
			iter->modifystatus();//After erase pointer point to the next iterator
			break;
		}
		else
		{
			iter++;
		}
	}
	if (Found_Book)
	{
		temp_book.WriteToFile(books);
	}
	if (Found_Beverage)
	{
		temp_beverage.WriteToFile(beverages);
	}
	if (Found_Computer)
	{
		temp_computer.WriteToFile(PCs);
	}
	if (!Found_Beverage && !Found_Book && !Found_Computer)
	{
		std::cout << "*��ƥ�����Ʒ���,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void list_goods_Menu()
{
	Admin temp;
	char delist_number[10];


	clearScreen();
	temp.showDelistedgoodsList();
	std::cout << "*������Ҫ�ϼܵ���Ʒ��ţ�" << std::endl;

	std::cin >> delist_number;
	Book temp_book;
	Computer temp_computer;
	Beverage temp_beverage;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	temp_book.ReadFromFile(books);
	temp_computer.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);
	bool Found_Book = false;
	bool Found_Computer = false;
	bool Found_Beverage = false;
	for (auto iter = books.begin(); iter != books.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "���¼�"))
		{
			iter->modifystatus();//After erase pointer point to the next iterator
			Found_Book = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	for (auto iter = PCs.begin(); iter != PCs.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "���¼�"))
		{
			iter->modifystatus();//After erase pointer point to the next iterator
			Found_Computer = true;
			break;
		}
		else
		{
			iter++;
		}
	}
	for (auto iter = beverages.begin(); iter != beverages.end();)
	{
		if (!strcmp(iter->getnumber(), delist_number) && (iter->getstatus() == "���¼�"))
		{
			Found_Beverage = true;
			iter->modifystatus();//After erase pointer point to the next iterator
			break;
		}
		else
		{
			iter++;
		}
	}
	if (Found_Book)
	{
		temp_book.WriteToFile(books);
	}
	if (Found_Beverage)
	{
		temp_beverage.WriteToFile(beverages);
	}
	if (Found_Computer)
	{
		temp_computer.WriteToFile(PCs);
	}
	if (!Found_Beverage && !Found_Book && !Found_Computer)
	{
		std::cout << "*��ƥ�����Ʒ���,�����ԣ�" << std::endl;
		Sleep(750);
	}
}
void delete_goods_Menu()
{
	clearScreen();
	Admin temp;
	char delete_number[10];
	
	
		clearScreen();
		temp.showgoodsList();
		std::cout << "*������Ҫɾ������Ʒ��ţ�" << std::endl;
		
		std::cin >> delete_number;
		Book temp_book;
		Computer temp_computer;
		Beverage temp_beverage;
		std::vector<Book> books;
		std::vector<Computer> PCs;
		std::vector<Beverage> beverages;
		temp_book.ReadFromFile(books);
		temp_computer.ReadFromFile(PCs);
		temp_beverage.ReadFromFile(beverages);
		bool Found_Book = false;
		bool Found_Computer = false;
		bool Found_Beverage = false;
		for (auto iter = books.begin(); iter != books.end();)
		{
			if (!strcmp(iter->getnumber(), delete_number))
			{
				iter = books.erase(iter);//After erase pointer point to the next iterator
				Found_Book = true;
				break;
			}
			else
			{
				iter++;
			}
		}
		for (auto iter = PCs.begin(); iter != PCs.end();)
		{
			if (!strcmp(iter->getnumber(), delete_number))
			{
				iter = PCs.erase(iter);//After erase pointer point to the next iterator
				Found_Computer = true;
				break;
			}
			else
			{
				iter++;
			}
		}
		for (auto iter = beverages.begin(); iter != beverages.end();)
		{
			if (!strcmp(iter->getnumber(), delete_number))
			{
				Found_Beverage = true;
				iter = beverages.erase(iter);//After erase pointer point to the next iterator
				break;
			}
			else
			{
				iter++;
			}
		}
		if (Found_Book)
		{
			temp_book.WriteToFile(books);
		}
		if (Found_Beverage)
		{
			temp_beverage.WriteToFile(beverages);
		}
		if (Found_Computer)
		{
			temp_computer.WriteToFile(PCs);
		}
		if (!Found_Beverage && !Found_Book && !Found_Computer)
		{
			std::cout << "*��ƥ�����Ʒ���,�����ԣ�" << std::endl;
			Sleep(750);
		}
	
}
void create_goods_Menu()
{
	clearScreen();
	int add_type;
	do
	{
		clearScreen();
		std::cout << "*��ѡ��Ҫ���ӵ���Ʒ���ͣ�" << std::endl;
		std::cout << "*1)�鼮" << std::endl;
		std::cout << "*2)�����" << std::endl;
		std::cout << "*3)����" << std::endl;
		std::cout << "*4)������һҳ" << std::endl;
		std::cout << "*��ѡ����������[1-4]" << std::endl;
		std::cin >> add_type;
		switch (add_type)
		{
		case 1:
			add_Book();
			break;
		case 2:
			add_Computer();
			break;
		case 3:
			add_Beverage();
			break;
		case 4:
			break;

		default:
			break;
		}
	} while (add_type!=4);
	
}
void delete_User_Menu(Admin &admin)
{
	clearScreen();
	char account[50];
	bool Found_User = false;//Found User flag
	bool Found_SuperUser = false;
	std::cout << "*������Ҫɾ�����û�����" << std::endl;
	std::cin >> account;
	if (!strcmp(admin.getusername(), account))
	{
		std::cout << "*�޷�ɾ���Լ�,�밴���������..." << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
		return;
	}
	std::vector<User> users;
	std::vector<SuperUser> superusers;
	User temp(account);
	SuperUser temp_superuser;
	temp.ReadFromFile(users);
	temp_superuser.ReadFromFile(superusers);
	auto iter = users.begin();
	for (;iter != users.end();)
	{
		if (!strcmp(iter->getusername(), account))
		{
			Found_User = true;
			iter = users.erase(iter);//After erase pointer point to the next iterator
			break;
		}
		else
		{
			iter++;
		}
	}

	auto iter1 = superusers.begin();

	for (; iter1 != superusers.end();)
	{
		if (!strcmp(iter1->getusername(), account))
		{
			Found_SuperUser = true;
			iter1 = superusers.erase(iter1);//After erase pointer point to the next iterator
			break;
		}
		else
		{
			iter1++;
		}
	}
	if (Found_User)
	{
		std::vector<Cart> carts;
		Cart temp_cart;
		temp_cart.ReadFromFile(carts);
		for (auto it = carts.begin(); it != carts.end();)
		{
			if (!strcmp(it->user.getusername(), account))
			{
				Found_User = true;
				it = carts.erase(it);//After erase pointer point to the next iterator
				break;
			}
			else
			{
				it++;
			}
		}
		temp_cart.WriteToFile(carts);
		temp.WriteToFile(users);
		std::cout << "*�ɹ�ɾ���û���" << std::endl;
	}
	else if (Found_SuperUser)
	{
		std::vector<Cart> carts;
		Cart temp_cart;
		temp_cart.ReadFromFile(carts);
		for (auto it = carts.begin(); it != carts.end();)
		{
			if (!strcmp(it->user.getusername(), account))
			{
				Found_User = true;
				it = carts.erase(it);//After erase pointer point to the next iterator
				break;
			}
			else
			{
				it++;
			}
		}
		temp_cart.WriteToFile(carts);
		temp_superuser.WriteToFile(superusers);
		std::cout << "*�ɹ�ɾ���û���" << std::endl;
	}
	else
	{
		std::cout << "*ɾ���û�ʧ��,�����ԣ�" << std::endl;
	}

	Sleep(1000);
	return;
}
void modify_User_Menu(User& user)
{
	int instruction;
	do
	{
		clearScreen();
		std::cout << "*ѡ����Ҫ�޸ĵ��û���Ϣ" << std::endl;
		std::cout << "*1)�û�����" << std::endl;
		std::cout << "*2)�û��ȼ�" << std::endl;
		std::cout << "*3)�û���ϵ��ʽ" << std::endl;
		std::cout << "*4)�˳��޸�" << std::endl;
		std::cout << "*��ѡ����������[1-4]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			user.modify_password();
			break;
		case 2:
			user.modify_level();
			break;
		case 3:
			user.modify_contact();
			break;
		case 4:
			break;

		default:
			break;
		}

	} while (instruction != 4);
}
void shoppingMenu(User& user)
{
	char instruction;
	do
	{
		std::vector<User>users;
		user.ReadFromFile(users);
		for (auto i : users)
		{
			if (!strcmp(i.getusername(), user.getusername()))
			{
				user = i;
				break;
			}
		}

		clearScreen();
		std::cout << "*��ӭ��" << user.getusername() << ",���ĵȼ���" << user.getlevel() << "!�������¹���Ȩ�ޣ�" << std::endl;
		std::cout << "*1)�����Ʒ" << std::endl;
		std::cout << "*2)�鿴���ﳵ" << std::endl;
		std::cout << "*3)�鿴�����б�" << std::endl;
		std::cout << "*4)������Ϣ��ѯ" << std::endl;
		std::cout << "*5)�˳��̳�" << std::endl;
		std::cout << "*��ѡ����������[1-5]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case '1':
			user.viewGoods();
			break;
		case '2':
			user.viewCarts();
			break;
		case '3':
			user.viewBills();
			break;
		case '4':
			user.printInfo();
			break;
		case '5':
			break;
		default:
			break;
		}
	} while (instruction != '5');

	
}
void manageMenu(Admin&admin)
{
	char instruction;
	do
	{
		clearScreen();
		std::cout << "*��ӭ��" << admin.getusername() << ",���Ľ�ɫ�ǹ���Ա!�������¹���Ȩ�ޣ�" << std::endl;
		std::cout << "*1)��Ʒ�������" << std::endl;
		std::cout << "*2)��Ʒ����" << std::endl;
		std::cout << "*3)�û�����" << std::endl;
		std::cout << "*4)���ù���" << std::endl;
		std::cout << "*5)ͳ��" << std::endl;
		std::cout << "*6)�˳�" << std::endl;
		std::cout << "*��ѡ����������[1-6]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case '1':
			admin.ManageGoodsWithCategory();
			break;
		case '2':
			admin.ManageGoods();
			break;
		case '3':
			admin.ManageUsers();
			break;
		case '4':
			admin.discountManage();
			break;
		case '5':
			admin.statistics();
			break;
		case '6':
			break;
		default:
			break;
		}
	} while (instruction!='6');
	
}
void superMenu(SuperUser& superuser)
{
	int instruction;
	do
	{
		std::vector<SuperUser>superusers;
		superuser.ReadFromFile(superusers);
		for (auto i : superusers)
		{
			if (!strcmp(i.getusername(), superuser.getusername()))
			{
				superuser = i;
				break;
			}
		}

		clearScreen();
		std::cout << "*��ӭ��" << superuser.getusername() << ",���ǳ����û�!�������¹���Ȩ�ޣ�" << std::endl;
		std::cout << "*1)��Ʒ�������" << std::endl;
		std::cout << "*2)��Ʒ����" << std::endl;
		std::cout << "*3)�û�����" << std::endl;
		std::cout << "*4)���ù���" << std::endl;
		std::cout << "*5)ͳ��" << std::endl;
		std::cout << "*6)�����Ʒ" << std::endl;
		std::cout << "*7)�鿴���ﳵ" << std::endl;
		std::cout << "*8)�鿴�����б�" << std::endl;
		std::cout << "*9)������Ϣ��ѯ" << std::endl;
		std::cout << "*0)�˳��̳�" << std::endl;
		std::cout << "*��ѡ����������[0-9]" << std::endl;
		std::string instruction_str;
		std::cin >> instruction_str;
		std::istringstream ins(instruction_str);
		ins >> instruction;
		switch (instruction)
		{
		case 1:
			superuser.ManageGoodsWithCategory();
			break;
		case 2:
			superuser.ManageGoods();
			break;
		case 3:
			superuser.ManageUsers();
			break;
		case 4:
			superuser.discountManage();
			break;
		case 5:
			superuser.statistics();
			break;
		case 6:
			superuser.viewGoods();
			break;
		case 7:
			superuser.viewCarts();
			break;
		case 8:
			superuser.viewBills();
			break;
		case 9:
			superuser.printInfo();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (instruction != 0);
}
void create_Admin_Menu()
{
	clearScreen();
	std::string input_token;
	std::cout << "*���������Ա��Կ" << std::endl;
	std::cin >> input_token;
	if (input_token == admin_token)
	{
		clearScreen();
		char account[50];
		char password[50];
		std::cout << "*�������˻�����" << std::endl;
		std::cin >> account;
		if (!checkUsersName(account))
		{
			return;
		}
		std::cout << "*�������˻����룺" << std::endl;
		std::cin >> password;
		std::vector<Admin> admins;
		Admin temp(account, password);
		temp.ReadFromFile(admins);
		admins.push_back(temp);
		temp.WriteToFile(admins);
		std::cout << "�����ɹ���" <<std:: endl;
		Sleep(1000);
		return;
	}
	else
	{
		std::cout << "*��Կ����,�����ԣ�" << std::endl;
		Sleep(1000);
	}
}
void create_User_Menu()
{
	clearScreen();
	char account[50];
	char password[50];
	char contact[20];
	double balance;
	std::cout << "*�������˻�����" << std::endl;
	std::cin >> account;
	if (!checkUsersName(account))
	{
		return;
	}
	std::cout << "*�������˻����룺" << std::endl;
	std::cin >> password;
	std::cout << "*��������ϵ��ʽ��" << std::endl;
	std::cin >> contact;
	std::cout << "*�������ֵ��" << std::endl;
	std::cin >> balance;
	std::vector<User> users;
	User temp(account, password,contact,1,balance);//default initialize it as ��ͨ�û�(1)
	temp.ReadFromFile(users);
	users.push_back(temp);
	temp.WriteToFile(users);
	std::cout << "�����ɹ���" << std::endl;
	Sleep(1000);
	return;
}
void create_SuperUser_Menu()
{
	clearScreen();
	char account[50];
	char password[50];
	char contact[20];
	double balance;
	std::cout << "*�������˻�����" << std::endl;
	std::cin >> account;
	if (!checkUsersName(account))
	{
		return;
	}
	std::cout << "*�������˻����룺" << std::endl;
	std::cin >> password;
	std::cout << "*��������ϵ��ʽ��" << std::endl;
	std::cin >> contact;
	std::cout << "*�������ֵ��" << std::endl;
	std::cin >> balance;
	std::vector<SuperUser> superusers;
	SuperUser temp(account, password, contact, 1, balance);//default initialize it as ��ͨ�û�(1)
	temp.ReadFromFile(superusers);
	superusers.push_back(temp);
	temp.WriteToFile(superusers);
	std::cout << "�����ɹ���" << std::endl;
	Sleep(1000);
	return;
}
void create_Menu()
{
	char EnrollType;
	do {
		clearScreen();
		std::cout << "*1)����Ա" << std::endl;
		std::cout << "*2)�û�" << std::endl;
		std::cout << "*3)�����û�" << std::endl;
		std::cout << "*4)������ҳ" << std::endl;
		std::cout << "*��ѡ��ע���û�����[1-4]" << std::endl;
		std::cin >> EnrollType;
		
		switch (EnrollType)
		{
		case '1':
			create_Admin_Menu();
			break;
		case '2':
			create_User_Menu();
			break;
		case '3':
			create_SuperUser_Menu();
			break;
		case '4':
			break;
		default:
			break;
		}
	} while (EnrollType!='4');
}
void sub_LoginMenu()
{
	char account[50];
	char password[50];
	std::cout << "�������˺�:" ;

	std::cout << std::endl;
	std::cin >> account;
	std::cout << "����������:" ;
	std::cout << std::endl;
	std::cin >> password;

	bool user_pass=false;
	bool admin_pass=false;
	bool superuser_pass = false;
	User temp_user(account, password);
	Admin temp_admin(account, password);
	SuperUser temp_superuser(account, password);
	std::vector<User> users;
	std::vector<Admin> admins;
	std::vector<SuperUser> superusers;
	temp_user.ReadFromFile(users);
	temp_admin.ReadFromFile(admins);
	temp_superuser.ReadFromFile(superusers);
	//Verified the password
	for (auto use : users)
	{
		if (!strcmp(use.getusername(), account) && !strcmp(use.getpassword(), password))
		{
			user_pass = true;
			temp_user = use;
			break;
		}
	}
	for (auto adm : admins)
	{
		if (!strcmp(adm.getusername(), account) && !strcmp(adm.getpassword(), password))
		{
			admin_pass = true;
			break;
		}
	}
	for (auto sup : superusers)
	{
		if (!strcmp(sup.getusername(), account) && !strcmp(sup.getpassword(), password))
		{
			superuser_pass = true;
			break;
		}
	}
	if (user_pass || admin_pass ||superuser_pass)
	{
		if (user_pass)
		{
			
			shoppingMenu(temp_user);
		}
		else if(admin_pass)
		{
			manageMenu(temp_admin);
		}
		else
		{
			superMenu(temp_superuser);
		}
	}
	
	
}
void LoginMenu()
{
	char LoginWay;
	Admin temp_admin;
	std::vector<Admin> adminn;
	temp_admin.ReadFromFile(adminn);
	do {
		clearScreen();

		std::cout << "*��ӭ��ʹ�������̳�ϵͳ*" << std::endl;
		std::cout << "*1)����һ�����˺�" << std::endl;
		std::cout << "*2)��¼�����˺�" << std::endl;
		std::cout << "*3)���ο�ģʽ�����̳�" << std::endl;
		std::cout << "*4)�˳�ϵͳ" << std::endl;
		std::cout << "*��ѡ����ʽ���[1-4]" << std::endl;
		std::cin >> LoginWay;
		switch (LoginWay)
		{
		case '1':
			create_Menu();
			break;
		case '2':
			sub_LoginMenu();
			break;
		case '3':
			//Directly enter the online shop
			tourist_menu();
			break;
		case '4':
			break;
		default:
			std::cout << "*������1-4֮�����!" << std::endl;
			break;
		}
	} while (LoginWay != '4');
}
void detailedPage(char* Select,User& user)
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
		if (!strcmp(i.getnumber(), Select))
		{
			i.printInfo();
			break;
		}

	}
	for (auto i : PCs)
	{
		if (!strcmp(i.getnumber(), Select))
		{
			i.printInfo();
			break;
		}
	}
	for (auto i : beverages)
	{
		if (!strcmp(i.getnumber(), Select))
		{
			i.printInfo();
			break;
		}
	}
	AddToCart(Select,user);
	//std::cout << "*�����������" << std::endl;
	//std::cin.ignore(100, '\n');
	//std::cin.get();
	clearScreen();
}
void AddToCart(char* Select,User& user)
{
	clearScreen();
	Cart cart(user);
	//Found user_cart position!!!
	FindCart(cart);
	Book temp_book;
	Computer temp_computer;
	Beverage temp_beverage;
	Cart temp_cart;
	std::vector<Book> books;
	std::vector<Computer> PCs;
	std::vector<Beverage> beverages;
	std::vector<Cart> CARTs;
	temp_book.ReadFromFile(books);
	temp_computer.ReadFromFile(PCs);
	temp_beverage.ReadFromFile(beverages);
	temp_cart.ReadFromFile(CARTs);
	std::cout << std::setprecision(0) << std::setiosflags(std::ios::fixed);
	for (auto i : books)
	{
		if (!strcmp(i.getnumber(), Select))
		{
			i.printInfo();
			std::cout << "*�Ƿ���ӽ����ﳵ��" << std::endl;
			std::cout << "*��1��ӽ����ﳵ,���������+�س�������һҳ" << std::endl;

			std::string decision;
			std::cin >> decision;
			clearScreen();
			if (decision == "1")
			{
				
				int goodscount;
				i.printInfo();
				std::cout << "*�����˻����Ϊ"<<std::setprecision(2)<<std::setiosflags(std::ios::fixed)<<user.getbalance() << std::endl;
				std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);
				switch (user.getlevelnum())
				{
				case 1:
					std::cout << "*��Ϊ" << user.getlevel()<<"!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..."  << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i,goodscount);

					std::cout << "*�ѳɹ���" << goodscount << "��" << "��" << i.getname() << "��" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;
				case 2:
					std::cout << "*��Ϊ" << user.getlevel() << "�ڱ��̳ǹ�������"<< std::setprecision(0) << std::setiosflags(std::ios::fixed)<<(1-Admin::discount[3])*100<<"%�Ż�!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..." << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i,goodscount);
					std::cout << "*�ѳɹ���" << goodscount << "��" << "��" << i.getname() << "��" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;
				case 3:
					std::cout << "*��Ϊ" << user.getlevel() << "�ڱ��̳ǹ�������"<< std::setprecision(0) << std::setiosflags(std::ios::fixed) << (1-Admin::discount[6])*100<<"%�Ż�!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..." << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i, goodscount);
					std::cout << "*�ѳɹ���" << goodscount << "��" << "��" << i.getname() << "��" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;

				default:
					break;
				}
			}
			break;
		}

	}
	for (auto i : PCs)
	{
		if (!strcmp(i.getnumber(), Select))
		{
			i.printInfo();
			std::cout << "*�Ƿ���ӽ����ﳵ��" << std::endl;
			std::cout << "*��1��ӽ����ﳵ,����������س�������һҳ" << std::endl;

			std::string decision;
			std::cin >> decision;
			clearScreen();
			i.printInfo();
			if (decision == "1")
			{
				int goodscount;
				std::cout << "*�����˻����Ϊ" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << user.getbalance() << std::endl;
				std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);
				switch (user.getlevelnum())
				{
				case 1:
					std::cout << "*��Ϊ" << user.getlevel() << "!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..." << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i, goodscount);
					std::cout << "*�ѳɹ���" << goodscount << "̨" << i.getname() << "����" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;
				case 2:
					std::cout << "*��Ϊ" << user.getlevel() << "�ڱ��̳ǹ�������"<< std::setprecision(0) << std::setiosflags(std::ios::fixed) << (1 - Admin::discount[4]) * 100 << "%�Ż�!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..." << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i, goodscount);
					std::cout << "*�ѳɹ���" << goodscount << "̨" << i.getname() << "����" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;
				case 3:
					std::cout << "*��Ϊ" << user.getlevel() << "�ڱ��̳ǹ�������" << std::setprecision(0) << std::setiosflags(std::ios::fixed) << (1 - Admin::discount[7]) * 100 << "%�Ż�!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..." << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i, goodscount);
					std::cout << "*�ѳɹ���" << goodscount << "̨" << i.getname() << "����" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;

				default:
					break;
				}
			}
			break;
		}
	}
	for (auto i : beverages)
	{
		if (!strcmp(i.getnumber(), Select))
		{
			i.printInfo();
			std::cout << "*�Ƿ���ӽ����ﳵ��" << std::endl;
			std::cout << "*��1��ӽ����ﳵ,����������س�������һҳ" << std::endl;

			std::string decision;
			std::cin >> decision;
			clearScreen();
			i.printInfo();
			if (decision == "1")
			{
				int goodscount;
				std::cout << "*�����˻����Ϊ" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << user.getbalance() << std::endl;
				std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);
				switch (user.getlevelnum())
				{
				case 1:
					std::cout << "*��Ϊ" << user.getlevel() << "!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..." << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i, goodscount);
					std::cout << "*�ѳɹ���" << goodscount << "ƿ" << i.getname() << "����" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;
				case 2:
					std::cout << "*��Ϊ" << user.getlevel() << "�ڱ��̳ǹ�������" << std::setprecision(0) << std::setiosflags(std::ios::fixed) << (1 - Admin::discount[5]) * 100 << "%�Ż�!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..." << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i, goodscount);
					std::cout << "*�ѳɹ���" << goodscount << "ƿ" << i.getname() << "����" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;
				case 3:
					std::cout << "*��Ϊ" << user.getlevel() << "�ڱ��̳ǹ�������" << std::setprecision(0) << std::setiosflags(std::ios::fixed) << (1 - Admin::discount[8]) * 100 << "%�Ż�!" << std::endl;
					std::cout << "*��������Ҫ�������Ʒ����..." << std::endl;
					std::cin >> goodscount;
					cart.addgoods(i, goodscount);
					std::cout << "*�ѳɹ���" << goodscount << "ƿ" << i.getname() << "����" << "���빺�ﳵ��" << std::endl;
					Sleep(750);
					break;

				default:
					break;
				}
			}
			break;
		}
	}
	std::cout << std::setprecision(0)<<std::resetiosflags(std::ios::fixed);
	std::vector<Cart>::iterator iter = CARTs.begin();
	bool Foundcart = false;
	for (; iter != CARTs.end(); iter++)
	{
		if (!strcmp(iter->user.getusername(), cart.user.getusername()))
		{
			*iter = cart;
			Foundcart = true;
			break;
		}
	}
	if (!Foundcart)
	{
		CARTs.push_back(cart);
	}

	cart.WriteToFile(CARTs);
}
void view_cart_menu(User& user)
{
	Cart cart_view(user);
	std::vector<Cart> carts;
	cart_view.ReadFromFile(carts);
	FindCart(cart_view);
	//cart_view.printInfo();

	int ShoppingNum;
	std::string ShoppingString;
	std::cout << "*1.ɾ�����ﳵ" << std::endl;
	std::cout << "*2.���㹺�ﳵ" << std::endl;
	std::cout << "*��ѡ��Ҫ���еĲ���[1-2]:" << std::endl;
	std::cin >> ShoppingString;
	std::istringstream ShoppingStream(ShoppingString);
	ShoppingStream >> ShoppingNum;
	switch (ShoppingNum)
	{
	case 1: {
		view_cartdelete_menu(cart_view);
		break;
	}
	case 2:
	{
		view_check_menu(cart_view);
		break;
	}
	default:
		break;
	}
	
	
}
void view_cartdelete_menu(Cart& cart)
{
	int ShoppingNum;
	std::string ShoppingString;
	clearScreen();
	cart.printInfo();
	std::cout << "*��ѡ��Ҫɾ���Ĺ����Ż�����δ��ʾ�ı�ŷ�����һҳ:" << std::endl;
	std::cin >> ShoppingString;
	std::istringstream ShoppingStream(ShoppingString);
	ShoppingStream >> ShoppingNum;
	if (ShoppingNum > 0 && ShoppingNum < cart.goodsCount + 1)
	{
		cart.exportgoods(cart.goods[ShoppingNum - 1], ShoppingNum - 1);

		UpdateCart(cart);

		std::cout << "*ɾ���ɹ��������������..." << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
	}
}
void view_check_menu(Cart& cart)
{
	int ShoppingNum;
	std::string ShoppingString;
	clearScreen();
	cart.printInfo();
	std::cout << "*��ѡ��Ҫ����Ĺ����Ż�����δ��ʾ�ı�ŷ�����һҳ:"  << std::endl;
	std::cin >> ShoppingString;
	std::istringstream ShoppingStream(ShoppingString);
	ShoppingStream >> ShoppingNum;
	if (ShoppingNum > 0 && ShoppingNum < cart.goodsCount + 1)
	{
		if(cart.goods[ShoppingNum-1].getstatus() == "���¼�")
		{ 
			std::cout<< "*����ʧ��,����Ʒ���¼ܣ�" << std::endl;
		}
		else if (cart.goods[ShoppingNum - 1].getstorage()<cart.goodsAddCount[ShoppingNum-1])
		{
			std::cout << "*����ʧ��,����Ʒ��治�㣡" << std::endl;
		}
		else if (cart.user.getbalance() > cart.goods[ShoppingNum - 1].getprice() * cart.goodsAddCount[ShoppingNum - 1] * cart.user.getdiscount(cart.goods[ShoppingNum - 1].gettype_num()))//&&�����㹻
		{
			Date nowa = Get_Sys_Time();
			Bill temp_bill(cart.user, cart.goods[ShoppingNum - 1], cart.goodsAddCount[ShoppingNum - 1], nowa.year, nowa.month, nowa.day, cart.goods[ShoppingNum - 1].getprice() * cart.goodsAddCount[ShoppingNum - 1] * cart.user.getdiscount(cart.goods[ShoppingNum - 1].gettype_num()));
			std::vector<Bill> bills;
			std::vector<Bill> Adminbills;
			temp_bill.ReadFromFile(bills);
			temp_bill.ReadFromFile(Adminbills);
			bills.push_back(temp_bill);
			Adminbills.push_back(temp_bill);
			temp_bill.WriteToFile(bills);
			temp_bill.WriteToAdminFile(bills);
			cart.user.spendmoney(cart.goods[ShoppingNum - 1].getprice() * cart.goodsAddCount[ShoppingNum - 1] * cart.user.getdiscount(cart.goods[ShoppingNum - 1].gettype_num()));
			cart.goods[ShoppingNum - 1].sold(cart.goodsAddCount[ShoppingNum - 1]);
			UpdateMerchandise(cart.goods[ShoppingNum - 1]);
			if (cart.user.gettype()==3)
			{
				UpdateUser(cart.user);
			}
			else if (cart.user.gettype() == 4)
			{
				UpdateSuperUser(cart.user);
			}
			cart.exportgoods(cart.goods[ShoppingNum - 1], ShoppingNum - 1);
			
			UpdateCart(cart);
		
			
			std::cout << "*����ɹ���" << std::endl;
		}
		else
		{
			std::cout << "*����ʧ��,����ϵ����Ա��ֵ��" << std::endl;
		}
	}
	std::cout << "*�����������..." << std::endl;
	std::cin.ignore(100, '\n');
	std::cin.get();
}
void UpdateUser(User& user)
{
	std::vector<User> users;
	user.ReadFromFile(users);
	for (std::vector<User>::iterator it = users.begin(); it != users.end(); it++)
	{
		if (!strcmp(it->getusername(), user.getusername()))
		{
			users.erase(it);
			break;
		}
	}
	users.push_back(user);
	user.WriteToFile(users);
	return;
}
void UpdateSuperUser(User& user)
{
	std::vector<SuperUser> superusers;
	SuperUser temp_superuser;
	temp_superuser.ReadFromFile(superusers);

	for (std::vector<SuperUser>::iterator it = superusers.begin(); it != superusers.end(); it++)
	{
		if (!strcmp(it->getusername(), user.getusername()))
		{
			temp_superuser = *it;
			superusers.erase(it);
			break;
		}
	}
	temp_superuser.modify_money(user.getbalance());
	temp_superuser.modify_contact(user.getcontact());
	temp_superuser.modify_level_direct(user.getlevelnum());
	superusers.push_back(temp_superuser);
	temp_superuser.WriteToFile(superusers);
	return;
}
void UpdateMerchandise(Merchandise& merchandise)
{
	switch (merchandise.gettype_num())
	{
	case 1:
	{
		Book temp_book;
		std::vector<Book> books;
		temp_book.ReadFromFile(books);
		for (std::vector<Book>::iterator it1 = books.begin(); it1 != books.end(); it1++)
		{
			if (!strcmp(it1->getname(), merchandise.getname()))
			{
				temp_book = *it1;
				books.erase(it1);
				break;
			}
		}
		temp_book.changestorage(merchandise.getstorage());
		books.push_back(temp_book);
		temp_book.WriteToFile(books);
		break;
	}
		
	case 2:
	{
		Computer temp_PC;
		std::vector<Computer> PCs;
		temp_PC.ReadFromFile(PCs);
		for (std::vector<Computer>::iterator it2 = PCs.begin(); it2 != PCs.end(); it2++)
		{
			if (!strcmp(it2->getname(), merchandise.getname()))
			{
				temp_PC = *it2;
				PCs.erase(it2);
				break;
			}
		}
		temp_PC.changestorage(merchandise.getstorage());
		PCs.push_back(temp_PC);
		temp_PC.WriteToFile(PCs);
		break;
	}
		
	case 3:
	{
		Beverage temp_beverage;
		std::vector<Beverage> beverages;
		temp_beverage.ReadFromFile(beverages);
		for (std::vector<Beverage>::iterator it = beverages.begin(); it != beverages.end(); it++)
		{
			if (!strcmp(it->getname(), merchandise.getname()))
			{
				temp_beverage = *it;
				beverages.erase(it);
				break;
			}
		}
		temp_beverage.changestorage(merchandise.getstorage());
		beverages.push_back(temp_beverage);
		temp_beverage.WriteToFile(beverages);
		break;
	}
		

	default:
		break;
	}

	return;
}
void view_bill_menu(User& user)
{
	Bill bill_view(user);
	std::vector<Bill> bills;
	bill_view.ReadFromFile(bills);
	bool FoundBill = false;
	std::cout << "*�˵��û�:" <<user.getusername()<<std::endl;
	int count=1;
	for (std::vector<Bill>::iterator iter = bills.begin(); iter != bills.end();iter++)
	{
		if (!strcmp(iter->user.getusername(), user.getusername()))
		{

			std::cout << "*�������:" << count++ << std::endl;
			iter->printInfo();
			FoundBill = true;
		}

	}
	//for (auto i : bills)
	//{
	//	if (!strcmp(i.user.getusername(), user.getusername()))
	//	{
	//		std::cout << "*�������:" << count++ << std::endl;
	//		i.printInfo();
	//		FoundBill = true;
	//	}
	//}
	if (!FoundBill)
	{
		std::cout << "*�������Ķ�����Ϣ��" << std::endl;
		Sleep(1000);
	}
	else
	{
		char decide_button;
		std::cout << "*1)��ϸ�鿴����" << std::endl;
		std::cout << "*2)ɾ������" << std::endl;
		std::cout << "*3)������һҳ" << std::endl;
		std::cout << "*��ѡ����������[1-3]" << std::endl;
		std::cin >> decide_button;
		switch (decide_button)
		{
		case '1':
		{
			int ShoppingNum;
			std::cout << "*��ѡ��Ҫ��ϸ�鿴�Ķ�����Ż�����δ��ʾ�ı�ŷ�����һҳ:" << std::endl;
			std::cin >> ShoppingNum;
			clearScreen();
			if (ShoppingNum > 0 && ShoppingNum < count)
			{
				int recount = 1;
				for (auto i : bills)
				{
					if (!strcmp(i.user.getusername(), user.getusername()))
					{
						if (recount++==ShoppingNum)
						{

							i.printInfo();

							switch (i.goods.gettype_num())
							{
							case 1:
							{
								Book temp_book;
								std::vector<Book> books;
								temp_book.ReadFromFile(books);
								for (std::vector<Book>::iterator it1 = books.begin(); it1 != books.end(); it1++)
								{
									if (!strcmp(it1->getname(), i.goods.getname()))
									{
										it1->printInfo();
	/*									std::cout << "*����������" << i.goodsAddCount << std::endl;

										std::cout << "*�������ڣ�" << i.year << "��" << i.month << "��" << i.day << "��" << std::endl;

										std::cout << "*ʵ�ʸ���۸�:" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << i.goods.getprice() * i.goodsAddCount * user.getdiscount() << std::endl;
										std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);

		*/								std::cout << std::endl;
										break;
									}
								}
								break;
							}

							case 2:
							{
								Computer temp_PC;
								std::vector<Computer> PCs;
								temp_PC.ReadFromFile(PCs);
								for (std::vector<Computer>::iterator it2 = PCs.begin(); it2 != PCs.end(); it2++)
								{
									if (!strcmp(it2->getname(), i.goods.getname()))
									{
										it2->printInfo();
										/*std::cout << "*����������" << i.goodsAddCount << std::endl;

										std::cout << "*�������ڣ�" << i.year << "��" << i.month << "��" << i.day << "��" << std::endl;

										std::cout << "*ʵ�ʸ���۸�:" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << i.goods.getprice() * i.goodsAddCount * user.getdiscount() << std::endl;
										std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);*/

										std::cout << std::endl;
										break;
									}
								}
								break;
							}

							case 3:
							{
								Beverage temp_beverage;
								std::vector<Beverage> beverages;
								temp_beverage.ReadFromFile(beverages);
								for (std::vector<Beverage>::iterator it = beverages.begin(); it != beverages.end(); it++)
								{
									if (!strcmp(it->getname(), i.goods.getname()))
									{
										it->printInfo();
							/*			std::cout << "*����������" << i.goodsAddCount << std::endl;

										std::cout << "*�������ڣ�" << i.year << "��" << i.month << "��" << i.day << "��" << std::endl;

										std::cout << "*ʵ�ʸ���۸�:" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << i.goods.getprice() * i.goodsAddCount * user.getdiscount() << std::endl;
										std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);

							*/			std::cout << std::endl;
										break;
									}
								}
								break;
							}
							default:
								break;
							}
							break;
						}


					}
				}

			}
			std::cout << "*�����������" << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
		}
			break;
		case '2':
			//delete_bills

		{
			int ShoppingNum;
			std::cout << "*��ѡ��Ҫ��ϸɾ���Ķ�����Ż�����δ��ʾ�ı�ŷ�����һҳ:" << std::endl;
			std::cin >> ShoppingNum;
			bool FoundBill = false;
			if (ShoppingNum > 0 && ShoppingNum < count)
			{
				int recount = 1;
				for (std::vector<Bill>::iterator iter = bills.begin(); iter != bills.end();)
				{
					if (!strcmp(iter->user.getusername(), user.getusername()))
					{
						if (recount++ == ShoppingNum)
						{

							bills.erase(iter);
							FoundBill = true;
							std::cout << "*ɾ���ɹ�!" << std::endl;
							bill_view.WriteToFile(bills);
							break;
						}
						else
						{
							iter++;
						}
					}
					else
					{
						iter++;
					}
				}

			}
			if (!FoundBill)
			{
				std::cout << "*ɾ��ʧ��!" << std::endl;
			}
			std::cout << "*�����������" << std::endl;
			std::cin.ignore(100, '\n');
			std::cin.get();
		}
			break;
		case '3':
			break;

		default:
			break;
		}
		
	}

}
void tourist_menu()
{
	Tourist temp_tourist;
	char instruction;
	do
	{
		clearScreen();

		std::cout << "*��ӭ������Ʒ���ģ��..." << std::endl;
		std::cout << "*1)���������Ʒ" << std::endl;
		std::cout << "*2)���������Ʒ" << std::endl;
		std::cout << "*3)������һҳ����/��¼�˺�" << std::endl;
		std::cout << "*��ѡ����������[1-3]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case '1':
			temp_tourist.viewGoods();
			break;
		case '2':
			temp_tourist.viewGoodsWithCategory();
			break;
		case '3':
			break;
		default:
			break;
		}

	} while (instruction != '3');
}
bool checkUsersName(char* username)
{
	bool Pass = true;
	User user;
	Admin admin;
	SuperUser superuser;
	std::vector<User>users;
	std::vector<Admin>admins;
	std::vector<SuperUser>superusers;
	user.ReadFromFile(users);
	admin.ReadFromFile(admins);
	superuser.ReadFromFile(superusers);
	for (auto i : users)
	{
		if (!strcmp(i.getusername(), username))
		{
			Pass = false;
			break;
		}
	}
	for (auto i : admins)
	{
		if (!strcmp(i.getusername(), username))
		{
			Pass = false;
			break;
		}
	}
	for (auto i : superusers)
	{
		if (!strcmp(i.getusername(), username))
		{
			Pass = false;
			break;
		}
	}
	if (!Pass)
	{
		std::cout << "*������ѡ���˻���,���˺��ѱ�ע�ᣡ" << std::endl;
		std::cout << "�����������..." << std::endl;
		std::cin.ignore(100, '\n');
		std::cin.get();
	}

	return Pass;
}