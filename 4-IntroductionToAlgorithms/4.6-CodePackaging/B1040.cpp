#include <iostream>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main()
{
	string str;
	cin>>str;
	
	long long countP = 0; //当前字符左边P的数量 
	long long countT = 0; //字符串中T的总数 
	long long result = 0; //保存最终结果 

	//先统计整个字符串中T的总数
	for(int i = 0;i<str.size();i++)
	{
		if(str[i] == 'T')
		{
			countT++;
		}
	}
	
	//遍历字符串，计算PAT的数量
	for(int i = 0;i<str.size();i++)
	{
		if(str[i] == 'P')
		{
			//遇到P,左边P的数量加1
			countP++; 
		}
		else if(str[i] == 'A')
		{
			//遇到A，计算以这个A为中心的PAT的数量
			result = (result + countP * countT) % MOD; 
		}
		else if(str[i] == 'T')
		{
			//遇到T，右边T的数量减1
			//对于后续的A来说，这个T已经不在右边了
			countT--; 
		}
	} 
	
	cout << result << endl;
	
	return 0; 
}
