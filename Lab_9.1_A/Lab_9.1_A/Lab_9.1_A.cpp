#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <stdarg.h>
#include <conio.h>
#include <string>

using namespace std;

// Перерахування спеціальностей
enum Spec { РІ, КН, ПМ };
const char* strSpec[] = { "РІ", "КН", "ПМ" };

// Функція для конвертації значення типу Spec у відповідний рядок
const char* Convert(Spec c) {
	return strSpec[c];
}

// Структура для збереження інформації про студента
struct Student {
	string prizv;   // Прізвище студента
	int kurs;       // Курс студента
	Spec spec;      // Спеціальність
	unsigned fis;   // Оцінка з фізики
	unsigned math;  // Оцінка з математики
	unsigned infor; // Оцінка з інформатики
};

// Функція для створення масиву студентів
void Create(Student* s, const int n) {
	int p;
	for (int i = 0; i < n; i++) {
		cout << "Student # " << i + 1 << ":" << endl;
		cin.get(); // Очищення потоку
		cin.sync();

		cout << "Surname: "; getline(cin, s[i].prizv); // Введення прізвища
		cout << "Course: "; cin >> s[i].kurs;         // Введення курсу
		cout << "Spec (0 - RI, 1 - KN, 2 - PM): ";   // Вибір спеціальності
		cin >> p;
		s[i].spec = (Spec)p;
		cout << "Scores" << endl;
		cout << "Physics: "; cin >> s[i].fis;       // Введення оцінки з фізики
		cout << "Math: "; cin >> s[i].math;         // Введення оцінки з математики
		cout << "Informatics: "; cin >> s[i].infor; // Введення оцінки з інформатики
	}
}

// Функція для виведення таблиці студентів
void Table(Student* s, const int n) {
	cout << fixed;
	cout << "|" << setw(30) << "Student" << setw(28) << "   |" << endl;
	cout << "-----------------------------------------------------------" << endl;

	cout << "|" << setw(10) << "Surname" << "  |  "
		<< setw(3) << "Course" << "  |  "
		<< setw(3) << "Spec" << "  |"
		<< setw(3) << "Phys" << "  |  "
		<< setw(3) << "Meth" << "  |  "
		<< setw(3) << "Infor" << "  |" << endl;

	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		// Виведення даних про кожного студента
		cout << "|  " << setw(2); cout << s[i].prizv << "  |  " << setw(5);
		cout << s[i].kurs << "  |" << setw(5);
		cout << Convert(s[i].spec) << "  |  " << setw(5);
		cout << s[i].fis << "  |" << setw(6);
		cout << s[i].math << "  |" << setw(6);
		cout << s[i].infor << "  |" << setw(6) << endl;
		cout << "-----------------------------------------------------------" << endl;
	}
}

// Функція для підрахунку студентів, у яких всі оцінки > 3
int Count1(Student* s, const int n) {
	int c = 0; // Лічильник
	for (int i = 0; i < n; i++) {
		if (s[i].fis > 3 && s[i].math > 3 && s[i].infor > 3) // Перевірка умов
			c++;
	}
	return c; // Повернення результату
}

// Функція для підрахунку відсотка студентів із середнім балом < 4
void Count2(Student* s, const int n) {
	double e = 0, proc;
	for (int i = 0; i < n; i++) {
		if ((s[i].fis + s[i].math + s[i].infor) / 3 < 4) // Перевірка середнього бала
			e++;
	}
	proc = (e / n) * 100; // Обчислення відсотка
	cout << "% srudent with awerage score 4: " << setprecision(2) << proc << endl; // Виведення результату
}

int main() {
	SetConsoleCP(1251);        // Налаштування кодування для вводу
	SetConsoleOutputCP(1251); // Налаштування кодування для виводу

	int n, c; // Кількість студентів та результат підрахунку
	cout << "N: "; cin >> n; // Введення кількості студентів

	Student* s = new Student[n]; // Динамічне створення масиву студентів

	Create(s, n); // Виклик функції створення
	Table(s, n);  // Виклик функції виведення таблиці
	c = Count1(s, n); // Виклик функції підрахунку
	cout << "Students without 3: " << c << endl; // Виведення кількості студентів без оцінок <= 3
	Count2(s, n); // Виклик функції підрахунку відсотка

	delete[] s; // Видалення масиву з пам'яті
	system("pause"); // Очікування дії від користувача
	return 0; // Завершення програми
}
