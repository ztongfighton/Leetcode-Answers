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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        for(int i = 1; i < m; ++i){
            prev = prev -> next;
        }
        
        reverseLinkedList(prev, m, n);
        return dummy.next;
    }
    
private:
    void reverseLinkedList(ListNode *head, int m, int n){
        auto prev = head -> next;
        for (int i = m; i < n; ++i){
            auto cur = prev -> next;
            prev -> next = cur -> next;
            cur -> next = head -> next;
            head -> next = cur;
        }
    }
};
