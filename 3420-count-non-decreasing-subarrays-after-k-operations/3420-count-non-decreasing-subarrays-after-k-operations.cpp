
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long diff = 0;

        deque<pair<int, int>> dq;

        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            int count = 1;

            while (!dq.empty() && dq.back().first < nums[l]) {
                auto [val, cnt] = dq.back();
                dq.pop_back();

                count += cnt;
                diff += 1LL * (nums[l] - val) * cnt;
            }

            dq.push_back({nums[l], count});

            while (diff > k) {
                auto [val, cnt] = dq.front();
                dq.pop_front();

                diff -= 1LL * (val - nums[r]);
                r--;

                if (cnt > 1) {
                    dq.push_front({val, cnt - 1});
                }
            }

            ans += r - l + 1;
        }

        return ans;
    }
};
