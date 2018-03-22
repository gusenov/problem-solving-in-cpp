#include "sort.hpp"

bool isNonDesc(int* arr, size_t n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

bool isNonDesc(float* arr, size_t n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

// Перезагрузка функций обмена значений двух переменных:
inline void swap(int* a, int* b) { int tmp = *a; *a = *b; *b = tmp; }
inline void swap(float* a, float* b) { float tmp = *a; *a = *b; *b = tmp; }

// Перегрузка функций сортировки выбором:

void selectionSort(int* arr, size_t n) {
	int i, j, min_idx;
	
	for (i = 0; i < n - 1; i++) {  // шаг за шагом сдвигаем границу неотсортированного подмассива.
		
		// Поиск мин. элемента в неотсортированном подмассиве:
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		swap(&arr[min_idx], &arr[i]);  // обмен найденного мин. элемента с первым элементом.
	}
}

void selectionSort(float* arr, size_t n) {
	int i, j, min_idx;
	
	for (i = 0; i < n - 1; i++) {  // шаг за шагом сдвигаем границу неотсортированного подмассива.
		
		// Поиск мин. элемента в неотсортированном подмассиве:
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		swap(&arr[min_idx], &arr[i]);  // обмен найденного мин. элемента с первым элементом.
	}
}

// Перегрузка функций сортировки пузырьком:

void bubbleSort(int* arr, size_t n) {
   int i, j;
   for (i = 0; i < n - 1; i++)      
       // Последние i элементов в массиве уже отсортированы.
       for (j = 0; j < n - i - 1; j++) 
           if (arr[j] > arr[j + 1])
              swap(&arr[j], &arr[j + 1]);
}

void bubbleSort(float* arr, size_t n) {
   int i, j;
   for (i = 0; i < n - 1; i++)      
       // Последние i элементов в массиве уже отсортированы.
       for (j = 0; j < n - i - 1; j++) 
           if (arr[j] > arr[j + 1])
              swap(&arr[j], &arr[j + 1]);
}

// Перегрузка функций сортировки вставками:

void insertionSort(int* arr, size_t n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;

       // Перемещение элементов arr[0 ... i - 1], которые больше чем key, на одную позицию вперёд с их текущей позиции:
	   while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

void insertionSort(float* arr, size_t n) {
   int i, j;
   float key;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;

       // Перемещение элементов arr[0 ... i - 1], которые больше чем key, на одную позицию вперёд с их текущей позиции:
	   while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

// Перегрузка функций сортировки Шелла:

void shellSort(int *arr, size_t n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
 
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            arr[j] = temp;
        }
    }
}

void shellSort(float *arr, size_t n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            float temp = arr[i];
 
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            arr[j] = temp;
        }
    }
}

// Перегрузка функций быстрой сортировки:

// Эта функция берет последний элемент в качестве опорного,
// ставит опорный элемент на правильное место в отсортированном массиве,
// и ставит все элементы, которые меньше опорного, слева от него,
// а которые больше опорного, ставит справа от него.
int partition(int* arr, int low, int high) {
	int pivot = arr[high];  // опорный элемент массива.
	int i = (low - 1);  // индекс наименьшего элемента.
	
	for (int j = low; j <= high- 1; j++) {
		if (arr[j] <= pivot) {  // если текущий элемент меньше или равен опорному:
			i++;  // увеличить индекс наименьшего элемента.
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);  // pi - это разделительный индекс.
		
		// Будем считать, что элемент arr[p] сейчас занимает правильную позицию.
		// Т.е. находится на своем месте в отсортированном массиве.
		
		// Раздельная сортировка элементов до разделительного индекса и после разделительного индекса:
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void quickSort(int* arr, size_t n) {
	quickSort(arr, 0, n - 1);
}

// Эта функция берет последний элемент в качестве опорного,
// ставит опорный элемент на правильное место в отсортированном массиве,
// и ставит все элементы, которые меньше опорного, слева от него,
// а которые больше опорного, ставит справа от него.
int partition(float* arr, int low, int high) {
	float pivot = arr[high];  // опорный элемент массива.
	int i = (low - 1);  // индекс наименьшего элемента.
	
	for (int j = low; j <= high- 1; j++) {
		if (arr[j] <= pivot) {  // если текущий элемент меньше или равен опорному:
			i++;  // увеличить индекс наименьшего элемента.
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(float arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);  // pi - это разделительный индекс.
		
		// Будем считать, что элемент arr[p] сейчас занимает правильную позицию.
		// Т.е. находится на своем месте в отсортированном массиве.
		
		// Раздельная сортировка элементов до разделительного индекса и после разделительного индекса:
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void quickSort(float* arr, size_t n) {
	quickSort(arr, 0, n - 1);
}
