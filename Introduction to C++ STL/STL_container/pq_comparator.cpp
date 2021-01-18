#include<iostream>
#include<queue>
using namespace std;
class Person{
    public:
    string name;
    int age;
    Person()
    {

    }
    Person(string name, int age)
    {
        this->name=name;
        this->age=age;
    }
};
class PersonCompare{
public:
    bool operator()(Person p1,Person p2)
    {
        return p1.age<p2.age;
    }
};
int main()
{
    int n;
    cin>>n;
    priority_queue<Person,vector<Person>, PersonCompare> pq;
    for(int i=0;i<n;i++)
    {
        string name;
        int age;
        cin>>name>>age;
        Person p(name,age);
        pq.push(p);
    }
    int k=3;
    for(int i=0;i<k;i++)
    {
        Person p= pq.top();
        cout<<p.name<<" "<<p.age<<endl;
        pq.pop();
    }
    return 0;

}
