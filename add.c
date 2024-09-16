#include "monty.h"


void add(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp_1 = *stack;         
    stack_t *temp_2 = (*stack)->next;  
    int sum = temp_1->n + temp_2->n;
    (*stack)->n = sum;

    
    (*stack)->next = temp_2->next;
    if (temp_2->next != NULL) {
        temp_2->next->prev = *stack;
    }

    
    free(temp_2);
}