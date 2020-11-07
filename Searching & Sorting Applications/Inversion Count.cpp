/*

Aggressive Cows Problem

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3 
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.

*/

#include <bits/stdc++.h>
using namespace std;
long long merge(long long *arr,int left,int mid,int right)
{
    int i=left,j=mid,k=0;
    long long count=0;
    long long temp[right-left+1];
    while(i<mid && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            count+=(mid-i);
        }
    }
    while(i<mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++)
    {
        arr[i]=temp[k];
    }
    return count;
}

long long merge_sort(long long *arr,int left,int right)
{
    long long count=0;
    if(right>left)
    {
        int mid=(left+right)/2;
        long long countLeft=merge_sort(arr,left,mid);
        long long countRight=merge_sort(arr,mid+1,right);
        long long myCount=merge(arr,left,mid+1,right);
        return myCount+countLeft+countRight;
    }
    return count;
}

long long getInversions(long long *arr,int n)
{
    long long ans=merge_sort(arr,0,n-1);
    return ans;
}

//#include "solution.h"

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}