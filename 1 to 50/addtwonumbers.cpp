/*we have to add two linked lists. we add two linked list by adding the corresponding nodes of the two linked lists. If the sum of two nodes is greater than 9, we carry over the value to the next node. We continue this process until we reach the end of both linked lists. If one linked list is longer than the other, we continue adding the remaining nodes of the longer list to the result. Finally, if there is a carry left after processing both linked lists, we create a new node for that carry and add it to the result linked list.

other approach is to convert the linked lists to integers, add them, and then convert the sum back to a linked list. However, this approach may not work for very large numbers that exceed the maximum value of an integer.

best approach is to use a recursive function that adds the corresponding nodes of the two linked lists and returns the sum as a new linked list. This approach avoids the need for converting the linked lists to integers and can handle very large numbers.

approach 3 is to use a stack to store the nodes of the two linked lists and then pop the nodes from the stacks to add them. This approach also avoids the need for converting the linked lists to integers and can handle very large numbers.

approach 4 is to use a dummy node to simplify the addition process. We create a dummy node and a current pointer that points to the dummy node. We then iterate through the two linked lists, adding the corresponding nodes and creating new nodes for the sum. Finally, we return the next node of the dummy node as the result linked list.


*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    listNode* addTwoNumbers(listNode* l1,listNode* l2){
        listNode* dummy = new listNode(0);//creating a dummy node with value 0
        listNode* curr = dummy; //creating a current pointer that points to the dummy node kyunki hum dummy node ke next ko return karenge
        int carry =0;
        while(l1!=NULL || l2!=NULL || carry!=0){//tab tak loop chalayenge jab tak l1 ya l2 NULL nahi ho jata ya carry 0 nahi ho jata
            int sum =carry;
            if(l1!=NULL){
                sum=sum+l1->val;
                l1=l1->next;

            }
            if(l2!=NULL){
                sum=sum+l2->val;
                l2=l2->next;
                
            }
            curr->next = new listNode(sum%10); //soch ye kyu kiya hoga? kyunki hum sum ka last digit ko hi current node mai store karennge
            curr = curr->next;
            carry = sum/10;

            
        }
        return dummy->next;
    }
}