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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr || k == 0) return head;
        ListNode *p = head;
        int len = 1;
        while (p -> next != nullptr){
            ++len;
            p = p -> next;
        }
        k = len - k % len;
        p -> next = head;
        for (int i = 0; i < k; ++i){
            p = p -> next;
        }
        
        ListNode *head2 = p -> next;
        p -> next = nullptr;
        return head2;
    }
};
