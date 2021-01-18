/*

online judge :
mostly online judge use processor than can perform 10^8 operation in 1 sec



    N         |     Worst Complexity     |    Example
    N<=10     |     O(n!) , O(2^n)       |    Permutation, Subsets
    N<=18     |     O(2^n*n^2)           |    TSP with DP
    N<22      |     O(2^n.N)             |    DP with Bitmask
    N<100     |     O(n^4)               |    floyd warshell
    N<2000    |     O(n^2logN)           | Two nested loop
    N<10^4    |     O(n^2)               |  Bubble sort
    N< 10^5.6 |     O(nlogn)             |  Greedy sorting nlogn
    N< 10^8   |     O(N), O(log n), O(1) | Linear DP
    N<= 10^18 |     O(log N) , O(1)      | Nth factorial

 2. Input output

    Scanf , printf fast I/O




    Constructive Algorithms


 */

#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        //Rounds
        cout<<n<<endl;
        //print the config for every round
        for(int i=0;i<n;i++)
        {
            cout<<n<<endl;
            for(int j=0;j<n;j++)
            {
                cout<<j+1<<' '<<(i+j)%n+1<<' '<<(i+j+1)%n+1<<endl;
            }
        }
    }
     return 0;
}


/*
                        Mathematical Theorems

1. Wilson's Theorem:
   n>1 n is prime  then
   (n-1)! = n-1(mod n)

2.Euler's theorem:
    a^phie(p) = 1(modp)
    a^p-1  = 1(mod p)
    a.a^p-2 = 1(mod p)
    a.y = 1 (mod p)
    inverse of a wrt ot p

    inverse of a wrt to p is a^p-2 where p is prime number
3. Lvkas theorem:
   nCr%p = n!/((n-r)!*r!) =  n(n-1).......(n-r+1)/r!
   =(a/b)%p
   =((n%p)*(n-1)%p.......)*[(b^-1)%p])%p

   = b^-1%p = (b^p-2)%p



*/

