//
// Created by Илья Гончаренко on 28.09.2023.
//

#include "shapeSorter.h"


bool ShapeSorter::compareByPerimeter(const Shape* a, const Shape* b) {
    return a->perimeter() < b->perimeter();
}

bool ShapeSorter::compareByArea(const Shape* a, const Shape* b) {
    return a->gaussArea() < b->gaussArea();
}

void ShapeSorter::sortByPerimeter(vector<Shape*>& shapes) {
    sort(shapes.begin(), shapes.end(), compareByPerimeter);
}

void ShapeSorter::sortShapesByArea(vector<Shape*>& shapes) {
    sort(shapes.begin(), shapes.end(), compareByArea);
}

void ShapeSorter::insertionSort(vector<Shape*> shapes) {
    int n = shapes.size();
    for (int i = 1; i < n; ++i) {
        Shape* key = shapes[i];
        int j = i - 1;
        while (j >= 0 && compareByPerimeter(shapes[j], key)) {
            shapes[j + 1] = shapes[j];
            j = j - 1;
        }
        shapes[j + 1] = key;
    }
}

void ShapeSorter::quickSort(vector<Shape*>& shapes, int low, int high) {
    if (low < high) {
        int pi = partition(shapes, low, high);
        quickSort(shapes, low, pi - 1);
        quickSort(shapes, pi + 1, high);
    }
}

int ShapeSorter::partition(vector<Shape*>& shapes, int low, int high) {
    Shape* pivot = shapes[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (compareByArea(shapes[j], pivot)) {
            i++;
            swap(shapes[i], shapes[j]);
        }
    }
    swap(shapes[i + 1], shapes[high]);
    return (i + 1);
}

void ShapeSorter::mergeSort(vector<Shape*>& shapes, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(shapes, left, middle);
        mergeSort(shapes, middle + 1, right);
        merge(shapes, left, middle, right);
    }
}

void ShapeSorter::merge(vector<Shape*>& shapes, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<Shape*> leftArray(n1);
    vector<Shape*> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = shapes[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = shapes[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (!compareByPerimeter(rightArray[j], leftArray[i])) {
            shapes[k] = leftArray[i];
            i++;
        } else {
            shapes[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        shapes[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        shapes[k] = rightArray[j];
        j++;
        k++;
    }
}

void ShapeSorter::bubbleSort(vector<Shape*>& shapes) {
    int n = shapes.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareByPerimeter(shapes[j], shapes[j + 1])) {
                swap(shapes[j], shapes[j + 1]);
            }
        }
    }
}