#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Account
{
        public:
        Account();
        Account (double bal);
        void deposit(double amount);
        void withdraw(double amount);
        double get_balance() const;
        void add_interest(double rate);

        private:
        double balance;
};

Account::Account()
{
}
Account::Account(double bal)
{
        balance = bal;
}

void Account::deposit(double amount)
{
        balance +=amount;
}

void Account::withdraw (double amount)
{
        if ( balance >= amount)
                balance -= amount;
        else
                balance -= 5.00;  // Charge a $5.00 penalty fee if attempting to withdraw more than balance.
}

double Account::get_balance()const
{
        return balance;
}

void Account::add_interest(double rate)
{
        balance *= ( 1 + (rate/100.0));
}

int main()
{

        cout << " Enter initial investment: ";
        double initial_investment;
        cin >> initial_investment;

        cout << " Enter annual interest rate in percentage: ";
        double rate_in_percentage;
        cin >> rate_in_percentage;

        double monthly_rate = rate_in_percentage/100.0/12.0;
        double final_amount = 2 * initial_investment;

        Account my_account(initial_investment);

        int months = 1;

        //
        // one iteration of the loop corresponds to one month
        //

        while ( my_account.get_balance()<final_amount)
        {
                my_account.add_interest(monthly_rate);
                months++;
        }

        cout << " It took " << months << " months for $ " << initial_investment <<
                " to double at " << rate_in_percentage << "% annual interest. \n";

        cout << " Account balance: " << my_account.get_balance() << "\n";

        return 0;
}