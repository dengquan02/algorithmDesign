#include <iostream>
using namespace std;

const int MAX_N = 1010;
const int inf = 100000000;


int main()
{
	int dp[MAX_N][10][10];	// 前i个已经完全匹配、第i+1个已经加了j、第i+2位已经加了k（减去 x 等价于加上 10-x）时所用的最少次数 
	char s1[MAX_N], s2[MAX_N];
	cin >> s1 >> s2;
	int len = strlen(s1);
	int up, dw;	// 第 i+1 位需要往上加、减的步数

	// 初始化
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = 0;	// 最初时（0个匹配）步数为0

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 10; j++) {
			up = (s2[i] - s1[i] - j + 20) % 10;		
			dw = (10 - up) % 10;
			// 第 i+1 位调整好后，枚举第 i+2 、i+3 位可以加或减的值
			for (int k = 0; k < 10; k++) {
				for (int x1 = 0; x1 <= up; x1++) {		// 枚举第 i+2 位可以加的值 - x1
					int t = (k + x1) % 10;		// 调整第 i+2 位已加的值		
					for (int y1 = 0; y1 <= x1; y1++) {	// 枚举第 i+3 位可以加的值 - y1
						dp[i + 1][t][y1] = min(dp[i + 1][t][y1], dp[i][j][k] + up);
					}
				}
				for (int x2 = 0; x2 <= dw; x2++) {		// 枚举第 i+2 位可以减的值 - x2
					int t = (k - x2 + 10) % 10;// 调整第 i+2 位已加的值
					for (int y2 = 0; y2 <= x2; y2++) {	// 枚举第 i+3 位可以减的值 - y2
						dp[i + 1][t][(10 - y2) % 10] = min(dp[i + 1][t][(10 - y2) % 10], dp[i][j][k] + dw);
					}
				}
			}
		}
	}

	cout << dp[len][0][0] << endl;

	return 0;
}