#include <cstdio>

int gcd(int a,int b)
{
	//辗转相除法求最大公约数 
	while(b){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main(){
	int n1,m1,n2,m2,K;
	
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&K);
	
	int n_min, m_min, n_max, m_max;
	//比较两个分数的大小，其实是通分法只算分子
	//因为同分后分母相同 
	if(n1*m2<n2*m1){
		n_min = n1; m_min = m1;
		n_max = n2; m_max = m2;
	}
	else{
		n_min = n2; m_min = m2;
		n_max = n1; m_max = m1;
	}
	
	//i的最大值和最小值，按照手算的方法 
	int lower = (n_min*K)/m_min+1;
	int upper = (n_max*K-1)/m_max;
	
	bool first = true;
	for(int i = lower;i<=upper;++i){
		if(gcd(i,K) == 1){
			if(first){
				printf("%d/%d",i,K);
				first = false;
			}
			else{
				printf(" %d/%d",i,K);
			}
		}
	}
	printf("\n");
	return 0;
}
