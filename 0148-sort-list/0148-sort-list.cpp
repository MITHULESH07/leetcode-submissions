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
                ListNode* temp = p1->next;
                p1->next = NULL;
                p1 = temp;
            }
            else{
                tail->next = p2;
                ListNode* temp = p2->next;
                p2->next = NULL;
                p2 = temp;
                
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