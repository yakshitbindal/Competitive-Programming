/*

Extract Unique characters

Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde

*/

#include<bits/stdc++.h>
using namespace std;
char* uniqueChar(char *str){
    char* a=new char[10000];
    map<char,int> m;
    for(int i=0;str[i]!='\0';i++)
    {
        m[str[i]]++;
    }
    int k=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(m[str[i]]==-1)
            continue;
        a[k++]=str[i];
        m[str[i]]=-1;
    }
    return a;
}

//main code
// #include<iostream>
// using namespace std;
// #include "solution.h"

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
