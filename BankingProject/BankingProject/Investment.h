#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>
using namespace std;


class Investment 
{
	public:
		Investment(double initialDeposit, double monthlyDeposit, double interest, int years);
		//Getters and Setters
		//Initial Investment Methods
		void SetInitialInvestment(double investment);
		double GetInitialInvestment();
		
		//Monthly Deposit
		void SetMonthlyDeposit(double deposit);
		double GetMonthlyDeposit();

		//Annual Interest
		void SetAnnualInterest(double interest);
		double GetAnnualInterest();

		//Number of years
		void SetYears(int years);
		int GetYears();

		void DisplayEditOptions(bool &run);
		
		//Display Information
		void DisplayBalanceInterest();

	private:
		double initialInvestment;
		double monthlyDeposit;
		double annualInterest;
		int years;
};
#endif
