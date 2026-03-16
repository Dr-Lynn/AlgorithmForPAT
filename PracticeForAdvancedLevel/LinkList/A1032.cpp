#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

const int MAXN = 100000;
struct Node{
	char data;
	int next;
}nodes[MAXN];

//记录链表的节点 
bool visited[MAXN] = {0}; //不需要用memset，这个在C++里更好使
 
int main(){
	int head1,head2,n;
	scanf("%d %d %d",&head1,&head2,&n);
	
	for(int i=0;i<n;++i){
		int addr, nxt;
		char ch;
		scanf("%d %c %d",&addr,&ch,&nxt);
		nodes[addr].data = ch;
		nodes[addr].next = nxt;
	}
	
	//记录第一个链表的所有节点 
	int p = head1;
	while(p != -1){
		visited[p] = true;
		p = nodes[p].next;
	} 
	//遍历第二个链表，寻找第一个公共节点 
	int q = head2;
	while(q != -1){
		if(visited[q]){
			printf("%05d\n", q);
			return 0;
		}
		q = nodes[q].next;
	}
	printf("-1\n");
	return 0;
}
