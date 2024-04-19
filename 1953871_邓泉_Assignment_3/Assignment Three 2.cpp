/* 1953871 邓泉 软件 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool CompareInterval(const Interval& a, const Interval& b)
{
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

int eraseOverlapIntervals(vector<Interval>& intervals)
{
	int count = 0;
	if (intervals.size() == 0) {
		return 0;
	}
	// 排序
	sort(intervals.begin(), intervals.end(), CompareInterval);
	int current_end = intervals[0].end;
	for (int i = 1; i < (int)intervals.size(); i++) {
		if (intervals[i].start < current_end) {
			count++;
		}
		else {
			current_end = intervals[i].end;
		}
	}
	return count;
}


int main()
{
	vector<Interval> intervals;
	// 输入 形如[[1,2],[2,3],[3,4],[1,3]]
	char ch;
	int s, e;
	cout << "intervals = ";
	cin >> ch;	// 开始：输入[
	while (ch != ']') {
		cin >> ch;	// [
		cin >> s;
		cin >> ch;	// ,
		cin >> e;
		cin >> ch;	// ]
		intervals.push_back(Interval(s, e));
		cin >> ch;	// , 继续; ] 结束
	}
	// 输出
	cout << eraseOverlapIntervals(intervals) << endl;
	
	return 0;
}