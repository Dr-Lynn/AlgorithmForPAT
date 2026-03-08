#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int N,hash[37] = {0};
	cin>>N;
	int num,count = 0;
	for(int i=0;i<N;i++){
		cin>>num;
		int cnt = 0;
		while(num){
			cnt += num%10;
			num = num/10;
		}
		hash[cnt] += 1;
	}
	
	for(int i = 0;i<=36;i++)
	{
		if(hash[i]>0) ++count;
	}
	printf("%d\n",count);
	
	bool first = true;
	for(int i = 0;i<=36;i++)
	{
		if(hash[i]>0){
			if(first){
				printf("%d",i);
				first = false;
			}
			else{
				printf(" %d",i);
			}
		}
	}
	printf("\n");
	return 0;
}
