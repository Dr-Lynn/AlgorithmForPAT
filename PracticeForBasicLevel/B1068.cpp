#include <iostream>
#include <map>
#include <cstdlib>
using namespace std;

int main(){
	int M, N, TOL;
	cin>>M>>N>>TOL; //M列N行
	
	int img[1000][1000];
	map<int, int> freq; // 统计颜色出现次数
	
	//读入图像并统计频率
	for(int i = 0;i<N;++i){
		for(int j = 0;j<M;++j){
			int color;
			cin>>color;
			img[i][j] = color;
			++freq[color];
		}
	}
	
	// 8 个邻域方向偏移
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int cnt = 0;          // 符合条件的点数
    int ans_x = -1, ans_y = -1, ans_color = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (freq[img[i][j]] != 1) continue;  // 不是独一无二

            bool ok = true;
            for (int k = 0; k < 8; ++k) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                    if (abs(img[i][j] - img[ny][nx]) <= TOL) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) {
                ++cnt;
                ans_x = j + 1;      // 列号从 1 开始
                ans_y = i + 1;      // 行号从 1 开始
                ans_color = img[i][j];
                if (cnt > 1) break; // 已找到多个，可提前退出
            }
        }
        if (cnt > 1) break;
    }

    // 输出结果
    if (cnt == 0) {
        cout << "Not Exist" << endl;
    } else if (cnt == 1) {
        cout << "(" << ans_x << ", " << ans_y << "): " << ans_color << endl;
    } else {
        cout << "Not Unique" << endl;
    }
 
	return 0;
}
