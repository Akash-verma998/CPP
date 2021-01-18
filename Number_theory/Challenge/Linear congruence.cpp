/*
We can solve this question using chines remainder theorem.


                        Chines Remainder theorem
                        System of linear congerence
x%2=1
it can be written like :
x = 1(mod 2) and CRT(Chines remainder theorem is used to find x

brute force solution take 1 to n

CRT:
 formula :
 generalize the system of linear recurrence
 nums = [2,3,7]
 vem = [1,2,5]

 so x%2 =1 , x%3=7 , x%7=5 these are three equation
 let us suppose that the size of the array is k:
 the x%num[0] = vem[0] .............. x%num[k-1] = vem[k-1]
 formula given by:
 x = sum of(rem[i]+pp[i]+inv[i]) from i  = 0 to k-1
 pp[i]  =  (product of all the numbers)/num[i];
 inv[i] = modular multiplicative inverse of pp[i] wrt to num[i]

 Ex pp[i]  wrt to 7
 (6*y)%7=1 here y is modular multiplicative inverse of 6

 EULAR phi Function:
 phi(8) =  no of number co prime with 8 have less than 8
 co prime no are those number whose gcd is 1;
 phi gives the count of +ve integers co prime with n

 phi(n) = n(1-1/p1)(1-1/p2)(1-1/p3)...(1-1/pk)

 N=(p1^k1)*(p2^k2)*(p3^k3)...(pn^kn)

 phi(N)=N(1-1/p1)(1-1/p2)(1-1/p3).........(1-1/pk)



*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y;
void extendedgcd(ll a,ll b)
{
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    extendedgcd(b,a%b);
    ll cx=y;
    ll cy=x-(a/b)*y;
    x=cx;
    y=cy;
    return;
}
int main() {
    ll k;
    cin>>k;
     vector<ll> arr(k);
     vector<ll> rr(k);
     ll p=1;
     for(ll i=0;i<k;i++)
     {
         cin>>arr[i];
          p*=arr[i];
     }
     for(ll i=0;i<k;i++)
     {
         cin>>rr[i];
     }
     vector<ll> pp(k);
     vector<ll> inv(k);
     for(ll i=0;i<k;i++)
     {
        pp[i]=p/arr[i];
        extendedgcd(pp[i],arr[i]);
        inv[i]=(x+arr[i])%arr[i];
     }

     ll sum=0;
     for(ll i=0;i<k;i++)
     {
        sum+=((rr[i]*pp[i]*inv[i])%p);
     }
 cout<<sum%p<<endl;
}
