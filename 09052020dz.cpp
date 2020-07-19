/*
Завдання
Написати програму, яка буде виводити інформацію про країну і про столицю цієї країни.
Країна про яку потрібно вивести інформацію визначається за допомогою констант.
Для цього потрібно :
1) Створити структуру, яка буде містити інформацію про столицю країни (мінімум 4 - поля);
2) Створити структуру, яка буде містити інформацію про країну (мінімум 5-ть полів)
і одним з цих полів повинна бути структура столиця.
3) Створити мінімум 3 об'єкти (змінні) структури країни і заповнити їх інформацією.
4) У програмі має робитися перевірка, чи є певна константі країна, якщо вона встановлена, то робити перевірку,
якій країні відповідає дана константа і виводити інформацію про дану країну.
Потім робити перевірку чи визначена константа столиця, якщо визначена то виводити інформацію про столицю цієї країни.
І так для всіх країн.
5) Потрібно створити константу для кожної країни, які ми описали в об'єктах структури.
Наприклад (# define USA 1 i # define UA 2 і т.д.).
6) Потрібно визначити дві константи країна і столиця. Константі країна потрібно надати значення відповідної країни.
А константу столиця потрібно просто визначити.
наприклад: # define USA 1 # define UA 2 # define COUNTRY UA # define CAPITAL
Умови до завдань:
1. Для визначення констант використовувати директиву # define
2. Щоб перевірити визначена константа чи ні використовувати директиви # ifdef - # endif; # ifndef - # endif
3. Для визначення частини коду, яка повинна компілюватися або не повинна використовувати - #if #else #endif
*/
#include <iostream>
#include <Windows.h>
using namespace std;
#define UA
#define UACapital
//#define USA
//#define USACapital
#define NO
#define NOCapital
struct capital // столиця
{
	char name[50];
	double area;
	int date_of_foundation;
	int population;
};
struct country // країна
{
	char name[50];
	char phone_code[50];
	int country_area;
	int population_of_the_country;
	char currency[25];
	capital cptl; // столиця
};
void PrintCptl(capital cptl) {
	cout << "Назва столиці - \t" << cptl.name << endl;
	cout << "Площа - \t\t" << cptl.area << endl;
	cout << "Дата заснування - \t" << cptl.date_of_foundation << endl;
	cout << "Популяція - \t\t" << cptl.population << endl << endl;
}
void PrintCntrs(country cntrs) {
	cout << "Назва країни - \t\t" << cntrs.name << endl;
	cout << "Телефонний код - \t" << cntrs.phone_code << endl;
	cout << "Площа - \t\t" << cntrs.country_area << endl;
	cout << "Популяція - \t\t" << cntrs.population_of_the_country << endl;
	cout << "Валюта - \t\t" << cntrs.currency << endl << endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
#ifdef UA
	country ua{ "Україна", "+380", 603628, 48457000, "Гривня (UAH)", { "Київ", 826.35, 482, 3703100 } };
	PrintCntrs(ua);
#ifdef UACapital
	PrintCptl(ua.cptl);
#endif 
#endif 

#ifdef USA
	country usa{ "Сполучені Штати Америки", "+1", 9826675, 308745538, "Долар США (USD)", { "Вашигтон", 177, 1790, 705749 } };
	PrintCntrs(usa);
#ifdef USACapital
	PrintCptl(usa.cptl);
#endif 
#endif 

#ifdef NO
	country no{ "Норвегія", "+47", 385207, 5367580, "Норвезька крона (NOK)", { "Осло", 454, 1048, 673469 } };
	PrintCntrs(no);
#ifdef NOCapital
	PrintCptl(no.cptl);
#endif 
#endif 
}
