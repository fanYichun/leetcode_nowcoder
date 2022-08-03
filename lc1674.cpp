#include <unordered_map>
#include <vector>

using namespace std;

int minMoves(vector<int>& nums, int limit) {
    unordered_map<int, int> freq_m;

    int nums_size = nums.size();

    for (int i = 0; i < nums_size / 2; i++) {
        int temp_sum = nums[i] + nums[nums_size - 1 - i];

        if (temp_sum <= 2 * limit)
            freq_m[temp_sum]++;
    }

    int max_freq_sum = 0;
    int max_freq_num = 0;

    for (auto& i : freq_m) {
        if (i.second > max_freq_num || i.second == max_freq_num && i.first < max_freq_sum) {
            max_freq_num = i.second;
            max_freq_sum = i.first;
        }
    }

    int cnt = 0;
    for (int i = 0; i < nums_size / 2; i++) {
        int temp_sum = nums[i] + nums[nums_size - 1 - i];
        if (temp_sum != max_freq_sum) {
            if (nums[i] >= limit && nums[nums_size - 1 - i] >= limit) cnt += 2;
            else cnt += 1;
        }
    }
    return cnt;
}

int main() {
    vector<int> nums = { 1, 2, 2, 1 };
    int res = minMoves(nums, 2);

    return 0;
}