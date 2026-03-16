#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

struct Node{
	int key;
	int next;
}nodes[MAXN];

struct ListNode{
	int addr;
	int key;
};

bool cmp(const ListNode& a,const ListNode& b){
	return a.key<b.key;
}

int main(){
	int n, head;
	cin>>n>>head;
	
	for(int i=0;i<n;++i){
		int addr,key,next;
		cin>>addr>>key>>next;
		nodes[addr].key = key;
		nodes[addr].next = next;
	}
	
	//遍历链表，收集有效节点
	vector<ListNode> list;
	int cur = head;
	while(cur != -1){
		ListNode node;
		node.addr = cur;
		node.key = nodes[cur].key;
		list.push_back(node);
		cur = nodes[cur].next;
	} 
	
	//如果链表为空
	if(list.empty()){
		cout<<"0 -1"<<endl;
		return 0;
	} 
	
	//按key排序
	sort(list.begin(), list.end(),cmp);
	
	//输出第一行
	cout<<list.size()<<" "<<setw(5)<<setfill('0')<<list[0].addr<<endl;
	//等效于这个代码：printf("%d %05d\n", list.size(), list[0].addr);
	
	//输出每个节点 
	for(int i = 0;i<list.size();++i){
		int addr = list[i].addr;
		int key = list[i].key;
		int nextAddr = (i == list.size()-1) ? -1 : list[i+1].addr;
		
		cout<<setw(5)<<setfill('0')<<addr<<" " <<key<<" ";
		if(nextAddr == -1) cout<<"-1"<<endl;
		else 
		cout<<setw(5)<<setfill('0')<<nextAddr<<endl;
	}
	return 0;
}
