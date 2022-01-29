#include <iostream>
#include <ctime>
using namespace std;

void inic(int* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 1000;
	}
}
void print(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void sortBo(int* array, int size) {
	int eq = 0;
	int sw = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[j] < array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sw++;
			}
			eq++;
		}
	}
	cout << "For: " << size << " Equals Bo: " << eq << endl;
	cout << " Swap Bo: " << sw<< endl;
}

void exch(int i, int j, int*array) {
	int tmp;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void sortQu(int left, int right, int* array, int &eqQ, int &swQ) {

	int i, j, m, h;
	i = left;
	j = right;
	m = array[(i + j) / 2];
	while (i <= j) {
		while (array[i] < m) i++;
		while (array[j] > m) j--;
		if (i <= j) {
			exch(i, j, array);
			i++;
			j--;
			swQ++;;
		}
		eqQ++;
	}
	if (left < j)
		sortQu(left, j, array, eqQ, swQ);
	if (i < right)
		sortQu(i, right, array, eqQ, swQ);
}



int main() {
	srand(time(0));
	int size = 100;
	for (; size <= 1000; size += 100) {
		int eqQ = 0;
		int swQ = 0;
		int* array = new int[size];
		inic(array, size);
		print(array, size);
		sortBo(array, size);
		print(array, size);
		inic(array, size);
		print(array, size);
		sortQu(0, (size - 1), array, eqQ, swQ);
		print(array, size);
		cout << "For: " << size <<" Equals Q: " << eqQ << endl;
		cout << "Swap Q: " << swQ << endl;
	}
}