#include<iostream>
long fact(long a);
using namespace std;
int main() {
	cout << "������һ����������׳ˣ�" << endl;
	long a;
	cin >> a;
	cout << a << "�Ľ׳�Ϊ�� " << fact(a) << endl;
}
long fact(long a) {
	long sum = 1;
	for (long i = 1; i <= a; ++i) {
		sum *= i;
	}
	return sum;
}