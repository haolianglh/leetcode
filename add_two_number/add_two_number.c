/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* They are in reversed order, so the first one is 342 and second one is 465. Adding them up gives us 807 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *tmp;
    struct ListNode *res;
    struct ListNode *ret;
    int i = 0;

    tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
    res = tmp;
    res->next = NULL;
    /*如果两个链表不全为空，或者上一个位有进位*/
    while(NULL != l1 || NULL != l2 || i)
    {
        tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp = tmp->next;
        tmp->next = NULL;
        tmp->val = (l1?l1->val:0)+(l2?l2->val:0)+i;
        l1 = l1?l1->next:NULL;
        l2 = l2?l2->next:NULL;
        i = tmp->val/10;
        tmp->val %= 10;
    }
    ret = res->next;
    free(res);
    return ret;
}