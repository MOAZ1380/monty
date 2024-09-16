
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
