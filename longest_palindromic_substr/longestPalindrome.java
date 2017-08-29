class Solution {
    public String longestPalindrome(String s) 
    {
        int i,j,k, t = 0;
        int max_len = 0;
        String res = "";
        for(i = 0; i < s.length();)
        {
            j = i;
            k = j;
            if (s.length() - i <= max_len/2)
            {
                break;
            }
            while(k< s.length()-1 && s.charAt(k+1) == s.charAt(k))
            {
                ++k;
            }
            i = k+1;
            while(j > 0 && k < s.length()-1 && s.charAt(k+1) == s.charAt(j-1))
            {
                --j;
                ++k;
            }
            if (k-j+1 > max_len)
            {
                max_len = k-j+1;
                t = j;
            } 
        }
        return res = s.substring(t,t+max_len);
    }
}
