q1. what is the expected no of trails for giving n Consectuive
heades?

let assume the answer is x
X=1/2(x+1)+1/4(x+2)+1/8(x+3)+1/16(x+4).....
because we need x more tarils is we get first head x+1 train neaded
if we get HT the for then for x we required x+2
if we get HHT the we required x+3
if HHHT then we required x+4
eq:
X=1/2(x+1)+1/4(x+2)+1/8(x+3)+1/16(x+4)....(1/2^n)*(n)
X=x(1/2+1/4+1/8......)+1/2+2/4+3/8+...n/2^n

Sn=1/2+2/4+3/8+...n/2^n
2*Sn = 1+ 2/2 + 3/4 + n/2^n-1
Sn = 1+ (2/2-1/2) (3/4-2/4).......-n/2^n
X= 2^n+1  - 2











#include<iostream>
using namespace std;
int main()
{

}
