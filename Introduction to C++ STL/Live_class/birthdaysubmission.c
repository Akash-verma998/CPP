#include<iostream>
using namespace std;
int main()
{
	int s;
	cin>>s;
    //compute the number of ppl such that
    float num = 365;
    float denum = 365;

    // p denote the prob of some ppl having birthday on same date
    float p=1;

    // n denotes the number of ppl needed
    int n=0;

    // if p becomes less than 0.5 because we are staring from the
    while (p>s){
        p=p*(num/denum);
        num--;
        n++;
        cout<<n<<endl;
    }

}
