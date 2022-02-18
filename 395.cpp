class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        
        int ans=0,l,r,unique,hash[26],kOrMore;
        
        for (int u=1; u<=26; u++) {   //loop for number of unique characters. Let's call this expectation
            memset(hash, 0, sizeof(hash));
            l=0, r=0, unique = 0, kOrMore = 0;
            while (r<n) {   //loop across whole string
                if (unique <= u) {   //if number of unique characters is less than current expectation
                    hash[s[r]-'a']++;   //increase hash count for character
                    unique += (hash[s[r]-'a'] == 1);   //if count for that character becomes 1, means we got one more unique character
                    kOrMore += (hash[s[r]-'a'] == k);  //if count for that character becomes k, means we got one more character satisfying >= k condition
                    r++; //increment the right pointer
                }
                else {    //if we have exceeded expectation, we move left pointer
                    hash[s[l]-'a']--;   //decrement count
                    unique -= (hash[s[l]-'a'] == 0);  // if count becomes 0, means we lost one unique character
                    kOrMore -= (hash[s[l]-'a'] == k-1);  // if count becomes k-1, means we lost one character that earlier satisfied >= k condition
                    l++; //increment the left pointer
                }
                
                if (unique==u && kOrMore==u)  //if we have exactly expected no. of characters and also they satisfy >= k condition, we found one possible answer
                    ans = max(ans, r-l);
            }            
        }
        
        return ans;
    }
};