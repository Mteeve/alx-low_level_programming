#include "lists.h"

/**
*sum_listint - calculates sumation of the data in listint_t lists.
*@head: first node in the linked lists.
*
*Return: resulting sum.
*
*/

int sum_listint(listint_t *head)

{
int sum = 0;
listint_t *temp = head;

while (temp)

{
sum += temp->n;
temp = temp->next;
}

return (sum);
}
