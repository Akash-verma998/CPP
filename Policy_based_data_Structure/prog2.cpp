#include<iostream>
#include <ext/pd_ds/assoc_container.hpp>
#include <ext/pd_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ppds;

int main()
{
	pbds st;
	st.insert(1);
	st.insert(3);
	st.insert(4);
	st.insert(10);
	st.insert(15);

	for(int i=0;i<st,size();i++)
	{
		cout<<st.find_by_order(i)<<"\n";
	}
}

