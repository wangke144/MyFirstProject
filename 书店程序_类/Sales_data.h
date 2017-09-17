#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Sales_data
{
	//���ݳ�Ա
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	//�����Ĺ��캯��
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
		//is���������Ϣ��this��һ��sala_data�Ķ���
		read(is, *this);
	};

	//�³�Ա ����Sales_data�Ĳ���
	//isbn
	string isbn() const { return bookNo; }

	//combine
	Sales_data& combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;

		return *this;
	};

	//ƽ���۸�
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

//Sales_data�ڵķǽӿڳ�Ա����
//��������ĺ�
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);

	return sum;
}

//��ӡ������Ϣ
std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();

	return os;
}
