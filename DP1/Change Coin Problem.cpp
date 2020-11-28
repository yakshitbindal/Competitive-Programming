#include<bits/stdc++.h>
using namespace std;

int coin_change(int n,int* d,int numD)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(numD==0)
        return 0;
    int output=coin_change(n-d[0],d,numD)+coin_change(n,d+1,numD-1);
    return output;
}

int coin_change_DP(int n,int* d,int numD,int **output)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(numD==0)
        return 0;
    if(output[n][numD]>-1)
    {
        return output[n][numD];
    }    
    int outputTemp=coin_change(n-d[0],d,numD)+coin_change(n,d+1,numD-1);
    output[n][numD]=outputTemp;
    return outputTemp;
}

int main()
{
    int d[2]={1,2};
    cout<<coin_change(4,d,2)<<endl;
    return 0;
}