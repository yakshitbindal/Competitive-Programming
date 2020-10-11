#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Interval
{
    int st,et;
};

bool compare(Interval i1,Interval i2)
{
    return i1.st < i2.st;
}


int main()
{
    //sort function
    int arr[]={21,4,52,4,2,43,5445,323,23,2};
    sort(arr,arr+10);
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,arr+6,greater<int>()); //descending order
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //if we have to sort on the basis of intervals
    //e.g: 
    // I1=(6,4)
    // I2=(3,4)
    // I3=(4,6)
    // I4=(8,13)
    // output: {3,4},{4,6},{6,4},{8,13}

    //we can make our own struct and implement our own compare function
    Interval ar[]={{6,4},{4,6},{3,4},{8,13}};
    sort(ar,ar+4,compare);
    for(int i=0;i<4;i++)
    {
        cout<<ar[i].st<<":"<<ar[i].et<<endl;
    }

    //binary search (the array should be in increasing order)
    sort(arr,arr+10);
    cout<<binary_search(arr,arr+10,3)<<endl;

    cout<<lower_bound(arr,arr+10,6); //it will give pointer to that position
    cout<<endl;
    
    cout<<lower_bound(arr,arr+10,6)-arr;
    cout<<endl;
    //if number is not available then it will return index of big number than that number

    cout<<upper_bound(arr,arr+10,3)-arr;

    cout<<__gcd(10,6)<<endl;
    cout<<pow(2,5)<<endl;
    cout<<pow(2.2,5)<<endl;

    return 0;
}