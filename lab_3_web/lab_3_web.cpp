// lab_3_web.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Triangle.h"

using namespace std;

Triangle** readTrianglesFromBrowser(int num, char **arguments);

char** takeArguments(char* string, char* splitter);

int ArgumentsCount(char *string, char splitter);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Content-type:text/plain\n\n";

	char *queryString = getenv("QUERY_STRING");
	/*char *queryString = new char[256]{ NULL };
	strcat(queryString, "1,3,4,90,1,3,1,4,1,2,2");*/

	char **arguments = takeArguments(queryString, ",");

	int num = atoi(arguments[0]),
		count = ArgumentsCount(queryString, ',');

	Triangle** triangles = readTrianglesFromBrowser(num, arguments + 1);

	cout << "Введите команду:\n "
		<< "1 - Увеличить угол\n "
		<< "2 - Уменьшить угол\n "
		<< "3 - Длина бисексрис\n "
		<< "4 - Длина отрезков, на которые бисектриса делит сторону\n "
		<< "5 - Величина углов\n";

	int pointer = num * 3 + 1;

	while (pointer < count) {
		int index = atoi(arguments[pointer++]);

		index--;

		if (index < 0 || index >= num) {
			cout << "Неправильный номер!";
			continue;
		}

		char *comand = arguments[pointer++];


		if (strcmp(comand, "1") == 0) {
			int number = atoi(arguments[pointer++]);


			if (number == 0)
			{
				cout << "Неверно!";
				number = 1;
			}

			triangles[index]->increaseAngle(number);

			cout << triangles[index]->getAngles()[0] << endl;

		}

		if (strcmp(comand, "2") == 0) {
			int number = atoi(arguments[pointer++]);


			if (number == 0)
			{
				cout << "Неверно!";
				number = 1;
			}


			triangles[index]->decreaseAngle(number);

			cout << triangles[index]->getAngles()[0] << endl;
		}

		if (strcmp(comand, "3") == 0) {
			double *bisectors = triangles[index]->getBisector();
			for (int i = 0; i < 3; i++)
			{

				cout << "Длинна бисектрисы " << i + 1 << " :" << bisectors[i] << endl;
			}

		}

		if (strcmp(comand, "4") == 0){
			double **side = triangles[index]->getSidesByBisector();
			for (int i = 0; i < 3; i++)
			{
				cout << "Сторона: " << i + 1 << endl;
				for (int j = 0; j < 2; j++)
				{
					cout << "Длина отрезка: " << side[i][j] << endl;
				}

			}

		}

		if (strcmp(comand, "5") == 0){
			double *angles = triangles[index]->getAngles();
			for (int i = 0; i < 3; i++)
			{

				cout << "Величина угла " << i + 1 << " : " << angles[i] << endl;
			}
		}
	}

	return 0;
}
Triangle** readTrianglesFromBrowser(int num, char **arguments) {

	Triangle **result = new Triangle*[num];

	for (int i = 0; i < num * 3; i += 3) {
		double side1 = atoi(arguments[i]),
			side2 = atoi(arguments[i + 1]),
			angle = atoi(arguments[i + 2]);

		result[i / 3] = new Triangle(side1, side2, angle);
	}

	return result;
}

int ArgumentsCount(char *string, char splitter) {
	int k = 1;

	for (int i = 0; i < strlen(string); i++)
		if (string[i] == splitter)
			k++;

	return k;
}

char** takeArguments(char* string, char* split) {
	int count = ArgumentsCount(string, split[0]);
	int j = 0;

	char *copyString = new char[256]{ NULL };
	strcpy(copyString, string);

	char** arguments = new char*[count] { NULL };
	for (int i = 0; i < count; i++)
		arguments[i] = new char[10]{ NULL };

	char *p = strtok(copyString, split);

	while (p != NULL) {
		strcpy(arguments[j], p);
		p = strtok(NULL, split);

		j++;
	}

	return arguments;
}

