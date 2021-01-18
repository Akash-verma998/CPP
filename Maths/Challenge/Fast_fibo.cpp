#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define MOD 1000000007
vector<vector<ll> > a;
vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B ){

    //third matrix mei result store
    vector<vector<ll> > C(2+1,vector<ll>(2+1));

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int x=0;x<2;x++){

                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            }

        }
    }
    return C;
}
vector<vector<ll> >  pow(vector<vector<ll> > A,ll p){

    //Base case
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
        ll n;
        cin>>n;
        a={{1,1},{1,0}};
        vector<vector<ll> > ans = pow(a,n+2);
        cout<<ans[0][0]<<endl;
    }

}
