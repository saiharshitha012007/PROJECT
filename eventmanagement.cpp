#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

char queue[SIZE][50];
int front = -1, rear = -1;
char stack[SIZE][50];
int top = -1;

void enqueue(char event[]) {
    if (rear == SIZE - 1) {
        printf("Queue Full! Cannot add more events.\n");
        return;
    }
    if (front == -1) front = 0;
    strcpy(queue[++rear], event);
    printf("Event added successfully!\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("No upcoming events to complete.\n");
        return;
    }
    printf("Event Completed: %s\n", queue[front]);
    strcpy(stack[++top], queue[front]);
    front++;
}

void showCompleted() {
    if (top == -1) {
        printf("No events completed yet.\n");
        return;
    }
    printf("\n--- Completed Events ---\n");
    for (int i = top; i >= 0; i--)
        printf("%s\n", stack[i]);
}

void showUpcoming() {
    if (front == -1 || front > rear) {
        printf("No upcoming events.\n");
        return;
    }
    printf("\n--- Upcoming Events ---\n");
    for (int i = front; i <= rear; i++)
        printf("%s\n", queue[i]);
}

int main() {
    int choice;
    char event[50];

    while (1) {
        printf("\n--- Event Management System ---\n");
        printf("1. Add Event\n");
        printf("2. Complete Event\n");
        printf("3. Show Upcoming Events\n");
        printf("4. Show Completed Events\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Event Name: ");
                fgets(event, 50, stdin);
                event[strcspn(event, "\n")] = 0;
                enqueue(event);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                showUpcoming();
                break;
            case 4:
                showCompleted();
                break;
            case 5:
                printf("Exiting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
