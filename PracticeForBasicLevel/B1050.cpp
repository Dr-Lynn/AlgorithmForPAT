#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <functional> //for greater
#include <cmath> // for sqrt
using namespace std;

int main(){
	int N;
	cin>>N;
	
	vector<int> nums(N);
	for(int i = 0;i<N;++i){
		cin>>nums[i];
	}
	
	//降序排序
	sort(nums.begin(), nums.end(), greater<int>());
	
	//计算行数m和列数n
	int n = (int)sqrt(N);
	while(N%n != 0){
		n--;
	} 
	int m = N/n; //自动满足 m>=n
	
	//创建m行n列的二维矩阵
	//vector这里必须有空格，c++98语法是这样，c++11以后就不用了 
	vector<vector<int> > matrix(m, vector<int>(n));
	
	//螺旋填充
	int top = 0, bottom = m-1, left = 0, right = n-1;
	int idx = 0;
	
	while(idx < N){
		//从左到右填充上边
		if(top <= bottom){
			for(int j = left; j <= right;++j){
				matrix[top][j] = nums[idx++];
			}
			top++;
		}
		
		//从上到下填充右边 
		if(left <= right){
			for(int i = top;i<=bottom;++i){
				matrix[i][right] = nums[idx++];
			}
			right--;
		}
		
		// 从右到左填充下边
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                matrix[bottom][j] = nums[idx++];
            }
            bottom--;
        }

        // 从下到上填充左边
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = nums[idx++];
            }
            left++;
        }
	}
	
	//输出矩阵
	for(int i = 0;i<m;++i)
	{
		for(int j = 0;j<n;++j){
			cout<<matrix[i][j];
			if(j != n-1){
				cout<<' ';
			}
		}
		cout<<endl;
	} 
	
	return 0;
}
