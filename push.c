
#include "monty.h"



/**
 * push - Adds a new node to the head of a stack.
 * @stack: Double pointer to the head of the stack.
 * @n: Value to be added to the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
void push(stack_t **stack, unsigned int line_number, int n) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *temp = *stack;

    while (temp != NULL) {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}


void pint(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number){
    if (stack == NULL || *stack == NULL) {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *temp = *stack;
    *stack = temp->next;
    if (*stack != NULL) {
        (*stack)->prev = NULL;
    }
    free(temp);
}  


void swap(stack_t **stack, unsigned int line_number){

    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *first = *stack;
    stack_t *second = (*stack)->next;

    first->next = second->next;
    second->next = first;
    second->prev = NULL;
    
    if (first->next != NULL) {
        first->next->prev = first;
    }

    *stack = second;
}



void nop(stack_t **stack, unsigned int line_number) {
    (void)stack;     
    (void)line_number; 
}
