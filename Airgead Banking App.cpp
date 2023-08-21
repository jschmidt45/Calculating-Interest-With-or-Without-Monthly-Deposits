#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;
//initialize variables used in multiple functions/in general
int i;
double initialInvestment;
double monthlyDeposit;
int annualInterest;
int numYears;
double interestEarned;

//function to display menu
void displayMenu() {
	for (i = 0; i < 34; ++i) {
		cout << '*';
	}
	cout << endl;
	for (i = 0; i < 11; ++i) {
		cout << '*';
	}
	cout << " Data Input ";
	for (i = 0; i < 11; ++i) {
		cout << '*';
	}
	cout << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
	cout << "Press enter to continue..." << endl;
}
//function to calculate new balance after 12 months with or without montly deposits and interest
double calcNewBalance(double startingBalance, double monthlyAmount, int interest) {
	double currentBalance = startingBalance;
	for (i = 0; i < 12; ++i) {
		//adds montly deposit to current balance before calculating interest, without monthly deposits, monthly amount is equal to 0.
		currentBalance = currentBalance + monthlyAmount;
		currentBalance = currentBalance + (currentBalance + monthlyAmount) * ((interest / 100.0) / 12);
	}
	return currentBalance;
}

//displays balnce after 12 months without monthly deposits
void displayBalanceWithoutDeposits(double initialAmount, double monthlyAmount, int interestRate, int numYears) {
	double yearEndBalance = initialAmount;
	cout << "   Balance and Interest Without Additional Monthly Deposits    " << endl;
	for (i = 0; i < 62; ++i) {
		cout << '=';
	}
	cout << endl;
	cout << "  Year          Year End Balance      Year End Earned Interest" << endl;
	for (i = 0; i < 62; ++i) {
		cout << '-';
	}
	cout << endl;
	//initialize local variables
	int j;
	int w;
	int x;
	for (j = 0; j < numYears; ++j) {
		//temporary variable for calculation
		double tempBalance = yearEndBalance;
		yearEndBalance = calcNewBalance(yearEndBalance, monthlyAmount, interestRate);
		interestEarned = yearEndBalance - (tempBalance + (monthlyAmount * 12));
		//output current year
		cout << "   " << j + 1;
		//if else statements to format amount of spaces in output to keep everything lined up
		if (j + 1 < 10) {
			w = 15;
		}
		else if (j + 1 < 100) {
			w = 14;
		}
		else {
			w = 13;
		}

		if (yearEndBalance < 10.00) {
			x = 30;
		}
		else if (yearEndBalance < 100.00) {
			x = 29;
		}
		else if (yearEndBalance < 1000.00) {
			x = 28;
		}
		else if (yearEndBalance < 10000.00) {
			x = 27;
		}
		else if (yearEndBalance < 100000.00) {
			x = 26;
		}
		else {
			x = 25;
		}
		//output with variable number of spaces and fixed two decimal points
		cout << std::setw(w) << "$" << fixed << setprecision(2) << yearEndBalance << std::setw(x) << "$" << interestEarned << endl;
	}
	cout << endl;
}
//dispalys balance after 12 months with montly deposits and interest
void displayBalanceWithDeposits(double initialAmount, double monthlyAmount, int interestRate, int numYears) {
	double yearEndBalance = initialAmount;
	cout << "     Balance and Interest With Additional Monthly Deposits     " << endl;
	for (i = 0; i < 62; ++i) {
		cout << '=';
	}
	cout << endl;
	cout << "  Year          Year End Balance      Year End Earned Interest" << endl;
	for (i = 0; i < 62; ++i) {
		cout << '-';
	}
	cout << endl;
	//initialize local variables
	int j;
	int w;
	int x;
	//loop to calculate total after number of years
	for (j = 0; j < numYears; ++j) {
		double tempBalance = yearEndBalance;
		yearEndBalance = calcNewBalance(yearEndBalance, monthlyAmount, interestRate);
		interestEarned = yearEndBalance - (tempBalance + (monthlyAmount * 12));
		cout << "   " << j + 1;
		//if else statements to determine amount of space to keep everything lined up
		if (j + 1 < 10) {
			w = 15;
		}
		else if (j + 1 < 100) {
			w = 14;
		}
		else {
			w = 13;
		}

		if (yearEndBalance < 10.00) {
			x = 30;
		}
		else if (yearEndBalance < 100.00) {
			x = 29;
		}
		else if (yearEndBalance < 1000.00) {
			x = 28;
		}
		else if (yearEndBalance < 10000.00) {
			x = 27;
		}
		else if (yearEndBalance < 100000.00) {
			x = 26;
		}
		else {
			x = 25;
		}
		//output with variable amount of spaces and 2 fixed decimal points
		cout << std::setw(w) << "$" << fixed << setprecision(2) << yearEndBalance << std::setw(x) << "$" << interestEarned << endl;
	}
}


int main() {
	//calls display menu function
	displayMenu();
	//takes user inputs
	cin >> initialInvestment;
	cin >> monthlyDeposit;
	cin >> annualInterest;
	cin >> numYears;
	//calls the function to display balance without monthly deposits, uses same equation but 0.00 is entered for monthly deposit
	displayBalanceWithoutDeposits(initialInvestment, 0.00, annualInterest, numYears);
	//calls the function to display balance with montly deposits
	displayBalanceWithDeposits(initialInvestment, monthlyDeposit, annualInterest, numYears);
	return 0;
}