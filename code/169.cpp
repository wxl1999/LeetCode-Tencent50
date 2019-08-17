#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                res = nums[i];
            }
            else
                count += (nums[i] == res) ? 1 : -1;
        }
        return res;
    }
};