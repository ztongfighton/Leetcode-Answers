/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (RandomListNode *cur = head; cur != nullptr;){
            RandomListNode *node = new RandomListNode(cur -> label);
            node -> next = cur -> next;
            cur -> next = node;
            cur = node -> next;
        }
        
        for (RandomListNode *cur = head; cur != nullptr; cur = cur -> next -> next){
            if (cur -> random != nullptr)
                cur -> next -> random = cur -> random -> next;
        }
        
        //notice the following part. Need to consider special case like the original list is empty
        RandomListNode dummy(-1); 
        for (RandomListNode *cur1 = head, *cur2 = &dummy; cur1 != nullptr;){  
            cur2 -> next = cur1 -> next;
            cur2 = cur2 -> next;
            cur1 -> next = cur1 -> next -> next;
            cur1 = cur1 -> next;
        }
        
        return dummy.next;
    }
};
