class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int max_seq = 0;
        for(auto x : nums)
            s.insert(x);

        for(int x : nums)
        { 
            if(s.count(x-1))
            {
                continue;
            }
            int seq_size = 1;
            for(int i=x+1; ; i++ )
            {
                if(s.count(i))
                {
                    seq_size++;
                }
                else
                {
                    break;
                }
            }

            max_seq = max(max_seq, seq_size);
        }

        return max_seq;
    }
};
