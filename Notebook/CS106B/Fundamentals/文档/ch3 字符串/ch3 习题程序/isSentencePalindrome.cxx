#include <cctype>
#include <string>
#include <iostream>
using namespace std;

bool isPalindrome(const string &rhs) {
    // 简洁实现：
    // return rhs == rhs.reserve();
    size_t len = rhs.length();
    if (len < 2) {
        return true;
    } else {
        char start = rhs[0];
        char finish = rhs[len - 1];
        return  start == finish && 
                isPalindrome(rhs.substr(1, len - 2));
    }
}

string normalizeSentence(const string &rhs) {
    //牢记这种对单个字符处理，并且生成新字符串的方式。
    string result;
    for (auto ch : rhs) {
        if (isalpha(ch)) {
            result += tolower(ch);
        }
    }
    return result;
}

// 实现思路:
// 将普通的句子进行normailize: "Madam, I'm Adam" ==> "madamimadam"
// 之后将规格化的句子进行回文判断。
bool isSentencePalindrome(const string &rhs) {
    return isPalindrome(normalizeSentence(rhs));
}

int main() {
    cout << "This program tests for sentence palindrome." << endl
         << "Indicate the end of the input with a blank line."<< endl;

    while (true) {
        cout << "Enter a sentence :" << endl;
        string line;
        getline(cin, line); // 使用getline读取一整行
        if (line.empty()) break;

        if (isSentencePalindrome(line)) {
            cout << "That sentence is a palindrome." << endl;
        } else {
            cout << "That sentence is not a palindrome." << endl;
        }
    }
    return 0;
}