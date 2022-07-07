#include <iostream>
#include <functional>
#include <unistd.h>

class Account
{
	private:
		double balance, lastWid, lastDep;
		friend class Inquire;

	public:
		Account(const double& balance) : balance(balance), lastWid(0), lastDep(0) {}
		void withdraw(const double& amt)
		{
			lastWid = amt;
			balance -= amt;
		}
		void deposit(const double& amt)
		{
			lastDep = amt;
			balance += amt;
		}
};

class Inquire
{
	public:
		void showBalance(const Account& acc)
		{
			std::cout<<"Your account balance is: "<<acc.balance<<std::endl;
		}
		double lastWidthdrawalAmt(const Account& acc) const
		{
			return acc.lastWid;
		}
		double lastDepositAmt(const Account& acc) const
		{
			return acc.lastDep;
		}
};

int main(int argc, char* argv[])
{
	if (argc < 2){
		std::cerr<<"Please feed initial balance as a program argument. Aborting!"<<std::endl;
		return -1;
	}

	int choice{3};

	std::cout<<"Welcome to friendly bank. What would you like to do?\n1) Widthdraw money\n2) Deposit money\n3) Show account balance\n4) Exit"<<std::endl;
	std::cin >> choice;

	if (choice > 4 || choice < 1){
		std::cerr<<"Invalid choice! Exiting..."<<std::endl;
		return -1;
	}

	Account acc = std::stod(argv[1]);
	Inquire inq;

	std::function<void(const Account&)> balance = std::bind(&Inquire::showBalance, &inq, std::placeholders::_1);
	std::function<double(const Inquire&, const Account&)> withdrawal = &Inquire::lastWidthdrawalAmt;
	std::function<double(const Inquire&, const Account&)> deposit = &Inquire::lastDepositAmt;

	double amount{0};

	switch(choice)
	{
		case 1:
			std::cout<<"Enter amount to be withdrawn:\t";
			std::cin >> amount;
			acc.withdraw(amount);
			break;
		case 2:
			std::cout<<"Enter amount to be deposited:\t";
			std::cin >> amount;
			acc.deposit(amount);
			break;
		case 3:
			balance(acc);
			return 0;
		case 4:
		default:
			std::cout<<"Exiting..."<<std::endl;
			sleep(1);
			std::cout<<"Have a great day ahead!"<<std::endl;
			sleep(1);
			return 0;
	}

	std::cout<<"\nTransaction successful. What would you like to do next?\n1) Show last widthdrawn amount\n2) Show last deposited amount\n3) Show account balance\n4) Exit"<<std::endl;
	std::cin >> choice;

	switch(choice)
	{
		case 1:
			std::cout<<withdrawal(inq, acc)<<std::endl;
			break;
		case 2:
			std::cout<<deposit(inq, acc)<<std::endl;
			break;
		case 3:
			balance(acc);
			break;
		case 4:
		default:
			std::cout<<"Exiting..."<<std::endl;
			sleep(1);
	}
	
	std::cout<<"Thank you for banking with us. Have a great day ahead!"<<std::endl;
	sleep(1);

	return 0;
}
