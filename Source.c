#define _CRT_SECURE_NO_WARNINGS

#define N 3

/*Libraries*/
#include <stdio.h>
#include <math.h>


/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

/* Declarations of other sub-functions */

int sumDigits(int);
int checkID(int);
int sumLongestArithmeticList(int);
int numberLength(int);
int rotateNumber(int, int);

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-%d : ", N);
				scanf("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */

void Ex1() {
	int id = 0, answer = 0;
	printf("please enter your id: ");
	scanf("%d", &id);
	answer = checkID(id);
	if (answer) {
		printf("Your id is a correct id.\n");
	}
	else {
		printf("Your id is incorrent.\n");
	}

}

void Ex2() {
	int size = 0, answer = 0;
	printf("please enter the arithmetic list size: ");
	scanf("%d", &size);
	answer = sumLongestArithmeticList(size);
	printf("The sum of the longest sequence arithmetic list is: %d.\n", answer);
}

void Ex3() {
	int number = 0, spins = 0, answer = 0;
	printf("please enter the number and the amount of spins: ");
	scanf("%d%d", &number, &spins);
	answer = rotateNumber(number, spins);
	printf("The number %d after %d spins is: %d.\n", number, spins, answer);
}

/* Sub-Function definitions */

int sumDigits(int num) {
	/*Write Code Here!*/
	/* assume:  n>=0 */
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}


int checkID(int id) {
	/*Write Code Here!*/
	int sum = 0, place = 0;
	while (id > 0) {
		sum += sumDigits(id % 10 * (place % 2 + 1));
		id /= 10;
		place++;
	}
	if (place > 9) return 0; // more than 9 digits is not an ID
	return sum % 10 == 0 ? 1 : 0;
}


int sumLongestArithmeticList(int n) {
	int diff = 0;
	int max_sum, sum;
	int num, prev;
	int max_len = 0, len, i;

	if (n == 0) return 0; // edge case, empty set
	printf("enter %d integers:\n", n);
	// first number
	scanf("%d", &num);
	max_sum = num;
	sum = num;
	len = 1;

	for (i = 1; i < n; i++) {
		prev = num;
		scanf("%d", &num);
		if ((num - prev) == diff) {
			sum += num;
			len += 1;
		}
		else {
			sum = prev + num;
			len = 2;
			diff = num - prev;
		}
		if (len == max_len && sum > max_sum) max_sum = sum;

		if (len > max_len) {
			max_sum = sum;
			max_len = len;
		}
	}
	return max_sum;
}



int numberLength(int num) {
	/*Write Code Here!*/
	int numdigits = 0;
	if (num < 10)
		return 1;
	while (num > 0)
	{
		numdigits++;
		num /= 10;
	}
	return numdigits;
}
int rotateNumber(int num, int spins) {
	int numLen = numberLength(num);
	spins %= numLen;
	return num / (int)pow(10, spins) + num % (int)pow(10, spins) * (int)pow(10, numLen - spins);
}

/* ------------------- */