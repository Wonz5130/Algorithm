#include<iostream>
using namespace std;

int main(){
	int m = 0;
	int n;
	cin >> n;
	for(int i = 0;i < n; ++i){
		for(int j = 2 * i;j <= n; ++j){
			m++;
		}
	}
	cout << m << endl;
	return 0;
}