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
class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;

        for(auto it:lists)
        {
            if(it!=nullptr)pq.push(it);
        }
        ListNode *ans=new ListNode(-1);
        ListNode *tail=ans;
        while(!pq.empty())
        {
            ListNode *curr=pq.top();
            pq.pop();

            tail->next=curr;
            tail=curr;

            curr=curr->next;

            if(curr!=nullptr) pq.push(curr);

        }

        return ans->next;
    }
};