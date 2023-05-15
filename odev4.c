#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Kuyruk {
    struct Node* front;
    struct Node* rear;
};


void Kuyrugubaslat(struct Kuyruk* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Kuyruða eleman ekleme
void enqueue(struct Kuyruk* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Eleman %d queue'ya eklendi.\n", value);
}

// Kuyruktan eleman silme
void dequeue(struct Kuyruk* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk bos.\n");
    } else {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;

        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        printf("Eleman %d kuyruktan cikarildi.\n", temp->data);
        free(temp);
    }
}

// Kuyruktaki elemanlari görüntüleme
void display(struct Kuyruk* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk bos.\n");
    } else {
        printf("Kuyruktaki elemanlar: ");
        struct Node* current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Kuyruk queue;
    Kuyrugubaslat(&queue);

    int choice, value;
    printf("Lutfen asagidaki islemlerden birini seciniz");

    while (1) {
        printf("\n1. Ekleme\n");
        printf("2. Silme\n");
        printf("3. Goruntuleme\n");
        printf("4. Cikis\n");
        printf("\nSeciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklemek istediginiz degeri giriniz: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Programdan cikildi\n");
                exit(0);
            default:
                printf("Yanlis secim\n");
        }
    }

    return 0;
}
