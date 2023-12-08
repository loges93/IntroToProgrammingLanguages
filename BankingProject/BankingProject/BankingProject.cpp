
#include <iostream>
#include <string>
#include "Investment.h"
using namespace std;

//Input Handling
void PromptUser(double &initialDeposit, double &monthlyDeposit, int &interest, int &years)
{
	cout << "**************************************" << endl;
	cout << "********* Investment Details *********" << endl;
	cout << endl << "Initial Investment Amount:  $";
	cin >> initialDeposit;
	cout << "Monthly Deposit:  $";
	cin >> monthlyDeposit;
	cout << "Annual Interest:  ";
	cin >> interest;
	cout << "Number of years:  ";
	cin >> years;
	system("pause");
	cout << endl;
}

int main()
{
	//Global variables for values and one boolean value to run the while loop
	double initialDeposit;
	double monthlyDeposit;
	int interest;
	int years;
	bool run = true;

	//Prompts user for values
	PromptUser(initialDeposit, monthlyDeposit, interest, years);

	Investment invest(initialDeposit, monthlyDeposit, interest, years);

	while (run)
	{
		invest.DisplayBalanceInterest();
		invest.DisplayEditOptions(run);
	}

}



