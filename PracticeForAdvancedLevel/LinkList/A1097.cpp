#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib> //for abs求绝对值 
using namespace std;

const int maxn = 100001;

struct Node{
	int data;
	int next;
}nodes[maxn];

int main(){
	int head, n;
	cin>>head>>n;
	
	//接收整个数组 
	for(int i = 0;i<n;++i){
		int addr,data,next;
		cin>>addr>>data>>next;
		nodes[addr].data = data;
		nodes[addr].next = next;
	}
	
	bool appeared[10001] = {false}; //记录绝对值是否出现过
	vector<int> result; //保留的节点地址位置
	vector<int> removed; //溢出的节点地址顺序
	
	int cur = head;
	while(cur != -1){
		int val = abs(nodes[cur].data);
		if(!appeared[val]){
			appeared[val] = true;
			result.push_back(cur);
		}else{
			removed.push_back(cur);
		}
		cur = nodes[cur].next;
	} 
	
	//输出结果链表
	for(size_t i = 0;i<result.size();++i){
		int addr = result[i];
		int next = (i == result.size()-1) ? -1 : result[i+1];
		printf("%05d %d ", addr, nodes[addr].data);
		if(next == -1) printf("-1\n");
		else printf("%05d\n", next);
	} 
	
	//输出移除链表 
	for(size_t i = 0;i<removed.size();++i){
		int addr = removed[i];
		int next = (i == removed.size()-1) ? -1 : removed[i+1];
		printf("%05d %d ", addr, nodes[addr].data);
		if(next == -1) printf("-1\n");
		else printf("%05d\n", next);
	} 
	
	return 0;
}
