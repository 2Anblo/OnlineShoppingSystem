#include "Cart.h"
#include "time.h"
Cart::Cart():user(),goods(nullptr),goodsCount(0),goodsAddCount(nullptr)
{}
Cart::Cart(User& my_user):user(my_user), goods(nullptr), goodsCount(0),goodsAddCount(nullptr)
{

}
Cart::Cart(User& my_user, Merchandise* my_goods, size_t my_count,int* my_goods_Count):user(my_user),goods(new Merchandise[my_count]),goodsCount(my_count),goodsAddCount(new int[my_count])
{
	for (size_t i = 0; i < goodsCount; i++)
	{
		goodsAddCount[i] = my_goods_Count[i];
		goods[i] = my_goods[i];
	}
}
Cart::~Cart()
{
	//delete[]goods;
}
std::ifstream& operator >> (std::ifstream& in, Cart& cart)//Use template
{
	size_t cnt;
	in.read((char*)&cnt, sizeof(cnt));
	
	
	if (in)
	{
		cart.goodsCount = cnt;
		in >> cart.user;
		//if (!cart.goods)
		//{
			cart.goodsAddCount = new int[cnt];
			cart.goods = new Merchandise[cnt];
		//}
		//else
		//{
		//	if(cart.goods)
		//	delete[]cart.goods;
		//	if(cart.goodsAddCount)
		//	delete[]cart.goodsAddCount;
		//	cart.goods = new Merchandise[cnt];
		//	cart.goodsAddCount = new int[cnt];
		//}
		for (size_t i=0; i < cnt; i++)
		{

			in >> cart.goods[i];
			in.read((char*)&cart.goodsAddCount[i], sizeof(cart.goodsAddCount[i]));
		}
	}
	
	return in;
}
std::ofstream& operator << (std::ofstream& out, Cart& cart)//Use template
{
	out.write((char*)&cart.goodsCount, sizeof(cart.goodsCount));
	out << cart.user;
	for (size_t i=0; i < cart.goodsCount; i++)
	{
		out << cart.goods[i];
		out.write((char*)&cart.goodsAddCount[i], sizeof(cart.goodsAddCount[i]));
	}
	
	return out;
}
void Cart::ReadFromFile(std::vector<Cart>& carts)
{
	std::ifstream fin("Cart.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	Cart cart;
	while (fin >> cart)
	{
		carts.push_back(cart);
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
void Cart::WriteToFile(std::vector<Cart>& carts)
{
	std::ofstream fout("Cart.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<Cart>::iterator it = carts.begin();
	for (; it != carts.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
Cart& Cart::operator=(const Cart& other)
{
	if (this != &other)
	{

		user = other.user;
		goodsCount = other.goodsCount;
		goods = new Merchandise[goodsCount];
		goodsAddCount = new int[goodsCount];
		for (size_t i = 0; i < goodsCount; i++)
		{
			goods[i] = other.goods[i];
			goodsAddCount[i] = other.goodsAddCount[i];
		}
	}
	return *this;
}
void Cart::addgoods(Merchandise& good,int& goodCount)
{
	goodsCount++;
	Merchandise* newGoods = new Merchandise[goodsCount];
	int* newGoodsCount = new int[goodsCount];
	for (size_t i = 0; i < goodsCount-1; i++)
	{
		newGoods[i]=goods[i];
		newGoodsCount[i] = goodsAddCount[i];
	}
	newGoods[goodsCount-1] = good;
	newGoodsCount[goodsCount - 1] = goodCount;

	goods = newGoods;
	goodsAddCount = newGoodsCount;
	//std::vector<Cart> temp_carts;
	//this->ReadFromFile(temp_carts);

}
void FindCart(Cart& cart)
{
	std::vector<Cart> carts;
	cart.ReadFromFile(carts);
	for (auto i : carts)
	{
		if (!strcmp(i.user.getusername(), cart.user.getusername()))
		{
			cart = i;
			break;
		}
	}
	return;
}
void UpdateCart(Cart& cart)
{
	std::vector<Cart> carts;
	cart.ReadFromFile(carts);
	for (std::vector<Cart>::iterator it = carts.begin(); it != carts.end(); it++)
	{
		if (!strcmp(it->user.getusername(), cart.user.getusername()))
		{
			carts.erase(it);
				break;
		}
	}
	carts.push_back(cart);
	cart.WriteToFile(carts);
	return;
}
void Cart::printInfo()
{
	std::cout << "*用户名:" << user.getusername() << std::endl;
	std::cout << "******************************************" <<  std::endl;
	std::cout << std::endl;
	for (size_t cnt = 0; cnt < goodsCount; cnt++)
	{
		std::cout << "*购物车内编号" << cnt+1<< std::endl;
		goods[cnt].printInfo();
		std::cout<<"*购物车中件数:" << goodsAddCount[cnt]<<std::endl;
		std::cout << "*折后每件价格为:" << std::setprecision(2)<<std::setiosflags(std::ios::fixed)<<goods[cnt].getprice()*user.getdiscount(goods[cnt].gettype_num()) << std::endl;
		std::cout<<std::endl;
	}
}
void Cart::exportgoods(Merchandise& good,int num)
{

	
	if (goodsCount > 1)
	{
		Merchandise* newGoods = new Merchandise[goodsCount - 1];
		int* newGoodsCount = new int[goodsCount - 1];
		for (size_t i = num; i < goodsCount - 1; i++)
		{
			goods[i] = goods[i + 1];

		}
		goodsCount--;
		for (size_t i = 0; i < goodsCount; i++)
		{
			newGoods[i] = goods[i];
			newGoodsCount[i] = goodsAddCount[i];

		}
		delete[]goods;
		delete[]goodsAddCount;
		goods = new Merchandise[goodsCount];
		goodsAddCount = new int[goodsCount];
		goods = newGoods;
		goodsAddCount = newGoodsCount;
	}
	else
	{
		delete[]goods;
		delete[]goodsAddCount;
		goods = nullptr;
		goodsAddCount = nullptr;
		goodsCount--;
	}

	
}

Bill::Bill():user(), goods(),goodsAddCount(0), year(0), month(0), day(0),payforreal(0)
{

}
Bill::Bill(User& my_user) :user(my_user), goods(), goodsAddCount(0), year(0), month(0), day(0),payforreal(0)
{

}
Bill::Bill(User& my_user, Merchandise my_goods, int my_goods_Count, int my_year, int my_month, int my_day,double my_payforreal): user(my_user), goods(my_goods)
{

	
		goodsAddCount = my_goods_Count;
		year = my_year;
		month= my_month;
		day = my_day;
		payforreal = my_payforreal;
	

}
std::ifstream& operator >> (std::ifstream& in, Bill& bill)
{

	if (in)
	{
			in >> bill.user;
			in >> bill.goods;
			in.read((char*)&bill.goodsAddCount, sizeof(bill.goodsAddCount));
			in.read((char*)&bill.year, sizeof(bill.year));
			in.read((char*)&bill.month, sizeof(bill.month));
			in.read((char*)&bill.day, sizeof(bill.day));
			in.read((char*)&bill.payforreal, sizeof(bill.payforreal));
	}

	return in;
}
std::ofstream& operator << (std::ofstream& out, Bill& bill)
{
		out << bill.user;
		out << bill.goods;
		out.write((char*)&bill.goodsAddCount, sizeof(bill.goodsAddCount));
		out.write((char*)&bill.year, sizeof(bill.year));
		out.write((char*)&bill.month, sizeof(bill.month));
		out.write((char*)&bill.day, sizeof(bill.day));
		out.write((char*)&bill.payforreal, sizeof(bill.payforreal));

	return out;
}
void Bill::ReadFromFile(std::vector<Bill>& bills)
{
	std::ifstream fin("Bill.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	Bill bill;
	while (fin >> bill)
	{
		bills.push_back(bill);
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
void Bill::ReadFromAdminFile(std::vector<Bill>& bills)
{
	std::ifstream fin("AdminBill.dat", std::ios::binary);
	if (!fin)
	{
		std::cout << "Fail to open the file!" << std::endl;
		return;
	}
	Bill bill;
	while (fin >> bill)
	{
		bills.push_back(bill);
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
void Bill::WriteToFile(std::vector<Bill>& bills)
{
	std::ofstream fout("Bill.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<Bill>::iterator it = bills.begin();
	for (; it != bills.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
void Bill::WriteToAdminFile(std::vector<Bill>& bills)
{
	std::ofstream fout("AdminBill.dat", std::ios::binary);
	if (!fout)
	{
		std::cout << "Fail to open the File!" << std::endl;
		return;
	}
	std::vector<Bill>::iterator it = bills.begin();
	for (; it != bills.end(); it++)
	{
		fout << *it;
	}
	fout.close();
}
void Bill::printInfo()
{


	std::cout << "*商品名称：" << goods.getname() << std::endl;

	std::cout << "*商品单价：" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << goods.getprice() << std::endl;
	std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);

	std::cout << "*购买数量：" << goodsAddCount << std::endl;

	std::cout << "*购买日期：" << year<<"年"<<month<<"月"<<day<<"日" << std::endl;

	std::cout << "*实际付款价格:" << std::setprecision(2) << std::setiosflags(std::ios::fixed) << payforreal << std::endl;
	std::cout << std::setprecision(0) << std::resetiosflags(std::ios::fixed);

	std::cout << std::endl;
}