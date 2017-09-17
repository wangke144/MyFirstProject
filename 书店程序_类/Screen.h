#pragma once
#include<iostream>
#include<string>
using namespace std;
class Screen {
public:
	typedef std::string::size_type pos;

	//���캯��
	Screen() = default;//Ĭ�ϵĹ��캯��
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
	//��ӡ����
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
	//���ݳ�Ա
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	void do_display(std::ostream &os) const
	{
		os << contents;
	}
};

//���ⲿ�ĳ�Ա����
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