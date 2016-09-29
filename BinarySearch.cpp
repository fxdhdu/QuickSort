/*
1、若输入数组已经有序，则需要判断输入数组是递增还是递减
2、mid的计算防止溢出
3、若数据的元素重复，则如何找到
*/

int BinarySearch(vector<int> &data, int value)
{
	if (data.size() == 0) return -1;
	sort(data.begin(), data.end());
	int L = 0, R = data.size() - 1, mid = 0;
	while (L <= R) {
		mid = L + ((R - L) >> 1);
		if (data[mid] == value) return mid;
		else if (data[mid] < value) L = mid + 1;
		else R = mid - 1;
	}
	return -1;
}
