/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *q = head, *p = head;
    if(p == NULL) return false;
    do{ p = p->next;
        q = q->next;
        
        if(q == NULL || q->next ==NULL) return false;
        q = q->next; 
    }while(p != q);
    return true;
}
