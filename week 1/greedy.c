/**
 * Created CS50 Week1.
 * User: Evgeniy Ryzhyk
 * Date: 20.09.2016
 */
#include <cs50.h>
#include <stdio.h>
#include <math.h>

void getDelivery(float floatNumber);

int valueTfive = 25;
int valueTen = 10; 
int valueFive = 5;
int valueOne = 1;
int valueCoins = 0;

int main(void) 
{
	float floatNumber;
	do {
		//ask user
		printf("O hai! How much change is owed? ");
		printf ("\n");
		//take answer
		scanf("%f", &floatNumber);
	} while (floatNumber < 0.0);

	getDelivery(floatNumber);
}

//response processing
void getDelivery(float floatNumber) 
{
	int num = roundf(floatNumber * 100);
	while (num > 0) {
		while (num >= valueTfive) {
			num -= valueTfive;
			valueCoins += 1;
		} 
		while (num >= valueTen) {
			num -= valueTen;
			valueCoins += 1;
		} 
		while (num >= valueFive) {
			num -= valueFive;
			valueCoins += 1;
		} 
		while (num >= valueOne) {
			num -= valueOne;
			valueCoins += 1;
		}
	}

	printf("%i\n", valueCoins);
}