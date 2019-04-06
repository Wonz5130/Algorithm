#include<cstdio>
using namespace std;
#define MAX 10000

void BInsSort(int v[], int n){
	int left,right;
	for(int i = 1;i < n; i++){
		left = 0;
		right = i -1;
		int x = v[i];
		while(left <= right){
			int mid = (left + right) / 2;
			if(x < v[mid])
				right = mid - 1;
			else left = mid + 1;
		}
		for(int j = i-1; j >= left; j--){
			v[j + 1] = v[j];
		}
		v[left] = x;
	}
}

int main(){
	int n;
	int a[MAX];
	for(int i = 0;i < n; ++i){
		scanf("%d",&a[i]);
	}
	BInsSort(a, n);
	for(int i = 0;i < n; ++i){
		printf("%d",a[i]);
	}
	return 0;
}
