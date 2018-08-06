//n! 递归函数
#include<iostream>
using namespace std;

int n_factorial(int n){
	if(n != 1){
		//--n;
		return(n * n_factorial(n-1));  //不是递减，而是参数为 n-1
	}
	else return 1;
}

int main(){
	int n;
	cin>>n;
	int result = n_factorial(n);
	cout<<result<<endl;
	return 0;
}