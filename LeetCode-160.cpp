/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    while(p != q) {
        p = (p ? p->next : headB);
        q = (q ? q->next : headA);
    }
    return p;
}*/

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    int cnta = 0, cntb = 0;
    while(p) p = p->next, cnta++;
    while(q) q = q->next, cntb++;
    int m = cnta - cntb;
    p = headA, q=headB;
    if(m < 0) {
        m = - m;
        swap(p, q);
    }
    while(m--) p = p->next;
    while(q != p) {
        p = p->next;
        q = q->next;
    }
        return p;

}
