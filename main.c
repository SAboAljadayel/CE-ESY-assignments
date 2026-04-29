#include <stdio.h>
#include <string.h>

#define SIZE 10   // غيّرها للتجربة


typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;


void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void writeBuffer(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }

    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }

    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;

    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[100];

    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "ESY-CE");

    for (int i = 0; i < strlen(name); i++) {
        writeBuffer(&cb, name[i]);
    }

    while (!isEmpty(&cb)) {
        char c = readBuffer(&cb);
        printf("%c", c);
    }

    printf("\n");

    return 0;
}
