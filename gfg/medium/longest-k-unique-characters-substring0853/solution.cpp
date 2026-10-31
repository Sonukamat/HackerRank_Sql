
class Solution {
public:
    int longestKSubstr(string &s, int k) {

        // Store frequency of 26 lowercase characters
        int count[26] = {0};

        // Starting pointer of sliding window
        int start = 0;

        // Count distinct characters
        int distinct = 0;

        // Store maximum substring length
        int ans = -1;

        // Expand window using end pointer
        for (int end = 0; end < s.size(); end++) {

            // Find index of current character
            int index = s[end] - 'a';

            // If character appears for the first time
            if (count[index] == 0) {
                distinct++;
            }

            // Increase character frequency
            count[index]++;

            // Shrink window if distinct characters exceed k
            while (distinct > k) {

                // Find index of starting character
                int leftIndex = s[start] - 'a';

                // Decrease its frequency
                count[leftIndex]--;

                // If frequency becomes zero, remove distinct character
                if (count[leftIndex] == 0) {
                    distinct--;
                }

                // Move start pointer forward
                start++;
            }

            // Update answer only when exactly k distinct characters exist
            if (distinct == k) {
                ans = max(ans, end - start + 1);
            }
        }

        // Return -1 if no valid substring exists
        return ans;
    }
};
