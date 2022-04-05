#include <bits/stdc++.h>

using namespace std;
int *Nhap_mang(int n) {
	int arr[n];
	int i;
	for (i = 0; i < n; i++) {
		cout << "Mhap phan tu mang thu " << i << ": "; cin >> arr[i];
	}
	return arr;
}
void find_sub_array_max(int n,int *arr) {
	int width_max = INT_MIN;
	int WM_start = 0, WM_last = 0, index_start = 0;
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		if(sum +arr[i] < arr[i]) {
			index_start = i;
			sum = arr[i];
		} else {
			sum += arr[i];
		}
		if(width_max < sum) {
			width_max = sum;
			WM_start = index_start;
			WM_last = i;
		}
	}
    cout << width_max << "\n";
    cout << "start from " << WM_start << " to " << WM_last << "\n";
}
int main() {
	int n;
	cout << "Nhap kich thuoc mang = "; cin  >> n;
	find_sub_array_max(n, Nhap_mang(n));
	return 0;
}
