#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

struct Student{
	string id;
	int score;
	char level;
	string room;
	string date;
};

bool cmpType1(const Student& a, const Student& b){
	if(a.score != b.score) return a.score>b.score;
	return a.id < b.id;
}

bool cmpType3(const pair<string,int>& a, const pair<string, int>& b){
	if(a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

int main(){
	int N,M;
	scanf("%d %d", &N, &M);
	
	vector<Student> students(N);
	char id[14];
	int score;
	
	for(int i = 0;i<N;++i){
		scanf("%s, %d",id, &score);
		students[i].id = id;
		students[i].score = score;
		students[i].level = id[0];
		
		students[i].room = string(id + 1, 3);
		students[i].date = string(id + 4, 6);
		
		for(int i = 1;i<=M;++i){
			int type;
			char inst[10];
			scanf("%d %s", &type, inst);
			
			printf("Case %d: %d %s\n", i, type, inst);
			
			if(type == 1){
				vector<Student> res;
				char level = inst[0];
				for(int j = 0;j<N;++j){
					if(students[j].level == level)
					   res.push_back(students[j]);
				}
				if(res.empty()){
					printf("NA\n");
				}else{
					sort(res.begin(), res.end(), cmpType1);
					for(size_t j = 0;j<res.size();++j)
					   printf("%s %d\n",res[j].id.c_str(), res[j].score);
				}
			}else if(type == 2){
				int cnt = 0,sum = 0;
				string roomInst = inst;
				for(int j = 0;j<N;++j){
					if (students[j].room == roomInst) {   // 考场匹配
                    ++cnt;
                    sum += students[j].score;
                }
            }
            if (cnt == 0) {
                printf("NA\n");
            } else {
                printf("%d %d\n", cnt, sum);
            }
        } else if (type == 3) {
            // 类型3：统计指定日期的各考场人数，并按人数降序、考场编号升序输出
            map<string, int> mp;        // 键：考场编号，值：该考场在该日期的人数
            string dateInst = inst;      // 指令中的日期
            for (int j = 0; j < N; ++j) {
                if (students[j].date == dateInst) {   // 日期匹配
                    ++mp[students[j].room];            // 对应考场人数加1
                }
            }
            if (mp.empty()) {
                printf("NA\n");
            } else {
                // 将map中的键值对转为vector，便于排序
                vector<pair<string, int> > res(mp.begin(), mp.end());
                sort(res.begin(), res.end(), cmpType3);   // 按规则排序
                for (size_t j = 0; j < res.size(); ++j)
                    printf("%s %d\n", res[j].first.c_str(), res[j].second);
            }
        }
    }
}
	return 0;
}
