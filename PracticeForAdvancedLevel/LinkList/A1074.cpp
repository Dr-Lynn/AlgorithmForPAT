#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100000;

struct Node{
	int data;
	int next;
}nodes[maxn];

int main(){
	int head, n, k;
	cin>>head>>n>>k;
	
	//输入整个链表 
	for(int i = 0;i<n;++i){
		int addr, data, next;
		cin>>addr>>data>>next;
		nodes[addr].data = data;
		nodes[addr].next = next;
	}
	
	//遍历链表，得到顺序地址
	vector<int> order;
	int p = head; 
	while(p != -1){
		order.push_back(p);
		p = nodes[p].next;
	}
	
	//分组翻转
	for(int i = 0;i+k <= (int)order.size();i+=k){
		reverse(order.begin()+i, order.begin()+i+k);
	} 
	
	//输出结果
	for(int i = 0;i<order.size();++i){
		int addr = order[i];
		int next = (i == (int)order.size() - 1) ? -1:order[i+1];
		if (next == -1)
            printf("%05d %d -1\n", addr, nodes[addr].data);
        else
            printf("%05d %d %05d\n", addr, nodes[addr].data, next);
	} 
	
	return 0;
}
