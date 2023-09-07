#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack.
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %d onto the stack.\n", value);
        exit(1);
    }

    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        exit(1);
    }

    return stack->data[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        char symbol = postfix[i];

        if (isdigit(symbol)) {
            push(&stack, symbol - '0'); // Convert char digit to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (symbol) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&stack, operand1 / operand2);
                    } else {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Invalid character in expression: %c\n", symbol);
                    exit(1);
            }
        }
        i++;
    }

    if (!isEmpty(&stack) && stack.top == 0) {
        return stack.data[0];
    } else {
        printf("Invalid postfix expression\n");
        exit(1);
    }
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}
