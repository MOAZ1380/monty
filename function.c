#include "main.h"
/***/
void push(stack_t **stack, int n)
{
    stack_t * new = NULL;
    stack_t * tmp = NULL;
    new = malloc(sizeof(stack_t *));
    if(new == NULL)
    {
        return 0;
    }
    new->n = value;
    new->next=NULL;
    if(*stack == NULL)
    {
        new->prev = NULL;
		*stack = new;
		return (new);
    }
    tmp = *stack
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new-prev = tmp;

}


void pall(stack_t **stack, unsigned int line_number)
{
    size_t i = 0;
    const dlistint_t *tmp = *stack;
    (void) line_number
    while (tmp != NULL && tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    
    for (; tmp != NULL; tmp = tmp->prev)
    {
        printf("%d\n", tmp->value);
        // i++;
    }
    
    // return i;
}


void free_stack(stack_t *stack)
{
    stack_t *tmp;
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
