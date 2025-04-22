//Create a temperature converter that converts Temperature from one unit to another
//It can convert Celsius into Kelvin, Fahrenheit to Kelvin, Kelvin to Celsius as well as Kelvin to Fahrenheit 
//In Thermodynamics or Material Science, Kelvin is used rather than Celsius because it represents the absolute scale from absolute zero and onwards

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {

	float temp; //Define a variable that accepts temp as a float
	char unit; //Define a variable that accepts unit inputs 

	printf("Your input must contain a unit. Use C for celsius, F for Fahrenheit and K for Kelvin\n"); 
	printf("Temperature input here:  \n"); 
	scanf("%f %c", &temp, &unit); //Evaluate the input for both the digits as well as the unit (letter) 

	//Create conditions for conversion
	//Convert Celsius to Kelvin
	if (unit == 'C' || unit == 'c') { 
		float kelvin = temp + 273.15;
		printf("%.2fC = %.2fK\n", temp, kelvin); 
	}
	//Convert Fahrenheit to Kelvin
	else if (unit == 'F' || unit == 'f') { 
		float kelvin = (temp - 32) * 5 / 9 + 273.15; 
		printf("%.2fF = %.2fK\n", temp, kelvin); 
	}
	//Convert Kelvin to Celsius and Fahrenheit 
	else if (unit == 'K' || unit == 'k') { 
		float celsius = temp - 273.15; 
		float fahrenheit = (temp - 273.15) * 9 / 5 + 32; 
		printf("%.2fK = %.2fC\n", temp, celsius); 
		printf("%.2fK = %.2fF\n", temp, fahrenheit); 
	}
	//For any input that doesn't fit the requirements, an error message will pop up
	else {
		printf("Invalid unit. Use C for Celsius, F for Fahrenheit and K for Kelvin.\n"); 
	} 

	return 0; 
}
