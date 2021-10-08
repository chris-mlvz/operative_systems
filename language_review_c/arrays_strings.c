#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // char c[][8] = {"Hola", "Mensaje"};
  // printf("%s\n", c[0]);
  // printf("%s\n", c[1]);

  // Array of strings in heap
  // Pointer to pointer
  char **strings = malloc(sizeof(char *) * 2);
  char *msg1 = malloc(sizeof(char) * 8);
  char *msg2 = malloc(sizeof(char) * 8);
  strcpy(msg1, "hello");
  strcpy(msg2, "message");

  strings[0] = msg1;
  strings[1] = msg2;

  printf("%s\n", strings[0]);
  printf("%s\n", strings[1]);

  free(strings);
  free(msg1);
  free(msg2);

  return 0;
}