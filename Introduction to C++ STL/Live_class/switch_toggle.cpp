#include<bits/stdc++.h>
using namespace std;
int main()
{
    int testcase;
    cin>>testcase;
    int mat[55][55];
    for(int i=0;i<testcase;i++)
    {
        int m,n,k;
        cin>>m>>n>>k;
        vector<int> buldlit(m,0);
        // read the conflict matrix
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                cin>>mat[r][c];
                if (mat[r][c]=='*'){
                    ++buldlit[r];
                }
            }
        }
        //bulblit ocntaing all the element that are lighting in particular row
        sort(buldlit.begin(),buldlit.end(),less<int>());

        int idx = 0;
        while(k>0  && idx<m && n-buldlit[idx]>buldlit[idx])
        {
            //for any left almost toggle a possible row
            buldlit[idx] = n - buldlit[idx];
            --k;
            ++idx;
        }
        if(k!=0 && k%2==1)
        {
            //vector<int>:: iterator it = min_element(buldlit.begin(),buldlit.end())
            auto it = min_element(buldlit.begin(),buldlit.end());
            *it = n - *it;
        }
        cout<< accumulate(buldlit.begin(),buldlit.end(),0)<<"\n";
    }
    return 0;

}
