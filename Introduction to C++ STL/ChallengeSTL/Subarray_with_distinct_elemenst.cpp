/*
Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct

Input Format
An integer n denoting size of array followed by n integers

Constraints
1<=N<=10^5

Output Format
The answer mod 10^9+7

Sample Input
3
1 2 3
Sample Output
10
*/

#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[10000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=0;
    int j=0;
    set<int> s;
    int res=0;
    while (i<n)
    {
        while(j<n && s.find(a[j])==s.end())
        {
            s.insert(a[j]);
            j++;
        }
        res = res + ((j-i)*(j-i+1))/2;
        res=res%1000000007;
        s.erase(a[i]);
        i++;
    }
    cout<<res<<endl;
    return 0;
}
