#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* next;
};

struct node* head;
struct node* tail;

void init_linked_list() {
    head = (struct node*)malloc(sizeof *head);
    tail = (struct node*)malloc(sizeof *tail);
    head->next = tail;
    tail->next = tail;
}

void delete_next(struct node* u) {
    if (u == tail || u->next == tail) return;
    struct node* old_next = u->next;
    u->next = u->next->next;
    free(old_next);
}

struct node* insert_after(struct node* u, int v) {
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof *new_node);
    new_node->key = v;
    new_node->next = u->next;
    u->next = new_node;
    return new_node;
}

void print_linked_list() {
    struct node* cur = head;
    printf("head ");
    while (cur->next != cur) {
        if (cur->key) printf("%d ", cur->key);
        cur = cur->next;
    }
    puts("");
}

int main() {
    init_linked_list();
    struct node* cur = head;
    cur = insert_after(cur, 5);
    cur = insert_after(cur, 6);
    cur = insert_after(cur, 1);
    cur = insert_after(cur, 2);
    cur = insert_after(cur, 3);
    delete_next(head->next->next);
    print_linked_list();
    return 0;
}