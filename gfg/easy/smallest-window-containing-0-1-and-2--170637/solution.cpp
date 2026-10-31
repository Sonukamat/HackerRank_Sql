
class Solution {
public:
    int smallestSubstring(string &s) {

        // Frequency of characters 0, 1 and 2
        int count[3] = {0};

        int start = 0;
        int ans = INT_MAX;

        // Expand the sliding window
        for (int end = 0; end < s.size(); end++) {

            // Include current character
            count[s[end] - '0']++;

            // Shrink window while all three characters exist
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {

                // Update minimum window length
                ans = min(ans, end - start + 1);

                // Remove the starting character
                count[s[start] - '0']--;

                // Move start forward
                start++;
            }
        }

        // Return -1 if no valid substring exists
        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};
