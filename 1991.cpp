#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
using namespace std;
int testcase;

int N, M;

int arr[1001][1001];
int visited[1001][1001];


queue<pair<int, int >> q;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int day[1001][1001] = { 0, };
int temp[2][26];


void pre(int x) {
	if (x == -1)
		return;
	cout << char(x + 65);
	pre(temp[0][x]);
	pre(temp[1][x]);

}
void in(int x) {
	if (x == -1)
		return;
	in(temp[0][x]);
	cout << char(x + 65);
	in(temp[1][x]);
}
void post(int x) {
	if (x == -1)
		return;
	post(temp[0][x]);
	post(temp[1][x]);
	cout << char(x + 65);
}
int first, P;

int main() {

	scanf("%d", &N);
	for (int i =1; i <= N; i++) {
		char a, b, c;
		int count;
		cin >> a >> b >> c;
		count = int (a - 'A');
		if (b == '.')
			temp[0][count] = -1;
		else {
			temp[0][count] = b-'A';
		}
		if (c == '.')
			temp[1][count] = -1;
		else
			temp[1][count] = c-'A';


	}
	pre(0);
	cout << endl;
	in(0);
	cout << endl;
	post(0);

	
	
	
	return 0;
}
