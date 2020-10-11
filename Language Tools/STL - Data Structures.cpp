#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    //string
    string s="Parikh";
    string s1(s);
    string s2(s,2,4);
    cout<<s<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;

    string s3=s.substr(1,4);
    cout<<s3<<endl;
    if(s1.compare(s2)==0)
    {
        cout<<s1<<" is equal to "<<s2<<endl;
    }
    else
    {
        cout<<s1<<" is not equal to "<<s2<<endl;
    }
    
    //vector
    vector<int> v(5);
    vector<int>::iterator it;  //to iterate over vector
    for(int i=0;i<v.size();i++)
    {
        v[i]=i+1;
    }
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
    
    return 0;
}