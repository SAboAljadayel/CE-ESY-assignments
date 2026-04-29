#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;


// Initialization
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}


// Check if full
int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}


// Check if empty
int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}


// Write function
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\nBuffer Overflow! Cannot write '%c'\n", data);
        return;
    }

    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;

    printf("Written '%c' -> head=%d tail=%d count=%d\n",
           data, cb->head, cb->tail, cb->count);
}


// Read function
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\nBuffer Underflow!\n");
        return '\0';
    }

    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;

    printf("Read '%c' -> head=%d tail=%d count=%d\n",
           data, cb->head, cb->tail, cb->count);

    return data;
}


int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];
    char finalString[60];

    // Input name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = 0;

  
    snprintf(finalString, sizeof(finalString), "%s ESY-CE", name);

    // Write to buffer
    for (int i = 0; i < strlen(finalString); i++) {
        write(&cb, finalString[i]);
    }

    // Read and print
    while (!isEmpty(&cb)) {
        char ch = read(&cb);
        if (ch != '\0') {
            printf("%c", ch);
        }
    }

    printf("\n");

    if (isEmpty(&cb)) {
        printf("Buffer is now completely empty.\n");
    }

    return 0;
}
