#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


vector<vector<int>> press;
int n, m, r;
bool visit[301][301];
const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0, 1, 0, -1 };

bool sol(int y, int x, int wall)
{
	return ((y  == wall || y == n - wall - 1) ||
		(y  != wall && x == wall || y != wall && x == m - wall - 1));
}
void moving(vector<vector<int>>& v, int y, int x, int post, int now, int wall)
{


	if (y + 1 < n && !visit[y + 1][x] && sol(y+1,x,wall)) {
		post = v[y + 1][x];
		v[y + 1][x] = now;
		visit[y + 1][x] = true;
		now = post;
		moving(v, y + 1, x, post, now, wall);
		return;
	}
	if (x + 1 < m && !visit[y][x + 1] && sol(y , x+1, wall)) {
		post = v[y][x + 1];
		v[y][x + 1] = now;
		visit[y][x + 1] = true;
		now = post;
		moving(v, y, x + 1, post, now, wall);
		return;
	}
	if (y - 1 >= 0 && !visit[y - 1][x] && sol(y - 1, x, wall)) {
		post = v[y - 1][x];
		v[y - 1][x] = now;
		visit[y - 1][x] = true;
		now = post;
		moving(v, y - 1, x, post, now, wall);
		return;
	}
	if (x - 1 >= 0 && !visit[y][x - 1] && sol(y, x-1, wall)) {
		post = v[y][x - 1];
		v[y][x - 1] = now;
		visit[y][x - 1] = true;
		now = post;
		moving(v, y, x - 1, post, now, wall);
		return;
	}
}
int main()
{
	cin >> n >> m >> r;
	press = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> press[i][j];
		}

	int len = n > m ? m/2 : n/2;
	int cnt = 0;
	while (cnt < r) {
		for (int wall = 0; wall < len; ++wall) {
			moving(press, wall, wall, 0, press[wall][wall], wall);
		}
		memset(visit, 0, sizeof(visit));
		cnt++;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << press[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
