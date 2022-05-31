#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
//
//class KthLargest {
//    int k;
//    priority_queue<int> maxHeap;
//    vector<int> topKElements;
//
//public:
//    KthLargest(int k, vector<int> &nums) {
//        this->k = k;
//        maxHeap = priority_queue<int>(nums.begin(), nums.end());
//
//        for (int x = 0; x < k; x++) {
//            topKElements.push_back(maxHeap.top());
//            maxHeap.pop();
//
//
//        }
//
//        string x = "sdf";
//
//        x.
//
//
//    }
//
//    int add(int val) {
//        maxHeap.push(val);
//
//
//        if (val > topKElements[topKElements.size() - 1]) {
//
//        }
//        topKElements
//    }
//};


class Solution {
public:
    int maxProduct(vector<string> &words) {
        int maxValue = 0;

        for (int x = 0; x < words.size() - 1; x++) {
            for (int y = 1; y < words.size(); y++) {
                string bigWord;
                string smallerWord;

                if (words[x].size() > words[x].size()) {
                    bigWord = words[x];
                    smallerWord = words[y];
                } else {
                    bigWord = words[x];
                    smallerWord = words[y];
                }

                unordered_set<char> chars;
                for (int i = 0; i < smallerWord.size(); i++) chars.insert(smallerWord[i]);

                bool validCombo = true;

                for (int i = 0; i < bigWord.size(); i++) {
                    if (chars.find(bigWord[i]) != chars.end()) {
                        validCombo = false;
                        break;
                    }
                }

                if (!validCombo) continue;

                maxValue = max(maxValue, (int) bigWord.size() * (int) smallerWord.size());
            }
        }

        return maxValue;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



int main() {
    Solution sol;

    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};

//    ["abcw","baz","foo","bar","xtfn","abcdef"]
//    ["a","ab","abc","d","cd","bcd","abcd"]
//    ["a","aa","aaa","aaaa"]
//
    std::cout << sol.maxProduct(words) << std::endl;
    return 0;
}
