
class Solution {
public:
    int findSubString(string& s) {

        vector<int> count(256, 0);
        int first = 0, second = 0;
        int len = s.size(), diff = 0;

        // Calculate total unique characters
        while(first < s.size())
        {
            if(count[s[first]] == 0)
                diff++;

            count[s[first]]++;
            first++;
        }

        // Reset frequency array
        for(int i = 0; i < 256; i++)
            count[i] = 0;

        first = 0;

        // Sliding window
        while(second < s.size())
        {
            // Expand window until all unique characters are present
            while(diff && second < s.size())
            {
                if(count[s[second]] == 0)
                    diff--;

                count[s[second]]++;
                second++;
            }

            // Update minimum length
            if(diff == 0)
                len = min(len, second - first);

            // Shrink window
            while(diff == 0)
            {
                len = min(len, second - first);

                count[s[first]]--;

                if(count[s[first]] == 0)
                    diff++;

                first++;
            }
        }

        return len;
    }
};
