/*
Remove Duplicates

Given an integer array A which contains duplicates. Remove duplicates from the array and return a new array without any duplicates.
That is, it should contain only unique elements.
NOTE : Best case time complexity-O(n) where n is the no of elements in the array.

Input Format :
First element is the size(N) of the array followed by N integers which are elements of the array separated by space

Sample Input :
10 105 106 111 114 105 135 138 111 147 114

Sample Output :
105 106 111 114 135 138 147

*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


vector<int> removeDuplicates(vector<int> input){
    /*
    set<int> s;
    vector<int> result;
    for(int i=0;i<input.size();i++)
    {
        if(s.find(input[i])==s.end())
        {
            s.insert(input[i]);
            result.push_back(input[i]);
        }
    }
    return result;
    */
    
    //another method
    vector<int> result;
    sort(input.begin(),input.end());
    result.push_back(input[0]);
    for(int i=1;i<input.size();i++)
    {
        if(input[i]!=input[i-1])
        {
            result.push_back(input[i]);
        }
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    vector<int> result=removeDuplicates(input);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}
