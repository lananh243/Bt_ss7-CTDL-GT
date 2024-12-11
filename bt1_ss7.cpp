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

int isFull(Queue* queue){
	if(queue->rear == MAX - 1){
		return 1;
	}
	return 0;
}

//Them phan tu vao cuoi hang doi
void enqueue(Queue* queue, int value){
	if(isFull(queue) == 1){
		printf("Xin loi hang doi da day");
		return;
	}
	if(isEmpty(queue) == 1){
		queue->front = 0;
	}
	queue->rear++;
	queue->array[queue->rear] = value;
}

//In ra 
void displayQueue(Queue* queue){
	if(isEmpty(queue)){
		printf("Loi hang doi");
		return; 
	}
	for(int i = queue->front; i <= queue->rear; i++){
		printf("%d\t",queue->array[i]);
	}
}


int main(){
	Queue queue;
	initalQueue(&queue);
	int value,n;
	printf("Nhap so luong phan tu cho hang doi : ");
	scanf("%d",&n);
	if (n > MAX) {
        printf("So luong phan tu khong the lon hon %d.\n", MAX);
        return 1;
    }
	for(int i = 0; i < n; i++){
		printf("a[%d] : ", i + 1);
		scanf("%d",&value);
		enqueue(&queue,value);
	}
	printf("Tat ca cac phan tu trong hang doi : \n");
	displayQueue(&queue);
	return 0; 
} 
