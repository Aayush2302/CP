#include<bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteNode(ListNode* head){
    ListNode* temp = head;

        if(head->next == NULL){
            return NULL;
        }
         ListNode* slow = head;
         ListNode* fast = head->next;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

      deleteNode(head);  

      while(head != NULL){
          cout<<head->val<<" ";
          head = head->next;
      }

    return 0;
}