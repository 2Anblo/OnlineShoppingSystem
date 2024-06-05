#include "Login.h"
SuperUser::SuperUser(char* my_username, char* my_password, char* my_contact, int my_level, double my_balance):
	User(my_contact,my_level,my_balance),Person(my_username,my_password,4)
{

}
SuperUser::SuperUser(char* my_username, char* my_password):Person(my_username, my_password, 4)
{

}
SuperUser::SuperUser()
{

}
void SuperUser::ReadFromFile(std::vector<SuperUser>& superusers)
{
	std::ifstream fin("SuperUser.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	SuperUser superuser;
	while (fin >> superuser)
	{
		superusers.push_back(superuser);
	}
	if (fin.eof())
	{
	
	}
	else if (fin.fail())
	{
		std::cout << "Fail to read the file!" << std::endl;
	}
	fin.close();
}
void SuperUser::WriteToFile(std::vector<SuperUser>& superusers)
{
	std::ofstream fout("SuperUser.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<SuperUser>::iterator it = superusers.begin();
	for (; it != superusers.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
std::ifstream& operator >> (std::ifstream& in, SuperUser& superuser)
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
		strcpy(superuser.username, user_i);
		strcpy(superuser.password, pass);
		strcpy(superuser.contact, conta);
		superuser.level = lev;
		superuser.balance = balanc;
	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, SuperUser& superuser)
{
	char user_i[50];
	char pass[50];
	char conta[20];
	int lev;
	double balanc;
	strcpy(user_i, superuser.username);
	strcpy(pass, superuser.password);
	strcpy(conta, superuser.contact);
	lev = superuser.level;
	balanc = superuser.balance;
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