#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		vector<int> V;
		int cnt = 0;

		while (!nums1.empty() || !nums2.empty())
		{
			if (nums1.empty())
			{
				V.push_back(nums2.front());
				nums2.erase(nums2.begin());
			}
			else if (nums2.empty())
			{
				if (cnt < m)
					V.push_back(nums1.front());
				nums1.erase(nums1.begin());
				cnt++;
			}
			else if (nums1.front() < nums2.front())
			{
				if (cnt < m)
					V.push_back(nums1.front());
				nums1.erase(nums1.begin());
				cnt++;
			}
			else
			{
				V.push_back(nums2.front());
				nums2.erase(nums2.begin());
			}
		}
		nums1 = V;
	}
};