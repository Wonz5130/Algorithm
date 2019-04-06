#include<cstdio>

//求最大公约数：辗转相除法(欧几里得算法)
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

/*
//更简洁的写法
int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
*/

int main(){
	int a, b;
	scanf("%d%d",&a,&b);
	printf("%d\n",gcd(a, b));
	return 0;
}