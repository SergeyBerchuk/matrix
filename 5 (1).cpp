Берчук Сергей УТС / б 22 - 2 - о вариант 1
//задание 1
#include <iostream>
#include <limits.h>
using namespace std;
int main() {
	const int n = 3, m = 4;
	int a[n][m] = { {1, 2, -3, 4}, {5, 6, 7, 8}, {-9, 10, 11, 12} };
	int minEl = INT_MAX;
	int minR = -1, minCol = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < minEl) {
				minEl = a[i][j];
				minR = i;
				minC = j;
			}
		}
	}

	if (minR != -1 && minC != -1) {
		for (int j = 0; j < m; j++) {
			a[minR][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

//задание 5

#include <iostream>
using namespace std;

const int N = 4;

int main() {
	int matrix[N][N] = { {2, 3, 1, 4}, {5, 9, 7, 6}, {8, 3, 2, 1}, {4, 7, 3, 8} };

	// Переставить минимальные элементы в строках с элементом на главной диагонали
	for (int i = 0; i < N; i++) {
		// Найти минимальный элемент в строке
		int min_element = matrix[i][0];
		int min_index = 0;
		for (int j = 1; j < N; j++) {
			if (matrix[i][j] < min_element) {
				min_element = matrix[i][j];
				min_index = j;
			}
		}

		// Если минимальный элемент находится на главной диагонали, ничего не делаем
		if (i == min_index) {
			continue;
		}

		// В противном случае, меняем минимальный элемент соответствующей диагональный элементом
		swap(matrix[i][min_index], matrix[min_index][i]);
	}

	// Вывести преобразованную матрицу
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}


//задание 7
#include <iostream>
using namespace std;
int main() {
	const int n = 5;
	int a[2][n] = { {5, 3, 2, 6, 7}, {3, 2, 6, 1, 5} };
	int maxWind = a[1][0];
	int maxWindIndex = 0;
	for (int j = 1; j < n; j++) {
		if (a[1][j] > maxWind) {
			maxWind = a[1][j];
			maxWindIndex = j;
		}
	}
	int maxRainIndex = 0;
	for (int j = 1; j < n; j++) {
		if (a[0][j] > a[0][maxRainIndex]) {
			maxRainIndex = j;
		}
	}
	if (maxRainIndex == maxWindIndex) {
		cout << "There was a hurricane." << endl;
	}
	else {
		cout << "There was no hurricane." << endl;
	}
	return 0;
}

// задание 9а
#include <iostream>
#include <fstream>
using namespace std;
const int ROWS = 3;
const int COLS = 3;
int main() {
	int image[ROWS][COLS];
	int choice;
	cout << "Выберите способ заполнения матрицы: \n";
	cout << "1 - ввод с клавиатуры\n";
	cout << "2 - чтение из файла\n";
	cin >> choice;

	if (choice == 1) {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				cout << "Введите значения пикселя [" << (i + 1) << "][" << (j + 1) << "]: ";
				cin >> image[i][j];
			}
		}
	}
	else if (choice == 2) {
		ifstream file("image.txt");
		if (file.is_open()) {
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					file >> image[i][j];
				}
			}
			file.close();
		}
		else {
			cout << "Не удалось открыть файл.\n";
			return 0;
		}
	}
	else {
		cout << "Некорректный выбор.\n";
		return 0;
	}
	cout << "\nИзображение:\n";
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << image[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}