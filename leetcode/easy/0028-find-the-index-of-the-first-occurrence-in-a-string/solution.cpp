
class Solution {
public:

    void lpsfind(vector<int>& lps, string s) {

        int pre = 0, suf = 1;

        while(suf < s.size())
        {
            // Match
            if(s[pre] == s[suf])
            {
                lps[suf] = pre + 1;
                suf++;
                pre++;
            }
            // Not Match
            else
            {
                if(pre == 0)
                {
                    lps[suf] = 0;
                    suf++;
                }
                else
                {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {

        if(needle.empty())
            return 0;

        vector<int> lps(needle.size(), 0);

        lpsfind(lps, needle);

        int first = 0, second = 0;

        while(first < haystack.size() &&
              second < needle.size())
        {
            // Match
            if(haystack[first] == needle[second])
            {
                first++;
                second++;
            }
            // Not Match
            else
            {
                if(second == 0)
                    first++;
                else
                    second = lps[second - 1];
            }
        }

        // Answer exists
        if(second == needle.size())
            return first - second;

        return -1;
    }
};
