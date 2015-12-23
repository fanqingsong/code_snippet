#include "NodeQueue.h"
#include<malloc.h> 
#include<stdlib.h>
#include<stdio.h>

BinaryTree * InitBiTree(){
	
	BinaryTree * binaryTree=(BinaryTree *)malloc(sizeof(BinaryTree));	
	binaryTree->lChild=NULL;
	binaryTree->rChild=NULL;
	return binaryTree;
}

BinaryTree * CreateBiTree(){
			
	char c;
	BinaryTree * binaryTree=NULL;

	c=getchar();
	
	if(c==' '){
		binaryTree=NULL;
	}else{
		binaryTree=InitBiTree();
		binaryTree->data=c-'0';
		binaryTree->lChild=CreateBiTree();
		binaryTree->rChild=CreateBiTree();
	}
	
	return binaryTree;

}	



void ClearBiTree(BinaryTree * binaryTree){
	

	if(binaryTree->lChild){
		ClearBiTree(binaryTree->lChild);
	}

	if(binaryTree->rChild){
		ClearBiTree(binaryTree->rChild);
	}

	if(binaryTree){
		free(binaryTree);
		binaryTree=NULL;
	}

}


void DestroyBiTree(BinaryTree * binaryTree){
	if(binaryTree){
		ClearBiTree(binaryTree);
	}
	binaryTree=NULL;
}

boolean BiTreeEmpty(BinaryTree * binaryTree){
	if(binaryTree){
		return 1;
	}else{
		return 0;
	}
}

int BiTreeDepth(BinaryTree * binaryTree){
	int depth=0;
	int t1=0;
	int t2=0;
    
	if(binaryTree){
		depth=1;
	}else{
		return 0;
	}

	
	if((binaryTree->lChild==NULL)&&(binaryTree->lChild==NULL)){
		return depth;
	}else if(binaryTree->rChild==NULL){
		depth+=BiTreeDepth(binaryTree->lChild);
	}else if(binaryTree->lChild==NULL){
		depth+=BiTreeDepth(binaryTree->rChild);
	}else{
		t1=BiTreeDepth(binaryTree->lChild);
		t2=BiTreeDepth(binaryTree->rChild);
		depth+=(t1>t2?t1:t2);
	}

	return depth;
}

Node * Root(BinaryTree * binaryTree){
	return binaryTree;
}

Item Value(BinaryTree * binaryTree,Node * e){
	return e->data;
}

void Assign(BinaryTree * binaryTree,Node * e,Item new_data){
	e->data=new_data;
}

Node * Parent(BinaryTree * binaryTree,Node * e){
	if(e==Root(binaryTree)){
		return NULL;
	}

	if(binaryTree->lChild==e||binaryTree->rChild==e){
		return binaryTree;
	}else{
		if(Parent(binaryTree->lChild,e)){
			return Parent(binaryTree->lChild,e);
		}else if(Parent(binaryTree->rChild,e)){
			return Parent(binaryTree->lChild,e);
		}else{
			return NULL;
		}
	}

	return NULL;
}

Node * LeftChild(BinaryTree * binaryTree,Node * e){
	return e->lChild;	
}

Node * RightChild(BinaryTree * binaryTree,Node * e){
	return e->rChild;	
}

Node * LeftSibling(BinaryTree * binaryTree,Node * e){
	if(Parent(binaryTree,e)){
		return LeftChild(binaryTree,Parent(binaryTree,e));
	}

	return NULL;

}


Node * RightSibling(BinaryTree * binaryTree,Node * e){
	if(Parent(binaryTree,e)){
		return RightChild(binaryTree,Parent(binaryTree,e));
	}

	return NULL;
}

boolean InsertChild(BinaryTree * binaryTree,Node * p,int LR,Node * node){
	boolean b=0;

	if(p!=NULL){
		if(LR==0){
			p->lChild=node;
			b=1;
		}else if(LR==1){
			p->rChild=node;
			b=1;
		}
	}

	return b;
}

boolean DeleteChild(BinaryTree * binaryTree,Node *p,int LR){
	boolean b=0;
	
	if(p!=NULL){
		if(LR==0){
			Node * temp=p->lChild;
			free(temp);
			p->lChild=NULL;			
			b=1;
		}else if(LR==1){
			Node * temp=p->rChild;
			free(temp);
			p->rChild=NULL;	
			b=1;
		}
	}

	return b;
}

void PreOrderTraverse(BinaryTree * binaryTree,void(*visit)()){

	if(binaryTree){
		visit(Value(binaryTree,Root(binaryTree)));
		PreOrderTraverse(binaryTree->lChild,visit);
		PreOrderTraverse(binaryTree->rChild,visit);
	}
}

void InOrderTraverse(BinaryTree * binaryTree,void(*visit)()){
	if(binaryTree){
		InOrderTraverse(binaryTree->lChild,visit);
		visit(Value(binaryTree,Root(binaryTree)));
		InOrderTraverse(binaryTree->rChild,visit);
	}
}

void PostOrderTraverse(BinaryTree * binaryTree,void(*visit)()){
	if(binaryTree){
		PostOrderTraverse(binaryTree->lChild,visit);
		PostOrderTraverse(binaryTree->rChild,visit);
		visit(Value(binaryTree,Root(binaryTree)));
	}
}

void LevelOrderTraverse(BinaryTree * binaryTree,void(*visit)()){
	if(binaryTree){
		
		NodeQueue * queue=NULL;
		queue=InitQueue();

		visit(binaryTree->data);
		if(binaryTree->lChild){
			EnQueue(queue,binaryTree->lChild);
		}

		if(binaryTree->rChild){
			EnQueue(queue,binaryTree->rChild);
		}

		while(IsQueueEmpty(queue)==1){
			Node * e=NULL;
			e=DeQueue(queue);
			visit(e->data);
			if(e->lChild){
				EnQueue(queue,e->lChild);
			}

			if(e->rChild){
				EnQueue(queue,e->rChild);
			}
		}

		DestroyQueue(queue);		
	}
}

void newLine(){
	printf("\n");
}

void scanAndchangeBiTree(BinaryTree * binaryTree,void(*change)()){
	if(binaryTree){
		change(binaryTree,binaryTree,Value(binaryTree,Root(binaryTree))+1);
		scanAndchangeBiTree(binaryTree->lChild,change);
		scanAndchangeBiTree(binaryTree->rChild,change);
	}
}

Node * CreateNode(){
	int d;
	Node * node;
	
	scanf("%d",&d);
	if(d=='\0'){
		node=NULL;
	}else{
		node=(Node *)malloc(sizeof(Node));
		node->data=d;
		node->lChild=NULL;
		node->rChild=NULL;
	}

	return node;

}