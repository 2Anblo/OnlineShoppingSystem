#include "Login.h"
void clearScreen()
{
	system("cls");
}
void ManageUsers(Admin& admin)
{
	//std::cout << "*欢迎您" << admin.getusername() << ",您的角色是管理员!具有以下功能权限：" << std::endl;
	int instruction;
	do
	{
		clearScreen();
		std::cout << "*1)增加一名用户" << std::endl;
		std::cout << "*2)删除一名用户" << std::endl;
		std::cout << "*3)修改用户信息" << std::endl;
		std::cout << "*4)查找用户" << std::endl;
		std::cout << "*5)用户充值" << std::endl;
		std::cout << "*6)返回上一页" << std::endl;
		std::cout << "*请选择输入命令[1-6]" << std::endl;
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
	std::cout << "*1)管理员" << std::endl;
	std::cout << "*2)用户" << std::endl;
	std::cout << "*3)返回首页" << std::endl;
	std::cout << "*请选择注册用户类型[1-3]" << std::endl;
}
void manageMenu(Admin&admin)
{
	int instruction;
	do
	{
		clearScreen();
		std::cout << "*欢迎您" << admin.getusername() << ",您的角色是管理员!具有以下功能权限：" << std::endl;
		std::cout << "*1)商品分类管理" << std::endl;
		std::cout << "*2)商品管理" << std::endl;
		std::cout << "*3)用户管理" << std::endl;
		std::cout << "*4)统计" << std::endl;
		std::cout << "*5)退出" << std::endl;
		std::cout << "*请选择输入命令[1-5]" << std::endl;
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
	std::cout << "*请输入管理员秘钥" << std::endl;
	std::cin >> input_token;
	if (input_token == admin_token)
	{
		clearScreen();
		char account[50];
		char password[50];
		std::cout << "*请输入账户名：" << std::endl;
		std::cin >> account;
		std::cout << "*请输入账户密码：" << std::endl;
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
		std::cout << "创建成功！" <<std:: endl;
		Sleep(1000);
		return;
	}
	else
	{
		std::cout << "*秘钥错误,请重试！" << std::endl;
		Sleep(1000);
	}
}
void create_User_Menu()
{
	clearScreen();
	char account[50];
	char password[50];
	std::cout << "*请输入账户名：" << std::endl;
	std::cin >> account;
	std::cout << "*请输入账户密码：" << std::endl;
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
	std::cout << "创建成功！" << std::endl;
	Sleep(1000);
	return;
}
void create_Menu()
{
	int EnrollType;
	do {
		clearScreen();
		std::cout << "*1)管理员" << std::endl;
		std::cout << "*2)用户" << std::endl;
		std::cout << "*3)返回首页" << std::endl;
		std::cout << "*请选择注册用户类型[1-3]" << std::endl;
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
	std::cout << "请输入账号:" ;

	std::cout << std::endl;//Okay to delete
	std::cin >> account;
	std::cout << "请输入密码:" ;
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
			std::cout << "*欢迎您"<<account<<",您的角色是普通用户!具有以下功能权限：" << std::endl;
			shoppingMenu();
		}
		else
		{
			//std::cout << "*欢迎您" << account << ",您的角色是管理员!具有以下功能权限：" << std::endl;
			manageMenu(temp_admin);
		}
	}
	Sleep(1000);
	//std::cout << "*3)返回首页" << std::endl;
	//std::cout << "*请选择注册用户类型[1-3]" << std::endl;
	
}
void LoginMenu()
{
	int LoginWay;

	do {
		clearScreen();

		std::cout << "*欢迎您使用在线商城系统*" << std::endl;
		std::cout << "*1)创建一个新账号" << std::endl;
		std::cout << "*2)登录已有账号" << std::endl;
		std::cout << "*3)以游客模式进入商城" << std::endl;
		std::cout << "*4)退出系统" << std::endl;
		std::cout << "*请选择访问界面[1-4]" << std::endl;
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
			std::cout << "*请输入1-4之间的数!" << std::endl;
			break;
		}
	} while (LoginWay != 4);
}