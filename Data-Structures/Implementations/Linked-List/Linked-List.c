/*
a. Create a linked list.
b. Insert an element at the start of the linked list.
c. Insert an element at the end of the linked list.
d. Insert an element before an existing element whose information is x in a linked list.
e. Insert an element after an existing element whose information is x in a linked list.
f. Delete the first element of the linked list.
g. Delete the last element of the linked list.
h. Delete the element whose information is x from a linked list.
i. Display the contents of the linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

/*Insert at begining*/
struct node *addtobegin(struct node *start, int data) {
    struct node *tmp = (struct node *) malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}

/*Insert at end*/
struct node *addatend(struct node *start, int data) {
    struct node *tmp = (struct node *) malloc(sizeof(struct node));
    tmp->info = data;
    struct node *p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = tmp;
    tmp->link = NULL;
    return start;
}

/*Insert before info=x*/
struct node *addbefore(struct node *start, int data, int x) {
    if (start == NULL) {
        printf("List is empty");
        return start;
    }
    if (x == start->info) {
        start = addtobegin(start, data);
        return start;
    }
    struct node *tmp, *p;
    tmp = (struct node *) malloc(sizeof(struct node));
    tmp->info = data;
    p = start;
    while (p->link != NULL) {
        if (p->link->info == x) {
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("\n%d not found in the list!!!", x);
    return start;
}

/*Insert after info=x*/
struct node *addafter(struct node *start, int data, int x) {
    struct node *tmp, *p;
    tmp = (struct node *) malloc(sizeof(struct node));
    tmp->info = data;
    p = start;
    while (p != NULL) {
        if (p->info == x) {
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("\n%d not found in the list!!!", x);
    return start;
}

/*Delete first element*/
struct node *delfirst(struct node *start) {
    struct node *tmp;
    if (start == NULL) {
        printf("\nList is empty!!");
        return start;
    }
    tmp = start;
    start = start->link;
    free(tmp);
    return start;
}

/*Delete last element*/
struct node *dellast(struct node *start) {
    struct node *tmp, *p;
    if (start == NULL) {
        printf("\nList is empty!!");
        return start;
    }
    if (start->link == NULL) {
        tmp = start;
        start = NULL;
        free(tmp);
        return start;
    }
    p = start;
    while (p->link != NULL) {
        tmp = p;
        p = p->link;
    }
    tmp->link = NULL;
    free(p);
    return start;
}

/*Delete at info=x*/
struct node *delat(struct node *start, int x) {
    struct node *tmp, *p;
    if (start == NULL) {
        printf("\nList is empty!!");
        return start;
    }
    if (start->info == x)
        return delfirst(start);
    p = start;
    while (p->link != NULL) {
        if (p->link->info == x) {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("\n%d not found in the list!!!", x);
    return start;
}


/*Display*/
void display(struct node *start) {
    struct node *p;
    p = start;
    printf("\nList is:\n");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("NULL");
}

/*Main*/

int main() {
    struct node *start;
    struct node *preptr;
    struct node *ptr;
    int data, x;
    preptr = (struct node *) malloc(sizeof(struct node));
    printf("Enter data of 1st node: ");
    scanf("%d", &data);
    preptr->info = data;
    preptr->link = NULL;
    start = preptr;
    while (1) {
        printf("\nEnter data of next node (-1 to end): ");
        scanf("%d", &data);
        if (data == -1)
            break;
        ptr = (struct node *) malloc(sizeof(struct node));
        ptr->info = data;
        ptr->link = NULL;
        preptr->link = ptr;
        preptr = ptr;
    }
    printf("Link List Created\n");
    display(start);
    int c;
    while (1) {
        printf("\n\nEnter choice:(0 to Exit) ");
        printf("\n1. Insert an element at the start of the linked list");
        printf("\n2. Insert an element at the end of the linked list");
        printf("\n3. Insert an element before an existing element whose information is x in a linked list");
        printf("\n4. Insert an element after an existing element whose information is x in a linked list");
        printf("\n5. Delete the first element of the linked list");
        printf("\n6. Delete the last element of the linked list");
        printf("\n7. Delete the element whose information is x from a linked list");
        printf("\n8. Display the contents of the linked list\n");
        scanf("%d", &c);
        switch (c) {
            case 0:
                exit(1);
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                start = addtobegin(start, data);
                break;
            case 2:
                printf("Enter element to add: ");
                scanf("%d", &data);
                start = addatend(start, data);
                break;
            case 3:
                printf("Enter x: ");
                scanf("%d", &x);
                printf("Enter element to add: ");
                scanf("%d", &data);
                start = addbefore(start, data, x);
                break;
            case 4:
                printf("Enter x: ");
                scanf("%d", &x);
                printf("Enter element to add: ");
                scanf("%d", &data);
                start = addafter(start, data, x);
                break;
            case 5:
                start = delfirst(start);
                printf("\nFirst element deleted successfully");
                break;
            case 6:
                start = dellast(start);
                printf("\nLast element deleted successfully");
                break;
            case 7:
                start = delat(start, x);
                printf("\nElement deleted successfully");
                break;
            case 8:
                display(start);
                break;
            default:
                printf("\nInvalid Choice!!");

        }

    }
    return 0;
}
