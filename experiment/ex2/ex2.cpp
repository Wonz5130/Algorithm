#include <iostream>
#include <cstring>  //memset需要用到这个库
#include <algorithm>
using namespace std;
int const MaxLen = 50;
 
class LCS
{
public:
    LCS(int nx, int ny, char *x, char *y)  //对数据成员m、n、a、b、c、s初始化
    {
        m = nx;  //对m和n赋值
        n = ny;
        a = new char[m + 2];  //考虑下标为0的元素和字符串结束标记
        b = new char[n + 2];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < nx + 2; i++)  //将x和y中的字符写入一维数组a和b中
            a[i + 1] = x[i];
        for(int i = 0; i < ny + 2; i++)
            b[i + 1] = y[i];
        c = new int[MaxLen][MaxLen];  //MaxLen为某个常量值
        s = new int[MaxLen][MaxLen];
        memset(c, 0, sizeof(c));  //对二维数组c和s中元素进行初始化
        memset(s, 0, sizeof(s));
  }
  int LCSLength();  //求最优解值（最长公共子序列长度）
 
  void CLCS()  //构造最优解（最长公共子序列）
  {
    CLCS(m, n);  //调用私有成员函数CLCS(int,int)
  }
 
private:
    void CLCS(int i, int j);
    int (*c)[MaxLen], (*s)[MaxLen];
    int m, n;
    char *a, *b;
};
 
int LCS::LCSLength()
{
    for(int i = 1; i <= m; i++)  //初始化行标或列标为0的元素
        c[i][0] = 0;
    for(int j = 1; j <= n; j++) 
        c[0][j] = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])  //由c[i-1][j-1]得到c[i][j]
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                s[i][j] = 1;
            }
            else if(c[i - 1][j] >= c[i][j - 1])  //由c[i-1][j]得到c[i][j]
            {
                c[i][j] = c[i - 1][j];
                s[i][j] = 2;
            }
            else  //由c[i][j-1]得到c[i][j]
            {
                c[i][j] = c[i][j - 1];
                s[i][j] = 3;
            }
        }
    }
    return c[m][n];  //返回最优解值
}

//构造最长公共子序列
void LCS::CLCS(int i, int j)
{
    if(i == 0 || j == 0)  //终止条件
        return;
    if(s[i][j] == 1)
    {
        CLCS(i - 1, j - 1);
        cout << a[i];  //输出最优解的当前分量
    }
    else if(s[i][j] == 2) 
        CLCS(i - 1, j);
    else  
        CLCS(i, j - 1);
}
 
int main()
{
    int nx, ny;
    char *x = new char[MaxLen], *y = new char[MaxLen];
    cout << "Please input X:" << endl;
    scanf("%s", x);
    nx = strlen(x);
    cout << "Please input Y:" << endl;
    scanf("%s", y);
    ny = strlen(y);
    LCS lcs(nx, ny, x, y);
    cout << "The LCSLength of X and Y is:" << lcs.LCSLength() << endl;
    cout << "The CLCS is:" << endl;
    lcs.CLCS();
    cout << endl;
    delete []x;
    delete []y;
    return 0;
}
