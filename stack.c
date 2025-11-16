#include <stdio.h>
#include <limits.h> // Used for INT_MIN as a clearer error return

// Define MAX_SIZE for the stack
#define MAX_SIZE 10

// Define the stack structure
typedef struct stack {
    int top;
    int stack_array[MAX_SIZE];
} Stack;

/**
 * @brief Initializes the stack by setting top to -1.
 * @param stack_pointer Pointer to the stack to initialize.
 */
void initialize_stack(Stack* stack_pointer) {
    stack_pointer->top = -1;
}

/**
 * @brief Checks if the stack is empty.
 * @param stack_pointer Pointer to the stack.
 * @return 1 (true) if empty, 0 (false) otherwise.
 */
int is_empty(Stack* stack_pointer) {
    return (stack_pointer->top == -1);
}

/**
 * @brief Checks if the stack is full.
 * @param stack_pointer Pointer to the stack.
 * @return 1 (true) if full, 0 (false) otherwise.
 */
int is_full(Stack* stack_pointer) {
    return (stack_pointer->top == (MAX_SIZE - 1));
}

/**
 * @brief Pushes a value onto the stack.
 * @param stack_pointer Pointer to the stack.
 * @param value The integer value to push.
 */
void push(Stack* stack_pointer, int value) {
    if (is_full(stack_pointer)) {
        printf("Error: The stack is full. Cannot push %d.\n", value);
    } else {
        stack_pointer->top++;
        stack_pointer->stack_array[stack_pointer->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

/**
 * @brief Pops a value from the stack.
 * @param stack_pointer Pointer to the stack.
 * @return The value at the top of the stack, or INT_MIN if the stack is empty.
 */
int pop(Stack* stack_pointer) {
    if (is_empty(stack_pointer)) {
        printf("Error: The stack is empty. Cannot pop.\n");
        // Return a sentinel value to indicate error
        // Note: If INT_MIN was a valid item, this logic would be flawed
        return INT_MIN; 
    } else {
        int value = stack_pointer->stack_array[stack_pointer->top];
        stack_pointer->top--;
        return value;
    }
}

/**
 * @brief Peeks at the top value of the stack without removing it.
 * @param stack_pointer Pointer to the stack.
 * @return The value at the top of the stack, or INT_MIN if the stack is empty.
 */
int peek(Stack* stack_pointer) {
    // BUG FIX: Added (stack_pointer) argument to is_empty
    if (is_empty(stack_pointer)) { 
        printf("Error: The stack is empty. Cannot peek.\n");
        // BUG FIX: Changed return NULL; to return INT_MIN;
        return INT_MIN;
    } else {
        return stack_pointer->stack_array[stack_pointer->top];
    }
}

/**
 * @brief Displays all contents of the stack from bottom to top.
 * @param stack_pointer Pointer to the stack.
 */
void display_contents(Stack* stack_pointer) {
    if (is_empty(stack_pointer)) {
        printf("Display: Stack is empty.\n");
        return;
    }
    printf("Stack contents (bottom to top):\n");
    for (int i = 0; i <= stack_pointer->top; i++) {
        printf("%d\n", stack_pointer->stack_array[i]);
    }
}

/**
 * @brief Main function to test the stack implementation.
 */
int main(void) {
    Stack my_stack;
    int popped_value;
    int peeked_value;

    printf("--- Initializing Stack ---\n");
    initialize_stack(&my_stack);

    printf("\n--- Testing on Empty Stack ---\n");
    printf("Is stack empty? %s\n", is_empty(&my_stack) ? "Yes" : "No");
    display_contents(&my_stack);
    popped_value = pop(&my_stack); // Test pop on empty
    peeked_value = peek(&my_stack); // Test peek on empty

    printf("\n--- Pushing Values ---\n");
    push(&my_stack, 10);
    push(&my_stack, 20);
    push(&my_stack, 30);

    printf("\n--- Testing After Pushes ---\n");
    printf("Is stack empty? %s\n", is_empty(&my_stack) ? "Yes" : "No");
    display_contents(&my_stack);
    
    peeked_value = peek(&my_stack);
    if (peeked_value != INT_MIN) {
        printf("Peeked value: %d\n", peeked_value);
    }
    
    printf("\n--- Popping Values ---\n");
    popped_value = pop(&my_stack);
    if (popped_value != INT_MIN) {
        printf("Popped value: %d\n", popped_value);
    }
    
    popped_value = pop(&my_stack);
    if (popped_value != INT_MIN) {
        printf("Popped value: %d\n", popped_value);
    }

    printf("\n--- Testing After Pops ---\n");
    display_contents(&my_stack);
    peeked_value = peek(&my_stack);
    if (peeked_value != INT_MIN) {
        printf("Peeked value: %d\n", peeked_value);
    }

    printf("\n--- Testing Stack Overflow ---\n");
    printf("Is stack full? %s\n", is_full(&my_stack) ? "Yes" : "No");
    // MAX_SIZE is 10. We have 1 item (10). Let's push 9 more.
    push(&my_stack, 40);
    push(&my_stack, 50);
    push(&my_stack, 60);
    push(&my_stack, 70);
    push(&my_stack, 80);
    push(&my_stack, 90);
    push(&my_stack, 100);
    push(&my_stack, 110);
    push(&my_stack, 120);

    printf("\n--- Testing Full Stack ---\n");
    printf("Is stack full? %s\n", is_full(&my_stack) ? "Yes" : "No");
    display_contents(&my_stack);
    push(&my_stack, 130); // Test push on full

    printf("\n--- Emptying Stack ---\n");
    while (!is_empty(&my_stack)) {
        popped_value = pop(&my_stack);
        printf("Popped value: %d\n", popped_value);
    }

    printf("\n--- Final Check ---\n");
    printf("Is stack empty? %s\n", is_empty(&my_stack) ? "Yes" : "No");
    display_contents(&my_stack);

    return 0;
}
