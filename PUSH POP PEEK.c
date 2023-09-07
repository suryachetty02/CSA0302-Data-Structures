#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
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
        return;
    }

    stack->data[++stack->top] = value;
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        exit(1);
    }

    return stack->data[stack->top--];
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        exit(1);
    }

    return stack->data[stack->top];
}

int main() {
    struct Stack stack;
    initialize(&stack);
    int choice, value;

    while (1) {
        printf("Stack operations menu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to PUSH onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                if (!isEmpty(&stack)) {
                    printf("%d popped from the stack.\n", pop(&stack));
                }
                break;

            case 3:
                if (!isEmpty(&stack)) {
                    printf("Top element of the stack: %d\n", peek(&stack));
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
