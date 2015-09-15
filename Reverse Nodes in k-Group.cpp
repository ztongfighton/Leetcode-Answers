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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr || k < 2) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;
        for (ListNode *p = prev -> next; p != nullptr;){
            for (int i = 0; i < k - 1 && p != nullptr; ++i){
                p = p -> next;
            }
            
            if (p != nullptr){
                ListNode *first = prev -> next;
                reverseList(prev, first, p);
                prev = first;
                p = prev -> next;
            }
            
        }
        return dummy.next;
    }
    
private:
    void reverseList(ListNode *head, ListNode *first, ListNode *last){
        ListNode *end = last -> next;
        ListNode *prev = head -> next;
        for (ListNode *cur = first -> next; cur != end;){
            prev -> next = cur -> next;
            cur -> next = head -> next;
            head -> next = cur;
            cur = prev -> next;
        }
    }
};
