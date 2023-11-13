#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

void insert(struct node **head, int coeff, int exp) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(struct node *head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
}

struct node *add(struct node *p1, struct node *p2) {
    struct node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insert(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insert(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            insert(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

struct node *multiply(struct node *p1, struct node *p2) {
    struct node *result = NULL;

    while (p1 != NULL) {
        struct node *temp = p2;
        while (temp != NULL) {
            int coeff = p1->coeff * temp->coeff;
            int exp = p1->exp + temp->exp;
            insert(&result, coeff, exp);
            temp = temp->next;
        }
        p1 = p1->next;
    }

    return result;
}

int main() {
    struct node *p1 = NULL;
    struct node *p2 = NULL;

    // Read the first polynomial
    int n;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents of the first polynomial:\n");
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insert(&p1, coeff, exp);
    }

    // Read the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents of the second polynomial:\n");
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insert(&p2, coeff, exp);
    }

    // Calculate the product of the two polynomials
    struct node *product = multiply(p1, p2);
    printf("Product of the two polynomials: ");
    display(product);
    printf("\n");

    // Calculate the sum of the two polynomials
    struct node *sum = add(p1, p2);
    printf("First polynomial: ");
    display(p1);
    printf("\n");
    printf("Second polynomial: ");
    display(p2);
    printf("\n");
    printf("Sum of the two polynomials: ");
    display(sum);
    printf("\n");

    return 0;
}

