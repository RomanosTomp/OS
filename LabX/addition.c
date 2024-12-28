#include <stdio.h>

//Function to add three integers 
int add( int *a, int *b, int *c){
	return *a + *b + *c ;
}


int main(){
	int num1, num2, num3 ;

	printf("Enter 3 integers:");
	scanf("%d %d %d", &num1, &num2, &num3);

	int sum = add(&num1, &num2, &num3);


	printf("\nThe sum is : %d\n", sum);

	return 0;
}

