#include<iostream>
#include<vector>
using namespace std;
//code from p40
struct result {
	result(int a, int b, int c) :left_low(a), right_high(b), sum(c) {}
	result() {}
	int left_low;
	int right_high;
	int sum;
};
result FIND_MAX_CROSSING_SUBARRAY(vector<int> &A, int low, int mid, int high) {
	result tempresult;
	int left_sum = -99999;
	int right_sum = -99999;
	int sum = 0;
	for (int i = mid; i >= low; --i) {
		sum = sum + A[i];
		if (sum > left_sum) {
			left_sum = sum;
			tempresult.left_low = i;
		}
	}
	sum = 0;
	for (int j = mid + 1; j <= high; ++j) {
		sum = sum + A[j];
		if (sum > right_sum) {
			right_sum = sum;
			tempresult.right_high = j;
		}
	}
	tempresult.sum = left_sum + right_sum;
	return tempresult;
}
result FIND_MAXIMUM_SUBARRAY(vector<int> &A, int low, int high) {
	if (high == low) {
		return result(low,low,A[low]);
	}
	else {
		int mid = (low + high) / 2;
		result temp1 = FIND_MAXIMUM_SUBARRAY(A, low, mid);
		result temp2 = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
		result res = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high);
		if (temp1.sum >= temp2.sum&&temp1.sum >= res.sum) {
			return temp1;
		}
		else if (temp2.sum >= temp1.sum&&temp2.sum >= res.sum) {
			return temp2;
		}
		else{
			return res;
		}
	}
}
int main() {
	int cas=0;
	int temp,n;
	cin>>cas;
	for(int i=1;i<=cas;++i){
		vector<int> a;
		cin>>n;
		for(int j=0;j<n;++j){
			int temp;
			cin>>temp;
			a.push_back(temp);
		}
		result res = FIND_MAXIMUM_SUBARRAY(a, 0, n-1);
		cout<<"Case "<<i<<":"<<endl;
		cout << res.sum<<" "<< res.left_low+1 << " " << res.right_high+1<<endl<<endl ;
	}
}
