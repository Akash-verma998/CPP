/*
Concept:
sum[n,m] = sum[m] - sum[n]
s(n) = f(0) + f(1) + f(2) + f(3) + f(4)

s(n) + f(1) = f(1) + f(0) + f(1) + f(2) + f(3) + f(4)..... f(n)

s(n) + f(1) = f(1) + f(2) + f(2) + f(3) + f(4) +  f(5) + f(6).....f(n)

s(n) + f(1) = f(2) + f(3) + f(3) + f(4) + f(5) + f(6) ...... f(n)

s(n) + f(1) =  f(n) + f(n+1) = f(n+2) // very good relation

s(n) =  f(n+2) - f(1) = f(n+2) - 1

so s(n,m) = s(m) - s(n-1)
          = f(m+2) - 1 -(f(n+1) - 1)
   s(n,m) = f(m+2) - f(n+1)// required result


*/


#include <iostream>
#include <vector>
using namespace std;

#define ll long long unsigned int
#define MOD 1000000007
vector<vector<ll> > a;
vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B ){

    //third matrix mei result store
    vector<vector<ll> > C(2+1,vector<ll>(2+1));

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int x=0;x<2;x++){

                C[i][j] = (C[i][j] + (A[i][x]*B[x][j]))%MOD;
            }

        }
    }
    return C;
}
vector<vector<ll> >  pow(vector<vector<ll> > A,ll p){
    //Base case
    if (p==0)
    {
        A[0][0]=1;
        return A;
    }
    if(p==1){
        return A;
    }
    //Rec Case
    if(p&1){
        return multiply(A, pow(A,p-1));
    }
    else{

        vector<vector<ll> > X = pow(A,p/2);
        return multiply(X,X);
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned int n,m;
        cin>>n>>m;
        a={{1,1},{1,0}};
        vector<vector<ll> > ans1 = pow(a,m+1);
        vector<vector<ll> > ans2 = pow(a,n);
        cout<<(ans1[0][0]%MOD-ans2[0][0]%MOD+MOD)%MOD<<endl;
    }

}

