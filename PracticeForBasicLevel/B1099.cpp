#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	if(n==2) return true;
	if(n%2==0) return false;
	int limit = sqrt(n);
	for(int i = 3;i<=limit;i += 2){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	int N;
	cin>>N;
	
	if(isPrime(N)){
		bool hasMinus = (N-6>=2 && isPrime(N-6));
		bool hasPlus = isPrime(N+6);
		if(hasMinus || hasPlus){
			cout<<"Yes"<<endl;
			if(hasMinus) cout<<N-6<<endl;
			else cout<<N+6<<endl;
			return 0;
		}
	}
	
	int m = N+1;
	while(true){
		if(isPrime(m)){
			if((m - 6 >= 2 && isPrime(m - 6)) || isPrime(m + 6)){
				cout<<"No"<<endl<<m<<endl;
				break;
			}
		}
		++m;
	}
	return 0;
}
