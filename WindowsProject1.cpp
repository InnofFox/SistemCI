#include "stdafx.h"
#include <locale>
#include <cstdlib>
#include <cstring>
#include <Windows.h>
#include <iostream>
using namespace std;
struct Disk
{
	char title[50];
	char director[50];
	char genre[25];
	int duration;
	int year;
	int IMDB;
};
const int N = 5;
Disk film[N]; // создаем массив из N структур Disk
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < N; i++)
	{
		printf("\n\nВведите данные для фильма №%d\n", i + 1);
		printf(" Название - ");
		SetConsoleCP(1251);
		gets_s(film[i].title, 49);
		SetConsoleCP(866);
		printf(" Режисёр - ");
		SetConsoleCP(1251);
		gets_s(film[i].director, 49);
		SetConsoleCP(866);
		printf(" Жанр - ");
		SetConsoleCP(1251);
		gets_s(film[i].genre, 49);
		SetConsoleCP(866);
		printf(" Длительность в минутах - ");
		scanf_s("%d", &film[i].duration);
		getchar();
		printf(" Год выпуска - ");
		scanf_s("%d", &film[i].year);
		getchar();
		printf(" Рейтинг - ");
		scanf_s("%d", &film[i].IMDB);
		getchar();
	}
	char find_director[50];
	printf("\n\n Введите Режисёра - ");
	SetConsoleCP(1251);
	gets_s(find_director, 49);
	SetConsoleCP(866);
	bool found = false;
	int p = 0;
	char *j;
	j = film[0].title;
	for (int i = 0; i < N; i++)
	{
		if (strcmp(film[i].director, find_director) == 0)
		{
			found = true;

			if (p < film[i].year)
			{
				p = film[i].year;
				j = film[i].title;
			}
		}
	}
	if (!found) {

		printf(" \n======== Неверное имя фильма ==========\n");
	}
	else
	{
		printf("\n======== Самый поздний вышедший фильм ==========\n");
		printf(" Название: ");

		cout << j;
		
	}
	char find2_genre[25];
	printf("\n\n Введите Жанр - ");
	SetConsoleCP(1251);
	gets_s(find2_genre, 24);
	SetConsoleCP(866);
	bool ex = false;
	found = false;

	char *y;
	y = film[0].title;
		for (int i = 0; i < N; i++)
	{
		if (strcmp(film[i].genre, find2_genre) == 0)
		{
			found = true;
			if (film[i].IMDB > 80)
			{
				ex = true;
				printf(" Фильм с рейтингом свыше 80: ");
				puts(film[i].title);
			
			}
		}
	}
		if (!found) {

			printf(" Фильма с таким названием нет\n");
		}
		else {


			if (!ex)
					{

				printf(" Фильма такого жанра с рейтингом IMDB>80 нет\n");
					}
			}
		for (int i = 0; i < N; ++i) {
			printf("\n\nФильм №%d", i + 1);
			printf("\n Название фильма:");
			cout <<  film[i].title;
			printf("\n Режисёр");
			cout << film[i].director;
			printf("\n Жанр");
			cout << film[i].genre;
			printf("\n Длительность в минутах:");
			cout << film[i].duration;
			printf("\n Год выпуска:");
			cout << film[i].year;
			printf("\n Рейтинг");
			cout << film[i].IMDB;
		}
	system("pause");
	return 0;
}
