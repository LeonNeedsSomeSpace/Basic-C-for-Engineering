//Type an array with 5 integers and print it out
//Array of digits gets reversed later

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	//Give your program the opportunity to take your input and print it out
	printf("Enter your integers here (MUST BE 5 INTEGERS! NO MORE, NO LESS!):\n");

	int random[5];   //Define a variable that accepts i as an integer

	for (int i = 0; i < 5; ++i) {
		scanf("%d", &random[i]); //Evaluate the input
	}

	printf("Your chosen array; \n"); 
	for (int i = 0; i < 4; i++) {
		printf("%d ", random[i]); //Print the first four integers
	}
	printf("%d\n\n", random[4]); //Print the last integer 

	//Now reverse the array

	int reverse; //Define a new variable that will store the values for the array but in reversed order 

	//Carry out reversal by storing each integer in the temporary variable
	for (int i = 0; i < 5 / 2; ++i) {
		reverse = random[i]; 
		random[i] = random[5 - 1 - i]; 
		random[5 - 1 - i] = reverse; 
	}

	//Print out the result

	//The array that was entered previously will now be printed out but in reverse order
	printf("Reversed array: "); 

	for (int i = 0; i < 4; i++) {
		printf("%d ", random[i]); 
	}
	printf("%d", random[4]); 


	return 0; 
}
