#include "Merchandise.h"
#include "Login.h"
Person::Person(char* my_username, char* my_password,int type_t)
{
	strcpy(username,my_username);
	strcpy(password,my_password);
	type = type_t;
}
Person::Person(char* my_username, int type_t)
{
	strcpy(username, my_username);
	type = type_t;
}
Person::Person()
{

}

std::ifstream& operator >> (std::ifstream& in, Person& person)//Must With Cite
{
	char user[50];
	char pass[50];

	in.read((char*)&user, sizeof(user));

	in.read((char*)&pass, sizeof(pass));
	if (in)
	{
		strcpy(person.username, user);
		strcpy(person.password, pass);
	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, Person& person)//Must With Cite
{
	char user[50];
	char pass[50];
	strcpy(user, person.username);
	strcpy(pass, person.password);
	if (out)
	{
		out.write((char*)&user, sizeof(user));
		out.write((char*)&pass, sizeof(pass));
	}
	return out;
}
void Person::ReadFromFile(std::vector<Person>people)
{
	std::ifstream fin("Person.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	Person person;
	while (fin >> person)
	{
		people.push_back(person);
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
void Person::WriteToFile(std::vector<Person>people)
{
	std::ofstream fout("Person.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<Person>::iterator it = people.begin();
	for (; it != people.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}