#include <iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int N;

int r = 6;
int main()
{
	while (1) {

		cin >> N;
		if (N == 0)
			return 0;
		vector<int> arr(N);
		vector<int> worker;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (int i=0; i < N - r; i++) {
			worker.push_back(0);
		}
		for (int i=0; i < 6; i++) {
			worker.push_back(1);
		}
		vector<vector <int>> ans;
		do {
			vector<int> temp;
			for (int i = 0; i < N; i++) {
				if (worker[i] == 1) {
					temp.push_back(arr[i]);
				}
			}
			
			ans.push_back(temp);
		} while (next_permutation(worker.begin(), worker.end()));
		sort(ans.begin(), ans.end());
		for (auto &v : ans) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << ' ';
			}
			cout << endl;
		}
		printf("\n");

	}

}
