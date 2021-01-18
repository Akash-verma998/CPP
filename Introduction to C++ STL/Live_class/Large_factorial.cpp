#include<iostream>
using namespace std;

void multiply(int *a,int &n,int no)
{
    // array 1 2 3 4 0 0 0 by 4
    int carry =0;
    for(int i=0;i<n;i++)
    {
        int product = a[i]*no + carry;
        a[i]=product%10;
        carry = product/10;
    }
    //left last carry
    while(carry)
    {
        a[n] = carry%10;
        carry = carry/10;
        n++;
    }
}
void big_fact(int number)
{
    // Assuming that the all value in starting is 0.
    int *a = new int[1000]{0};
    a[0]=1;
    int n=1; // it contain the index before which we have stored our answer.
    for(int i=2;i<=number;i++)
    {
        multiply(a,n,i);
    }
    // print the digit in reverse order
    for(int i=n-1;i>=0;i--)
    {
        cout<<a[i];
    }
    cout<<endl;

}
int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    big_fact(num);
    return 0;
}
