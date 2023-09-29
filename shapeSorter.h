//
// Created by Илья Гончаренко on 28.09.2023.
//

#ifndef INC_198432_SHAPESORTER_H
#define INC_198432_SHAPESORTER_H
#include "figure.h"
#pragma once


#include <vector>
class ShapeSorter {
public:
    static bool compareByPerimeter(const Shape* a, const Shape* b);
    static bool compareByArea(const Shape* a, const Shape* b);

    static void sortByPerimeter(vector<Shape*>& shapes);
    static void sortShapesByArea(vector<Shape*>& shapes);
    static void insertionSort(vector<Shape*> shapes);
    static void quickSort(vector<Shape*>& shapes, int low, int high);
    static int partition(vector<Shape*>& shapes, int low, int high);

    static void mergeSort(vector<Shape*>& shapes, int left, int right);
    static void merge(vector<Shape*>& shapes, int left, int middle, int right);

    static void bubbleSort(vector<Shape*>& shapes);
};

#endif //INC_198432_SHAPESORTER_H
