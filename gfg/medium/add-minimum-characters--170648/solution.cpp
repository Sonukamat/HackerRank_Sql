class Solution {
  public:
    int addMinChar(string str) {

        // Step 1: Store original length
        int size = str.length();

        // Step 2: Reverse the string
        string rev = str;
        reverse(rev.begin(), rev.end());

        // Step 3: Combine original + separator + reverse
        string s = str + "$" + rev;

        // Step 4: Create LPS array
        int n = s.length();
        vector<int> lps(n, 0);

        int pre = 0;
        int suf = 1;

        // Step 5: Build LPS array using KMP
        while (suf < n) {

            // Characters match
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }

            // Characters do not match
            else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                }
                else {
                    pre = lps[pre - 1];
                }
            }
        }

        // Step 6: Calculate minimum characters to add
        return size - lps[n - 1];
    }
};