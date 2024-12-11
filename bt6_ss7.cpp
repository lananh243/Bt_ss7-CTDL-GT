#include<stdio.h>
#include<stdlib.h>
#define MAX 100 

typedef struct Queue {
	int array[MAX];
	int front;
	int rear;
}Queue; 

//Khoi tao hang doi

void initalQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

//Kiem tra hang doi rong
int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

//Kiem tra hang doi 
int isFull(Queue* queue) {
    return (queue->front == 0 && queue->rear == MAX - 1) || (queue->rear + 1 == queue->front);
}

// Them phan tu vao dau hang doii
void addFront(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi da day\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->front = (queue->front - 1 + MAX) % MAX;
    }
    queue->array[queue->front] = value;
}

// Them phan tu vao cuoi hang doii
void addRear(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi da day\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX;
    }
    queue->array[queue->rear] = value;
}

// Lay phan tu dau tien 
int removeFront(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return -1;
    }
    int value = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; 
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return value;
}

// Lay phan tu cuoi cung  
int removeRear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return -1;
    }
    int value = queue->array[queue->rear];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; 
    } else {
        queue->rear = (queue->rear - 1 + MAX) % MAX;
    }
    return value;
}

// Hien thi cac phan tu trong hang doi
void displayQueue(Queue* queue){
	if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->array[i]);
        if (i == queue->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n"); 
}

int main() {
    Queue queue;
    initalQueue(&queue);
	int value;
	
	do {
		printf("\n*********************MENU******************************\n");
		printf("0. Thoat \n");
		printf("1. Them phan tu vao dau hang doi \n");
		printf("2. Them phan tu vao cuoi hang doi \n");
		printf("3. Lay ra phan tu dau cua hang doi\n");
		printf("4. Lay ra phan tu cuoi cua hang doi\n");
		printf("5. Hien thi hang doi \n");
		printf("6. Kiem tra hang doi rong \n");
		printf("Moi ban chon 0 - 6 : ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 0 :
				exit(0);
			case 1 :
				printf("Moi ban nhap vao gia tri : ");
				scanf("%d",&value);
				addFront(&queue, value);
				break;
			case 2 :
				printf("Moi ban nhap vao gia tri : ");
				scanf("%d",&value);
				addRear(&queue, value);
				break;
			case 3 :
				removeFront(&queue);
				if (value != -1) {
                    printf("Phan tu dau tien : %d\n", value);
                }
				break;
			case 4 :
				removeRear(&queue);
				if (value != -1) {
                    printf("Phan tu cuoi : %d\n", value);
                }
				break;
			case 5 :
				displayQueue(&queue);
				break;
			case 6:
                if (isEmpty(&queue)) {
                    printf("Hang doi rong\n");
                } else {
                    printf("Hang doi khong rong\n");
                }
                break;
			default:
				printf("Vui long chon lai");
		}
	}while(1==1);
	return 0;
}

