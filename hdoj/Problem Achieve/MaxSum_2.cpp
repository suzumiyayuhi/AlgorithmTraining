#include<iostream>
using namespace std;
int main() {
	int counter, counterX = 0;
	cin >> counter;
	while (counter--){
		int num;
		int first, en = 1;
		cin >> num;
		int UX[100000], EX[100000];
		for (int i = 0; i < num; ++i)
			cin >> UX[i];
		EX[0] = UX[0];
		for (int i = 1; i < num; ++i) {
			if (EX[i - 1] >= 0)
				EX[i] = EX[i - 1] + UX[i];
			else
				EX[i] = UX[i];
		}
		int max = EX[0];
		for (int i = 0; i < num; ++i) {
			if (max < EX[i]) {
				max = EX[i];
				en = i;
			}
		}
		int x = 0;
		for (int k = en; k >= 0; --k) {
			x += UX[k];
			if (x == max)
				first = k;
		}
		++counterX;
		cout << "Case " << counterX << ":" << endl;
		cout << max << " " << ++first << " " << ++en ;
		if (counterX >= 1)
		{
			cout << endl << endl;
		}
	}
	return 0;
}