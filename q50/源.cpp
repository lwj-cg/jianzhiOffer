#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<unordered_map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        std::unordered_map<char, int> myMap;
        for (auto iter = s.begin(); iter != s.end(); ++iter)
        {
            myMap[*iter] += 1;
        }
        for (auto iter = s.begin(); iter != s.end(); ++iter)
        {
            if (myMap[*iter] == 1)
                return *iter;
        }
        return ' ';
    }
};