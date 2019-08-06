#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return findKthLargest(nums, 0, nums.size() - 1, k - 1);
    }

    int findKthLargest(vector<int>& nums, int m, int n, int k) {
        if (m == n)
            return nums[m];
        int p = partition(nums, m, n);
        if (p == k)
            return nums[p];
        else if (p < k) {
            return findKthLargest(nums, p + 1, n, k);
        }
        else {
            return findKthLargest(nums, m, p - 1, k);
        }
    }

    int partition(vector<int>& nums, int p, int r) {
        int pivot = (rand() % (r - p + 1)) + p;
        swap(nums[pivot], nums[p]);
        int x = nums[p];
        int k = p;
        for (int i = p + 1; i <= r; i++) {
            if (nums[i] >= x) {
                swap(nums[i], nums[++k]);
            }
        }
        swap(nums[p], nums[k]);
        return k;
    }
};