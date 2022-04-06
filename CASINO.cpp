#include<iostream>
#include<cstdlib>			//To use Random function
#include<string>
#include<bits-stdc++.h>//string input
using namespace std;
void rules() {							//TO Display Rules of game
	system("cls");
	cout << "							RULES\n\n\n\n";
	cout << "					\033[1;41mCasino Game have some set of rules\033[0m\n\n";
	cout << "					\033[1;41mPlayer need to Choose Number between 1-10\033[0m\n\n";
	cout << "					\033[1;41mWinner will get 2 times of betting amount\033[0m\n\n";
	cout << "					\033[1;41mBetting Amount should not be more than 1000000 \033[0m\n\n";
	cout << "					\033[1;41mWrong bet, you will lose amount\033[0m\n\n";
}
int betted(int Inv) {//Getting Betting Amount EveryTime Player wants to bit
	int BettingAmount;
	do {
		cout << "Enter the amount that you want to bit\n";
		cin >> BettingAmount;
		if (BettingAmount > Inv) {
			cout << "\033[1;41mError\033[0m\n";
			cout << "Betting Amount can't be more than Balance Amount that you have invested\n";
			cout << "Enter valid Bettting Amount\n";
		}
	} while (BettingAmount > Inv);
	return BettingAmount;
}

int main() 
{
	cout << "						Welcome to Casino Universe                \n";
	char choice = 'a';
	int InvestedAmount;
	rules();
	
	do {
		do {//Getting Amount to start the game 
			cout << "Add Balance to your account To start the game\n";
			cin >> InvestedAmount;
			if (InvestedAmount > 1000000) {
				cout << "\033[1;41mYou have entered invalid amount\033[0m\n";
				cout << "enter valid amount\n";
			}
		} while (InvestedAmount > 1000000);
		
		string Name;
		int  BettingAmount,guess, RandomNumber;
		cout << "Enter your name\n";
		cin.ignore();
		getline(cin, Name);
		cout << "Welcome Casino Game " << Name << "\n";
		cout <<"\nYour Current Balance "<<InvestedAmount<<"\n";
		//Here game start
			do {
				BettingAmount = betted(InvestedAmount);
				srand((time(0)));
				RandomNumber = rand() % 10 + 1;
				cout << "Guess Number " << Name<<": ";
				cout << RandomNumber;
				cin >> guess;
				if (guess == RandomNumber) {
					cout << "Great,You Guessed That Lucky Number\n";
					InvestedAmount = InvestedAmount+BettingAmount * 2;
					cout << "\033[1;42mHere is your Winning amount \033[0m " << Name << " " << InvestedAmount<<"\n\n";
					cout << "Want to play again press Y/y\n";
					cin >> choice;

				}
				else if (guess<0 ||guess>=10) {
					cout << "\033[1;41mYou Have Guessed number which is not valid\033[0m\n\n";
				}
				else {
					cout << "Better Luck Next Time " << Name<<"\n\n";
					cout << "Lucky Number was " << RandomNumber<<"\n\n";
					InvestedAmount -= BettingAmount;
					cout << "Here is your  amount " << Name << " " << InvestedAmount << "\n";
					if (InvestedAmount <= 0) {
						cout << "\033[1;41mNo Money left to play this game further\033[0m\n";
						break;
					}
					cout << "Want to play again press Y/y\n\n";
					cin >> choice;
				}
			} while (choice=='Y' or choice=='y');
			cout << "THANKS FOR PLAYING CASINO GAME IN CASINO UNIVERSE\n\n";
			cout << "\033[1;44mHere is your Balance Amount\033[0m " << Name << " " << InvestedAmount<<"\n\n";
			//game end
			cout << "If you are New Player then press Y/y\n\n";
			cin >> choice;
	} while (choice == 'Y' or choice == 'y');
}
