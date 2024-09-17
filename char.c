#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", (*stack)->n);
}

void pstr(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        printf("\n");
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    while (temp != NULL && temp->n != 0 && temp->n >= 0 && temp->n <= 127) {
        printf("%c", temp->n);
        temp = temp->next;
    }
    printf("\n");
}