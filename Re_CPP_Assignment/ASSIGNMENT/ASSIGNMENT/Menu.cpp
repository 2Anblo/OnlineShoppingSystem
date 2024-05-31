#include "Login.h"
void clearScreen()
{
	system("cls");
}
void ManageUsers(Admin& admin)
{
	//std::cout << "*��ӭ��" << admin.getusername() << ",���Ľ�ɫ�ǹ���Ա!�������¹���Ȩ�ޣ�" << std::endl;
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
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			//create_User_Menu();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}

	} while (instruction!=6);
	
}
void shoppingMenu()
{
	std::cout << "*1)����Ա" << std::endl;
	std::cout << "*2)�û�" << std::endl;
	std::cout << "*3)������ҳ" << std::endl;
	std::cout << "*��ѡ��ע���û�����[1-3]" << std::endl;
}
void manageMenu(Admin&admin)
{
	int instruction;
	do
	{
		clearScreen();
		std::cout << "*��ӭ��" << admin.getusername() << ",���Ľ�ɫ�ǹ���Ա!�������¹���Ȩ�ޣ�" << std::endl;
		std::cout << "*1)��Ʒ�������" << std::endl;
		std::cout << "*2)��Ʒ����" << std::endl;
		std::cout << "*3)�û�����" << std::endl;
		std::cout << "*4)ͳ��" << std::endl;
		std::cout << "*5)�˳�" << std::endl;
		std::cout << "*��ѡ����������[1-5]" << std::endl;
		std::cin >> instruction;
		switch (instruction)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			ManageUsers(admin);
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (instruction!=5);
	
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
		std::cout << "*�������˻����룺" << std::endl;
		std::cin >> password;
		std::vector<Admin> admins;
		Admin temp(account, password);
		temp.ReadFromFile(admins);
		admins.push_back(temp);
		/*for (auto i : admins)
		{
			i.printUsername();
		}*/
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
	std::cout << "*�������˻�����" << std::endl;
	std::cin >> account;
	std::cout << "*�������˻����룺" << std::endl;
	std::cin >> password;
	std::vector<User> users;
	User temp(account, password);
	temp.ReadFromFile(users);
	users.push_back(temp);
	/*for (auto i : admins)
	{
		i.printUsername();
	}*/
	temp.WriteToFile(users);
	std::cout << "�����ɹ���" << std::endl;
	Sleep(1000);
	return;
}
void create_Menu()
{
	int EnrollType;
	do {
		clearScreen();
		std::cout << "*1)����Ա" << std::endl;
		std::cout << "*2)�û�" << std::endl;
		std::cout << "*3)������ҳ" << std::endl;
		std::cout << "*��ѡ��ע���û�����[1-3]" << std::endl;
		std::cin >> EnrollType;
		switch (EnrollType)
		{
		case 1:
			create_Admin_Menu();
			break;
		case 2:
			create_User_Menu();
			break;
		case 3:
			break;
		default:
			break;
		}
	} while (EnrollType!=3);
}
void sub_LoginMenu()
{
	char account[50];
	char password[50];
	std::cout << "�������˺�:" ;

	std::cout << std::endl;//Okay to delete
	std::cin >> account;
	std::cout << "����������:" ;
	std::cin >> password;
	std::cout << std::endl;
	bool user_pass=false;
	bool admin_pass=false;
	User temp_user(account, password);
	Admin temp_admin(account, password);
	std::vector<User> users;
	std::vector<Admin> admins;
	temp_user.ReadFromFile(users);
	temp_admin.ReadFromFile(admins);
	for (auto use : users)
	{
		if (!strcmp(use.getusername(), account) && !strcmp(use.getpassword(), password))
		{
			user_pass = true;
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
	if (user_pass || admin_pass)
	{
		if (user_pass)
		{
			std::cout << "*��ӭ��"<<account<<",���Ľ�ɫ����ͨ�û�!�������¹���Ȩ�ޣ�" << std::endl;
			shoppingMenu();
		}
		else
		{
			//std::cout << "*��ӭ��" << account << ",���Ľ�ɫ�ǹ���Ա!�������¹���Ȩ�ޣ�" << std::endl;
			manageMenu(temp_admin);
		}
	}
	Sleep(1000);
	//std::cout << "*3)������ҳ" << std::endl;
	//std::cout << "*��ѡ��ע���û�����[1-3]" << std::endl;
	
}
void LoginMenu()
{
	int LoginWay;

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
		case 1:
			create_Menu();
			break;
		case 2:
			sub_LoginMenu();
			break;
		case 3:
			//Directly enter the online shop
			break;
		case 4:
			break;
		default:
			std::cout << "*������1-4֮�����!" << std::endl;
			break;
		}
	} while (LoginWay != 4);
}