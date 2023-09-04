# include "project3B_deque.h"
// Create node and allocate dynamic memory
Node *newNode(void *data, size_t dataSize){
	Node *node = malloc(sizeof(Node));
	if (node == NULL){
		exit(EXIT_FAILURE);
	}
	
	
	node->data = malloc(dataSize);
			
	memcpy(node->data, data, dataSize);

	
		

	node->next = NULL;
	node->prev = NULL;

	
	if (node->data == NULL){
		exit(EXIT_FAILURE);
	}
	return node;
	
}

// Create deque and allocate dynamic memory
Deque *createDeque(){
	Deque *deque = malloc(sizeof(Deque));
	deque->count = 0;
	deque->front = NULL;
	deque->back = NULL;
	return deque;

}

// Insert item at the front of deque
void insertFront(Deque *deque, void *data, size_t dataSize){
	Node *new_node = newNode(data, dataSize);
	if (deque->front == NULL){
	
		deque->back = new_node;
		deque->front = new_node;
		

		
	}else{
		
		deque->front->prev = new_node;
		new_node->next = deque->front;
		
		deque->front = new_node;
		
	}
	
	deque->count++;
	
}


// Insert item at the back of deque
void insertBack(Deque *deque, void *data, size_t dataSize){
	Node *new_node = newNode(data, dataSize);
	if (deque->back == NULL){
		deque->back = new_node;
		deque->front=new_node;
		
		
	}else{
		deque->back->next = new_node;
		new_node->prev = deque->back;
		deque->back = new_node;
		
	}
	
	deque->count++;
}

// Remove item from the front of the deque
void removeFront(Deque *deque, void *data, size_t dataSize){
	
	memcpy(data, deque->front->data, dataSize);
	deque->count--;
	if (deque->count == 0){
		free(deque->front->data);
		free(deque->front);
		deque->back = NULL;
		deque->front = NULL;
	}else{
	Node *new_front = deque->front->next;
	free(deque->front->data);
	free(deque->front);
	deque->front = new_front;
	deque->front->prev = NULL;
	}
}

// Remove item from the back of the deque
void removeBack(Deque *deque, void *data, size_t dataSize){
	
	memcpy(data, deque->back->data, dataSize);
	deque->count--;
	if (deque->count == 0){
		free(deque->back->data);
		free(deque->back);
		deque->back = NULL;
		deque->front = NULL;
	}else{
	Node *new_back = deque->back->prev;
	free(deque->back->data);
	free(deque->back);
	deque->back = new_back;
	
	deque->back->next = NULL;
	}
	
}


// Free dynamic memory initialized for deque
void freeDeque(Deque *deque){
		free(deque);
}


// Print deque
void printDeque(Deque *deque, printData print){
	
	Node *cur_node = deque->front;
	
	for(int i = 0; i < deque->count; i++){
		print(cur_node->data);
	
	cur_node = cur_node->next;
	}
	printf("\n");
}



