#include<iostream>
long fact(long a);
using namespace std;
int main() {
	cout << "请输入一个整数，求阶乘：" << endl;
	long a;
	cin >> a;
	cout << a << "的阶乘为： " << fact(a) << endl;
}
long fact(long a) {
	long sum = 1;
	for (long i = 1; i <= a; ++i) {
		sum *= i;
	}
	return sum;
}