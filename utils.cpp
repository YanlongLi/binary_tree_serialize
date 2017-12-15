/* =============================================================================
#     FileName: utils.cpp
#         Desc:
#       Author: YanlongLi
#        Email: lansunlong@gmail.com
#     HomePage:
#      Created: 2017-12-15 09:24:02
#      Version: 0.0.1
#   LastChange: 2017-12-15 09:24:02
#      History:
#               0.0.1 | YanlongLi | init
============================================================================= */
#include "headers.h"

using namespace std;

vector<string> str_split(const string& s, char c) {
    vector<string> vec;
    int i = 0, j = -1;
    while (++j < s.length()) {
        if (s[j] == c) {
            if (j != i) {
                vec.push_back(s.substr(i, j - i));
            }
            i = j + 1;
        }
    }
    if (j != i) {
        vec.push_back(s.substr(i, j - i));
    }
    return vec;
}

string str_join(const vector<string>& vec, char c) {
    string ret = "";
    for (int i = 0; i < vec.size(); i++) {
        ret += (i == 0 ? vec[i] : c + vec[i]);
    }
    return ret;
}
