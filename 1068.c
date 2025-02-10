#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000


typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;


void initStack(Stack *s) {
    s->top = -1;
}


bool isEmpty(Stack *s) {
    return s->top == -1;
}


void push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c;
    }
}


char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0'; 
}


char top(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0'; 
}

int main() {
    char str[MAX_SIZE];
    while (scanf("%s", str) != EOF) {
        Stack s;
        initStack(&s);
        bool isCorrect = true;

        for (int i = 0; i < strlen(str); ++i) {
            if (str[i] == '(') {
                push(&s, str[i]);
            } else if (str[i] == ')') {
                if (isEmpty(&s)) {
                    isCorrect = false;
                    break;
                }
                if (top(&s) == '(') {
                    pop(&s);
                }
            }
        }

        if (!isCorrect || !isEmpty(&s)) {
            printf("incorrect\n");
        } else {
            printf("correct\n");
        }
    }

    return 0;
}
