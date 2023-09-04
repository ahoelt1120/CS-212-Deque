# include "project3B_deque.h"

int main(){
	Deque *long_deque = createDeque();
	Deque *string_deque = createDeque();
	char *input = (char *)malloc(sizeof(char)*MAX_STR_LEN);
	size_t str_size = sizeof(char)*MAX_STR_LEN;
	size_t long_size = sizeof(long int)*2;
	long int *long_ptr = (long int *)malloc(sizeof(long int)*2);
	do{
		
		printf("Please enter an integer or a string (empty to exit): \n");
		fgets(input, sizeof(char)*100, stdin);
		
		
		if (input[0] != '\n'){
			
			for(int i = 0; i < MAX_STR_LEN; i++){
				if (input[i] == '\n'){
					input[i] = 0;
					break;
				}
			}
			char * endPtr;
			long int num;
			
			
			num = strtol(input, &endPtr, 10);
			*long_ptr = num;
				
			if (*endPtr != 0){
			  	printf("You entered the string: \"%s\"\n", input);
				if (string_deque->count % 2 == 0){
				insertFront(string_deque, input, str_size);
				}else{
				insertBack(string_deque, input, str_size);
				}
			}else{
			  	printf("You entered the number: %ld\n", num);
				
				if (long_deque->count % 2 == 0){
					insertFront(long_deque, long_ptr, long_size);
				}else{
					insertBack(long_deque, long_ptr, long_size);
				}
				}
			
			}else{
				
				break;
			}
		} while (1);
	free(input);
	free(long_ptr);	
	
	

	printf("\nPrinting string deque\n");
	void print_str(void *s){
		printf("%s ", (char *)s);}
	printDeque(string_deque, &print_str);

	printf("\nPrinting long deque\n");
	void print_long(void *d){
		printf("%ld ", *(long int *)d);}
	printDeque(long_deque, &print_long);



	printf("\nRemoving string deque data using count\n");
	int str_deque_size = string_deque->count;
	char * str_point = (char *)malloc(str_size);
	
	for (int i = 0; i < str_deque_size; i++){
		if(i % 2  != 0){
			
			removeFront(string_deque, str_point, str_size);
			printf("Removing %s\n", str_point);
		}else{
			removeBack(string_deque, str_point, str_size);
			printf("Removing %s\n", str_point);
			
			
			}
		}
	free(str_point);
	printf("\nRemoving long deque data using count\n");
	int long_deque_size = long_deque->count;
	long int *long_point = (long int*)malloc(long_size);
	
	for (int i = 0; i < long_deque_size; i++){
		if(i % 2  != 0){
			
			removeFront(long_deque, long_point, long_size);
			printf("Removing %ld\n", *long_point);
		}else{
			removeBack(long_deque, long_point, long_size);
			printf("Removing %ld\n", *long_point);
			
			
			}
		}
	free(long_point);
	freeDeque(string_deque);
	freeDeque(long_deque);
	}

	
