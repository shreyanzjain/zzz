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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = head;
        for(int i = 0; i < n; i++){
            right = right->next;
        }
        if(right == NULL){
            head = head->next;
            return head;
        }
        while(right->next != NULL){
            right = right->next;
            left = left->next;
        }
        ListNode* temp = left->next;
        if(left->next != NULL){
        left->next = left->next->next;
        } 
        delete(temp);
        return head;
    }
};