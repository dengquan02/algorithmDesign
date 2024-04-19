#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
#define FILENAME "a.txt"

int main()
{
	//�Ǹ�������nλ������������λ�ϵ�����֮�����ֵ��Ϊk
	int n, k;
	cout << "������n��k��" << endl;
	cin >> n >> k;
	
	if (n >= 2 && k >= 0 && k <= 9) {	//�Ϸ����ж�
		queue<int> que;
		for (int i = 1; i <= 9; i++) {	//��ʼ�����У��ȼ��루���ܵģ���λ���֣�������ǰ���㣩
			que.push(i);
		}
		que.push(0);					//��Ϊ0�������������������Ϊÿ��ѭ���Ľ�����

		//����
		int num, d;						//��ǰ�����Լ���ĩβ����
		for (int i = 1; i < n; i++) {	//ѭ��n-1�Σ�ÿһ��ѭ����que�����������һλ��n-1�κ�͵��˷���Ҫ���nλ����
			while ((num = que.front()) != 0) {
				d = num % 10;
				//����С˳�����μ���
				if (d - k >= 0) {
					que.push(num * 10 + d - k);
				}
				if (k != 0 && d + k <= 9) {
					que.push(num * 10 + d + k);
				}
				que.pop();
			}
			que.pop();			//��ͷ��0����
			que.push(0);		//0���β
		}

		//���
		if (que.front() != 0) {
			cout << que.front();
			que.pop();
		}
		while (que.front() != 0) {
			cout << "," << que.front();
			que.pop();
		}

		/*
		//��� ���浽txt�ļ�
		ofstream ofs;
		ofs.open(FILENAME, ios::out);		//������ķ�ʽ���ļ� -- д�ļ�
		if (que.front() != 0) {
			ofs << que.front();
			que.pop();
		}
		while (que.front() != 0) {
			ofs << "," << que.front();
			que.pop();
			
		}
		ofs.close();						//�ر��ļ�
		*/
	}

	return 0;
}
