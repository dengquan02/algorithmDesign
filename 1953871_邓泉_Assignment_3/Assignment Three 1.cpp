/* 1953871 邓泉 软件 */
#include <iostream>
using namespace std;

/*
n = 0	1								[0]
n = 1	1+9								[0;1,2...9]
n = 2	1+9+9*(10-1)					[0;1,2...9;10,11...,98(除去11,22,...,99)]
n = 3	1+9+9*(10-1)+9*(10-1)*(10-2)	[0;1,2...9;10,11...,98(除去11,22,...,99);100,101...998(除去111,222...999;11)]
.
.
.
n = k	f(0)+f(1)+f(2)+...+f(k)
*/
// 自底向上的DP算法 动态规划
int countNumberWithUniqueDigits(int n)
{
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 10;
	}

	int dp[10];
	dp[0] = 1;
	dp[1] = 9;
	int count = dp[0] + dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] * (10 - i + 1);
		count += dp[i];
	}
	return count;
}


int main()
{
	int n;

	// 输入
	while (1) {
		cout << "n = ";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "输入非法，请重新输入。" << endl;
			system("pause");
			system("cls");
		}
		else if (n < 0 || n >= 10) {
			cout << "输入的数字不在[0,10)范围内，请重新输入。" << endl;
			system("pause");
			system("cls");
		}
		else {
			break;
		}
	}

	// 输出
	cout << countNumberWithUniqueDigits(n) << endl;

	return 0;
}