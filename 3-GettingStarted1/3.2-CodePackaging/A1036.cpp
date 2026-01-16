#include <iostream>
#include <string>
using namespace std;

typedef struct SG
{
    string name;
    char gender;
    string id;
    int grade;
}s_grade;

int main() {
    int n;
    cin>>n;
    s_grade temp_m,temp_f,stu;
    int m_l_grade = 101, f_h_grade = -1;
    bool count_m = false,count_f = false;
    char gen[2] = {'M','F'};

    for(int i = 0;i<n;i++)
    {
        cin>>stu.name>>stu.gender>>stu.id>>stu.grade;
        if(stu.gender == 'M')
        {
            count_m = true;
            if(stu.grade<m_l_grade)
            {
                temp_m = stu;
                m_l_grade = stu.grade;
            }
        }
        if(stu.gender == 'F')
        {
            count_f = true;
            if(stu.grade>f_h_grade)
            {
                temp_f = stu;
                f_h_grade = stu.grade;
            }
        }
    }
    if(count_f)
    {
        cout<<temp_f.name<<" "<<temp_f.id<<endl;
    } else{
        cout<<"Absent"<<endl;
    }
    if(count_m)
    {
        cout<<temp_m.name<<" "<<temp_m.id<<endl;
    } else{
        cout<<"Absent"<<endl;
    }
    if(count_f && count_m)
    {
        cout<<f_h_grade-m_l_grade<<endl;
    } else{
        cout<<"NA"<<endl;
    }

    return 0;
}
