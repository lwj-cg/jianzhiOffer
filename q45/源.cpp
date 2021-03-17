#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

template<typename T>
void Partition(vector<T>& nums, int begin, int end, int& keyIdx, function<bool(T, T)> compare)
{
	if (begin >= end) return;
	keyIdx = (begin + end) / 2;
	std::swap(nums[end], nums[keyIdx]);
	int p1 = begin;
	int p2 = end-1;
	while (p1 <= p2)
	{
		while (p1<=end&&compare(nums[p1], nums[end])) ++p1;
		while (p2>=0&&compare(nums[end], nums[p2])) --p2;
		if (p1 <= p2)
		{
			std::swap(nums[p1], nums[p2]);
			++p1;
			--p2;
		}
	}
	std::swap(nums[p1], nums[end]);
	keyIdx = p1;
}

template<typename T>
void myQuickSort(vector<T>& nums, int begin, int end, function<bool(T,T)> compare)
{
	if (begin >= end) return;
	int keyIdx;
	Partition(nums, begin, end, keyIdx, compare);
	myQuickSort(nums, begin, keyIdx - 1, compare);
	myQuickSort(nums, keyIdx + 1, end, compare);
}

class Solution {
public:
	string minNumber(vector<int>& nums) {
		auto compare = [](int x, int y)->bool {
			if ((to_string(x) + to_string(y)) < (to_string(y) + to_string(x)))
			{
				return true;
			}
			else return false;
		};
		myQuickSort<int>(nums, 0, nums.size()-1, compare);
		string str = "";
		for (int i = 0; i < nums.size(); i++)
		{
			str += to_string(nums[i]);
		}
		return str;
	}
};

int main()
{
	vector<int> v = { 1,1,1,1 };
	Solution sol;
	string str = sol.minNumber(v);
}