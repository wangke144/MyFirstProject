#pragma once
#include<iostream>
#include<string>
using namespace std;
class Screen {
public:
	typedef std::string::size_type pos;

	//构造函数
	Screen() = default;//默认的构造函数
	Screen(pos ht, pos wd, char c) :
		height(ht), width(wd), contents(ht*wd, c) { };
	Screen(pos ht, pos wd) :
		height(ht), width(wd), contents(ht*wd, ' ') { };

	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	//打印内容
	Screen &display(ostream &os)
	{
		do_display(os);
		return *this;
	}

	const Screen &display(ostream &os) const
	{
		do_display(os);
		return *this;
	}

private:
	//数据成员
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	void do_display(std::ostream &os) const
	{
		os << contents;
	}
};

//类外部的成员函数
inline

Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}


char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}