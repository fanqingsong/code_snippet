#include"NodeQueue.h"
#include<malloc.h> 
#include<stdlib.h>

NodeQueue * InitQueue(){	
	
	NodeQueue * queue=(NodeQueue *)malloc(sizeof(NodeQueue));
	queue->front=queue->rear=(QNode *)malloc(sizeof(QNode));
	queue->front->next=NULL;
	return queue;
}

boolean DestroyQueue(NodeQueue * queue){
	while(queue->front){
		queue->rear=queue->front->next;
		free(queue->front);
		queue->front=queue->rear;
	}

	return 1;
}

boolean EnQueue(NodeQueue * queue,Node * node){
	
	QNode * p=(QNode *)malloc(sizeof(QNode));
	if(!p){
		return 0;
	}
	p->data=node;
	p->next=NULL;
	queue->rear->next=p;
	queue->rear=p;
	
	return 1;
}

Node * DeQueue(NodeQueue * queue){
	
	Node * node;

	QNode * p=queue->front->next;
	
	if(queue->front==queue->rear){
		return NULL;
	}


	node=p->data;
	
	queue->front->next=p->next;

	if(queue->rear==p){
		queue->rear=queue->front;
	}

	free(p);
	
	return node;
	
	
}

boolean IsQueueEmpty(NodeQueue * queue){
	if(queue->front==queue->rear){
		return 0;
	}else{
		return 1;
	}
}