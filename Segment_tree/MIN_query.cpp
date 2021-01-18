#include <iostream>
#include<climits>
using namespace std;
void build(int *a, int *tree, int ss, int se, int i){
    if(ss==se){
        tree[i]= a[ss];
        return;
    }
    int mid= (ss+se)/2;
    build(a,tree,ss,mid,2*i);
    build(a,tree,mid+1,se,2*i+1);
    tree[i]= min(tree[2*i], tree[2*i+1]);
    return;
}
int query(int *tree,int ss,int se,int l,int r,int i){
    if(l>se || r<ss)
    return INT_MAX;

    if(l<=ss && r>=se)
    return tree[i];

    int mid=(ss+se)/2;
    int ls= query(tree,ss,mid,l,r,2*i);
    int rs= query(tree,mid+1,se,l,r,2*i+1);
    return min(ls,rs);
}
void update(int *tree,int ss,int se,int l,int i,int r){
    if(l>se || l<ss)
    return;

    if(ss==se){
    tree[i]=r;
    return; }

    int mid=(ss+se)/2;
    update(tree,ss,mid,l,2*i,r);
    update(tree,mid+1,se,l,2*i+1,r);
    tree[i]= min(tree[2*i], tree[2*i+1]);
}
void print(int *tree, int n){
    for(int j=0; j<4*n+1; j++) cout<<tree[j]<<" ";
}
int main() {
    int n,q; cin>>n>>q;
    int a[n]; a[0]=-1;
    for(int i=0;i<n;i++) cin>>a[i];
    int *tree= new int[4*n+1];
    build(a,tree,0,n-1,1);
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        int ss=1, se=n,i=1;
        if(type==1) {cout<<query(tree, ss,se,l,r,i)<<endl;}
        if(type==2) {update(tree,ss,se,l,i,r);  
        }
    }
    
}