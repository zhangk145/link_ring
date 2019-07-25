
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct node *link_init() {
    int i = 0;
    struct node *pp = NULL;
    struct node *entry = NULL;
    struct node * p = NULL;
    struct node *head = malloc(sizeof(struct node));
    head->value = 0;
    head->next = NULL;
    pp = head;
    for (i = 1; i < 7; i++) {
        p = malloc(sizeof(struct node));
        p->value = i;
        p->next = NULL;
        pp->next = p;
        pp = pp->next;
        printf("p:%p value:%d\n", p, p->value);
    }
    entry = p;
    printf("entry:%p entry:%d\n", entry, entry->value);
    for (; i < 18; i ++) {
        p = malloc(sizeof(struct node));
        p->value = i;
        p->next = NULL;
        pp->next = p;
        pp = pp->next;
        printf("p:%p value:%d\n", p, p->value);
    }
    pp->next = entry;
    return head;
}

int main(int argc, char *argv[]) {
    struct node *link = link_init();
    struct node *p = link;
    // while (p) {
    //     printf("ptr:%p value:%d\n", p, p->value);
    //     p = p->next;
    //     sleep(1);
    // }

    struct node *first = link;
    struct node *second = link;
    struct node *cross = NULL;

    while(first && second && second->next) {
        first = first->next;
        second = second->next->next;
        printf("first:%d second:%d\n", first->value, second->value);
        if (first == second) {
            break;
        }
        // usleep(100000);
    }
    printf("cross first ptr:%p first:%d\n", first, first->value);
    printf("cross second ptr:%p second:%d\n", second, second->value);
    cross = first;
    int circle_len = 0;
    p = first->next;
    while (p != first) {
        circle_len++;
        p = p->next;
    }
    printf("circle len:%d\n", circle_len);
    p = link;
    while (p != cross) {
        printf("p ptr:%p value:%d\n", p, p->value);
        printf("cross ptr:%p value:%d\n", cross, cross->value);
        p = p->next;
        cross = cross->next;
        // sleep(1);
    }
    printf("cross ptr:%p value:%d\n", cross, cross->value);
    return 0;
}