#include <iostream>
#include <algorithm>
#include "1984.h"


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
                // Додавання п'ятикутника
                std::vector<Point> pentagonPoints;
                // Отримати координати точок п'ятикутника
                // Створити об'єкт Pentagon та додати його до вектора shapes
                break;
            }
            case 4: {
                // Додавання багатокутника
                std::vector<Point> polygonPoints;
                // Отримати координати точок багатокутника
                // Створити об'єкт Polygon та додати його до вектора shapes
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
                // Вихід з програми
                // Звільнення пам'яті для об'єктів фігур
                for (Shape* shape : shapes) {
                    delete shape;
                }

            }
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
                break;
        }
    }

    return 0;
}