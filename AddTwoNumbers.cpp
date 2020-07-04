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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return listSum(l1,l2);
    }
    

  private: 
    ListNode* listSum (ListNode* a, ListNode* b){
        //add values at the root of both lists
        int total = a->val + b->val;
        //Check if number is greater than 10. If it is not rem will be equal to 0.
        int rem = total/10;
        // make a new list with root->val as the remainder of total 
        auto root = new ListNode(total%10);
        auto last = root;
        a = a->next;
        b = b->next;
        
        while(a!= NULL || b!= NULL){
            int a1 = 0;
            int b1 = 0;
            
            if(a!=NULL){
                a1 = a->val;
                a = a->next;
            }
            
            if(b!= NULL){
                b1 = b->val;
                b = b->next;
            }
            int t = a1+b1+rem;
            rem = t/10;
            last->next = new ListNode(t%10);
            last = last->next; 
        }
        if (rem > 0) last->next = new ListNode(rem);
        return root; 
    }
};



/* example 6->4->3 + 4->5->6
654 + 346 =1000
1. 6+4 = 10
2. rem = 10/10 = 1
3. new list contaning one value which is 10%10 = 0 as root value. Last points to root as well.
//Inside of the loop
4. 4+5+rem(which is 1) = 10
5. rem = 1;
6. new list = 0->0
7. 3+6+rem(which is 1 again) = 10
8. rem = 1;
9. new list = 0->0->0
//Exists the loop
10. If rem contains any value add that value in the new list as a new node
 new list = 0->0->0->1
*/