/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p ;
    ret.next = head; 
    p = &ret;
    while(p && p->next) {
        if(p->next->val == val) {
            p->next= p->next->next;
        }else p = p->next;
    }
    return ret.next;
}
