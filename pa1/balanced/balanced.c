#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



// Struct to hold the expected close brace character and a pointer to the next element.
typedef struct element {
    char close;
    struct element* next;
} element;
element *push(element *stack, char val);
char pop(element **stack);
void freeList(element *stack);
FILE *openFile(char *filename);
bool checkBalanced(FILE *fp);
bool compareChars(char open, char close);

int main(int argc, char* argv[])
{
    FILE *fp;
    if ((fp = openFile(argv[1])) == 0) return EXIT_FAILURE;

    bool balanced = checkBalanced(fp);

    printf ( balanced ? "yes" : "no" );
    fclose(fp);
    return EXIT_SUCCESS;
}

FILE *openFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen failed");
        return NULL;
    }
    return fp;
}

// read file, push opening brackets to stack.  Pop and compare if closing bracket
bool checkBalanced(FILE *fp) {
    bool balanced = true;
    element *stack = NULL;
    char buff;
    while ( fscanf(fp, "%c", &buff)==1 ) {
        if (buff == '(' || buff == '[' || buff == '{' || buff == '<') {
            stack = push(stack, buff);

        }
        if (buff == ')' || buff == ']' || buff == '}' || buff == '>') {
            char open = pop(&stack);
            compareChars(open, buff);
        }
    }
    if (stack != NULL) balanced = false;
    freeList(stack);
    return balanced;
}

// Compare open and close chars
bool compareChars(char open, char close) {
    switch (close) {
        case ']':
            if (open != '[') return false;
            break;
        case '}':
            if (open != '{') return false;
            break;
        case ')':
            if (open != '(') return false;
            break;
        case '>':
            if (open != '<') return false;
            break;
    }
    return true;
}

// push value to stack, returns new head
element *push(element *stack, char val) {
    element *node;
    node = (element*)malloc(sizeof(element));
    node->close = val;
    node->next = stack;
    return node;

}

// pop's the top item of the stack, returns value, advances pointer to new head, frees old head
char pop(element **stack) {
    if (*stack == NULL) {
        return -1;
    }
    element* temp = *stack;
    char item = (*stack)->close;
    *stack = (*stack)->next;
    free(temp);
    return item;
}

// Recursively free list
void freeList(element *stack) {
    if (stack == NULL) return;
    freeList(stack->next);
    free(stack);
}