
#include <stdio.h.>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
struct kmn
{
	int x;
	int y;
	double *distance;
};


kmn* scan(char*filename,int &size)
{
	FILE *f;
	if (NULL == (f = fopen(filename, "r")))
	{
		printf("error open\n");
		system("pause");
		exit(0);
	}
	
	kmn *a=NULL;
	size = 0;
	while (!feof(f))
	{
		a = (kmn*)realloc(a,sizeof(kmn)*(size + 1));
		fscanf(f, "%d", &a[size].x);
		fscanf(f, "%d", &a[size].y);
		size++;
	}
	fclose(f);
	for (int i = 0;i < size;i++)
	{
		a[i].distance = (double*)malloc(size - 1);
		for (int j = 0;j < size;j++)
		{
			a[i].distance[j] = sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2));
		}
	}
	return a;
}
double maxR(kmn *a, int razm)
{
	double max = a[0].distance[0];
	for (int i = 0;i < razm;i++)
	{

		for (int j = 0;j < razm;j++)
		{
			if (a[i].distance[j] > max) { max = a[i].distance[j]; }
		}
	}
	return max;
}
double minR(kmn *a, int razm)
{
	double min = a[0].distance[0];
	for (int i = 0;i < razm;i++)
	{
		for (int j = 0;j < razm;j++)
		{
			if (a[i].distance[j] < min) { min = a[i].distance[j]; }
		}
	}

	return min;
}
void main()
{
	setlocale(0, "RUS");

	char filename[30];
	printf("Введите имя файла\n");
	scanf("%s", filename);
	int i;
	kmn *a=scan(filename,i);

	printf("Минимальное расстояние = %f\nМаксимальное расстояние = %f\n", minR(a,i), maxR(a,i));
	system("pause");
}