#include<bits/stdc++.h>
using namespace std;
vector<string> v;
void generate_string(char *in, char *out, int i, int j)
{
	if(in[i]=='\0')
	{
		out[j] = '\0';
		v.push_back(out);
		return ;
	}
	int digit = in[i] - '0';
	char ch = digit + 'a' -1;
	out[j] = ch;
	generate_string(in,out,i+1,j+1);

	if(in[i+1]!='\0')
	{
		int second_digit = in[i+1]-'0';
		int no = digit*10 + second_digit;
		if(no<=26)
		{
			ch = no + 'a' - 1;
			out[j] = ch;
			generate_string(in,out,i+2,j+1);
		}
	}
	return ;
}
int main()
{
	char in[100];
	cin>>in;
	char out[100];
	generate_string(in,out,0,0);
	for(int i=0;i<v.size();i++)
	{
		if(i==0)
			cout<<"["<<v[i]<<", ";
		else if(i==v.size()-1)
			cout<<v[i]<<"]\n";
		else cout<<v[i]<<", ";
	}
	return 0;
}
