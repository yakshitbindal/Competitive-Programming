/*

Triplet sum

You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.
Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5


 Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)

*/

#include<bits/stdc++.h>
using namespace std;
int tripletSum(int *arr, int size, int x)
{
    int count=0;
	sort(arr,arr+size);
    for(int i = 0; i < size; i++)
    {
        int s = i + 1;
        int  e = size - 1;
        int val =x-arr[i];
        while(s < e)
        {
            if(arr[s]+arr[e]>val)
            {
                e--;
            }
            else if(arr[s]+arr[e]<val)
            {
                s++;
            }
            else
            {
                int count1=0, count2=0;
                for(int j=s;j<=e;j++)
                {
                    if(arr[j]==arr[s])
                    {
                        count1++;
                    }
                    else
                        break;
                }
                for(int j=e;j>=s;j--)
                {
                    if(arr[j]==arr[e])
                    {
                        count2++;
                    }
                    else
                        break;
                }
                int combine=count1*count2;
                if(arr[s]==arr[e])
                {
                    combine=((e-s+1)*(e-s))/2;
                }
                for(int k=0;k<combine;k++)
                {
                    //cout<<arr[i]<<" "<<arr[s]<<" "<<arr[e]<<endl;
                    count++;
                }
                s=s+count1;
                e=e-count2;
            }
        }
    }
	return count;
}

//main code

// #include <iostream>
// #include <algorithm>
// using namespace std;

// #include "solution.h"

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}