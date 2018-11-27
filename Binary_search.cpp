//二分查找：
int findLastLE(int *array, int n, int target) // satisfy condition: array[?] <= target and the last one
{
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (array[mid] <= target)
			start = mid + 1;
		else if (array[mid] > target)
			end = mid - 1;
	}
	
	if (start == 0)
		return -1;
 
	return start - 1;
}
 
int findFirstGE(int *array, int n, int target) // satisfy condition: array[?] >= target  and the first one
{
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (array[mid] < target)
			start = mid + 1;
		else if (array[mid] >= target)
			end = mid - 1;
	}
	if (end == n - 1)
		return -1;
	return end + 1;

}
