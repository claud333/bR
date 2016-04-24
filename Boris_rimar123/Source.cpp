
#include <stdio.h.>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

FILE*f;
struct kmn
{
	int x;
	int y;

}*a;

int openfile(char*filename)
{
	if ((f = fopen(filename, "r")) == NULL)
	{
		printf("Ошибка открытия файла\n");
		system("pause");
		exit(0);
	}

	int a;
	int kol = 0;
	while (!feof(f))
	{
		fscanf(f, "%d", &a);
		kol++;
	}
	fclose(f);
	return kol / 2;
}
void scan(kmn *a, char*filename)
{
	f = fopen(filename, "r");
	int i = 0;
	while (!feof(f))
	{
		fscanf(f, "%d", &a[i].x);
		fscanf(f, "%d", &a[i].y);
		i++;
	}
	fclose(f);
}
double maxR(kmn *a, int razm)
{
	double max = 0;
	for (int i = 1; i < razm; i++)
	{
		if (max < (sqrt(pow(a[i].x*a[i].x - a[i - 1].x*a[i - 1].x, 2) + (pow(a[i].y*a[i].y - a[i - 1].y*a[i - 1].y, 2)))))
		{
			max = (sqrt(pow(a[i].x*a[i].x - a[i - 1].x*a[i - 1].x, 2) + (pow(a[i].y*a[i].y - a[i - 1].y*a[i - 1].y, 2))));
		}
	}
	return max;

}
double minR(kmn *a, int razm)
{
	double  min = 9999;
	for (int i = 1; i < razm; i++)
	{
		if (min >(sqrt(pow(a[i].x*a[i].x - a[i - 1].x*a[i - 1].x, 2) + (pow(a[i].y*a[i].y - a[i - 1].y*a[i - 1].y, 2)))))
		{
			min = (sqrt(pow(a[i].x*a[i].x - a[i - 1].x*a[i - 1].x, 2) + (pow(a[i].y*a[i].y - a[i - 1].y*a[i - 1].y, 2))));
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
	int razm = openfile(filename);
	a = new kmn[razm];
	scan(a, filename);
	printf("Минимальное расстояние = %f\nМаксимальное расстояние = %f\n", minR(a, razm), maxR(a, razm));
	system("pause");
}