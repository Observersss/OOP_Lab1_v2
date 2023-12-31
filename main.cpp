#include "figure.h"
#include "shapeSorter.h"


int main()  {

    cout<<"Оберіть режим роботи:\n"<<"1 - Демострація функціоналу\n"<<"2 - Детальна робота з програмою\n";
    int choise;
    cin>>choise;
    if(choise==1){
        // Створюємо декілька об'єктів різних фігур
        vector<Point> trianglePoints = {Point(0, 0), Point(4, 0), Point(2, 3)};
        vector<Point> quadrilateralPoints = {Point(0, 0), Point(4, 0), Point(4, 3), Point(0, 3)};
        vector<Point> pentagonPoints = {Point(0, 0), Point(4, 0), Point(5, 2), Point(2, 4), Point(0, 2)};
        vector<Point> polygonPoints = {Point(0, 0), Point(4, 0), Point(5, 2), Point(4, 4), Point(2, 6), Point(0, 4)};
        // Створюємо об'єкти фігур
        cout<<"////////////////////////////////\n";
        Triangle triangle(trianglePoints);
        cout<<"Точки трикутника :\n";
        triangle.printPoints();

        cout << "Периметр трикутника: " << triangle.perimeter() << endl;
        cout << "Площа трикутника: " << triangle.gaussArea() << endl;

        if(triangle.isSpecial()){
            cout<<"Трикутник - спеціальний!"<<endl;
        }


        cout<<"////////////////////////////////\n";
        Quadrilateral quadrilateral(quadrilateralPoints);
        cout<<"Точки чотирикутника :\n";
        quadrilateral.printPoints();

        cout << "Периметр чотирикутника: " << quadrilateral.perimeter() << endl;
        cout << "Площа чотирикутника: " << quadrilateral.gaussArea() <<endl;

        // Визначаємо, чи є фігури спеціальними та виводимо повідомлення
        if (quadrilateral.isSpecial()) {
            cout << "Чотирикутник - спеціальний!" << endl;
        }

        cout<<"////////////////////////////////\n";
        Pentagon pentagon(pentagonPoints);
        cout<<"Точки п'ятикутника :\n";
        pentagon.printPoints();

        cout << "Периметр п'ятикутника: " << pentagon.perimeter() << endl;
        cout << "Площа п'ятикутника: " << pentagon.gaussArea() << endl;

        if (pentagon.isSpecial()) {
            cout << "П'ятикутник - спеціальний!" << endl;
        }

        cout<<"////////////////////////////////\n";
        Polygon polygon(polygonPoints);
        cout<<"Точки n-кутника :\n";
        polygon.printPoints();

        cout << "Периметр багатокутника: " << polygon.perimeter() << endl;
        cout << "Площа багатокутника: " << polygon.gaussArea() << endl;

        if (polygon.isSpecial()) {
            cout << "Багатокутник - спеціальний!" << endl;
        }

        cout<<"////////////////////////////////\n";



        vector<Shape*> shapes = {&triangle, &quadrilateral, &pentagon, &polygon};

        cout << "Original Order:\n";
        for (Shape* shape : shapes) {
            shape->printPoints();
            cout << "Perimeter: " << shape->perimeter() << "\n";
            cout << "Gauss Area: " << shape->gaussArea() << "\n\n";
        }

        ShapeSorter::insertionSort(shapes);

        cout << "Sorted by Perimeter:\n";
        for (Shape* shape : shapes) {
            shape->printPoints();
            cout << "Perimeter: " << shape->perimeter() << "\n";
            cout << "Gauss Area: " << shape->gaussArea() << "\n\n";
        }

        // Sorting by area
        ShapeSorter::quickSort(shapes, 0, 3);

        cout << "Sorted by Area:\n";
        for (Shape* shape : shapes) {
            shape->printPoints();
            cout << "Perimeter: " << shape->perimeter() << "\n";
            cout << "Gauss Area: " << shape->gaussArea() << "\n\n";
        }
        return 0;

    }else{
    vector<Shape *> shapes; // Вектор для зберігання об'єктів фігур
    vector<Point> points;
    while (true) {
        cout << "Оберіть опцію:\n";
        cout << "1. Додати трикутник\n";
        cout << "2. Додати чотирикутник\n";
        cout << "3. Додати п'ятикутник\n";
        cout << "4. Додати багатокутник\n";
        cout << "5. Переглянути інформацію про фігури\n";
        cout << "6. Сортування фігур\n";
        cout << "7. Сортування по перимтру/площі\n";
        cout << "7. Сортування за обраним алгоритмом\n";
        cout << "9. Вихід з программи\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Додавання трикутник
                // Отримати координати точок трикутника, наприклад, з введення користувача
                int v = 3;
                for (int i = 0; i < v; ++i) {
                    Point point;
                    cout << "Введіть координати точки " << i + 1 << " (x y): ";
                    cin >> point.x >> point.y;
                    points.push_back(point);
                }
                // Створити об'єкт Triangle
                Triangle *pTriangle = new Triangle(points);
                // Додати об'єкт Triangle до вектора shapes
                shapes.push_back(pTriangle);
                points.clear();
                cout << "Трикутник додано.\n";
                break;
            }

            case 2: {
                // Додавання чотирикутника
                // Отримати координати точок трикутника, наприклад, з введення користувача
                int v = 4;
                for (int i = 0; i < v; ++i) {
                    Point point;
                    cout << "Введіть координати точки " << i + 1 << " (x y): ";
                    cin >> point.x >> point.y;
                    points.push_back(point);
                }
                // Створити об'єкт Triangle
                Quadrilateral *pQuadrilater = new Quadrilateral(points);
                // Додати об'єкт Triangle до вектора shapes
                shapes.push_back(pQuadrilater);
                points.clear();
                cout << "Чотирикутник додано.\n";
                break;
            }
            case 3: {
                int v = 5;
                for (int i = 0; i < v; ++i) {
                    Point point;
                    cout << "Введіть координати точки " << i + 1 << " (x y): ";
                    cin >> point.x >> point.y;
                    points.push_back(point);
                }
                // Створити об'єкт Triangle
                Pentagon *pPentagon = new Pentagon(points);
                // Додати об'єкт Triangle до вектора shapes
                shapes.push_back(pPentagon);
                points.clear();
                cout << "П'ятикутник додано." << endl;
                break;
            }
            case 4: {
                int n;
                cout << "Введіть кількість вершин (n): ";
                cin >> n;

                vector<Point> vertices;
                for (int i = 0; i < n; ++i) {
                    Point point;
                    cout << "Введіть координати точки " << i + 1 << " (x y): ";
                    cin >> point.x >> point.y;
                    vertices.push_back(point);
                }

                // Створити об'єкт n-кутника (Polygon)
                Polygon *polygon = new Polygon(vertices);

                // Додати об'єкт n-кутника до вектора shapes
                shapes.push_back(polygon);

                cout << n << "-кутник додано." << endl;
                break;
            }
            case 5: {
                // Перегляд інформації про фігури
                for (const Shape *shape: shapes) {
                    cout << "Периметр: " << shape->perimeter() <<endl;
                    cout << "Площа: " << shape->gaussArea() << endl;
                    cout << "Спеціальна фігура: " << shape->isSpecial() << endl;
                }
                break;
            }
            case 6: {
                // Сортування фігур
                ShapeSorter::sortByPerimeter(shapes); // Використовуйте власну реалізацію сортування
                cout << "Фігури було відсортовано." << endl;
                break;
            }
            case 7: {
                // Сортування за видом сортування (по периметру, площі тощо)
                cout << "Введіть вид сортування (наприклад, 'периметр' чи 'площа'): ";
                string sortCriteria;
                cin >> sortCriteria;

                if (sortCriteria == "периметр") {
                    ShapeSorter::sortByPerimeter(shapes);
                    cout << "Фігури було відсортовано за периметром." << endl;
                } else if (sortCriteria == "площа") {
                    ShapeSorter::sortShapesByArea(shapes);
                    cout << "Фігури було відсортовано за площею." <<endl;
                } else {
                    cout << "Невірний вид сортування. Спробуйте ще раз." << endl;
                }
                break;
            }
            case 8: {
                // Сортування за вибраним алгоритмом
                cout << "Виберіть алгоритм сортування ('insertion', 'quicksort', 'merge', 'bubble' і т.д.): ";
                string sortAlgorithm;
                cin >> sortAlgorithm;

                if (sortAlgorithm == "insertion") {
                    ShapeSorter::insertionSort(shapes);
                    cout << "Фігури було відсортовано за допомогою алгоритму сортування вставкою." << endl;
                } else if (sortAlgorithm == "quicksort") {
                    ShapeSorter::quickSort(shapes, 0, points.size() - 1);
                    cout << "Фігури було відсортовано за допомогою алгоритму швидкого сортування." << endl;
                } else if (sortAlgorithm == "merge") {
                    ShapeSorter::mergeSort(shapes, 0, points.size() - 1);
                    cout << "Фігури було відсортовано за допомогою алгоритму злиття." << endl;
                } else if (sortAlgorithm == "bubble") {
                    ShapeSorter::bubbleSort(shapes);
                    cout << "Фігури було відсортовано за допомогою алгоритму бульбашкового сортування."
                              << endl;
                } else {
                    cout << "Невірний алгоритм сортування. Спробуйте ще раз." << endl;
                }
                break;
            }
            case 9: {
                // Вихід з програми
                // Звільнення пам'яті для об'єктів фігур
                for (Shape *shape: shapes) {
                    delete shape;
                }
                return 0;
            }
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
                break;
        }
    }
    }
}