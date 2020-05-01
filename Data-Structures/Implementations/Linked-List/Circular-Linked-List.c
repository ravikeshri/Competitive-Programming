/*
C Program to Demonstrate Circular linked list.
(a) Creation of Circular linked list
(b) Insertion at beginning
(c) Insertion at remaining
(d) Deletion at beginning
(e) traverse
(f) Search
(g) sort
(h) update
*/

/*
Instead of head, we keep track of last element
So that insertion and deletion at beginning and
end becomes efficient
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *addtoempty(struct node *last) {
    struct node *tmp;
    tmp = (struct node *) malloc(sizeof(struct node));
    printf("Enter data of node 1: ");
    scanf("%d", &tmp->data);
    last = tmp;
    last->next = last;
    return last;
}

struct node *addatend(struct node *last) {
    struct node *tmp;
    tmp = (struct node *) malloc(sizeof(struct node));
    scanf("%d", &tmp->data);
    tmp->next = last->next;
    last->next = tmp;
    last = tmp;
    return last;
}

struct node *addatbeg(struct node *last) {
    struct node *tmp;
    tmp = (struct node *) malloc(sizeof(struct node));
    scanf("%d", &tmp->data);
    tmp->next = last->next;
    last->next = tmp;
    return last;
}



struct node *delatbeg(struct node *last) {
    if (last == NULL) {
        printf("\nList is already empty!!");
        return last;
    }
    struct node *tmp;
    tmp = last->next;
    last->next = tmp->next;
    free(tmp);
    return last;
}

struct node *create(struct node *last) {
    int n, i;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    if (n == 0)
        return last;
    last = addtoempty(last);
    for (i = 2; i <= n; i++) {
        printf("Enter data of node %d: ", i);
        last = addatend(last);
    }
    return last;
}



void search(struct node *last) {
    int search;
    printf("\nEnter data to search: ");
    scanf("%d", &search);
    if (last == NULL) {
        printf("\nList is empty!!");
        return;
    }
    struct node *p = last->next;
    int count = 1;
    do {
        if (p->data == search) {
            printf("\n%d found at node %d\n", search, count);
            return;
        }
        count++;
        p = p->next;
    } while (p != last->next);
    printf("\n%d not found!!\n", search);
}

struct node *update(struct node *last) {
    if (last == NULL) {
        printf("\nList is empty!!");
        return last;
    }
    int old, new;
    printf("\nEnter old data: ");
    scanf("%d", &old);
    printf("Enter new data: ");
    scanf("%d", &new);
    struct node *p = last->next;
    do {
        if (p->data == old) {
            p->data = new;
            printf("\nData updated successfully!!");
            return last;
        }
        p = p->next;
    } while (p != last->next);
    printf("\n%d not found!!\n", old);
}

struct node *sort(struct node *last) {
    if (last == NULL) {
        printf("\nList is empty!!\n");
        return last;
    }
    struct node *p, *q;
    int tmp;
    for (p = last->next; p != last; p = p->next) {
        for (q = p->next; q != last->next; q = q->next) {
            if (p->data > q->data) {
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
    printf("\nList sorted successfully!!\n");
    return last;
}

void display(struct node *last) {
    struct node *p;
    if (last == NULL) {
        printf("\nList is empty!!\n");
        return;
    }
    p = last->next;
    printf("\nList is:\n");
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
}

int main() {
    struct node *last = NULL;
    int ch;
    while (1) {
        printf("\n\n(1) Creation of Circular linked list\n(2) Insertion at beginning\n(3) Insertion at remaining\n(4) Deletion at beginning\n(5) traverse\n(6) Search\n(7) sort\n(8) update\n(9) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                last = create(last);
                break;
            case 2:
                printf("Enter data to be added: ");
                last = addatbeg(last);
                break;
            case 3:
                printf("Enter data to be added: ");
                last = addatend(last);
                break;
            case 4:
                last = delatbeg(last);
                break;
            case 5:
                display(last);
                break;
            case 6:
                search(last);
                break;
            case 7:
                last = sort(last);
                break;
            case 8:
                last = update(last);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
