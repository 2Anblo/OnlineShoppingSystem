#include "Login.h"
User::User(char* my_username, char* my_password):Person(my_username,my_password,3)
{

}
User::User()
{

}
std::ifstream& operator >> (std::ifstream& in, User& user)//Use template
{
	char user_i[50];
	char pass[50];

	in.read((char*)&user_i, sizeof(user_i));

	in.read((char*)&pass, sizeof(pass));
	if (in)
	{
		strcpy(user.username, user_i);
		strcpy(user.password, pass);
	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, User& user)//Use template
{
	char user_i[50];
	char pass[50];
	strcpy(user_i, user.username);
	strcpy(pass, user.password);
	if (out)
	{
		out.write((char*)&user_i, sizeof(user_i));
		out.write((char*)&pass, sizeof(pass));
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
		std::cout << "*文件读取完毕！" << std::endl;
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
char* User::getusername()
{
	return username;
}
char* User::getpassword()
{
	return password;
}