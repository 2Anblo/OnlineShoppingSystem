#include "Login.h"
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
	/*char user[50];
	char pass[50];
	strcpy(user, admin.username);
	strcpy(pass, admin.password);
	if (out)
	{
		out.write((char*)&user, sizeof(user));
		out.write((char*)&pass, sizeof(pass));
	}*/
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
	while (fin >> admin)
	{
		admins.push_back(admin);
	}
	if (fin.eof())
	{
		std::cout << "*文件读取完毕！" << std::endl;
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