#include <iostream>
#include <ctime>

using namespace std;

int mas(int arr[], const int size ) {
	int a0;
	cin >> a0;
	arr[0] = a0;
	int a1;
	cin >> a1;
	arr[1] = a1;
	int a2;
	cin >> a2;
	arr[2] = a2;
	int a3;
	cin >> a3;
	arr[3] = a3;
	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int a[4] = {};
	int number = rand() % 9;
	a[0] = 1 + rand() % 8;
	if (a[0] == number) {
		while (a[0] == number) {
			number = rand() % 9;
		}
	}
	a[1] = number;
	if (a[0] == number || a[1] == number) {
		while (a[0] == number || a[1] == number) {
			number = rand() % 9;
		}
	}
	a[2] = number;
	if (a[0] == number || a[1] == number || a[2] == number) {
		while (a[0] == number || a[1] == number || a[2] == number) {
			number = rand() % 9;
		}
	}
	a[3] = number;
	for (int i = 0; i < 4; i++) {
		cout << a[i];
	}
	cout << endl;


	cout << "Ââåäèòå ÷åòûğåõçíà÷íîå ÷èñëî(êàæäóş öèôğó ÷åğåç ïğîáåë):";
	int user_number[4];
	mas(user_number, 4);
	while (a[0] != user_number[0] || a[1] != user_number[1] || a[2] != user_number[2] ||
		a[3] != user_number[3]) {
		int bulls = 0;
		int cows = 0;
		for (int i = 0; i < 4; i++) {
			if (a[i] == user_number[i]) {
				bulls +=1;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (a[i] == user_number[j] && i!=j) {
					cows +=1;
				}
			}
		}
		cout << "Êîğîâ:" << cows << endl;
		cout << "Áûêîâ:" << bulls << endl;
		mas(user_number, 4);
	}
	if (a[0] == user_number[0] && a[1] == user_number[1] && a[2] == user_number[2] &&
		a[3] == user_number[3]) {
		cout << "ÏÎÁÅÄÀ";
	}
	return 0;
	}

