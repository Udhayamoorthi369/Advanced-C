/**
author : udhayamoorthi
18-09-2021


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

    struct ListNode *inverse(struct ListNode *head) {
    struct ListNode *prev = NULL, *cur = head, *next = head; 
    while (next!=NULL) {
        cur = next;
        next = cur->next;
        cur->next = prev;
        prev = cur;
        if (next==head) {
            next->next = cur;
            return next;
        }
    }
    return cur;
}
 
bool hasCycle(struct ListNode *head) {
    if (head==NULL || head->next==NULL) {
        return 0;
    }
    struct ListNode *tail = inverse(head);
    int r = (head==tail);
    inverse(tail);
    return r; 
}
