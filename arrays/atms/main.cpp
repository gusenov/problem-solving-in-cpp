#include <iostream>
#include <cstdlib>

using namespace std;

// Банкомат:
class ATM {
	private:
	
	double balance;  // количество денег.
	
	public:
	
	ATM() {
		this->balance = 0.0;
	}
		
	ATM(double startBalance) {
		this->balance = startBalance;
	}

	double getBalance() {
		return this->balance;
	}
		
	void setBalance(double balanceValue) {
		this->balance = balanceValue;
	}
};

int main() {
	
	ATM ATMs[100];
	
	for (int i = 0; i < 100; i++) {
		ATMs[i].setBalance(rand());
		cout << "ATM # " << i + 1 << ": " << ATMs[i].getBalance() << " $" << endl;
	}
	
	// Пауза перед выходом:
	cin.get();
	cin.get();
	
	return 0;
}
