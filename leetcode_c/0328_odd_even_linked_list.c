/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *oddListHead=NULL, *oddListTail=NULL;
    struct ListNode *evenListHead=NULL, *evenListTail=NULL;
    struct ListNode *nextP;
    int i=0;

    if (!head)      return NULL;

    while (head) {
        nextP = head->next;
        head->next = NULL;

        if (i%2==0) {
            if (evenListHead) {
                evenListTail->next = head;
                evenListTail = evenListTail->next;
            } else {
                evenListHead = head;
                evenListTail = head;
            }
        } else {
            if (oddListHead) {
                oddListTail->next = head;
                oddListTail = oddListTail->next;
            } else {
                oddListHead = head;
                oddListTail = head;
            }
        }

        head = nextP;
        i++;
    }
    evenListTail->next = oddListHead;
    return evenListHead;
}