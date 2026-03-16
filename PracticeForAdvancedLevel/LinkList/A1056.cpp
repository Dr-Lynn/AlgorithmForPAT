#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int Np, Ng;
	cin>>Np>>Ng;
	
	vector<int> weight(Np);
	for(int i = 0;i<Np;++i){
		cin>>weight[i];
	}
	
	queue<int> q;
	for(int i=0;i<Np;++i){
		int order;
		cin>>order;
		q.push(order);
	}
	
	vector<int> rank(Np, 0); //记录排名
	
	//模拟比赛过程
	while(q.size()>1){
		int size = q.size();
		int groups = (size + Ng - 1)/Ng;
		int loserRank = groups + 1;
		
		//将当前轮所有选手选出
		vector<int> cur;
		while(!q.empty()){
			cur.push_back(q.front());
			q.pop();
		}
		
		//分组处理  
		for(int g = 0;g<groups;++g){
			int start = g*Ng;
			int end = start + Ng;
			if(end > size) end = size; //最后一个分组的长度小于Ng
			
			//找出该组中重量最大的选手
			int maxIdx = cur[start];
			for(int j = start+1;j<end;++j){
				if(weight[cur[j]]>weight[maxIdx]){
					maxIdx = cur[j];
				}
			}
			
			// 设置该组其他选手的排名，将胜利者入队
			for(int j = start;j<end;++j){
				if(cur[j] != maxIdx){
					rank[cur[j]] = loserRank;
				}
			}
			q.push(maxIdx); 
		} 
	}
	
	//最后一人为冠军
	if(!q.empty()){
		rank[q.front()] = 1;
	} 
	
	//输出结果
	for(int i = 0;i<Np; ++i){
		if(i > 0) cout<<" ";
		cout<<rank[i];
	} 
	cout<<endl;
	
	return 0;
}
