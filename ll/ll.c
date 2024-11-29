#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    void *val;
    struct _node *next;
} Node;

Node *ll_insert_start(Node *p, void *val, size_t size) {
    Node *new_node = malloc(sizeof(Node));
    new_node->next = p;
    new_node->val = malloc(size);
    memcpy(new_node->val, val, size);
    return new_node;
}

void ll_free(Node *p) {
    Node *tmp;
    while (p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp->val);
        free(tmp);
    }
}

void ll_print(Node *p, void print_node(void *val, int last)) {
    while (p != NULL) {
        print_node(p->val, p->next == NULL);
        p = p->next;
    }
    printf("\n");
}

void print_int(int *val, int last) {
    printf("%d%s", *val, last ? "\n" : ", ");
}

int main(void) {
    Node *ll = NULL;

    for (int i = 0; i < 10; i++) 
        ll = ll_insert_start(ll, &i, sizeof(int));

    ll_print(ll, (void (*)(void *, int)) print_int);

    ll_free(ll);
}
