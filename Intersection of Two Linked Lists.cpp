/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *p = headA, *q = headB;
        int len1 = 1;
        int len2 = 1;
        while (p -> next){
            p = p -> next;
            ++len1;
        }
        while (q -> next){
            q = q -> next;
            ++len2;
        }
        
        if (p != q) return nullptr;
        p = headA;
        q = headB;
        if (len1 > len2){
            for (int i = 0; i < len1 - len2; ++i)
                p = p -> next;
        }
        else{
            for (int i = 0; i < len2 - len1; ++i)
                q = q -> next;
        }
        
        while (p){
            if (p == q)
                return p;
            p = p -> next;
            q = q -> next;
        }
    }
};
