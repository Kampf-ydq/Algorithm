#include <iostream>

using namespace std;

int Binarysearch(int a[],int x,int len);

int main()
{
    int array[10],i,number;
    cout << "按升序输入任意的10个整数: ";
    for(i = 0; i < 10; i++)
        cin>>array[i];
    cout<<"\n输入要查找的数: ";
    cin >> number;
    cout<<number<<"在数组中的位置---->"<<Binarysearch(array,number,10)<<endl;
    return 0;
}

int Binarysearch(int a[],int x,int len)
{
    int left = 0;
    int right = len - 1;
    int index;
    while(left <= right){
        index = (left + right) / 2;
        if(a[index] == x)
            return index + 1;
        else if(a[index] < x)
            left = index + 1;
        else
            right = index - 1;
    }

    return -1;
}
