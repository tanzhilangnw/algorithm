﻿//峰值元素是指其值严格大于左右相邻值的元素。

//给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

//你可以假设 nums[-1] = nums[n] = -∞ 。

//你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
//提示：
//
//1 <= nums.length <= 1000
//- 231 <= nums[i] <= 231 - 1
//对于所有有效的 i 都有 nums[i] != nums[i + 1]


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        auto  get = [&](int i)->pair<int, int> {
            if (i == -1 || i == n)
                return { 0,0 };
            else
                return{ 1,nums[i] };
        };

        int left = 0, right = n, idx = -1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (get(mid) > get(mid + 1) && get(mid) > get(mid - 1)) {
                idx = mid;
                return idx;
            }
            if (get(mid) < get(mid + 1))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return idx;
    }
};