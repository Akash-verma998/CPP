#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll calc(ll n,ll r){
    ll res=1;
    if(r>n/2){
        r=n-r;
    }
    for(ll i=0;i<r;i++){
        res*=n;
        res/=(i+1);
        n--;
    }
    return res;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        ll N,K,n,r;
        cin>>N>>K;
        cout<<calc(N-1,K-1)<<endl;
    }
	return 0;
}
