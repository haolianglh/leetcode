char* longestPalindrome(char* s) 
{
    int max_len = 0;
    int tmp_len = 0;
    int str_len = strlen(s);
    int i,j,k;
    char * left;
    /* 对s的每一个字符采取中心扩展法进行判断，但是for循环中无需++i，完全依靠line17的i=k+1来变化 */
    for (i = 0; i < str_len;)
    {
        j = i;
        k = j;
        if (str_len - i <= max_len/2)
        {
            break;
        }
        /*跳过重复的字符，即可以跳过连续重复的字符，也同时统一了奇偶两种长度的回文子串的处理方式*/
        while(k < str_len - 1 && s[k+1] == s[k])
        {
            ++k;
        }
        i = k+1;
        /*中心扩展，j向前，k向后，逐一判断是否回文*/
        while(j>0 && k < str_len -1 && s[k+1] == s[j-1])
        {
            --j;
            ++k;
        }
        /* 本次for循环中算出的可能的回文子串的长度记录在tmp_len中 */
        tmp_len = k-j+1;
        if (max_len < tmp_len)
        {
            left = &s[j];
            max_len = tmp_len;
        }
    }
    left[max_len] = 0;
    return left;
}
