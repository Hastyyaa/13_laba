#include <iostream>
#include <vector>
using namespace std;

// Функція для бінарного пошуку місця вставки
int binarySearch(const vector<int>& arr, int item, int low, int high) {
    if (high <= low) {
        return (item > arr[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == arr[mid]) {
        return mid + 1;
    }

    if (item > arr[mid]) {
        return binarySearch(arr, item, mid + 1, high);
    }

    return binarySearch(arr, item, low, mid - 1);
}

// Функція для сортування методом бінарної вставки
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Знаходимо місце для вставки поточного елемента
        int location = binarySearch(arr, key, 0, j);

        // Зсуваємо елементи масиву для звільнення місця під ключ
        while (j >= location) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    vector<int> arr = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };

    cout << "Масив до сортування: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    binaryInsertionSort(arr);

    cout << "Масив після сортування: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
