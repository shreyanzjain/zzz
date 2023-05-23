/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* first = head -> next;
        ListNode* newNode = new ListNode(0);
        ListNode* newNodeHead = newNode;
        int flag = 0;

        while(first -> next != NULL)   {
            newNode -> val += first -> val;
            if(first -> val == 0)   {
                newNode -> next = new ListNode(0);
                newNode = newNode -> next;
            }
            first = first -> next;
        }

        return newNodeHead;
    }
};