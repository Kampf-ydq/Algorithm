#include <iostream>

using namespace std;

int f(int a)
{
    if(a == 1)
        return 1;
    else
        return a * f(a - 1);
}
int main()
{
    int n;
    cout << "输入阶乘中的数字n : " ;
    cin>>n;
    cout<<endl<<n<<"! = "<<f(n)<<endl;
    return 0;
}
