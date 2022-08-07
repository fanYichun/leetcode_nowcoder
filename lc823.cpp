#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    unordered_set<int> s(arr.begin(), arr.end());

    unordered_map<int, int> m;

    for (int i = 0; i < arr.size(); i++) {
        int cnt = 1;

        for (int j = 0; j < i; j++) {
            int k = arr[i] / arr[j];
            if (arr[i] % arr[j] == 0 && s.find(k) != s.end()) {
                cnt += m[arr[j]] * m[k];
            }
        }

        m[arr[i]] = cnt;
    }

    int sum = 0;

    for (auto& n : m) {
        sum += n.second;
    }

    return sum;
}

int main() {
    vector<int> v = { 2, 4, 16 };
    int n = numFactoredBinaryTrees(v);

    return 0;
}