#include <iostream>
#include <string>

using namespace std;

int mas(int arr[], const int size) {
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
	cout << "Введите число:";
	int user_number[4];
	mas(user_number, 4);
	int a[4] = {0,0,0,0};
	for (int i = 1000; i < 9999 + 1; i++) {
		int a1 = i / 1000;                   
		int b = (i / 100) % 10;
		int c = (i / 10) % 10;
		int d = i % 10;
		if ((a1 != b) && (a1 != c)
			&& (a1 != d) && (b != c)
			&& (b != d) && (c != d)) {
			a[0] = a1;
			a[1] = b;
			a[2] = c;
			a[3] = d;
			if (a[0] == user_number[0] && a[1] == user_number[1] && a[2] == user_number[2] &&
				a[3] == user_number[3]) {
				for (int t = 0; t < 4; t++) {
					cout << a[t];
					
				}
				cout << endl;
				cout << "Победа!" << endl;
				break;
				
			}
			else {
				for (int t = 0; t < 4; t++) {
					cout << a[t];
				}
				cout << endl;
				int bulls = 0;
				int cows = 0;
				for (int m = 0; m < 4; m++) {
					if (a[m] == user_number[m]) {
						bulls += 1;
					}
				}
				for (int m = 0; m < 4; m++) {
						for (int n = 0; n < 4; n++) {
							if (a[m] == user_number[n] && m != n) {
								cows += 1;
							}
						}
				}
				cout << "Коров:" << cows << endl;
				cout << "Быков:" << bulls << endl;
			}	
		}
	}
	return 0;
}