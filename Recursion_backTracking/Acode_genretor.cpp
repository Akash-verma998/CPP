#include<bits/stdc++.h>
using namespace std;
void generate_string(char *in, char *out, int i, int j)
{
	//base case
	if(in[i]=='\0')
	{
		out[j] = '\0';
		cout<<out<<endl;
		return ;
	}

	//rec case

	//one digit at time
	int digit = in[i] - '0';
	char ch = digit + 'A' -1;
	out[j] = ch;
	generate_string(in,out,i+1,j+1);

	//two at a time
	if(in[i+1]!='\0')
	{
		int second_digit = in[i+1]-'0';
		int no = digit*10 + second_digit;
		if(no<=26)
		{
			ch = no + 'A' - 1;
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
	return 0;
}
