#include <iostream>
#include <algorithm>
#include "1984.h"
#include "Algorithm.h"

int main() {
    vector<Shape*> shapes; // Вектор для зберігання об'єктів фігур
    vector<Point> points;
    while (true) {
        std::cout << "Оберіть опцію:" << std::endl;
        std::cout << "1. Додати трикутник" << std::endl;
        std::cout << "2. Додати чотирикутник" << std::endl;
        std::cout << "3. Додати п'ятикутник" << std::endl;
        std::cout << "4. Додати багатокутник" << std::endl;
        std::cout << "5. Переглянути інформацію про фігури" << std::endl;
        std::cout << "6. Вийти" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Додавання трикутник
                // Отримати координати точок трикутника, наприклад, з введення користувача
                int v =3;
                for (int i = 0; i < v; ++i) {
                    Point point;
                    std::cout << "Введіть координати точки " << i + 1 << " (x y): ";
                    std::cin >> point.x >> point.y;
                    points.push_back(point);
                }
                // Створити об'єкт Triangle
                Triangle* pTriangle = new Triangle(points);
                // Додати об'єкт Triangle до вектора shapes
                shapes.push_back(pTriangle);
                points.clear();
                std::cout << "Трикутник додано." << std::endl;
                break;
            }

            case 2: {
                // Додавання чотирикутника
                // Отримати координати точок трикутника, наприклад, з введення користувача
                int v =4;
                for (int i = 0; i < v; ++i) {
                    Point point;
                    std::cout << "Введіть координати точки " << i + 1 << " (x y): ";
                    std::cin >> point.x >> point.y;
                    points.push_back(point);
                }
                // Створити об'єкт Triangle
                Quadrilateral* pQuadrilater = new Quadrilateral(points);
                // Додати об'єкт Triangle до вектора shapes
                shapes.push_back(pQuadrilater);
                points.clear();
                std::cout << "Чотирикутник додано." << std::endl;
                break;
            }
            case 3: {
                int v =5;
                for (int i = 0; i < v; ++i) {
                    Point point;
                    std::cout << "Введіть координати точки " << i + 1 << " (x y): ";
                    std::cin >> point.x >> point.y;
                    points.push_back(point);
                }
                // Створити об'єкт Triangle
                Pentagon* pPentagon = new Pentagon(points);
                // Додати об'єкт Triangle до вектора shapes
                shapes.push_back(pPentagon);
                points.clear();
                std::cout << "П'ятикутник додано." << std::endl;
                break;
            }
            case 4: {
                int n;
                std::cout << "Введіть кількість вершин (n): ";
                std::cin >> n;

                std::vector<Point> vertices;
                for (int i = 0; i < n; ++i) {
                    Point point;
                    std::cout << "Введіть координати точки " << i + 1 << " (x y): ";
                    std::cin >> point.x >> point.y;
                    vertices.push_back(point);
                }

                // Створити об'єкт n-кутника (Polygon)
                Polygon* polygon = new Polygon(vertices);

                // Додати об'єкт n-кутника до вектора shapes
                shapes.push_back(polygon);

                std::cout << n << "-кутник додано." << std::endl;
                break;
            }
            case 5: {
                // Перегляд інформації про фігури
                for (const Shape* shape : shapes) {
                    std::cout << "Периметр: " << shape->perimeter() << std::endl;
                    std::cout << "Площа: " << shape->gaussArea() << std::endl;
                    std::cout << "Спеціальна фігура: " << shape->isSpecial() << std::endl;
                }
                break;
            }
            case 6: {
                // Сортування фігур
                ShapeSorter::sortShapes(shapes); // Використовуйте власну реалізацію сортування
                std::cout << "Фігури було відсортовано." << std::endl;
                break;
            }
            case 7: {
                // Сортування за видом сортування (по периметру, площі тощо)
                std::cout << "Введіть вид сортування (наприклад, 'периметр' чи 'площа'): ";
                std::string sortCriteria;
                std::cin >> sortCriteria;

                if (sortCriteria == "периметр") {
                    ShapeSorter::sortShapesByPerimeter(shapes);
                    std::cout << "Фігури було відсортовано за периметром." << std::endl;
                } else if (sortCriteria == "площа") {
                    ShapeSorter::sortShapesByArea(shapes);
                    std::cout << "Фігури було відсортовано за площею." << std::endl;
                } else {
                    std::cout << "Невірний вид сортування. Спробуйте ще раз." << std::endl;
                }
                break;
            }
            case 8: {
                // Сортування за вибраним алгоритмом
                std::cout << "Виберіть алгоритм сортування ('insertion', 'quicksort', 'merge', 'bubble' і т.д.): ";
                std::string sortAlgorithm;
                std::cin >> sortAlgorithm;

                if (sortAlgorithm == "insertion") {
                    ShapeSorter::insertionSort(shapes);
                    std::cout << "Фігури було відсортовано за допомогою алгоритму сортування вставкою." << std::endl;
                } else if (sortAlgorithm == "quicksort") {
                    ShapeSorter::quickSort(shapes,0,points.size()-1);
                    std::cout << "Фігури було відсортовано за допомогою алгоритму швидкого сортування." << std::endl;
                } else if (sortAlgorithm == "merge") {
                    ShapeSorter::mergeSort(shapes,0,points.size()-1);
                    std::cout << "Фігури було відсортовано за допомогою алгоритму злиття." << std::endl;
                } else if (sortAlgorithm == "bubble") {
                    ShapeSorter::bubbleSort(shapes);
                    std::cout << "Фігури було відсортовано за допомогою алгоритму бульбашкового сортування." << std::endl;
                } else {
                    std::cout << "Невірний алгоритм сортування. Спробуйте ще раз." << std::endl;
                }
                break;
            }
            case 9:{
                // Вихід з програми
                // Звільнення пам'яті для об'єктів фігур
                for (Shape* shape : shapes) {
                    delete shape;
                }
                return 0;
            }
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
                break;
        }
    }

    return 0;
}