#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a[1001][1001];
int visited[1001][1001][2]; 
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int bfs() {
	queue <pair<pair<int, int>, int>> q; 
	q.push({ { 1,1 }, 0 });
	visited[1][1][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int obs = q.front().second;
		q.pop();

		if (x == n && y == m) return visited[x][y][obs];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				
				if (a[nx][ny] == 0 && visited[nx][ny][obs] == 0) {
					visited[nx][ny][obs] = visited[x][y][obs] + 1;
					q.push({ { nx,ny }, obs });
				}

				
				if (a[nx][ny] == 1 && obs == 0) {
					visited[nx][ny][obs + 1] = visited[x][y][obs] + 1;
					q.push({ {nx,ny}, obs + 1 });
				}
			}
		}
	}
	return -1;
}
int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	cout << bfs() << endl;

	

}
