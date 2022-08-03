#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> freq;

    for (auto& item : nums) {
        freq[item]++;
    }

    vector<pair<int, int>> v(freq.begin(), freq.end());

    sort(v.begin(), v.end(), [=](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
        });

    vector<int> res;

    for (int i = 0; i < k; i++) {
        auto it = v.rbegin();
        res.push_back(it->first);
        v.pop_back();
    }

    return res;
}

int main() {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    vector <int> res = topKFrequent(nums, 2);

    return 0;
}