#include <iostream>
#include <vector>

using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    int nums_size = nums.size();

    int max_score = 0;
    int end_sub_score = 0;
    int low_index = 0;

    int* freq = new int[100001];
    memset(freq, 0, 100001 * sizeof(int));

    for (int i = 0; i < nums_size; i++) {
        int temp_cnt = nums[i];
        end_sub_score += temp_cnt;
        freq[temp_cnt]++;

        if (freq[temp_cnt] == 2) {
            while (low_index < nums_size) {
                if (nums[low_index] == temp_cnt) {
                    end_sub_score -= temp_cnt;
                    freq[temp_cnt]--;
                    low_index++;
                    break;
                }
                end_sub_score -= nums[low_index];
                freq[nums[low_index]]--;
                low_index++;
            }
        }
        if (end_sub_score > max_score) max_score = end_sub_score;
    }

    int res = max_score;
    delete[] freq;
    return res;
}

int main() {
    vector<int> v;
    for (int i = 0; i <= 100000; i++) {
        v.push_back(i);
    }
    int res = maximumUniqueSubarray(v);

    return 0;
}