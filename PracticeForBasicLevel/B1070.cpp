#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main(){
	int N;
	cin>>N; 
	vector<int> lines(N);
	for(int i = 0;i<N;++i){
		cin>>lines[i];
	}
	sort(lines.begin(), lines.end());
	double ans = lines[0];
	for(int i = 1;i<N;++i){
		ans = (ans+lines[i])/2.0;
	}
	cout<<(int)ans<<endl;
	
	return 0;
}
