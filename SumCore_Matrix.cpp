#include <bits/stdc++.h>
using namespace std;

// struct
struct Matrix {
    int hang, cot;
    int tich, tong, cahai;
    int mt[100][100];
};

// xu viec nhap hang va cot xem co dung ko

void nhapSohang_vasocot(Matrix & mt1, Matrix & mt2)
{

    cout << "nhap hang cua ma tran 1: ";
    cin >> mt1.hang;
    cout << "nhap cot cua ma tran 1: ";
    cin >> mt1.cot;
    cout << "nhap hang cua ma tran 2: ";
    cin >> mt2.hang;
    cout << "nhap cot cua ma tran 2: ";
    cin >> mt2.cot;
    cout << "-------------------------------------------------------\n";
    cout << "ban muon tinh tich ma tran hay tong ma tran hay ca 2 hai\n";
    cout << "neu tinh tich thi nhap vao:1\n";
    cout << "neu tinh tong thi nhap vao:2\n";
    cout << "neu tinh ca hai thi nhap vao: 3\n";
    char s;
    cin >> s;
    char a;
    if (s == '1')  {
        mt1.tich = 1;
        if (mt1.cot != mt2.hang) {
            cout << "khong the tinh duoc tich ma tran\n";
            cout << "ban co muon nhap lai hang va cot cua 2 ma tran hay ko\n";
            cout << "neu co tinh nhap vao: c\n";
            cout << "neu khong thi nhap vao: k\n";
            cin >> a;
            if (a == 'c') {
                nhapSohang_vasocot(mt1, mt2);
            }
            if (a == 'k') {
                exit(0);
            }
        }
    } else if ((s == '3') || (s == '2')) {
        if ((mt1.hang != mt2.hang ) || (mt1.cot != mt2.cot )) {
            cout << "khong the tinh duoc tong cua ma tran\n";
            cout << "ban co muon nhap lai khong ?\n";
            cout << "neu co thi hay nhap vao 1 ma tran vuong nha\n";
            cout << "neu co tinh nhap vao: c\n";
            cout << "neu khong thi nhap vao: k\n";
            cin >> a;
            if (a == 'c') {
                nhapSohang_vasocot(mt1, mt2);
            } else {
                exit (0);
            }
        }
    }
    if (s == '2') {
        mt1.tong = 1;
    } else if (s == '3') {
        mt1.cahai = 1;
    }
}

// nhap ma tran can tinh;

void nhapMaTrix(Matrix& mt1 , Matrix & mt2) {
    cout << "------------------------------\n";
    cout << "\nhay nhap ma tran 1\n";
    for (int i = 0; i < mt1.hang; i++) {
        for (int j = 0; j < mt1.cot; j++) {
            cin  >> mt1.mt[i][j];
        }
    }
    cout << "hay nhap ma tran 2\n";
    for (int i = 0; i < mt2.hang; i++) {
        for (int j = 0; j < mt2.cot; j++) {
            cin  >> mt2.mt[i][j];
        }
    }
}

// in ma tran

void inMaTrix(Matrix& mt1) {
    for (int i = 0; i < mt1.hang; i++) {
        for (int j = 0; j < mt1.cot; j++) {
            cout << mt1.mt[i][j] << " ";
        }
        cout << endl;
    }
}

// tinh tong hai ma tran

void tongMatrix(const Matrix& mt1, const Matrix& mt2, Matrix& mtTong) {
    mtTong.hang = mt1.hang;
    mtTong.cot = mt1.cot;
    for (int i = 0; i < mt1.hang; i++) {
        for (int j = 0; j < mt1.cot; j++) {
            mtTong.mt[i][j] = mt1.mt[i][j] + mt2.mt[i][j];
        }
    }
}

// tinh tich 2 ma tran

void tichMatrix(const Matrix& mt1, const Matrix& mt2, Matrix& mtTich) {
    mtTich.hang = mt1.hang;
    mtTich.cot = mt2.cot;
    for (int i = 0; i < mt1.hang; i++) {

        for (int j = 0; j < mt2.cot; j++) {
            int sum = 0;
            for (int k = 0; k < mt1.cot; k++) {
                sum += mt1.mt[i][k] * mt2.mt[k][j];
            }
            mtTich.mt[i][j] = sum;
        }

    }
}


// xu li ham main

int main ()
{
    Matrix mt1, mt2, mtTong, mtTich;
    nhapSohang_vasocot(mt1, mt2);
    nhapMaTrix(mt1, mt2);
    cout << "------------------------------\n";
    if (mt1.cahai == 1) {
        tongMatrix(mt1, mt2, mtTong);
        tichMatrix(mt1, mt2, mtTich);
        cout << "tong ca 2 ma tran la\n";
        inMaTrix(mtTong);
        cout << "\ntich cua 2 ma tran la\n";
        inMaTrix(mtTich);
    } else if (mt1.tich == 1) {
        tichMatrix(mt1, mt2, mtTich);
        cout << "tich cua 2 ma tran la\n";
        inMaTrix(mtTich);
    } else if (mt1.tong == 1) {
        tongMatrix(mt1, mt2, mtTong);
        cout << "tong ca 2 ma tran la\n";
        inMaTrix(mtTong);
    }
}
// 1 2
// 3 4
// 5 6
// 7 8
