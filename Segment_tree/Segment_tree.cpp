#include<iostream>
using namespace std;
int lazy[10000];
int queryLazy(int *tree, int ss, int se, int qs, int qe, int index)
{
    //first step resolve the lazy value
    if(lazy[index]!=0)
    {
        tree[index]+=lazy[index];
        if(ss!=se)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(ss>qe||se<qs)
    {
        return INT_MAX;
    }
    if(ss>=qs && se<=qe)
    {
        return tree[index];
    }
    //partial over lap
    int mid = (ss+se)/2;
    int left=queryLazy(tree,ss,mid,qs,qe,2*index);
    int right = queryLazy(tree,mid+1,se,qs,qe,2*index+1);
    return min(left,right);
}
void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    //never go to down side if u have lazy value at node, first resolve it.
    if(lazy[index]!=0)
    {
        tree[index] +=lazy[index];
        // if not a leaf node
        if(ss!=se)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
        // out of bounds
        if(ss>r|| l>se)
        {
            return ;
        }
        // complete overlap
        if(ss>=l && se<=r)
        {
            tree[index]+=inc;
            //pass the lazy value to the children
            if(ss!=se)
            {
                lazy[2*index] +=  inc;
                lazy[2*index+1]+=inc;
            }
        }
        int mid = (se+ss)/2;
        updateRangeLazy(tree,ss,mid,l,r,inc,2*index);
        updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);
        tree[index] = min(tree[2*index],tree[2*index+1]);
        return;
    }
}
void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    // out of bounds
    if(l>se||r<ss)
    {
        return ;
    }
    // leaf node
    if(ss==se)
    {
        tree[index]+=inc;
        return ;
    }

    // left and right
    int mid = (ss+se)/2;
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;

}
void updateNode(int *tree, int ss, int se, int i, int increment, int index)
{
    if(i>se||i<ss)
    {
        return ;
    }
    if(ss==se)
    {
        tree[index]+=increment;
        return;
    }
    int mid =  (ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index]= min(tree[2*index],tree[2*index+1]);
}
int query(int *tree, int ss, int se, int qs, int qe, int index)
{
    // complete overlap
    if(ss>=qs && se<=qe)
    {
        return tree[index];
    }
    //no overlap
    if(qe<ss || qs>se)
    {
        return INT_MAX;
    }
    int mid=(ss+se)/2;
    int leftans = query(tree,ss,mid,qs,qe,2*index);
    int rightans = query(tree,mid+1,se,qs,qe,2*index+1);
    return min(leftans, rightans);
}
void buildTree(int *a,int s,int e,int *tree,int index)
{
    if(s==e)
    {
        tree[index]=a[s];
        return ;
    }
    int mid=(s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}
int main()
{
    int a[]={1,3,2,-5,6,4};
    int n= sizeof(a)/sizeof(int);
    int *tree = new int[4*n+1];
    buildTree(a,0,n-1,tree,1);
    for(int i=1;i<=13;i++)
    {
        cout<<tree[i]<<" ";
    }
    /*
    cout<<"\n";
//    int l,r;
//    cin>>l>>r;
//    cout<<query(tree,0,n-1,l,r,1);
    int l,r, inc;
    cin>>l>>r>>inc;
    updateRange(tree,0,n-1,l,r,inc,1);
    int no_of_q = 6;
    while(no_of_q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<queryLazy(tree,0,n-1,l,r,1)<<endl;
    }
    */
    return 0;
}
