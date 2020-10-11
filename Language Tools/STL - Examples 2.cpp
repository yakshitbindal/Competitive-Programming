/*

First non repeating character

In a given string, find the first non-repeating character .You are given a string, that can contain repeating characters. Your task is to return the first character in this string that does not repeat. i.e., occurs exactly once. The string will contain characters only from English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). If there is no non-repeating character print the first character of string.

Input Format :
Line 1 : A String , as mentioned above.

Output Format :
First non-repeating character

Sample Input 1 :
aDcadhc

Sample Output 1:
D

Sample Input 2 :
gdhIgHada

Sample Output 2 :
h

*/
#include<iostream>
#include<cstring>
#include<map>
using namespace std;


char nonRepeatingCharacter(string str)
{
    map<char,int> m;
    for(int i=0;i<str.length();i++)
    {
        m[str[i]]++;
    }
    for(int i=0;i<str.length();i++)
    {
        if(m[str[i]]==1)
            return str[i];
    }
    return str[0];
}

int main()
{
    string str;
    cin>>str;
    cout<<nonRepeatingCharacter(str)<<endl;
}
