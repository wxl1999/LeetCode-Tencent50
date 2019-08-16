#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int size = pow(2, nums.size());
        for (int i = 0; i < size; i++) {
            vector<int> tmp;
            int j = i;
            int offset = 0;
            while (j) {
                if (j % 2)
                    tmp.push_back(nums[offset]);
                ++offset;
                j /= 2;
            }
            res.push_back(tmp);
        }
        return res;
    }
};