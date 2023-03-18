#include<iostream>
using namespace std;

int main()
{
    int i;
    cout<<sizeof(i)<<endl;


    int *arr;
    // arr = (int*) malloc(6*sizeof(int));
    arr = (int *) calloc(6,sizeof(int));
    cout<<sizeof(arr)<<endl;

    for(int i=0;i<6;i++)
    {
        arr[i] = i+2;
    }

    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }

}