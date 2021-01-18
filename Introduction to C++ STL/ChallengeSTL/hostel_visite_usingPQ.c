#include <iostream>
#include<queue>
#define ll long long
using namespace std;

class coord{
    public:
    ll x;
    ll y;
    coord(ll x,ll y){
        this->x=x;
        this->y=y;
    }
    int dist(){
        return x*x+y*y;
    }


};
bool compare(coord a,coord b){
    return a.dist()<b.dist();
}

class cmp{
public:
bool operator()(coord n1,coord n2){
    return n1.dist()<n2.dist();
}
};

int main(){
    priority_queue<coord,vector<coord>,cmp>pq;
    ll q,k;
    ll cs=0;
    cin>>q>>k;
    for(ll i=0;i<q;i++){
        ll query;
        cin>>query;
        if(query==1){
            ll x,y;
            cin>>x>>y;
            coord c(x,y);
            if(cs<k){
            pq.push(c);
            cs++;
            }
        else{
                if(compare(c,pq.top()))
                    pq.pop();
                pq.push(c);
            }
        }
        else if(query==2){
        coord c=pq.top();
        cout<<c.dist()<<endl;
        }
    }
}
