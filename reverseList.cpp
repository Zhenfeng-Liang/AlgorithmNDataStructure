// reverse a linked list.
// A simple and tail recursive C++ program to reverse
// a linked list

using namespace std;
 
struct node
{
    int data;
    struct node *next;
};
 
void reverseUtil(node *curr, node *prev, node **head);

// This function mainly calls reverseUtil()
// with prev as NULL
void reverse(node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}
 
// A simple and tail recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(node *curr, node *prev, node **head)
{
    /* If last node mark it head*/
    if (!curr->next)
    {
        *head = curr;
 
        /* Update next to prev node */
        curr->next = prev;
        return;
    }
 
    /* Save curr->next node for recursive call */
    node *next = curr->next;
 
    /* and update next ..*/
    curr->next = prev;
 
    reverseUtil(next, curr, head);
}
