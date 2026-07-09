class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0;

       while(l1 || l2 || carry)
       {
            int sum=carry;

            if(l1!=nullptr)
            {
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2!=nullptr)
            {
                sum+=l2->val;
                l2=l2->next;
            }

            temp->next=new ListNode(sum%10);
            temp=temp->next;
            carry=sum/10;
       }

       return dummy->next;
    }
};