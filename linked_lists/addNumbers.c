
// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode *ans = dummy;

    int carry = 0, sum = 0;
    while(l1 != NULL || l2 != NULL || carry != 0){
        int x = l1!=NULL?l1->val:0;
        int y = l2!=NULL?l2->val:0;

        sum = carry + x + y;
        carry = sum / 10;
        sum = sum % 10;
        ans->next = new ListNode(sum);

        if(l1 != NULL)  l1 = l1->next;
        if(l2 != NULL)  l2 = l2->next;
        ans = ans->next;
    }
    return dummy->next;
}
