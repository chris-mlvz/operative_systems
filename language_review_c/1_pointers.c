#include <stdio.h>

int main()
{
  int a = 5;
  int *pointer_a = &a;
  int *another_pointer = pointer_a;
  *pointer_a = 12;
  printf("Value of 'a': %i\n", a);
  printf("Value of 'pointer_a': %p\n", pointer_a);
  printf("Value of 'a' through 'pointer_a': %i\n", *pointer_a);
  printf("Value of the pointer 'another pointer': %p\n", another_pointer);
  return 0;
}