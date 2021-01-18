#include<bits/stdc++.h>



using namespace std;



int arr[100005];

int sorted_arr[100005];

int temp[100005];



int main()

{

    int t;

    cin>>t;

    while(t--)

    {

        int n, k;

        cin>>n>>k;

        //unordered_map<int, int> m;

        for(int i=0;i<n;i++)

        {

            cin>>arr[i];

          //  if(m.find(arr[i])==m.end())

            //    m[arr[i]]=1;

            //else

              //  m[arr[i]]++;

            //if(arr[i]>n)

              //  f=1;

            sorted_arr[i]=arr[i];

            temp[i]=-1;

        }



        sort(sorted_arr, sorted_arr+n);

        int flag=1;

        for(int i=0;i<n;i++)

        {

            int f=0;

            int element=arr[i];

            int upper=upper_bound(sorted_arr, sorted_arr+n, element)-sorted_arr-1;

            int lower=lower_bound(sorted_arr, sorted_arr+n, element)-sorted_arr;

            //cout<<lower<<" "<<upper<<endl;

            int start=abs(i-lower)%k;

            if(!start)

                start=lower;

            else if(i<lower)

                start=lower+k-start;

            else

                start=lower+start;

            //cout<<arr[i]<<" "<<start<<endl;

            for(int j=start;j<=upper;j+=k)

            {

                if(temp[j]==-1)

                {

                    temp[j]=0;

                    f=1;

                    break;

                }

            }

            //cout<<pos<<" "<<i<<endl;

            if(!f//abs(i-pos)%k!=0)

            )

            {

                flag=0;

                break;

            }

        }



        if(flag)

            cout<<"yes"<<endl;

        else

            cout<<"no"<<endl;

    }

}
