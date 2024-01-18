#include "calc.h"

void print_lexem(elements *lexem, int count) {
  printf("%d\n", count);

  for (int i = 0; i < count; i++) {
    printf("stack[%d]:\n", i);
    printf("type: %d\n", lexem->type);
    printf("priority: %d\n", lexem->priority);
    printf("operation: \"%s\"\n", lexem->operation);
    printf("value: %Lf\n", lexem->value);
    printf("\n");
    lexem++;
  }
}

void free_lexem(elements *lexem, int count) {
  for (int i = 0; i < count; i++) {
    (lexem + i)->type = 0;
    (lexem + i)->priority = 0;
    memset((lexem + i)->operation, 0, sizeof((lexem + i)->operation));
    (lexem + i)->value = 0;
  }
}

