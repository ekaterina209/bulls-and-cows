#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void mas(vector<int> &arr, size_t size){
	int n;
	for (int i = 0; i < size; i++) {
		cin >> n;
		arr[i] = n;
		
	}
}

void povtor(vector<int> &arr, size_t size) {
	int flag1 = 0;
	while (flag1 == 0) {
		int k = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i] == arr[j] && i != j) {
					k++;
				}
			}
		}
		if (k == 0) {
			flag1 = 1;
		}
		else {
			cout << "Вы неправильно ввели число, введите новое:";
			mas(arr, size);
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	cout << "Cколько цифр будет в числе?";
	size_t n;
	cin >> n;
	vector<int> a(n);
	a[0] = rand() % 9 + 1;
	for (int i = 1; i < n; i++) {
		a[i] = rand() % 10;
	}
	int flag = 0;
	while (flag == 0) {
		int k = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i] == a[j] && i != j) {
					a[i] = rand() % 10;
					k++;
				}
			}
		}
		if (k == 0) {
			flag = 1;
		}
	}
	cout << "Введите число(каждую цифру через пробел):";
	vector<int> user_number(n);
	mas(user_number, n);
	povtor(user_number, n);
	while (user_number!= a) {
		int bulls = 0;
		int cows = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == user_number[i]) {
				bulls +=1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i] == user_number[j] && i!=j) {
					cows +=1;
				}
			}
		}
		cout << "Коров:" << cows << endl;
		cout << "Быков:" << bulls << endl;
		mas(user_number, n);
		povtor(user_number, n);
	}
	cout << "Победа!";
	return 0;
}

