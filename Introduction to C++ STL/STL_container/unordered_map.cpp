#include <iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

class Student{
    public:

    string firstname;
    string lastname;
    string rollno;

    Student(string f,string l,string no){
        firstname = f;
        lastname  = l;
        rollno = no;
    }
    bool operator==(const Student &s)const{
        return rollno==s.rollno;
    }
};

class Hashfn
{
public:
    size_t operator()(const Student &s) const{
        return s.firstname.length()+s.lastname.length();
    }

};
int main() {
    unordered_map<Student,int,Hashfn> student_map;

    Student p1("Prateek","Narang","010");
    Student p2("Rahul","Kumar","023");
    Student p3("Prateek","Gupta","030");
    Student p4("Rahul","Kumar","120");

    student_map[p1]=100;
    student_map[p2]=200;
    student_map[p3]=300;
    student_map[p4]=400;
    for(auto s: student_map)
        cout<< s.first.firstname<<" "<<s.first.lastname<<" "<<s.first.rollno<<" "<<s.second<<endl;
    return 0;
}
