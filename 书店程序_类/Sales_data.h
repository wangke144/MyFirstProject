#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Sales_data
{
	//数据成员
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	//新增的构造函数
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { };
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) { };

	istream &read(istream &is, Sales_data &item)
	{
		double price = 0;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = price * item.units_sold;

		return is;
	}

	Sales_data(std::istream &is) 
	{
		//is是输入的信息，this是一个sala_data的对象
		read(is, *this);
	};

	//新成员 关于Sales_data的操作
	//isbn
	string isbn() const { return bookNo; }

	//combine
	Sales_data& combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;

		return *this;
	};

	//平均价格
	double Sales_data::avg_price() const
	{
		if(units_sold)
		{
			return revenue / units_sold;
		}
		else {
			return 0;
		}
	}
};

//Sales_data内的非接口成员函数
//两个对象的和
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);

	return sum;
}

//打印交易信息
std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();

	return os;
}
