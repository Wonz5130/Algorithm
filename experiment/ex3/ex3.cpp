#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int count = 0;

//判定两个皇后是否在同一列或在同一斜线上
bool Place(int k, int i, int *x)
{
   for(int j = 0; j < k; j++)
   if((x[j] == i) || (abs(x[j] - i) == abs(j - k))) 
       return false;
   return true;
}

//递归函数（求解n皇后问题）
void NQueens(int k, int n, int *x) 
{
    for(int i = 0; i < n; i++)  //显式约束的第一种观点，x[k] = 0,1,···,n-1
    {
        if(Place(k, i, x))  //约束函数
        {
            x[k] = i;
            if(k == n - 1)    
            {
                for(i = 0; i < n; i++) 
                  cout << x[i] << " ";  //输出一个可行解
                cout << endl;
                count ++;
            }
            else
            {
               NQueens(k + 1, n, x);  //深度优先进入下一层
            }
       }
    }
}


void NQueens(int n, int *x)
{
    NQueens(0, n, x);
}


int main()
{
    int queens[8];  //8皇后
    count = 0;
    for(int i = 0; i < 8; i++) 
        queens[i] = -1;
    NQueens(8, queens);
    cout << "The result is: " << count << endl;
    return 0;
}