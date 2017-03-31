#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int counter,temp = 0;
	cin >> counter;
	string a, b;
	while (counter != temp) {
		cin >> a >> b;
		bool swi = false;
		string last;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		vector<int> result;
		size_t i = 0;
		while ((a.size() > i) && (b.size() > i)) {
			int tem1 = 0, tem2 = 0;
			if (swi == true) {
				++tem2;
			}
			tem1 = a[i] - 48 + b[i] - 48;
			if (tem1 + tem2 >= 10) {
				swi = true;
			}
			else
			{
				swi = false;
			}
			tem2 = (tem1+tem2) % 10;
			result.push_back(tem2);
			++i; 
		}
		if (a.size() > b.size()) {
			while (i<a.size())
			{
				if (swi==true)
				{
					int tem1 = a[i]-48,tem2=1;
					if (tem1 + tem2 >= 10) {
						swi = true;
					}
					else
					{
						swi = false;
					}
					tem2 = (tem1 + tem2) % 10;
					result.push_back(tem2);
				}
				else
				{
					result.push_back(a[i] - 48);
				}
				++i;
			}
		}
		else if (a.size() < b.size()) {
			while (i<b.size())
			{
				if (swi == true)
				{
					int tem1 = b[i]-48, tem2 = 1;
					if (tem1 + tem2 >= 10) {
						swi = true;
					}
					else
					{
						swi = false;
					}
					tem2 = (tem1 + tem2) % 10;
				
					result.push_back(tem2);
				}
				else
				{
					result.push_back(b[i] - 48);
				}
				++i;
			}
		}
			if (swi == true)
			{
				result.insert(result.end(), 1);
			}
		vector<int>::reverse_iterator rbeg = result.rbegin();
		for (int y=0; rbeg != result.rend(); ++rbeg) {
			last.push_back(*rbeg+48);
			++y;
		}
		++temp;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		cout << "Case " << temp << ":" << endl;
		cout << a << " + " << b << " = " << last ;
		if (counter >= 0)
			cout << endl << endl;
	}
}
