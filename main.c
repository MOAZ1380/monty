#include "main.h"
/***/
int main(int argc, char *argv)
{
    unsigned int line_number = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    
    FILE * filename = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while(read = getline(&line, &len, filename))
    {
        line_number++;
        char *opcode = strtok(line, " \n");
        char *arg = strtok(NULL, " \n");
        if (opcode)
        {
            execute_instruction(opcode, arg, line_number);
        }
    }
    free(line);
    fclose(filename);
    free_stack(stack);
    return 0;
}
