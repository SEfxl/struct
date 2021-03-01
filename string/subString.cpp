#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 给出一个串s,一个字符串t,在s中找出包含T所有字母的最小子串
 * @param s
 * @param t
 * @return
 */
string minWindow(string s, string t) {

    unordered_map<char, int> need, window;
    for (char c : t) {
        need[c]++;
    }

    int left = 0, right = 0, valid = 0;

    int start, len = INT_MAX; //保留子串的起始位置和长度

    while (right < s.size()) {

        char c = s[right]; //将要移入窗口的字符
        right++; //右移窗口

        if (need.count(c)) {
            window[c]++; //窗口数据更新
            if (window[c] == need[c]) {
                valid++;
            }

        }

        //如果找到一个子集,判断窗口是否要收缩
        while (valid == need.size()) {
            if (right - left < len) {
                len = right - left;
                start = left;
            }

            char d = s[left]; //将要移出窗口的字符
            left++; //左移窗口

            if (need.count(d)) { //窗口数据更新
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
    }

    return len == INT_MAX ? "" : s.substr(start, len);

}

/**
 * 给定两个字符s和t,写一个函数来判断t的排列是s的一个子串
 * @param s
 * @param t
 * @return
 */
bool isContainSubString(string s, string t) {

    unordered_map<char, int> need, window;
    for (char c:t) {
        need[c]++;
    }

    int left = 0, right = 0, valid = 0;

    while (right < s.size()) {
        char c = s[right]; //需要移动到窗口的元素
        right++; //窗口右移
        //printf("c = %c\n",c);

        if (need.count(c)) { //窗口数据更新
            window[c]++;
            if (need[c] == window[c]) {
                valid++;
            }
        }

        while (valid == need.size()) {
            printf("c = %c, size=%d right=%d, left=%d\n", c, valid, right, left);

            if (right - left == need.size()) {
                return true; //找到直接返回
            } else if (right - left > need.size()) {

                char d = s[left]; //需要滑出窗口的元素
                left++; //窗口左移
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }

            }
        }

    }

    return false; //未找到

}

/**
 * 给定一个字符串s和t,找到s中所有是t的字母异位词的子串,返回这些子串的起始索引
 * @param s
 * @param t
 * @return
 */
vector<int> getSubStringStartIndex(string s, string t) {

    unordered_map<char, int> need, window;
    for (char c:t) {
        need[c]++;
    }

    int left = 0, right = 0, valid = 0;
    vector<int> res; //存储返回的结果

    while (right < s.size()) {

        char c = s[right]; //找到需要进入窗口的元素
        right++; //窗口右移

        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) {
                valid++;
            }
        }

        while (right - left >= t.size()) {

            if (valid == need.size()) {
                res.push_back(left);
            }

            char d = s[left]; //需要移除的窗口数据
            left++; //窗口左侧收缩
            if (need.count(d)) {
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }

        }
    }

    return res;

}


/**
 * 最长无重复子串的长度
 * @param s
 * @return
 */
int lengthOfLongestSubString(string s) {

    unordered_map<char, int> window;
    int left = 0, right = 0;
    int subLength = 0;

    while (right < s.size()) {
        char c = s[right];
        right++; //窗口右移

        //窗口数据更新
        window[c]++;

        while (window[c] > 1) {

            char d = s[left];
            left++; //窗口紧缩右移

            //窗口数据更新
            window[d]--;
        }

        if(subLength < right-left) {
            subLength = right-left;
        }

    }

    return subLength;

}

int main() {

    string s = "EBBANCF";
    string t = "ABC";
    string res = minWindow(s, t);
    cout << "结果为：" << res << endl << endl;


    string s1 = "DDABCF";
    string t1 = "ABC";
    bool res1 = isContainSubString(s1, t1);
    cout << "结果为：" << res1 << endl << endl;

    string s2 = "cbaebabacd";
    string t2 = "abc";
    vector<int> res2 = getSubStringStartIndex(s2, t2);
    printf("res2 size is %d\n", res2.size());
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << " ";
    }
    cout << endl << endl;



    string s3 = "abcabcdd";
    //string s3 = "ddddd";
    //string s3 = "pwwkew";
    int res3 = lengthOfLongestSubString(s3);
    cout << "结果为：" << res3 << endl << endl;


    return 0;

}