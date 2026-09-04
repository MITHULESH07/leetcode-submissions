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
    ListNode* merge(ListNode* p1,ListNode* p2){
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(p1 && p2){
            if(p1->val <= p2->val){
                tail->next = p1;
                p1 = p1->next;
            }
            else{
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        if(p1){
            tail->next = p1;
        }else{
            tail->next = p2;
        }
        return dummy->next;
    }
    ListNode* MergeSort(ListNode* head){
        if(!head || !head->next)return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* left = head;
        ListNode* right = slow->next; 
        slow->next = NULL;
        ListNode* left_node = MergeSort(left);
        ListNode* right_node = MergeSort(right);
        return merge(left_node,right_node);
    }
    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
};