#include <iostream>
using namespace std;

const int MAXN = 1005;

int main(){
	int M, N, K;
	cin>>M>>N>>K;
	
	int seq[MAXN];
	int stack[MAXN];
	
	while(K--){
		for(int i = 0;i<N;i++){
			cin>>seq[i];
		}
		int top = -1;
		int cur = 1;
		int i = 0;
		
		while(i<N){
			if(top != -1 && stack[top] == seq[i]){
				top--;
				i++;
			}
			else if(cur<=N){
				if(top+1>=M) break;
				stack[++top] = cur++;
			}
			else break;
		}
		if(i == N) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
	
	
	
	return 0;
}
