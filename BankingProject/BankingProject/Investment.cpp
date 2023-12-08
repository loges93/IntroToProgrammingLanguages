#include "Investment.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Constructors
Investment::Investment(double initialInvestment = 0.0, double monthlyDeposit = 0.0, double annualInterest = 0.0, int years = 0)
{
	this->initialInvestment = initialInvestment;
	this->monthlyDeposit = monthlyDeposit;
	this->annualInterest = annualInterest * 0.01;
	this->years = years;
}

//Getters and Setters
//Intial Investment
void Investment::SetInitialInvestment(double investment)
{
	initialInvestment = investment;
}
double Investment::GetInitialInvestment()
{
	return initialInvestment;
}

//Monthly Deposit
void Investment::SetMonthlyDeposit(double deposit)
{
	monthlyDeposit = deposit;
}
double Investment::GetMonthlyDeposit()
{
	return monthlyDeposit;
}

//Annual Interest
void Investment::SetAnnualInterest(double interest)
{
	annualInterest = interest * 0.01;
}
double Investment::GetAnnualInterest()
{
	return annualInterest;
}

//Number of years
void Investment::SetYears(int years)
{
	years = years;
}
int Investment::GetYears()
{
	return years;
}

//Outputs balances by year
void Investment::DisplayBalanceInterest()
{
	cout << "   Balance and Interest Without Additional Monthly Deposits  " << endl;
	cout << setw(40) << "Compounded Monthly" << endl;
	cout << "=============================================================" << endl;
	cout << setw(8) << "Year" << setw(23) << "Year End Balance";
	cout << setw(30) << "Year End Earned Interest" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//currentYearBalance to hold the current balance without changing original
	double currentYearBalance = GetInitialInvestment();
	double currentYearInterest;
	//Without monthly deposits
	for (int year = 1; year <= years; year++)
	{
		currentYearInterest = currentYearBalance * pow(1 + annualInterest / 12, 12) - currentYearBalance;
		currentYearBalance = currentYearBalance * pow(1 + annualInterest / 12, 12);
		cout << setw(8) << to_string(year) + "|";
		cout << setw(23) << setprecision(2) << fixed << currentYearBalance;
		cout << setw(30) << setprecision(2) << currentYearInterest << endl;
	}

	//Setting currentBalance back to initial
	currentYearBalance = initialInvestment;
	
	//With additional deposit
	cout << endl << "   Balance and Interest With Additional Monthly Deposits  " << endl;
	cout << setw(40) << "Compounded Monthly" << endl;
	cout << "=============================================================" << endl;
	cout << setw(8) << "Year" << setw(23) << "Year End Balance";
	cout << setw(30) << "Year End Earned Interest" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Holds previous annualBalance value to be subtracted to get accumulated interest total for year
	double tempBalance;
	for (int year = 1; year <= years; year++)
	{
		//Adds monthly deposits and compounds interest for total year balance
		//Saves value at the beginning of year
		tempBalance = currentYearBalance;
		for (int month = 1; month <= 12; month++)
		{
			currentYearBalance += monthlyDeposit;
			currentYearBalance *= (1 + (annualInterest / 12));
		}
		
		//Outputs
		currentYearInterest = currentYearBalance - tempBalance - monthlyDeposit * 12;
		cout << setw(8) << to_string(year) + "|";
		cout << setw(23) << setprecision(2) << fixed << currentYearBalance;
		cout << setw(30) << setprecision(2) << currentYearInterest << endl;
	}
	system("pause");
}
//Display edit options
void Investment::DisplayEditOptions(bool &run)
{
	int choice; 
	cout << endl << "Enter The Number Of Your Choice" << endl;
	cout << "=================================" << endl;
	cout << "1 - Change Initial Deposit" << endl;
	cout << "2 - Change Monthly Deposit" << endl;
	cout << "3 - Change Annual Interest" << endl;
	cout << "4 - Change Years" << endl;
	cout << "5 - End Program" << endl;
	cin >> choice;

	//Manage user choice
	if (choice == 1)
	{
		double initDeposit;
		cout << "Please enter a new initial deposit: ";
		cin >> initDeposit;
		this->SetInitialInvestment(initDeposit);
	}
	else if (choice == 2)
	{
		double monthlyDeposit;
		cout << "Please enter a new monthly deposit: ";
		cin >> monthlyDeposit;
		SetMonthlyDeposit(monthlyDeposit);
	}
	else if (choice == 3)
	{
		double interest;
		cout << "Please enter a new annual interest rate: ";
		cin >> interest;
		SetAnnualInterest(interest);

	}
	else if (choice == 4)
	{
		int years;
		cout << "Please enter a new year timeframe: ";
		cin >> years;
		this->SetYears(years);
	}
	else
	{
		run = false;
		cout << endl << "THANKS FOR USING AIRGEAD BANKING!" << endl;
	}
	cout << endl;

}