#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number) { 
    stack_t *temp = *stack;
    stack_t *last = *stack;
    if (temp == NULL || temp->next == NULL) {
        return;
    }

    *stack = temp->next;
    (*stack)->prev = NULL;

    while (last->next != NULL)
    {
        last = last->next;
    }

    temp->next = NULL;
    temp->prev = last;
    last->next = temp;
}



void rotr(stack_t **stack, unsigned int line_number) { 
    stack_t *temp = *stack;
    stack_t *last = *stack;
    if (temp == NULL || temp->next == NULL) {
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    
    if (last->prev != NULL) {
        last->prev->next = NULL;
    }
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    (*stack) = last;
}