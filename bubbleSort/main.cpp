#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,8,6,3,9,10};
    int i,j,temp;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6 - i; j++){
            if(arr[j] < arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout<<"Bubble½µÐòÎª: "<<endl;
    for(i = 0; i < 6; i++){
        cout<< arr[i] <<" ";
    }
    return 0;
}
