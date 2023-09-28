#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;
struct Point {
    double x;
    double y;
};

class Shape {
protected:
    std::vector<Point> points;
public:
    Shape(const std::vector<Point>& pts) : points(pts) {}
    // Статичний метод для обчислення відстані між двома точками
    static double distanceBetweenPoints(const Point& p1, const Point& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
    virtual bool isSpecial() const = 0;
    double perimeter() const
    {
        long perimeter=0;

        auto prev = points.begin();
        auto curr=prev+1;

        while (curr!=points.end())
        {
            perimeter+= distanceBetweenPoints(*prev,*curr);
            ++prev;
            ++curr;
        }
        perimeter+= distanceBetweenPoints(points.back(),points.front());
        return perimeter;
    }
    double gaussArea() const{
        double totalArea = 0.0;
        int numVertices =points.size();

        for (int i = 0; i < numVertices; ++i) {
            const Point& currentPoint = points[i];
            const Point& nextPoint = points[(i + 1) % numVertices];

            totalArea += (currentPoint.x * nextPoint.y - nextPoint.x * currentPoint.y);
        }

        return std::abs(totalArea) / 2.0;
    }
    virtual ~Shape() {}
};

class Triangle : public Shape {
protected:
    enum TriangleType {
        Invalid,
        Equilateral,
        Isosceles,
        Right,
        Scalene

    };
    static std::unordered_map<TriangleType, std::string> triangleMessages;
public:

    Triangle(const std::vector<Point> &pts) : Shape(pts) {}

    void tria() const {
        triangleMessages.insert(make_pair(Invalid, "Данний трикутник не може існувати"));
        triangleMessages.insert(make_pair(Equilateral, "Трикутник рівносторонній"));
        triangleMessages.insert(make_pair(Isosceles, "Трикутник рівнобедрений"));
        triangleMessages.insert(make_pair(Right, "Трикутник є прямокутним"));
        triangleMessages.insert(make_pair(Scalene, "Данний трикутник не є спеціальним"));
    }

    bool isSpecial() const override {
        if (triangleMessages.empty()) { tria(); }
        // Перевірка чи є трикутник рівностороннім, рівнобедреним або прямокутним
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        double c = distanceBetweenPoints(points[2], points[0]);
        if (a + b <= c || b + c <= a || a + c <= b) {
            std::cout << triangleMessages[Invalid] << std::endl;
            return Invalid;
        }
        if (a == b && b == c) {
            std::cout << triangleMessages[Isosceles] << std::endl;
            return Equilateral;
        }

        if (a == b || b == c || a == c) {
            std::cout << triangleMessages[Equilateral] << std::endl;
            return Isosceles;
        }

        if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
            std::cout << triangleMessages[Right] << std::endl;
            return Right;
        }
        std::cout << triangleMessages[Scalene] << std::endl;
        return Scalene;
    }
};
    class Quadrilateral : public Shape {
    protected:
        enum QuadrilateralType {
            Invalid,
            Square,
            Rectangle,
            Rhombus,
            Parallelogram,
            Trapezoid,
            AngularQuadrilateral,
            ConvexQuadrilateral
        };
        static std::unordered_map<QuadrilateralType, std::string> quadrilateralMessages;

    public:
        Quadrilateral(const std::vector<Point>& pts) : Shape(pts) {}

        void initializeQuadrilateralMessages()const {
            quadrilateralMessages.insert({Invalid, "Данний чотирикутник не може існувати"});
            quadrilateralMessages.insert({Square, "Чотирикутник - квадрат"});
            quadrilateralMessages.insert({Rectangle, "Чотирикутник - прямокутник"});
            quadrilateralMessages.insert({Rhombus, "Чотирикутник - ромб"});
            quadrilateralMessages.insert({Parallelogram, "Чотирикутник - параллелограмм"});
            quadrilateralMessages.insert({Trapezoid, "Чотирикутник - Трапеція"});
            quadrilateralMessages.insert({AngularQuadrilateral, "Чотирикутник - угловий"});
            quadrilateralMessages.insert({ConvexQuadrilateral, "Чотирикутник - випуклий"});
        }

        bool isSpecial() const override {
            if(quadrilateralMessages.empty()){initializeQuadrilateralMessages();}

            double side1 = distanceBetweenPoints(points[0], points[1]);
            double side2 = distanceBetweenPoints(points[1], points[2]);
            double side3 = distanceBetweenPoints(points[2], points[3]);
            double side4 = distanceBetweenPoints(points[3], points[0]);

            double diagonal1 = distanceBetweenPoints(points[0], points[2]);
            double diagonal2 = distanceBetweenPoints(points[1], points[3]);

            if (side1 + side2 + side3 < side4 && side2 + side3 + side4 < side1 && side3 + side4 + side1 < side2 && side4 + side1 + side2 < side3) {
                cout<<quadrilateralMessages[Invalid]<<'\n';
                return false;
            }

            // Проверка на квадрат
            if (side1 == side2 && side2 == side3 && side3 == side4 && diagonal1 == diagonal2) {
                cout<<quadrilateralMessages[Square]<<'\n';
                return true;
            }

            // Проверка на прямоугольник (все углы прямые)
            if (side1 == side3 && side2 == side4) {
                cout<<quadrilateralMessages[Rectangle]<<'\n';
                return true;
            }

            // Проверка на ромб (все стороны равны)
            if (side1 == side2 && side2 == side3 && side3 == side4) {
                cout<<quadrilateralMessages[Rhombus]<<'\n';
                return true;
            }

            // Проверка на параллелограмм (противоположные стороны равны, углы между смежными равны)
            if (side1 == side3 && side2 == side4 && diagonal1 != diagonal2) {
                cout<<quadrilateralMessages[Parallelogram]<<'\n';
                return true;
            }

            // Проверка на трапецію (хоча б дві сторони паралельні)
            if ((side1 == side2 && side3 != side4) || (side1 != side2 && side3 == side4)) {
                cout<<quadrilateralMessages[Trapezoid]<<'\n';
                return true;
            }

            // Проверка на угловий чотирикутник (хоча б один угол не прямий)
            if (angleBetweenSides(side1, side2, side3) != 90.0 || angleBetweenSides(side2, side3, side4) != 90.0 || angleBetweenSides(side3, side4, side1) != 90.0 || angleBetweenSides(side4, side1, side2) != 90.0) {
                cout<<quadrilateralMessages[AngularQuadrilateral]<<'\n';
                return true;
            }

            // Проверка на выпуклий чотирикутник (відповідні перевірки)
            if (checkConvexity()) {
                cout << quadrilateralMessages[ConvexQuadrilateral] << '\n';
                return true;
            }else{
                cout<<"Чотирикутник - не випуклий\n";
                return true;}

            cout << "Чотирикутник звичайний" << std::endl;
            return false;
        }

        double angleBetweenSides(double a, double b, double c) const {
            return std::acos((a * a + b * b - c * c) / (2 * a * b)) * (180.0 / M_PI);
        }

        bool checkConvexity() const {
            int numVertices = points.size();
            for (int i = 0; i < numVertices; ++i) {
                const Point& p1 = points[i];
                const Point& p2 = points[(i + 1) % numVertices];
                const Point& p3 = points[(i + 2) % numVertices];
                double crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
                if (crossProduct < 0) {
                    return false; // Невипуклий чотирикутник
                }
            }
            return true; // Випуклий чотирикутник
        }


    };
/*
class Pentagon : public Shape{
private:
    std::vector<Point> points;
public:
    Pentagon(const std::vector<Point>& pts) : points(pts) {}

    // Функція для обчислення периметра багатокутника
    double perimeter() const override {
        double perimeter = 0.0;
        int numVertices = points.size();

        for (int i = 0; i < numVertices; ++i) {
            perimeter += distanceBetweenPoints(points[i], points[(i + 1) % numVertices]);
        }

        return perimeter;
    }

    double area() const override {
        // Обчислення площі прямокутника за формулою Гаусса
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        return a * b;
    }
    bool isSpecial() const override {
        // Перевірка, чи є п'ятикутник ромбом
        double sideLength = distanceBetweenPoints(points[0], points[1]);
        for (int i = 1; i < 5; ++i) {
            if (std::abs(distanceBetweenPoints(points[i], points[(i + 1) % 5]) - sideLength) > 1e-6) {
                cout<<"Данний п'ятикутник не є ромбом\n";
                return false; // Якщо хоча б одна сторона не рівна іншим, то не ромб
            }
        }
        cout<<"Данний п'ятикутник є ромбом\n";
        return true; // Усі сторони рівні, це ромб
    }
};

class Polygon: public Shape{
private:
    std::vector<Point> points;
public:
    Polygon(const std::vector<Point>& pts) : points(pts) {}

    // Функція для обчислення периметра багатокутника
    double perimeter() const override {
        double perimeter = 0.0;
        int numVertices = points.size();

        for (int i = 0; i < numVertices; ++i) {
            perimeter += distanceBetweenPoints(points[i], points[(i + 1) % numVertices]);
        }

        return perimeter;
    }

    double area() const override {
        // Обчислення площі прямокутника за формулою Гаусса
        double a = distanceBetweenPoints(points[0], points[1]);
        double b = distanceBetweenPoints(points[1], points[2]);
        return a * b;
    }
    bool isSpecial() const override {
        // Реалізація для перевірки прямокутників
        // ...
    }
};
*/