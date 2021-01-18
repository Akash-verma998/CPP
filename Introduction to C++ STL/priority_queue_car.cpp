#include<bits/stdc++.h>
#include<queue>
using namespace std;

class Car{
public:
    int x;
    int y;
    int id;
    Car(int id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist()
    {
        return x*x+y*y;
    }
    void print()
    {
        cout<<"Id: "<<id;
        cout<<" Location: "<<x<<","<<y<<endl;
    }
};
class carCompare{
public:
    bool operator()(Car a, Car b)
    {
       return a.dist()>b.dist();
    }
};
int main()
{
    priority_queue<Car,vector<Car>,carCompare> pq;
    int x[10] = {5,6,17,18,9,11,0,3};
    int y[10] = {1,-2,8,9,10,91,1,2};

    // insert this in q
    for(int i=0;i<8;i++)
    {
        Car c(i,x[i],y[i]);
        pq.push(c);
    }
    // heap max
    while(!pq.empty())
    {
        Car p = pq.top();
        p.print();
        pq.pop();
    }
}
