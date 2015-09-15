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
    void reorderList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        while (fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        ListNode *head2 = slow -> next;
        slow -> next = nullptr;
        head2 = reverseList(head2);
        ListNode *p = head, *q = head2;
        ListNode *prev = &dummy;
        while (q != nullptr){
            ListNode *next = p -> next;
            prev -> next = p;
            p -> next = q;
            prev = q;
            q = q -> next;
            p = next;
        }
        
        if (p != nullptr) prev -> next = p;
        else prev -> next = nullptr;
    }
    
private:
    ListNode *reverseList(ListNode *head){
        ListNode dummy(-1);
        for (ListNode *prev = &dummy, *cur = head; cur != nullptr; ){
            ListNode *next = cur -> next;
            cur -> next = prev -> next;
            prev -> next = cur;
            cur = next;
        }
        return dummy.next;
    }
};
