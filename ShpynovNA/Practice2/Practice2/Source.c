#include <stdio.h>
#include <stdlib.h>
int bigger(max, k)
{
	time_t t;
	int n;
	srand((unsigned)time(&t));
	n = (rand() % (max - k)) + k;
	return n;
}
int smaller(min, k)
{
	time_t t;
	int n;
	srand((unsigned)time(&t));
	n = (rand() % (k - min)) + min;
	return n;
}
void A()
{
	time_t t;
	int a, n, i = 0;
	srand((unsigned)time(&t));
	n = rand() % 1000;
	printf("enter your first guess: ");
	do {
		i++;
		scanf("%d", &a);
		if ((a == n) && (a>0) && (a<1000))
		{
			printf("That's it! Attemts count: %d", i);
			return 0;
		}
		else if ((a < n) && (a > 0) && (a < 1000))
		{
			printf("bigger... ");
		}
		else if ((a > n) && (a > 0) && (a < 1000))
		{
			printf("smaller... ");
		}
		int a;
	} while (1);
}
void B()
{
	time_t t;
	char ch;
	int n = 0, a, i = 0, k = 0, min = 0, max = 1000;
	srand((unsigned)time(&t));
	printf("enter one natural number to 1000 from 0: ");
	do {
		scanf("%d", &a);
	} while ((a > 1000) || (a < 0));
	n = rand() % 1000;
	do {
		i++;
		printf("is it %d", n);
		printf("? ");
		do {
			scanf("%c", &ch);
		} while ((ch != 'y') && (ch != 'b') && (ch != 's'));
		if (ch == 'y') {
			printf("hooray! it's %d", n);
			printf("! Total attemts count: %d", i);
			return 0;
		}
		else if (ch == 'b') {
			min = n + 1;
			max--;
			n = bigger(max, n);
		}
		else {
			max = n - 1;
			min++;
			n = smaller(min, n);
		}
	} while (1);
}
int main()
{
	char a;
	printf("choose game, A or B: ");
	do {
		scanf("%c", &a);
	} while ((a != 'A') && (a != 'B'));
	if (a == 'A') 
	{
		A();
	}
	else
	{
		B();
	}
	return 0;
}