//#include<iostream>
//using namespace std;
//struct  PhanSo
//{
//
//	long long int tu;
//	long long int mau;
//	long long int ucln;
//};
//
//void nhap(struct PhanSo& a)
//{
//	std::cin >> a.tu>>a.mau;
//}
//long long int USCLN(long long a, long long b)
//{
//	if (a == 0) return b;
//	return USCLN(b % a, a);
//}
//
//void rutgon(struct PhanSo& a)
//{
//	long long int ucln=USCLN(a.tu, a.mau);
//	ucln = USCLN(a.tu, a.mau);
//	a.tu /= ucln;
//	a.mau /= ucln;
//}
//void in(PhanSo& a)
//{
//	std::cout << a.tu << '/' << a.mau;
//}
//
//
//int main() {
//	struct PhanSo p;
//	nhap(p);
//	rutgon(p);
//	in(p);
//	return 0;
//}