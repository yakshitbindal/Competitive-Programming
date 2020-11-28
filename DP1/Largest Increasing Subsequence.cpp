#include<bits/stdc++.h>
using namespace std;

int lic(vector<int> input,int size)
{
    
    int* output = new int[size];
    output[0] = 1;
    for(int i=1;i<size;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(input[j]>input[i])
                continue;
            int tempOutput=output[j]+1;
            if(tempOutput>output[i])
                output[i]=tempOutput;
        }
    }
     int max_length = 0;
    for(int i=0; i<size; i++){
        if(output[i]>max_length)
        max_length = output[i];
    }
    delete [] output;
    return max_length;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
       int num;
       cin>>num;
       v.push_back(num);
    }
    cout<<lic(v,n);
    return 0;
}