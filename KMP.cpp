#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextVector(string pattern)
    {
        int m = pattern.size();
        vector<int> result(m);
        for (int i = 1; i < m; i++)
        {
            int j = result[i - 1];
            while (j&&pattern[i] != pattern[j])
                j = result[j - 1];
            result[i] = pattern[i] == pattern[j] ? j + 1 : 0;
        }
        return result;
    }
    vector<int> KMP(string str, string pattern)
    {
        int n = str.size(), m = pattern.size();
        vector<int> arr = nextVector(pattern);
        vector<int> result;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            while (p>0 && pattern[p] != str[i])
                p = arr[p - 1];
            if (str[i] == pattern[p])
                p++;
            if (p == m)
                result.push_back(i - p + 1);
        }
        return result;
    }
};

int main(int argc, _TCHAR* argv[])
{
    Solution s;
    string str = "BBC ABCDAB ABCDABCDABDE";
    string patter = "ABCDABD";
    vector<int> v = s.KMP(str, patter);
    for (auto i : v)
        cout << i << endl;

    getchar();
    return 0;
}
