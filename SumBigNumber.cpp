#include <bits/stdc++.h>
using namespace std;

// dao nguoc cac so lai

void reverse (int a[] , int n) {
	int left = 0 , right = n - 1;
	while (left < right) {
		int tmp;
		tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left ++ ;
		right--;
	} 
}
void bignumber(char a[] , char b[]) {	
	// xet strlen (a) >= strlen(b);
	int n1 = strlen(a), n2 = strlen(b);
	int x1[n1] , y1[n2] , z[n1+1];
	// doi char sang int 	
	for (int i = 0; i < n1; i++) {
		x1[i] = a[i] - '0';
	}
	for (int i = 0; i < n2; i++) {
		y1[i] = b[i] - '0';
	}
	// dao nguoc chuoi ki tu
	reverse(x1,n1);
	reverse(y1,n2);
	//chen phan tu ko vao trong cai xau ki tu nho hon
	for (int i  = n2; i < n1; i++) {
		y1[i] = 0;
	}
	int nho = 0; int n = 0;
	for (int i  = 0; i < n1; i++) {
		int tmp = x1[i] + y1[i] + nho;
		z[n++] = tmp % 10;
		nho = tmp / 10;
	}
	if (nho) {
		z[n++] = nho;
	}
	for (int i = n - 1; i >=0; i--) {
		cout << z[i];
	}

	//day la cach cac ban xem no hoat dong ntn


	// cout << endl;
	// for (int i = 0; i < n1; i++) {
	// 	cout << x1[i];
	// }
	// cout << endl;
	// for (int i = 0; i < n2; i++) {
	// 	cout << y1[i];
	// }

} 
int main ()
{
	char a[1001];
	char b[1001];
	cin >> a >> b;
	if (strlen(a) > strlen(b) ) {
		bignumber(a,b);
	} else {
		bignumber(b,a);
	}

}
