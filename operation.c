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



void mul(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp_1 = *stack;         
    stack_t *temp_2 = (*stack)->next;  
    int sum = temp_2->n * temp_1->n;
    
    
    (*stack)->n = sum;

    
    (*stack)->next = temp_2->next;
    if (temp_2->next != NULL) {
        temp_2->next->prev = *stack;
    }

    
    free(temp_2);
}

void sub(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp_1 = *stack;         
    stack_t *temp_2 = (*stack)->next;  
    int sum = temp_2->n - temp_1->n; 
    (*stack)->n = sum;

    
    (*stack)->next = temp_2->next;
    if (temp_2->next != NULL) {
        temp_2->next->prev = *stack;
    }

    
    free(temp_2);
}



void div_two_one(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp_1 = *stack;         
    stack_t *temp_2 = (*stack)->next;  
    
    

    if (temp_1->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    int sum = temp_2->n / temp_1->n;
    
    
    (*stack)->n = sum;

    
    (*stack)->next = temp_2->next;
    if (temp_2->next != NULL) {
        temp_2->next->prev = *stack;
    }

    
    free(temp_2);
}



void mod(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp_1 = *stack;         
    stack_t *temp_2 = (*stack)->next;  
    
    

    if (temp_1->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    int sum = temp_2->n % temp_1->n;
    
    
    (*stack)->n = sum;

    
    (*stack)->next = temp_2->next;
    if (temp_2->next != NULL) {
        temp_2->next->prev = *stack;
    }

    
    free(temp_2);
}