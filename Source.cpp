#include <iostream>
#include <vector>
#include <string>

using namespace std;


//��� ������� ��������� ���� �� ����������� ��� ���
int povtor(vector<int> arr, size_t size) {
	int k = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i] == arr[j] && i != j) {
				k++;
			}
		}
	}
	return k;

}
//��� ������� ��������� ���� �� ����������� ����� � �����
int povtor_int(int numeric) {
	size_t length = to_string(numeric).length();
	vector<int> number(length);
	for (int i = length - 1; i >= 0; i--) {
		number[i] = numeric % 10;
		numeric = numeric / 10;
	}
	if (povtor(number, length) == 0) {
		return 0;
	}
	else {
		return 1;
	}
	
}

//��� ����������� ����� � ������ � ��������� ���
vector<int> vec(int input) {
	int flag = 0;
	while (flag == 0) {
		size_t length = to_string(input).length();
		vector<int> number(length);
		for (int i = length - 1; i >= 0; i--) {
			number[i] = input % 10;
			input = input / 10;
		}
		if (povtor(number, length) != 0) {
			cout << "�� ����� ����������� �����, ������� �����:";
			cin >> input;
		}
		else {
			return number;
		}
	}
}
//������� ����� � �����
void BullsAndCows(vector<int> arr, vector<vector<int>> a, size_t k, int &bulls, int &cows, int length) {
	for (int i = 0; i < length; i++) {
		if (a[k][i] == arr[i]) {
			bulls += 1;
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (a[k][i] == arr[j] && i != j) {
				cows += 1;
			}
		}
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	//��� ���� �����
	int input;
	cout << "���� ��������!"<< endl<<"������� �����:";
	cin >> input;
	vector<int> number;
	number = vec(input);
	size_t length =  number.size();
	//��� � ����� ������� ���������� ����� � ���������(������� �� ����� �����)
	size_t unique=9;
	int n = 9;
	for (int i = length-1; i > 0; i--) {
		unique = unique * n;
		n = n - 1;
	}
	//��� ������ ������ ����� ������ ����� 
	size_t number_length = length;
	string one = "1";
	string first_str = one + string(length - 1, '0');
	int first = stoi(first_str);
	// ��� �������� ������ ����� ����������� ������� � ���������
	int j = first,i=0;
	vector<vector<int>> mas_unique(unique);
	for (int i = 0; i < unique; i++) {
		mas_unique[i].resize(number_length);
	}
	while (j < (first * 10)) {
		int b = j;
		if (povtor_int(b) == 0) {
			for (int k = length - 1; k >= 0; k--) {
				mas_unique[i][k] = b % 10;
				b = b / 10;
			}
			i++;
		}
		j++;
	}
	//��� ��� �������� ����. ���� ����� �� �������� �� ��������, �� ���� ������ ��� 000... � ��� ������ �� �����������
	int flag = 0;
	vector<int> now(length);
	while (flag == 0) {
		for (int i = 0; i < unique; i++) {
			int k = 0;
			for (int j = 0; j < length; j++) {
				k += mas_unique[i][j];
			}
			if (k == 0) {
				continue;
			}
			else {
				cout << "����� ����������:" << " ";
				for (int j = 0; j < length; j++) {
					cout << mas_unique[i][j];
					now[j] = mas_unique[i][j];
				}
			}
			int cows = 0;
			int bulls = 0;
			BullsAndCows(number, mas_unique, i, bulls, cows, length);
			cout << "�����:" << cows<<endl;
			cout << "�����:" << bulls << endl;
			if (bulls == length) {
				cout << "��������� �������!";
				flag =1;
				break;
			}
			if (cows == 0 && bulls == 0) {
				for (int g = 0; g < unique; g++) {
					for (int i1 = 0; i1 < length; i1++) {
						for (int i2 = 0; i2 < length; i2++) {
							if (mas_unique[g][i1] == now[i2]) {
								for (int i3 = 0; i3 < length; i3++) {
									mas_unique[g][i3] = 0;
								}
							}
						}
					}
				}
			}
			if ((cows + bulls) < length && (cows + bulls)!=0) {
				for (int g = 0; g < unique; g++) {
					int m = 0;
					for (int i1 = 0; i1 < length; i1++) {
						for (int i2 = 0; i2 < length; i2++) {
							if (mas_unique[g][i1] == now[i2]) {
								m +=1;
							}
						}
					}
					if (m == length) {
						for (int i3 = 0; i3 < length; i3++) {
							mas_unique[g][i3] = 0;
						}
					}
				}
			}
			if ((cows + bulls) == length) {
				for (int g = 0; g < unique; g++) {
					int m = 0;
					for (int i1 = 0; i1 < length; i1++) {
						for (int i2 = 0; i2 < length; i2++) {
							if (mas_unique[g][i1] == now[i2]) {
								m += 1;
							}
						}
					}
					if (m == 0) {
						for (int i3 = 0; i3 < length; i3++) {
							mas_unique[g][i3] = 0;
						}
					}
				}
			}
		}
	}
}
