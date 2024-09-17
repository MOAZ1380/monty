#include "monty.h"
#include <ctype.h> 
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    while (fgets(line, BUFFER_SIZE, file)) {
        line_number++;
        char *opcode = strtok(line, " \n");
        char *arg_str = strtok(NULL, " ");
        int argument = arg_str ? atoi(arg_str) : 0;

        if (!opcode || opcode[0] == '#') {
            continue;
        }
        if (strcmp(opcode, "push") == 0) {
            if (!arg_str || !isdigit(*arg_str)) {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, line_number, argument);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack, line_number);
        } else if (strcmp(opcode, "pint") == 0) {
            pint(&stack, line_number);
        } 
        else if(strcmp(opcode, "pop") == 0){
            pop(&stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(&stack, line_number);
        }
        else if (strcmp(opcode, "sub") == 0)
        {
            sub(&stack, line_number);
        }

        else if (strcmp(opcode, "add") == 0)
        {
            add(&stack, line_number);
        }
        else if (strcmp(opcode, "nop") == 0) {
            nop(&stack, line_number);
        }

        else if (strcmp(opcode, "div") == 0) {
            div_two_one(&stack, line_number);
        } 
        else if (strcmp(opcode, "mul") == 0) {
            mul(&stack, line_number);
        } 
        else if (strcmp(opcode, "mod") == 0) {
            mod(&stack, line_number);
        } 
        else if (strcmp(opcode, "pchar") == 0) {
            pchar(&stack, line_number);
        }
        else if (strcmp(opcode, "pstr") == 0) {
            pstr(&stack, line_number);
        }

        else if (strcmp(opcode, "rotl") == 0) {
            rotl(&stack, line_number);
        }

        else if (strcmp(opcode, "rotr") == 0) {
            rotr(&stack, line_number);
        }

        else {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
