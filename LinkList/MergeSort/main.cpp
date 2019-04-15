#include <iostream>

using namespace std;

class Mergesort{
private:

public:
    int temp[8];//过渡数组
    int arr[8];
    void Merge(int a[],int left,int right);
    void MergeSort(int a[],int left,int right);
};

void Mergesort::Merge(int a[],int left,int right)
{
    int i = left;
    int m = (left + right) / 2;
    int j = m + 1;
    int t = 0;
    while(i <= m && j <= right){
        if(a[i] < a[j]){
            temp[t] = a[i];
            t++;
            i++;
        }else{
            temp[t] = a[j];
            t++;
            j++;
        }
    }

    while(i <= m){
        temp[t] = a[i];
        t++;
        i++;
    }

    while(j <= right){
        temp[t] = a[j];
        t++;
        j++;
    }

    cout<<"0"<<endl;
}

void Mergesort::MergeSort(int a[],int left,int right)
{
    int mid;
    if(left < right){
       mid = (left + right) / 2;
       MergeSort(a,left,mid);//×ó±ß¹é²¢ÅÅÐò
       MergeSort(a,mid + 1,right);//ÓÒ±ß¹é²¢ÅÅÐò
       Merge(a,left,right);//ºÏ²¢

    }

}

int main()
{
    Mergesort m;
    cout<<"Input: ";
    for(int i = 0; i < 8; i++)
        cin>>m.arr[i];

    m.MergeSort(m.arr,0,7);
    cout << "After MergeSorting: ";
    for(int i = 0; i < 8; i++)
        cout<<m.temp[i]<<" ";
    return 0;
}
