#include <iostream>
using namespace std;

void drawStar(int i, int j, int num) {
    if (i >= num / 3 && i < 2 * num / 3 && j >= num / 3 && j < 2 * num / 3) {
        cout << ' '; // 중앙 부분 공백
    } else {
        if (num / 3 == 0)
            cout << '*'; // 가장 작은 단위 별출력
        else
            drawStar(i % (num / 3), j % (num / 3), num / 3);
    }
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++)
            drawStar(i, j, num);
        cout << '\n';
    }

    return 0;
}
