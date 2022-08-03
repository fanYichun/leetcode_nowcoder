#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int numSplits(string s) {

    int good_cnt = 0;

    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;

    freq1[s[0]]++;

    int sub1_n = 1;

    for (auto c : s) freq2[c]++;
    freq2[s[0]]--;

    int sub2_n = 0;
    for (auto f : freq2) if (f.second != 0) sub2_n++;

    if (sub1_n == sub2_n)
        good_cnt++;

    for (int i = 1; i < s.size(); i++) {
        char c = s[i];

        freq1[c]++;
        freq2[c]--;

        if (freq1[c] == 1) sub1_n++;
        if (freq2[c] == 0) sub2_n--;

        if (sub1_n == sub2_n)
            good_cnt++;
    }

    return good_cnt;
}

int main() {
    string s = "acbadbaada";
    int res = numSplits(s);

    return 0;
}