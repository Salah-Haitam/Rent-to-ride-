#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud dans la liste chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour ajouter un nœud à la fin de la liste chaînée
void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Fonction pour afficher la liste chaînée
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Fonction pour faire pivoter la liste chaînée vers la droite par k éléments
void rotateRight(Node** head_ref, int k) {
    int count ;
     Node* current;
      Node* kthNode;
    if (k == 0)
        return;

    count = 1;
    current = *head_ref;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

   kthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}

// Fonction pour faire pivoter la liste chaînée vers la gauche par k éléments
void rotateLeft(Node** head_ref, int k) {
   int count;
   Node* current;
   Node* kthNode;
    if (k == 0)
        return;

    count = 1;
    current = *head_ref;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

kthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}

int main() {
    Node* head = NULL;
    int n, i, data, k;

    printf("Entrez le nombre d'éléments de la liste : ");
    scanf("%d", &n);

    printf("Entrez les éléments de la liste : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Entrez la valeur de k pour la rotation : ");
    scanf("%d", &k);

    printf("Liste originale : ");
    printList(head);

    if (k > 0) {
        rotateRight(&head, k);
        printf("Liste après rotation vers la droite par %d éléments : ", k);
    } else if (k < 0) {
        rotateLeft(&head, -k);
        printf("Liste après rotation vers la gauche par %d éléments : ", -k);
    } else {
        printf("La liste reste inchangée.");
    }

    printList(head);

    return 0;
}
