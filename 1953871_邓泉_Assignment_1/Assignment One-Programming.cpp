#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
#define FILENAME "a.txt"

int main()
{
	//非负整数有n位，任意相邻两位上的数字之差（绝对值）为k
	int n, k;
	cout << "请输入n，k：" << endl;
	cin >> n >> k;
	
	if (n >= 2 && k >= 0 && k <= 9) {	//合法性判断
		queue<int> que;
		for (int i = 1; i <= 9; i++) {	//初始化队列，先加入（可能的）首位数字（不能有前导零）
			que.push(i);
		}
		que.push(0);					//因为0不可能是输出，将其作为每次循环的结束符

		//构建
		int num, d;						//当前数字以及其末尾数字
		for (int i = 1; i < n; i++) {	//循环n-1次（每一次循环后que里的数就增加一位，n-1次后就到了符合要求的n位数）
			while ((num = que.front()) != 0) {
				d = num % 10;
				//按大小顺序依次加入
				if (d - k >= 0) {
					que.push(num * 10 + d - k);
				}
				if (k != 0 && d + k <= 9) {
					que.push(num * 10 + d + k);
				}
				que.pop();
			}
			que.pop();			//队头的0出队
			que.push(0);		//0入队尾
		}

		//输出
		if (que.front() != 0) {
			cout << que.front();
			que.pop();
		}
		while (que.front() != 0) {
			cout << "," << que.front();
			que.pop();
		}

		/*
		//输出 保存到txt文件
		ofstream ofs;
		ofs.open(FILENAME, ios::out);		//用输出的方式打开文件 -- 写文件
		if (que.front() != 0) {
			ofs << que.front();
			que.pop();
		}
		while (que.front() != 0) {
			ofs << "," << que.front();
			que.pop();
			
		}
		ofs.close();						//关闭文件
		*/
	}

	return 0;
}
