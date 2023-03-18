#include<iostream>
using namespace std;

struct Student{
    int roll_no;
    string name;
    int age;

};

int main()
{
    // Student s;
    // s.roll_no=3;
    // s.name="tom";
    // s.age=18;

    // cout<<s.roll_no<<" "<<s.name<<" "<<s.age<<endl;
    Student s[3];

    for(int i=0;i<3;i++)
    {
        cout<<"Enter name: ";
        cin>>s[i].name;
        cout<<"Enter age: ";
        cin>>s[i].age;
        cout<<"Enter roll no: ";
        cin>>s[i].roll_no;
    }

    for(int i=0;i<3;i++)
    {
        cout<<"name: "<<s[i].name<<endl;
        cout<<"age: "<<s[i].age<<endl;
        cout<<"roll no: "<<s[i].roll_no<<endl;
    }
    return 0;
}