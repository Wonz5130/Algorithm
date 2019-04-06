#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/*int transfer(int *a){
	int aa;
	string a1 = to_string(a);
	string b1 = to_string(b);
	int len = a1.length();
	int length = len;;
	int i = 0;
	while(i != len){
		aa = a1[i++] * pow(2, --length);
	}
	int j = 0;
	length = len;
	while(j != len){
		bb = b1[j++] * pow(2, --length);
	}
	return 0;
}*/

int binarymultiply(int x, int y, int n){
	/*int multiply = x * y;
	x = abs(x);
	y = abs(y);*/
	if(x == 0 || y == 0){
		return 0;
	}
	if(n == 1 || n == 0){
		//return transfer(&x) * transfer(&y);
		return x * y;
	}
	else{
		//int len = n/2;
		int A = x / pow(10, (int)n/2);
		int B = x - A * pow(10, (int)n/2);
		int C = y / pow(10, (int)n/2);
		int D = y - C * pow(10, (int)n/2);
		int a = binarymultiply(A, C, n);
		int b = binarymultiply(A - B, D - C, n/2);
		int c = binarymultiply(A, C, n/2);
		int d = binarymultiply(B ,D , n/2);
		//int e = binarymultiply(B, D, 0);
		//int *a1 = b + c + d;
		//transfer(a1);
		return a * pow(2, n) + (b + c + d) * pow(2, n/2) + B * D;
	}
}

int main(){
	int x, y, n;
	cin >> x;
	cin >> y;
	cin >> n;
	int result = binarymultiply(x, y, n);
	cout << result << endl;
	return 0;
}
