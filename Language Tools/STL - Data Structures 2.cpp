#include<iostream>
#include<utility>
#include<set>
#include<map>
using namespace std;
int main()
{

    //pair
    pair<int,char> p;
    p=make_pair(2,'b');
    pair<int,char> p2(1,'a');

    cout<<p.first<<" "<<p.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;

    //set
    set<int> s; //sets are implemented by balanced binary tree
    int arr[]={1,2,3,4,5,6,1,2,3,4,5};
    for(int i=0;i<11;i++)
    {
        s.insert(arr[i]);
    }
    set<int>::iterator it; //it will always contain unique elements
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }

    if(s.find(6)==s.end())
    {
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }

    //map
    map<int,int> mp;
    for(int i=0;i<11;i++)
    {
        mp[arr[i]]++;
    }
    map<int,int>::iterator itr;
    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        cout<<itr->first<<":"<<itr->second<<endl;
    }
    cout<<endl;

    mp.erase(1); //erase 1
    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        cout<<itr->first<<":"<<itr->second<<endl;
    }

    //map is same as unordered_map only order will be different

}