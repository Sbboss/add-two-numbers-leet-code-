/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //Given by leetcode
class Solution {
public:
//defining a prev pointer to store the address of previous node to insert at end
    ListNode *prev;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //declaring a resultant linked list l3 as NULL
        ListNode *l3 = NULL;
        // initializing and declaring 2 variable sum and carry
        int sum=0, carry=0;
        //loop for extracing and storing of element 
        while(l1 != NULL || l2 != NULL){
        //takes l1/l2->val else 0
            int x = ((l1 != NULL) ? l1->val : 0);
            int y = ((l2 != NULL) ? l2->val : 0);
            sum = x + y + carry;
            //if sum>10 then carry is 1
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            /* inserting at the end as seen if condition runs only once
               then else to store at end*/ 
            if(l3 == NULL){
                l3 = newNode;
            }
            else
                prev->next = newNode;
            prev = newNode;
            if(l1 != NULL){
            l1 = l1->next;
            }
            if(l2 != NULL){
            l2 = l2->next;
            }
        }
        if(carry > 0){
        // if carry if left at the end then to store it at end
            ListNode *newNode = new ListNode(carry);
            prev->next = newNode;
        }
     return l3;   
    }
        
};
