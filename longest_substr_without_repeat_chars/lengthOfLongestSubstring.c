/*所有的符合要求的字串，其首字节一定是夹在两个重复字符中间的第一个位置，因此工作是对比这些字串，选出长度最大者 */
int lengthOfLongestSubstring(char* s) 
{
    int len = 0;
    /* c_addr[]记录所有128种字符在s中最大的位置*/
    char *c_addr[128] = {0};
    /*用end来遍历s*/
    char *end;
    char *tmp;
    /* end = s从s的头部开始循环 */
    end = s;

    while(*end)
    {
        /*记录该字符串上次出现的位置到tmp中*/
        tmp = c_addr[*end];
        /* c_addr则继续记录本次出现的位置 */
        c_addr[*end] = end;
        /* 如果出现tmp！= NULL,则说明出现了重复字符，如果重复字符的前字符位置是包含在当前字串内，则进入if语句 */
        if (tmp >= s)
        {
            /*if语句的作用是
             * 1.计算一下当前字串的长度，看下和记录在案的上一个符合要求的字串进行比较，记录长度更大的
             * 2. 更新下一个待处理字串的起始位置到s,该位置是重复字符的前一个的位置加1
             */
            len = end-s>len? end-s : len;
            s = tmp+1;
        }
        ++end;
    }
    len = end-s>len?end-s:len;
    return len;
}