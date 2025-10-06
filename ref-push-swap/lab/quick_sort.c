// push_swap_quick.c
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

// ------------------ Stack helpers ------------------
t_node *new_node(int val) {
    t_node *n = malloc(sizeof(t_node));
    n->value = val;
    n->next = NULL;
    return n;
}

void push(t_stack *s, int val) {
    t_node *n = new_node(val);
    n->next = s->top;
    s->top = n;
}

int pop(t_stack *s) {
    if (!s->top) return 0;
    t_node *tmp = s->top;
    int val = tmp->value;
    s->top = tmp->next;
    free(tmp);
    return val;
}

int stack_size(t_stack *s) {
    int i = 0;
    t_node *cur = s->top;
    while (cur) { i++; cur = cur->next; }
    return i;
}

// ------------------ Operations ------------------
void sa(t_stack *a) {
    if (!a->top || !a->top->next) return;
    t_node *first = a->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    a->top = second;
    printf("sa\n");
}

void pa(t_stack *a, t_stack *b) {
    if (!b->top) return;
    push(a, pop(b));
    printf("pa\n");
}

void pb(t_stack *a, t_stack *b) {
    if (!a->top) return;
    push(b, pop(a));
    printf("pb\n");
}

void ra(t_stack *a) {
    if (!a->top || !a->top->next) return;
    t_node *first = a->top;
    t_node *cur = a->top;
    while (cur->next) cur = cur->next;
    a->top = first->next;
    first->next = NULL;
    cur->next = first;
    printf("ra\n");
}

void rra(t_stack *a) {
    if (!a->top || !a->top->next) return;
    t_node *cur = a->top;
    t_node *prev = NULL;
    while (cur->next) { prev = cur; cur = cur->next; }
    prev->next = NULL;
    cur->next = a->top;
    a->top = cur;
    printf("rra\n");
}

// ------------------ Quick sort logic ------------------
int find_pivot(t_stack *s, int len) {
    int *arr = malloc(len * sizeof(int));
    t_node *cur = s->top;
    for (int i = 0; i < len; i++) { arr[i] = cur->value; cur = cur->next; }
    // simple bubble sort to find median
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j+1]) { int tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp; }
    int pivot = arr[len/2];
    free(arr);
    return pivot;
}

void quick_sort_a(t_stack *a, t_stack *b, int len) {
    if (len <= 1) return;
    int pivot = find_pivot(a, len);
    int pushed = 0, rotated = 0;
    for (int i = 0; i < len; i++) {
        if (a->top->value < pivot) { pb(a, b); pushed++; }
        else { ra(a); rotated++; }
    }
    for (int i = 0; i < rotated; i++) rra(a);
    quick_sort_a(a, b, len - pushed);
    // sort B and push back
    for (int i = 0; i < pushed; i++) pa(a, b);
}

// ------------------ Main ------------------
int main(int ac, char **av) {
    t_stack a = {NULL};
    t_stack b = {NULL};
    for (int i = ac-1; i > 0; i--) push(&a, atoi(av[i]));
    quick_sort_a(&a, &b, stack_size(&a));
    return 0;
}
