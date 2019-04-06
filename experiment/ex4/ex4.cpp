#include <iostream>
using namespace std;
int MOD;

//由公开密钥e和n，求私有密钥d
int ext_euclid(int a, int b, int &x, int &y) 
{ 
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = ext_euclid(b, a % b, x, y);
    int t = x % MOD;
    x = y % MOD;
    y = ((t - a / b * x) % MOD + MOD) % MOD;
    return gcd;
}


int main()
{
    int p, q, i, d;
    cout << "请输入一个质数 p (for example: 101) :";
    cin >> p;
    cout << "请输入一个质数 q (for example: 113) :";
    cin >> q;
    int n = p * q;
    cout<<"分组加密时，每个分组的大小 n 不能超过 p*q=";
    cout << n << endl;

    //求得φ(n)=(p-1)*(q-1)的值
    MOD = (p - 1) * (q - 1);
    cout << "模φ(n)=(p-1)*(q-1)=";
    cout << MOD << endl << endl;

    //选取与φ(n)互质的公钥e
    int e;
    cout << "输入与φ(n)互质的公钥 e (for example: 3533):";
    cin >> e;

    //由e和φ(n)生成私钥d
    int x, y;
    ext_euclid(e, MOD, d, y);
    while(d < 0) 
        d += MOD;
    cout << "通过调用扩展欧几里德算法，求得密钥d为：" << d << endl;

    //利用生成的公钥{e,n}对明文M进行加密
    int M, C;
    cout << "现在公钥{e,n}、私钥{d,n}均已生成完毕。\n\n请输入需要传输的明文内容进行加密(for example: 9726):";
    cin >> M;
    C = 1;
    for(i = 1; i <= e; i++)
        C = C * M % n;
    cout << "明文M=" << M << "经加密后得到密文C=M^e(mod n):" << C << endl;

    //利用生成的私钥私钥{e,n}对密文C进行解密
    M = 1;
    for(i = 1; i <= d; i++)
        M = M * C % n;
    cout << "密文C=" << C << "经解密后得到明文M=C^d(mod n):" << M << endl;
    return 0;
}

