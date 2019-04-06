#include<cstdio>
#include<algorithm>
using namespace std;

struct Fraction{
	long long up,down;  //分数的乘法和除法结果可能会越界,所以用 long long 型比较好
};

//求最大公约数：辗转相除法(欧几里得算法)
long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

/*
//更简洁的写法
long long gcd(long long a, long long b){
	return !b ? a : gcd(b, a % b);
}
*/

//分数化简
Fraction reduction(Fraction result){
	if(result.down < 0){  //分母为负数,令分子和分母都变为相反数
		result.up = - result.up;
		result.down = - result.down;
	}
	if(result.up == 0){  //如果分子为0
		result.down = 1;  //令分母为1
	}
	else{  //如果分子不为0,进行约分
		int d = gcd(abs(result.up),abs(result.down));  //分子分母的最大公约数
		result.up /= d;  //约去最大公约数
		result.down /= d;
	}
	return result;
}

//分数加法
Fraction add(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

//分数减法
Fraction minu(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

//分数乘法
Fraction multi(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

//分数除法
Fraction divide(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

//分数输出
void showResult(Fraction r){
	r = reduction(r);
	if(r.down == 1) printf("%lld\n",r.up);  //整数
	else if(abs(r.up) > r.down){  //假分数
		printf("%lld %lld/%lld\n",r.up / r.down,abs(r.up) % r.down,r.down);
	}
	else{  //真分数
		printf("%lld/%lld\n",r.up,r.down);
	}
}

int main(){
	Fraction f1,f2;
	scanf("%lld/%lld %lld/%lld",&f1.up,&f1.down,&f2.up,&f2.down);
	f1 = reduction(f1);
	f2 = reduction(f2);
	showResult(add(f1,f2));
	showResult(minu(f1,f2));
	showResult(multi(f1,f2));
	showResult(divide(f1,f2));
	return 0;
}
