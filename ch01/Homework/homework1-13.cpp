//计算二项式系数
#include<iostream>
using namespace std;

//递归算法
int n_factorial(int n){
	if(n != 1){
		return(n * n_factorial(n-1));  //不是递减，而是参数为 n-1
	}
	else return 1;
}

int binomial(int n, int m){
	if(n > m){
		return n_factorial(n)/(n_factorial(m) * n_factorial(n-m));
	}
	else return -1;
}

int main(){
	int m,n;
	cin>>n>>m;
	int result = binomial(n, m);
	cout<<result<<endl;
	return 0;
}


/*
//迭代算法
int main(){
	int m,n;
	cin>>n>>m;
	int x,y,z;
	x = y = z = 1;
	int temp = n-m;
	if(n > m){
		while(n != 1){
			x *= (n--);
		}
		while(m != 1){
			y *= (m--);
		}
		while(temp != 1){
			z *= (temp--);
		}
		cout<<x/(y*z)<<endl;
		return 0;
	}
	else
		return -1;	
}
*/