#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
typedef struct Student{
    string sname;
    string sid;
    int grade;
}stu;
int main() {
    int n;
    scanf("%d",&n);
    stu student[1010];
    int min = 101,minid=0,max = -1,maxid=0;
    for(int i=0;i<n;i++)
    {
        cin>>student[i].sname>>student[i].sid>>student[i].grade;
        if(student[i].grade>max)
        {
            max = student[i].grade;
            maxid = i;
        }
        if(student[i].grade<min)
        {
            min = student[i].grade;
            minid = i;
        }
    }
    cout<<student[maxid].sname<<" "<<student[maxid].sid<<endl;
    cout<<student[minid].sname<<" "<<student[minid].sid<<endl;
    return 0;
}
