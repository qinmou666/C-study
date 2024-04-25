#include<iostream>
#include<vector>
#define HASHTABLE_CAPACITY 1000
using namespace std;
int binarySearch(vector<int> &nums, int target) {
	int i = 0;
	int j = nums.size() - 1;
	while (i <= j) {
		int m = i + (j - i) / 2;
		if (target > nums[m])
			i = m+1;
		else
		{
			if (target == nums[m])
				return i;
			else {
				j = m-1;
			}
		}
	}
	return -1;
}


int main() {
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,176,899,8888,9999,12121,12123,12334 };
	int res=binarySearch(v, 12121);
	printf("%d", res);
}