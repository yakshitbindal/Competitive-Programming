#include<bits/stdc++.h>
using namespace std;

int min_cost_iterative(int** input,int m,int n)
{
    int** dp=new int*[m];
    for(int i=0;i<m;i++)
    {
        dp[i]=new int[n];
    }
    dp[m-1][n-1]=input[m-1][n-1];
    for(int i=m-1;i>=0;i--)
    {
        dp[i][n-1]=dp[i+1][n-1] + input[i][n-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        dp[m-1][i]=dp[m-1][i+1] + input[i][n-1];
    }
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j]=input[i][j] + min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]));
        }
    }
    int ans=dp[0][0];
    for(int i=0;i<n;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
}

int min_cost_rec_DP(int** input,int si,int sj,int ei,int ej,int** output)
{
    if(si==ei && sj==ej)
        return input[ei][ej];
    if(si>ei || sj>ej)
        return INT_MAX;
    if(output[si][sj]>-1)
        return output[si][sj];
    int option1=min_cost_rec_DP(input,si+1,sj,ei,ej,output);
    int option2=min_cost_rec_DP(input,si+1,sj+1,ei,ej,output);
    int option3=min_cost_rec_DP(input,si,sj+1,ei,ej,output);
    int ans=input[si][sj] + min(option1,min(option2,option3));
    output[si][sj]=ans;
    return ans;
}

int min_cost_rec(int** input,int si,int sj,int ei,int ej)
{
    if(si==ei && sj==ej)
        return input[ei][ej];
    if(si>ei || sj>ej)
        return INT_MAX;
    int option1=min_cost_rec(input,si+1,sj,ei,ej);
    int option2=min_cost_rec(input,si+1,sj+1,ei,ej);
    int option3=min_cost_rec(input,si,sj+1,ei,ej);
    return input[si][sj] + min(option1,min(option2,option3));
}

int main()
{
    int n;
    cin>>n;
    int** input=new int*[n];
    int** output=new int*[n];
    for(int i=0;i<n;i++)
    {
        input[i]=new int[n];
        output[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
            output[i][j]=-1;
        }
    }
    cout<<min_cost_rec_DP(input,0,0,n-1,n-1,output)<<endl;
    for(int i=0;i<n;i++)
    {
        delete[] input[i];
    }
    delete [] input;
}