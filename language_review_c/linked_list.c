#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *next;
};

int main()
{
  struct Node *head = malloc(sizeof(struct Node));
  head->value = 1;
  head->next = malloc(sizeof(struct Node));
  head->next->value = 2;
  head->next->next = malloc(sizeof(struct Node));
  head->next->next->value = 3;

  printf("Address of the first node %p\n", head);
  printf("Value of the first node %i\n", head->value);

  printf("Address of the second node %p\n", head->next);
  printf("Value of the second node %i\n", head->next->value);

  printf("Address of the tercer node %p\n", head->next->next);
  printf("Value of the tercer node %i\n", head->next->next->value);

  return 0;
}