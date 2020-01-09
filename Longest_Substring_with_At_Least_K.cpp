class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n == 0) return 0;
        int arr[26] = {0};
        for (char ch : s) arr[ch-'a']++;
        int mid = 0;
        while (mid < n) if (arr[s[mid]-'a'] < k) break; else mid++;
        if (mid == n) return n;
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < n) if (arr[s[mid]-'a'] < k) mid++; else break;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
}
