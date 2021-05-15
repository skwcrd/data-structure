/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* current = NULL;
    int carry = 0;

    current = result;

    carry += l1->val + l2->val;

    current->val = carry % 10;
    current->next = NULL;

    carry = floor(carry / 10);

    l1 = l1->next;
    l2 = l2->next;

    while( (l1 != NULL) || (l2 != NULL) ) {
        struct ListNode* tmp = (struct ListNode*) malloc(sizeof(struct ListNode));

        if ( l1 != NULL && l2 != NULL ) {
            carry += l1->val + l2->val;

            tmp->val = carry % 10;
            tmp->next = NULL;
            current->next = tmp;

            l1 = l1->next;
            l2 = l2->next;
            current = current->next;

            carry = floor(carry / 10);
        } else {
            if ( l1 != NULL ) {
                carry += l1->val;

                tmp->val = carry % 10;
                tmp->next = NULL;
                current->next = tmp;

                carry = floor(carry / 10);

                l1 = l1->next;
                current = current->next;
            } else if ( l2 != NULL ) {
                carry += l2->val;

                tmp->val = carry % 10;
                tmp->next = NULL;
                current->next = tmp;

                carry = floor(carry / 10);

                l2 = l2->next;
                current = current->next;
            }
        }
    }

    if ( carry > 0 ) {
        struct ListNode* tmp = (struct ListNode*) malloc(sizeof(struct ListNode));
        tmp->val = carry % 10;
        tmp->next = NULL;
        current->next = tmp;
    }

    return result;
}