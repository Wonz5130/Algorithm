#include <iostream>
using namespace std;
int MOD;

//�ɹ�����Կe��n����˽����Կd
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
    cout << "������һ������ p (for example: 101) :";
    cin >> p;
    cout << "������һ������ q (for example: 113) :";
    cin >> q;
    int n = p * q;
    cout<<"�������ʱ��ÿ������Ĵ�С n ���ܳ��� p*q=";
    cout << n << endl;

    //��æ�(n)=(p-1)*(q-1)��ֵ
    MOD = (p - 1) * (q - 1);
    cout << "ģ��(n)=(p-1)*(q-1)=";
    cout << MOD << endl << endl;

    //ѡȡ���(n)���ʵĹ�Կe
    int e;
    cout << "�������(n)���ʵĹ�Կ e (for example: 3533):";
    cin >> e;

    //��e�ͦ�(n)����˽Կd
    int x, y;
    ext_euclid(e, MOD, d, y);
    while(d < 0) 
        d += MOD;
    cout << "ͨ��������չŷ������㷨�������ԿdΪ��" << d << endl;

    //�������ɵĹ�Կ{e,n}������M���м���
    int M, C;
    cout << "���ڹ�Կ{e,n}��˽Կ{d,n}����������ϡ�\n\n��������Ҫ������������ݽ��м���(for example: 9726):";
    cin >> M;
    C = 1;
    for(i = 1; i <= e; i++)
        C = C * M % n;
    cout << "����M=" << M << "�����ܺ�õ�����C=M^e(mod n):" << C << endl;

    //�������ɵ�˽Կ˽Կ{e,n}������C���н���
    M = 1;
    for(i = 1; i <= d; i++)
        M = M * C % n;
    cout << "����C=" << C << "�����ܺ�õ�����M=C^d(mod n):" << M << endl;
    return 0;
}

