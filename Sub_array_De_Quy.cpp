#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int *input(int n) {
	int arr[n];
	int i;
	for (i = 0; i < n; i++) {
		cout << "Mhap phan tu mang thu " << i << ": "; cin >> arr[i];
	}
	return arr;
}
int max_left(int i, int j, int &dau, int *arr) {
	int max_sum = INT_MIN;
	int sum = 0;
	int k;
	for ( k = j; k >=i; k--) {
		sum += arr[k];
		if (max_sum < sum) {
			max_sum = sum;
			dau = k;
		}
	}
	return max_sum;
}
int max_right(int i, int j, int &cuoi, int *arr) {
	int max_sum = INT_MIN;
	int sum = 0, k;
	for ( k = i; k >=j; k++) {
		sum += arr[k];
		if (max_sum < sum) {	max_sum = sum;	cuoi = k;}
	}
	return max_sum;
}
int max_sub (int i, int j, int &dau, int &cuoi, int *arr) {
	int dau_1, dau_2, dau_3, cuoi_1, cuoi_2, cuoi_3;
	if (i == j) {
		dau = i; cuoi = i; return arr[i];
	} else {
		int m = (i + j) /2;
		int wl, wr, wm;
		wl = max_sub(i, m, dau_1, cuoi_1, arr);
		wr = max_sub(m+1, j, dau_2, cuoi_2, arr);
		wm = max_left(i, m, dau_3, arr) + max_right(m+1, j, cuoi_3, arr);
		int best = max(max(wl, wr), wm);
		if (best == wl) {	dau = dau_1;	cuoi = cuoi_1;}
		else if (best == wr) {	dau = dau_2;	cuoi = cuoi_2;} 
		else if (best == wm) {	dau = dau_3;	cuoi = cuoi_3;}
		return best;
	}
}

int main() {
	int n;
	cout << "kich thuoc ?"; cin >> n;	
	int dau, cuoi;
	max_sub(0, n-1, dau, cuoi, input(n));
	cout << "Tong: " << " - [l:r] = [" << dau << ":" << cuoi << "]\n";
}
