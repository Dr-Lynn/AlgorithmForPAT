#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_ID = 100000; //id从0到99999

int main(){
	int partner[MAX_ID];
	memset(partner, -1, sizeof(partner)); //初始化伴侣数组为-1
	
	int N;
	scanf("%d", &N);
	for(int i = 0;i<N;++i){
		int a, b;
		scanf("%d %d", &a, &b);
		partner[a] = b;
		partner[b] = a;
	} 
	
	int M;
	scanf("%d", &M);
	bool present[MAX_ID] = {false}; //标记出席人员，false本来就是0，所以可以这么搞 
	vector<int> guests; //存储所有出席的id
	for(int i = 0;i<M;++i){
		int id;
		scanf("%d", &id);
		guests.push_back(id);
		present[id] = true;
	} 
	
	vector<int> lonely; //存放落单的客人
	// 遍历所有出席的人，无伴侣或者伴侣未出席，则落单 
	for(size_t i = 0;i<guests.size();++i){
		int id = guests[i];
		if(partner[id] == -1 || !present[partner[id]]){
			lonely.push_back(id);
		} 
	}
	
	sort(lonely.begin(), lonely.end());
	
	printf("%d\n", (int)lonely.size());
	if(!lonely.empty()){
		for(size_t i = 0;i<lonely.size();++i){
			if(i>0) printf(" ");
			printf("%05d", lonely[i]); //五位输出，不足补零
		}
		printf("\n");
	} 
	return 0;
} 
