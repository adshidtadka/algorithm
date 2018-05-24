#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

const int MAX_N = 110;
const int INF = 10000000;

typedef pair<int, int> P;

char maze[MAX_N][MAX_N + 1];
int n, m;
int sx, sy;
int gx, gy;

int d[MAX_N][MAX_N];

//移動４方向ベクトル
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// (sx, sy)から(gx, gy)への最短距離を求める
// たどり着けないとINF
int bfs() {
	queue<P> que;
	//全ての点をINFで初期化
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			d[i][j] = INF;
		}
	}

	//スタート地点をqueに入れて距離を0にする
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	//キューが空になるまでループ
	while(que.size()) {
	    //キューの先頭を取り出す
	    P p = que.front();
	    que.pop();
	    //ゴールなら終了
	    if (p.first == gx && p.second == gy)
	    {
	    	break;
	    }
	    //移動4方向ループ
	    for (int i = 0; i < 4; ++i)
	    {
	    	//移動した後の点を(nx, ny)とする
	    	int nx = p.first + dx[i];
	    	int ny = p.second + dy[i];

	    	//移動が可能か
	    	//すでに訪れていないか
	    	if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF)
	    	{
	    		//移動できるならばキューに入れて、距離を代入
	    		que.push(P(nx, ny));
	    		d[nx][ny] = d[p.first][p.second] + 1;
	    	}
	    }
	}
	return d[gx][gy];
}

void solve() {
	int res = bfs();
	printf("%d\n", res);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> maze[i][j];
		}
	}
	solve();
	return 0;
}






