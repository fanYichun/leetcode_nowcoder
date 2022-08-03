#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string replaceWords(vector<string>& dictionary, string sentence) {
    vector<string> str_split;
    int last_index = 0;

    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ' ') {
            str_split.push_back(sentence.substr(last_index, i - last_index));
            last_index = i + 1;
        }
    }
    str_split.push_back(sentence.substr(last_index, sentence.size() - last_index));

    unordered_set<string> dict(dictionary.begin(), dictionary.end());

    vector<string> rep_str;

    for (auto& s : str_split) {
        int i = 1;
        int flag = false;

        for (; i <= s.size(); i++) {
            string temp = s.substr(0, i);
            if (dict.find(temp) != dict.end()) {
                rep_str.push_back(temp);
                flag = true;
                break;
            }
        }

        if (!flag) rep_str.push_back(s);
    }

    string res = "";
    for (auto& i : rep_str) {
        if (res.empty()) res += i;
        else res += " " + i;
    }

    return res;
}

int main() {
	vector<string> v = { "cat", "bat", "rat" };
    string res = replaceWords(v, "the cattle was rattled by the battery");

    return 0;
}