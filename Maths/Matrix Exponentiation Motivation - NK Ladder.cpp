//suppose there is n ladder and you can max jump of k then your recurrence function will look like this
//f(n) = f(n-1)+f(n-2)+f(n-3)+.....f(n-k)

// f(n) =  sum f(1-i) where i goes to i=0 to k

//base case n==0 1way
// n<0    0 way

//tree
//4->3->0
//4->3->1->0
//4->3->2->1->0
//4->3->2->0
//4->2->0
//4->2->1->0
//4->1->0
//Time Complexity  Recursion O(k^n)
//                 DP        O(nk)
//                 matrix    O(k^3*logn)
// buy using dp    1 1 2 4 7 13 24 44 ... means next sum of previous k in this case k=3
            //     0 1 2 3 4 5  6  7
//                 f(i) = f(i-1) - f(i-(k+1)) +f(i-1)
                // f(i) = 2*f(i-1) - f(i-(k+1)) this is new recurrence by which O(n) and exp O(logn)

// If some ladder have snake
//f(i) =  sum(c[i-k]*f(i-k)) if there is snake c[i-k]=0
                                        //else c[i-k]=1













#include<iostream>
using namespace std;
int main()
{




}
