// 2019-10-12
// LeetCode: 1
#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* blankHead = new ListNode(0);
        ListNode* r = blankHead;
        int carry = 0;
        while(p != NULL || q != NULL) {
            int v1 = p != NULL ? p->val : 0;
            int v2 = q != NULL ? q->val : 0;
            int sum = v1 + v2;
            int result = (sum + carry) % 10;
            carry = (sum + carry ) / 10;
            r->next = new ListNode(result);
            if (p) {
                p = p->next;
            }
            if (q) {
                q = q->next;
            }
            r = r->next;
        }

        if (carry) {
            r->next = new ListNode(carry);
        }

        return blankHead->next;
    }
public:
    void testCase()
    {
        int a[] = {1,8,9};
        ListNode* l1 = makeList(a, 3);
        printList(l1);
        int b[] = {2,3,5};
        ListNode* l2 = makeList(b, 3);
        printList(l2);
        ListNode* l3 = addTwoNumbers(l1,l2);
        printList(l3);

        int c[] = {2, 3};
        ListNode* l4  = makeList(c, 2);
        printList(l4);
        l3 = addTwoNumbers(l1, l4);
        printList(l3);

        l4 = new ListNode(0);
        l2 = new ListNode(0);
        l3 = addTwoNumbers(l4, l2);
        printList(l3);

        int d[] = {9,9,9,9,9};
        ListNode* l5 = makeList(d,5);
        l2 = new ListNode(1);
        l3 = addTwoNumbers(l5,l2);
        printList(l3);
    }

private:
    ListNode* makeList(int a[], int len)
    {
        ListNode* head = new ListNode(a[0]);
        if(len == 1)
        {
            return head;
        }

        ListNode* p = head;
        for(int i = 1; i < len; i++) {
            ListNode* node = new ListNode(a[i]);
            p->next = node;
            p = node;
        }
        return head;
    }

    void printList(ListNode* head)
    {
        ListNode* p = head;
        while(p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};