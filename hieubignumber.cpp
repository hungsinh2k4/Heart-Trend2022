#include <bits/stdc++.h>
using namespace std;

// dao nguoc so lai

void reverse(int a[] , int n) {
	int left = 0, right = n - 1;
	while (left < right) {
		int tmp;
		tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}
}
void hieu(char a[], char b[]) {
	int n1 = strlen(a) , n2 = strlen(b), n = 0;
	int x1[n1] , y1[n2] , z[n1];
	// chuyen char sang int
	for (int i = 0; i < n1; i++) {
		x1[i] = a[i] - '0';
	}
	for (int i = 0; i < n2; i++) {
		y1[i] = b[i] - '0';
	}
	// dao nguoc no lai
	reverse(x1, n1);
	reverse(y1, n2);
	// gan phan rong = 0;
	// vi du 54 thi se la 4500 ok
	for (int i = n2; i < n1; i++) {
		y1[i] = 0;
	}
	int nhotru1 = 0;
	// tru nhu binh thuong thoi
	for (int i = 0; i < n1; i++) {   // vai test 536 363     635 363  371 1083 139  
		int tmp = 0;						// 3801 931  449			
		tmp  = x1[i] - y1[i] - nhotru1;
		if (tmp >= 0) {
			z[n++] = tmp;
			nhotru1 = 0;
		} else if (tmp < 0) {
			tmp = 10 + x1[i] - y1[i] - nhotru1;
			z[n++] = tmp;
			nhotru1 = 1;
		}
	}
	// kiem tra xem phan tu dau tien co bang 0 hay khong thi xoa no di
	while (z[n-1] == 0) {
		n--;
	}
	// no 2 so bang nhau thi xoa sach thi minh phai tang 1 so len 
	// thi se cout 0;
	if (n == 0) {
		n = 1;
	}
	for (int i  = n - 1; i >= 0; i--) {
		cout << z[i];
	}



	// day la cho de tham khao cach no van hanh


	// cout << endl;
	// for (int i = 0; i < n1; i++) {
	// 	cout << x1[i];
	// }
	// cout << endl;
	// for (int i = 0; i < n1; i++) {
	//  	cout << y1[i];
	//  }
}
int main ()
{
	char a[1001];
	char b[1001];
	cin >> a >> b;
	if (strlen(a) >= strlen(b)) {
		hieu(a, b);
	} else {
		hieu(b, a);
	}
}
