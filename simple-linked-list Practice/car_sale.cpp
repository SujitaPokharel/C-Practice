#include<stdio.h>

struct SALE_RECORD
{
	int total;
	int month[12];
};

typedef struct SALE_RECORD saleRecord;

void creatRecord(SALE_RECORD *car);
void bubbleSort(SALE_RECORD *record);
void printRecord(SALE_RECORD saleImage);

int main()
{
	saleRecord myRecord;
	creatRecord(&myRecord);
	printRecord(myRecord);
	bubbleSort(&myRecord);
	printRecord(myRecord);
	return 0;
}

void creatRecord(SALE_RECORD *car)
{
	int i, sum = 0;
	printf("please input the sale of each month from Jan to Dec:\n");
	for (i=0; i<12; i++) {
		scanf("%d",&(car->month[i]));
		sum = sum + car->month[i];
	}
	car->total = sum;
}

void bubbleSort(saleRecord *record)
{
	int *sale = &(record->month[0]);
	int i, j;
	int temp;
	for (i=0; i<12; i++) {
		for (j=i+1; j< 12; j++)
			if ( sale[i] > sale[j]) {
				temp = sale[i];
				sale[i] = sale[j];
				sale[j] = temp;
			}
	}
}

void printRecord(saleRecord saleImage)
{
	int i;
	printf("The total sale is %d:\n", saleImage.total);
	printf("The monthly sale records are:");
	for (i=0; i<12; i++)
		printf("%d ", saleImage.month[i]);
	printf("\n");
}