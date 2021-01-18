#include<bits/stdc++.h>
using namespace std;

#define ll long long



ll p[100005];

void seive(){
    for(ll i=0;i<=100000;i++)p[i]=1;
    for(ll i=2;i*i<=100000;i++){
        if(p[i]){
            for(ll j=i*i;j<=100000;j+=i)
            p[j]=0;
        }
    }


}
ll segmented_sieve(ll a,ll b){
    bool pp[b-a+1];
    memset(pp,1,sizeof(pp));
    for(ll i=2;i*i<=b;i++){
        if(p[i]){
            int j;
            if(a>i){
				if(a%i)	j=a-a%i+i;
				else j=a;
			}
            else j=i;
            for(;j<=b;j+=i){
                if(j!=i) pp[j-a]=0;
            }
        }
    }
	//cout<<p[0]<<endl;
    ll res=1;
    for(ll i=a;i<=b;i++){
		//cout<<"A"<<endl;
        if(pp[i-a] && i!=1)cout<<i<<endl;
    }
    return res;
}
int main(){
	ll t;
    cin>>t;
    seive();
    while(t--){
        cout<<endl;
        ll l,r;
        cin>>l>>r;
        segmented_sieve(l,r);
    }
    return 0;
}
