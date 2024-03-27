#include "main.h"
/***/
void execute_instruction(const char *opcode, const char *arg, unsigned int line_number)
{
    int n;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};

    for (int i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            if (strcmp(opcode, "push") == 0)
            {
                if (!arg)
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
                n = atoi(arg);
                push(&stack, n);
            }
            else
            {
                instructions[i].f(&stack, line_number);
            }
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
