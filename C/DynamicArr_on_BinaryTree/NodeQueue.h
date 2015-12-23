#include"BinaryTree.h"

typedef struct QNode{
	Node * data;
    struct QNode * next;
}QNode;

typedef struct{
	QNode * front;
	QNode * rear;
}NodeQueue;

NodeQueue * InitQueue();

boolean DestroyQueue(NodeQueue * queue);

boolean EnQueue(NodeQueue * queue,Node * node);

Node * DeQueue(NodeQueue * queue);

boolean IsQueueEmpty(NodeQueue * queue);
