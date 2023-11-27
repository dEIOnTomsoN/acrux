#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head != NULL) {
            printf(" + ");
        }
    }
}

struct Node* add(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    struct Node* current = result;

    while (p1 != NULL || p2 != NULL) {
        int coeff1 = (p1 != NULL) ? p1->coeff : 0;
        int exp1 = (p1 != NULL) ? p1->exp : 0;

        int coeff2 = (p2 != NULL) ? p2->coeff : 0;
        int exp2 = (p2 != NULL) ? p2->exp : 0;

        if (exp1 > exp2) {
            insert(&current, coeff1, exp1);
            p1 = p1->next;
        } else if (exp1 < exp2) {
            insert(&current, coeff2, exp2);
            p2 = p2->next;
        } else {
            insert(&current, coeff1 + coeff2, exp1);
            p1 = p1->next;
            p2 = p2->next;
        }

        if (current->next != NULL) {
            current = current->next;
        }
    }

    return result;
}

struct Node* multiply(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL) {
        struct Node* temp = p2;
        while (temp != NULL) {
            insert(&result, p1->coeff * temp->coeff, p1->exp + temp->exp);
            temp = temp->next;
        }
        p1 = p1->next;
    }

    return result;
}

int main() {
    struct Node* p1 = NULL;
    struct Node* p2 = NULL;

   
    int n, coeff, exp;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents of the first polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&p1, coeff, exp);
    }

   
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents of the second polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&p2, coeff, exp);
    }

    
    struct Node* product = multiply(p1, p2);
    printf("Product of the two polynomials: ");
    display(product);
    printf("\n");

 
    struct Node* sum = add(p1, p2);
    printf("Sum of the two polynomials: ");
    display(sum);
    printf("\n");

    return 0;
}
