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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!(head) || !(head->next) || !(head->next->next))return {-1,-1};
        ListNode * prev = head;
        ListNode * curr = prev->next;
        ListNode * nxt = curr->next;
        int fcp = -1, lcp = -1;
        int precp = -1;
        int minD = INT_MAX;
        int i = 2; 
        while(nxt){
            if((prev->val>curr->val && nxt->val>curr->val) || (prev->val<curr->val && nxt->val<curr->val)){
                if(precp!=-1){
                    minD = min(minD,i-precp);
                }
                else{
                    fcp = i;
                }
                precp = i;

            }
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            i++;
        }
        if(precp ==-1 || precp == fcp)return {-1,-1};
        int maxD = precp - fcp;
        return {minD,maxD};
    }
};