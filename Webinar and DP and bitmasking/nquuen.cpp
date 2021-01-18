/*
                                                    Backtracking with Bitmasking webinar
N queen Problem:
three approach :
1. Normal backtracking and issafe fucntion
2. Backtracking and bitsets
3. Backtracking and Bitmask = World's most efficient solution
        generate a bitmask for all the row
        how to find last set bits directly:
         n = n&(-n)
         n= 001010
        -n= 110101+1 = 110110
        p = n*(-n) if we want to remove last set bits = n=n-p

*/

/*
// count set bits code
#include<iostream>
using namespace std;
int countBits(int n)
{
    int count = 0;
    while(n>0)
    {
        int p = n&(-n);
        n-=p;
        count++;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    cout<<countBits(n)<<endl;
}

*/


#include<iostream>
using namespace std;
int ans=0,n,Done;
//rowmask denote which position or column in all rows are filled
// ld and rd denote unsafe position for current row
//most optimised nqueen code
void solve(int rowMask,int ld, int rd)
{
    if (rowMask==Done)
    {
        ans++;
        return ;
    }
    int safe = Done & (~(rowMask|ld|rd));
    while(safe)
    {
        int p = safe & (-safe);
        safe = safe - p;
        solve((rowMask|p),(ld|p)<<1,(rd|p)>>1);
    }
}
int main()
{
    cin>>n;
    Done = (1<<n)-1;
    solve(0,0,0);
    cout<<ans;
    return 0;
}

