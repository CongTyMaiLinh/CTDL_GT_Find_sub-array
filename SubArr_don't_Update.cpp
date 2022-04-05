#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cout << "Nhap kich thuoc mang = "; cin  >> n;
	int arr[n];
	int i;
	for (i = 0; i < n; i++) {
		cout << "Mhap phan tu mang thu " << i << ": "; cin >> arr[i];
	}
	int width_max = INT_MIN; 
	int WM_start = 0, WM_last = 0, index_start = 0;
	for ( i = 0; i < n; i++) {
		int sum = 0; int j;
		for(j = i; j < n; j++) {
			if (sum + arr[j] < arr[j]) {
				sum = arr[j];
				index_start = j;
			} else {
				sum += arr[j];
			}
			if (width_max < sum) {
				width_max = sum;
				WM_start = index_start;
				WM_last = j;
			}
		}
	}
    cout << width_max << "\n";
    cout << "start from " << WM_start << " to " << WM_last << "\n";
	return 0;
}
