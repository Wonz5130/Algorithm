#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010
int a[MAX];

/*
template <class T>
int SortableList<T>::Tsearch(const T& x, int left, int right)const{
	if(left <= right){
		int m = (left + right)/3;
		int n = 2 * (left + right)/3;
		if(x < l[m]) return TSearch(x, left, m-1);
		else if(x > l[n]) return TSearch(x, n+1, right);
		else if(x > l[m] && x < l[n]) return TSearch(x, m, n);
		else if(x == l[m]) return m;
		else rturn n;
	}
	return -1;
}
*/

int TSearch(int * &x, int left, int right){
	if(left <= right){
		int m = (left + right)/3;
		int n = 2 * (left + right)/3;
		if(x < a[m]) return TSearch(x, left, m-1);
		else if(x > a[n]) return TSearch(x, n+1, right);
		else if(x > a[m] && x < a[n]) return TSearch(x, m, n);
		else if(x == a[m]) return m;
		else return n;
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int *temp = a;
	cout << const int& (TSearch(temp, 0, n-1)) << endl;
	return 0;
}