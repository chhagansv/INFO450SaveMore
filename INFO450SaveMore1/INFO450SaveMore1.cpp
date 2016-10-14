// INFO450SaveMore1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
	using namespace std;


struct date
{
	int d, m, y;
};

class account
{
	int ac_no; 
	date creation;
	float rate;
	float bal;

public: account()
{
	ac_no = 0;
	creation = date(); 
	rate = 0;
	bal = 0;
}

		account(int a, date c, float r, float b)
		{
			ac_no = a;
			creation = c; 
			rate = r;
			bal = b;
		}

		void setDate(date d)
		{
			creation.d = d.d;
			creation.m = d.m;
			creation.y = d.y;
		}

		date getDate()
		{
			return date();
		}

		void setAccountNumber(int acno)
		{
			ac_no = acno;
		}

		int getAccountNumber()
		{
			return ac_no;
		}

		void setAccountRate(float r)
		{
			rate = r;
		}

		float getAccountRate()
		{
			return rate;
		}

		void setBalance(float b)
		{
			bal = b;
		}

		float getBalance()
		{
			return bal;
		}

		bool withdraw(float b)
		{
			if (bal < b)
				return false;
			bal = bal - b;
			return true;
		}

		void deposit(float b)
		{
			bal = bal + b;
		}

		void display()
		{
			cout << "Account Number:" << ac_no << endl;
			cout << "Interest Rate:" << rate << endl;
			cout << "Balance:" << bal << endl;
		}
};

class Savings :public account
{
public: void setRate()
{
	float bal = getBalance();
	if (bal < 10000)
	{
		account::setAccountRate(1);
	}
	else
	{
		account::setAccountRate(2);
	}
}

		void setBalance(float b)
		{
			account::setBalance(b);
			setAccountRate(5.00);
		}

		bool withdraw(float w)
		{
			bool b = account::withdraw(w);
			b = account::withdraw(2);
			return b;
		}
};

class Checking :public account
{
public: void setBalance(float b)
{
	account::setBalance(b);
	if (getBalance() < 500)
		account::withdraw(5);
}

		bool withdraw(float b)
		{
			if (account::withdraw(b))
			{
				if (getBalance() < 500)
					return account::withdraw(5);
			}
			return false;
		}
};

class CD :public account
{
	int term;
public: CD(int a, date c, float r, float b, int t) :account(a, c, r, b)
{
	term = t;
	update();
}

		void update()
		{
			if (term < 5)
			{
				account::setAccountRate(5);
			}
			else
			{
				account::setAccountRate(10);
			}
		}

		bool withdraw(float b)
		{
		if (getSystemDate() - getDate() < term)
		{
		float w = 10 * getBalance() / 100;
		account::withdraw(w);
		}
		return account::withdraw(b);
		}
};

int main()
{
	Savings ac1;
	ac1.setBalance(10000);
	ac1.setRate();

	Checking ac2;
	ac2.setBalance(600);

	CD ac3(100, date(), 0, 10000, 3);

	ac1.display();
	ac2.display();
	ac3.display();

	ac2.withdraw(200);
	ac1.withdraw(1000);
	ac3.withdraw(2000);
};

    return 0;
}

