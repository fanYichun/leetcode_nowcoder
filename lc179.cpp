#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> nums_s;

    for (int i : nums) {
        nums_s.push_back(to_string(i));
    }

    sort(nums_s.begin(), nums_s.end(), [](string& a, string& b) -> bool {
        int a_size = a.size();
        int b_size = b.size();
        int max_size = max(a_size, b_size);
        int min_size = min(a_size, b_size);
        int i = 0;

        for (; i < min_size; i++) {
            if (b[i] > a[i]) return false;
            else if (a[i] > b[i]) return true;
        }
        if (i == max_size) return false;

        return a + b > b + a;
    });

    if (nums_s.empty() || nums_s[0] == "0") return "0";

    string res;
    for (string& n : nums_s) {
        res += n;
    }
    return res;
}

int main() {
	vector<int> v = { 432, 43243 };
    string s = largestNumber(v);

    return 0;
}