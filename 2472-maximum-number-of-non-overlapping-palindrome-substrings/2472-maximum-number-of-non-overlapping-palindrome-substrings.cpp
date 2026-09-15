class Solution {
public:
    int dp[2001][2001];
    int n, k;
    string s;
    bool isPalindrome(int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int rec(int i, int j) {
        if (j == n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        int maxi = 0;
        if (isPalindrome(i, j) && j - i + 1 >= k) {
            ans++;
            maxi = rec(j+1,j+1);
        } else {
            maxi = max(rec(i + 1, max(j, i + 1)),rec(i, j + 1));
        }
        return dp[i][j] = ans + maxi;
    }

    int maxPalindromes(string s, int k) {
        n = s.length();
        this->k = k;
        this->s = s;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};