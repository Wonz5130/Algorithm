//欧几里得算法，又称辗转相除法
#include<iostream>
using namespace std;

void Swap(int &a,int &b){
	int c = a;
	a = b;
	b = c;
}

//尾递归版本
int RGcd(int m,int n){  //欧几里德递归算法
	if (m == 0) return n;  //终止条件
	return RGcd(n%m,m);
}

int Gcd(int m,int n){
	if (m > n) Swap(m,n);
	return RGcd(m,n);
}

//迭代版本
int Gcd1(int m,int n){
	if (m == 0) return n;
	if (n == 0) return m;
	if (m > n) Swap(m,n);
	while (m > 0){
		int c = n%m; 
	    n = m; 
        m = c;	
	}
	return n;
}

//不事先比较 m 和 n 大小
int Gcd2(int m,int n){
    while (m != 0 && n != 0){
	    if (m > n) m %= n;
	    else n %= m;
    }
    return m+n;
}

//连续整数检测
int Gcd3(int m,int n){
	if (m == 0) return n;
	if (n == 0) return m;
	int t = m>n?n:m;  //令 t = min{m,n}
	while (m%t || n%t) t--;
	return t;
}


int main(){
	int m,n;
	int result;
	cin>>m>>n;
	result = Gcd(m,n);
	cout<< result <<endl;
	result = Gcd1(m,n);
	cout<< result <<endl;
	result = Gcd2(m,n);
	cout<< result <<endl;
	result = Gcd3(m,n);
	cout<< result <<endl;
	cout<<m*n /Gcd(m,n)<<endl;  //输出最小公倍数
	return 0;	
}