#include "Merchandise.h"
#include "Login.h"
Book::Book() {type = 1; }
Book::Book(char* my_number, char* my_name, double my_price, int my_storage, bool my_status, char*my_writer,char*my_publish) :Merchandise(my_number, my_name, my_price, my_storage, my_status, 1)
{
	strcpy(writer, my_writer);
	strcpy(publish, my_publish);
}
std::ifstream& operator >> (std::ifstream& in, Book& book)
{
	char my_number[10];
	char my_name[50];
	double my_price;
	int my_storage;
	bool my_status = true;
	int my_type;
	char my_writer[50];
	char my_publish[50];

	in.read((char*)&my_number, sizeof(my_number));
	in.read((char*)&my_name, sizeof(my_name));
	in.read((char*)&my_price, sizeof(my_price));
	in.read((char*)&my_storage, sizeof(my_storage));
	in.read((char*)&my_status, sizeof(my_status));
	in.read((char*)&my_type, sizeof(my_type));
	in.read((char*)&my_writer, sizeof(my_writer));
	in.read((char*)&my_publish, sizeof(my_publish));
	if (in)
	{
		strcpy(book.number, my_number);
		strcpy(book.name, my_name);
		book.price = my_price;
		book.storage = my_storage;
		book.status = my_status;
		book.type = my_type;
		strcpy(book.writer, my_writer);
		strcpy(book.publish, my_publish);
	}
	return in;
}
std::ofstream& operator << (std::ofstream& out, Book& book)
{
	out.write((char*)&book.number, sizeof(book.number));
	out.write((char*)&book.name, sizeof(book.name));
	out.write((char*)&book.price, sizeof(book.price));
	out.write((char*)&book.storage, sizeof(book.storage));
	out.write((char*)&book.status, sizeof(book.status));
	out.write((char*)&book.type, sizeof(book.type));
	out.write((char*)&book.writer, sizeof(book.writer));
	out.write((char*)&book.publish, sizeof(book.publish));
	return out;
}
void Book::ReadFromFile(std::vector<Book>& books)
{
	std::ifstream fin("Book.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	Book book;
	while (fin >> book)
	{
		books.push_back(book);
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
void Book::WriteToFile(std::vector<Book>& books)
{
	std::ofstream fout("Book.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<Book>::iterator it = books.begin();
	for (; it != books.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
void add_Book()
{

	clearScreen();
	char my_number[10];
	char my_name[50];
	double my_price;
	int my_storage;
	bool my_status = 1;
	char my_writer[50];
	char my_publish[50];
	
	std::cout << "*请输入商品编号：" << std::endl;
	std::cin >> my_number;
	if (!checkGoodsNumber(my_number))
	{
		return;
	}
	std::cout << "*请输入商品名称：" << std::endl;
	std::cin >> my_name;
	std::cout << "*请输入商品价格：" << std::endl;
	std::cin >> my_price;
	std::cout << "*请输入商品库存：" << std::endl;
	std::cin >> my_storage;
	std::cout << "*请输入作者：" << std::endl;
	std::cin >> my_writer;
	std::cout << "*请输入出版社：" << std::endl;
	std::cin >> my_publish;

	std::vector<Book> books;
	Book temp(my_number, my_name, my_price, my_storage, my_status, my_writer, my_publish);
	temp.ReadFromFile(books);
	books.push_back(temp);

	temp.WriteToFile(books);
	std::cout << "创建成功！按任意键继续..." << std::endl;
	std::cin.ignore(100, '\n');
	std::cin.get();
	return;
}
void Book::printInfo()
{
	std::cout << "*商品编号：" << number << std::endl;

	std::cout << "*商品名称：" << name << std::endl;

	std::cout << "*商品价格：" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << price << std::endl;
	std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);

	std::cout << "*商品库存：" << storage << std::endl;

	std::cout << "*作者：" << writer << std::endl;

	std::cout << "*出版社：" << publish << std::endl;

	std::cout << "*状态：" << getstatus() << std::endl;


	std::cout << std::endl;

}
char* Book::getnumber()
{
	return number;
}
std::string Book::getstatus()
{
	std::string temp;
	if (status == true)
	{
		temp = "上架中";
	}
	else
	{
		temp = "已下架";
	}
	return temp;
}
void Book::modifystatus()
{
	status = !status;
}
char* Book::getname()
{
	return name;
}
Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		strcpy(number, other.number);
		strcpy(name, other.name);
		price = other.price;
		storage = other.storage;
		status = other.status;
		strcpy(writer, other.writer);
		strcpy(publish, other.publish);

	}
	return *this;
}
