#include<iostream>
using namespace std;
int main()
{
    //compute the number of ppl such that
    float num = 365;
    float denum = 365;

    // p denote the prob of some ppl having birthday on same date
    float p=1;

    // n denotes the number of ppl needed
    int n=0;

    // if p becomes less than 0.5 because we are staring from the
    while (p>0.5){
        p=p*(num/denum);
        num--;
        n++;
        cout<<"Probability is "<<p<<"and"<<" no of people are "<<n<<endl;
    }

}
