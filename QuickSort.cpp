#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

int RandomInRange(int start, int end)
{
	if (end > start)
	{
		srand((unsigned int)time(NULL));
		return start + rand() % ((end - start));
	}
	return 0;
}

int Partition(vector<int> &data, int start, int end)
{
	int index = RandomInRange(start, end);
	swap(data[index], data[end]);

	int small = start - 1;
	for (index = start; index < end; index++) {
		if (data[index] < data[end]) {
			++small;
			if (small != index)
				swap(data[index], data[small]);
		}
	}
	++small;
	swap(data[small], data[end]);
	return small;
}

void QuickSort(vector<int> &data, int start, int end)
{
	if (start == end) return;
	int index = Partition(data, start, end);
	if (index > start) QuickSort(data, start, index);
	if (index < end) QuickSort(data, index + 1, end);
}
void QuickSort(vector<int> &data)
{
	if (data.size() == 0 || data.size() == 1) return;
	else QuickSort(data, 0, data.size() - 1);
	return;
}

int main(void)
{
	int n, tmp;
	while (cin >> n) {
		vector<int> data;
		while (n--) {
			cin >> tmp;
			data.push_back(tmp);
		}
		QuickSort(data);
		for (int i = 0; i < data.size(); i++) {
			cout << data[i] << ' ';
		}
		cout << endl;
	}
}
