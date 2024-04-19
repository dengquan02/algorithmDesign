#include <iostream>
using namespace std;

const int MAX_N = 1010;
const int inf = 100000000;


int main()
{
	int dp[MAX_N][10][10];	// ǰi���Ѿ���ȫƥ�䡢��i+1���Ѿ�����j����i+2λ�Ѿ�����k����ȥ x �ȼ��ڼ��� 10-x��ʱ���õ����ٴ��� 
	char s1[MAX_N], s2[MAX_N];
	cin >> s1 >> s2;
	int len = strlen(s1);
	int up, dw;	// �� i+1 λ��Ҫ���ϼӡ����Ĳ���

	// ��ʼ��
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = 0;	// ���ʱ��0��ƥ�䣩����Ϊ0

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 10; j++) {
			up = (s2[i] - s1[i] - j + 20) % 10;		
			dw = (10 - up) % 10;
			// �� i+1 λ�����ú�ö�ٵ� i+2 ��i+3 λ���Լӻ����ֵ
			for (int k = 0; k < 10; k++) {
				for (int x1 = 0; x1 <= up; x1++) {		// ö�ٵ� i+2 λ���Լӵ�ֵ - x1
					int t = (k + x1) % 10;		// ������ i+2 λ�Ѽӵ�ֵ		
					for (int y1 = 0; y1 <= x1; y1++) {	// ö�ٵ� i+3 λ���Լӵ�ֵ - y1
						dp[i + 1][t][y1] = min(dp[i + 1][t][y1], dp[i][j][k] + up);
					}
				}
				for (int x2 = 0; x2 <= dw; x2++) {		// ö�ٵ� i+2 λ���Լ���ֵ - x2
					int t = (k - x2 + 10) % 10;// ������ i+2 λ�Ѽӵ�ֵ
					for (int y2 = 0; y2 <= x2; y2++) {	// ö�ٵ� i+3 λ���Լ���ֵ - y2
						dp[i + 1][t][(10 - y2) % 10] = min(dp[i + 1][t][(10 - y2) % 10], dp[i][j][k] + dw);
					}
				}
			}
		}
	}

	cout << dp[len][0][0] << endl;

	return 0;
}