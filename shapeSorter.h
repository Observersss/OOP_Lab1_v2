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

    static void sortByPerimeter(std::vector<Shape*>& shapes);
    static void sortShapesByArea(std::vector<Shape*>& shapes);
    static void insertionSort(std::vector<Shape*> shapes);
    static void quickSort(std::vector<Shape*>& shapes, int low, int high);
    static int partition(std::vector<Shape*>& shapes, int low, int high);

    static void mergeSort(std::vector<Shape*>& shapes, int left, int right);
    static void merge(std::vector<Shape*>& shapes, int left, int middle, int right);

    static void bubbleSort(std::vector<Shape*>& shapes);
};

#endif //INC_198432_SHAPESORTER_H
