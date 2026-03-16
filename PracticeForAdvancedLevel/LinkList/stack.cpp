#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> st;
	
	st.push(10);
	st.push(20);
	
	int x = st.top(); //x = 20
	cout<<"x = "<<x<<endl;
	
	st.pop(); //不返回被移除的元素 
	int y = st.top(); //y = 10
	cout<<"y = "<<y<<endl;
	
	if(!st.empty()){
		cout<<st.size(); //输出1 
	}
	
	return 0;
}
