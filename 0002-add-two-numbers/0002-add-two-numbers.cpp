class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *d1 = dummy;

        int carry = 0;

        ListNode *t1 = l1, *t2 = l2;

        while(t1 != nullptr || t2 != nullptr)
        {
            int sum = carry;

            if(t1 != nullptr)
            {
                sum += t1->val;
                t1 = t1->next;
            }

            if(t2 != nullptr)
            {
                sum += t2->val;
                t2 = t2->next;
            }

            carry = sum / 10;

            d1->next = new ListNode(sum % 10);
            d1 = d1->next;
        }

        if(carry)
        {
            d1->next = new ListNode(carry);
        }

        return dummy->next;
    }
};