#include "figure.h"
#pragma once
// Shape//
void Shape::printPoints() const {
    int pointNumber = 1;
    for (const Point& p : points) {
        std::cout << "Point " << pointNumber << ": (" << p.x << ", " << p.y << ")\n";
        pointNumber++;
    }
}

Shape::Shape(const std::vector<Point>& pts) : points(pts) {}

double Shape::distanceBetweenPoints(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double Shape::perimeter() const {
    double perimeter = 0.0;

    auto prev = points.begin();
    auto curr = prev + 1;

    while (curr != points.end()) {
        perimeter += distanceBetweenPoints(*prev, *curr);
        ++prev;
        ++curr;
    }
    perimeter += distanceBetweenPoints(points.back(), points.front());
    return perimeter;
}

double Shape::gaussArea() const {
    double totalArea = 0.0;
    int numVertices = points.size();

    for (int i = 0; i < numVertices; ++i) {
        const Point& currentPoint = points[i];
        const Point& nextPoint = points[(i + 1) % numVertices];

        totalArea += (currentPoint.x * nextPoint.y - nextPoint.x * currentPoint.y);
    }

    return std::abs(totalArea) / 2.0;
}
//Triangle//
std::unordered_map<Triangle::TriangleType, std::string> Triangle::triangleMessages;

Triangle::Triangle(const std::vector<Point>& pts) : Shape(pts) {}

bool Triangle::isSpecial() const {
    if (triangleMessages.empty()) {
        triangleMessages.insert({Invalid, "Данний трикутник не може існувати"});
        triangleMessages.insert({Equilateral, "Трикутник рівносторонній"});
        triangleMessages.insert({Isosceles, "Трикутник рівнобедрений"});
        triangleMessages.insert({Right, "Трикутник є прямокутним"});
        triangleMessages.insert({Scalene, "Данний трикутник не є спеціальним"});
        triangleMessages.insert({Convex, "Трикутник впуклий"});
        triangleMessages.insert({Concave, "Трикутник опуклий"});
    }

    double a = distanceBetweenPoints(points[0], points[1]);
    double b = distanceBetweenPoints(points[1], points[2]);
    double c = distanceBetweenPoints(points[2], points[0]);

    if (a + b <= c || b + c <= a || a + c <= b) {
        std::cout << triangleMessages[Invalid] << std::endl;
        return Invalid;
    }

    if (a == b && b == c) {
        if (a * a + b * b == c * c) {
            std::cout << triangleMessages[Right] << std::endl;
            return Right;
        }
        std::cout << triangleMessages[Equilateral] << std::endl;
        return Equilateral;
    }

    if (a == b || b == c || a == c) {
        if (a * a + b * b == c * c) {
            std::cout << triangleMessages[Right] << std::endl;
            return Right;
        }
        std::cout << triangleMessages[Isosceles] << std::endl;
        return Isosceles;
    }

    if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
        std::cout << triangleMessages[Right] << std::endl;
        return Right;
    }

    if (isConvex()) {
        std::cout << "Чотирикутник є опуклим" << std::endl;
        std::cout << triangleMessages[Convex] << std::endl;
    } else {
        std::cout << "Чотирикутник є впуклим" << std::endl;
        std::cout << triangleMessages[Concave] << std::endl;
    }

    std::cout << triangleMessages[Scalene] << std::endl;
    return Scalene;
}

bool Triangle::isConvex() const {
    // Перевірка на впуклість
    int numVertices = points.size();

    if (numVertices < 4) {
        return false; // Мінімум 4 вершини для чотирикутника
    }

    for (int i = 0; i < numVertices; ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % numVertices];
        const Point& p3 = points[(i + 2) % numVertices];

        double crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

        if (crossProduct < 0) {
            return false; // Знак перепутнувся, отже, чотирикутник невпуклий
        }
    }

    return true; // Чотирикутник впуклий
}
//Quadrilateral//
std::unordered_map<Quadrilateral::QuadrilateralType, std::string> Quadrilateral::quadrilateralMessages;

Quadrilateral::Quadrilateral(const std::vector<Point>& pts) : Shape(pts) {}

void Quadrilateral::initializeQuadrilateralMessages() const {
    quadrilateralMessages.insert({Invalid, "Данний чотирикутник не може існувати"});
    quadrilateralMessages.insert({Square, "Чотирикутник - квадрат"});
    quadrilateralMessages.insert({Rectangle, "Чотирикутник - прямокутник"});
    quadrilateralMessages.insert({Rhombus, "Чотирикутник - ромб"});
    quadrilateralMessages.insert({Parallelogram, "Чотирикутник - параллелограмм"});
    quadrilateralMessages.insert({Trapezoid, "Чотирикутник - Трапеція"});
    quadrilateralMessages.insert({AngularQuadrilateral, "Чотирикутник - угловий"});
    quadrilateralMessages.insert({ConvexQuadrilateral, "Чотирикутник - випуклий"});
}

bool Quadrilateral::isSpecial() const {
    if (quadrilateralMessages.empty()) {
        initializeQuadrilateralMessages();
    }

    double side1 = distanceBetweenPoints(points[0], points[1]);
    double side2 = distanceBetweenPoints(points[1], points[2]);
    double side3 = distanceBetweenPoints(points[2], points[3]);
    double side4 = distanceBetweenPoints(points[3], points[0]);

    double diagonal1 = distanceBetweenPoints(points[0], points[2]);
    double diagonal2 = distanceBetweenPoints(points[1], points[3]);

    if (side1 + side2 + side3 < side4 && side2 + side3 + side4 < side1 && side3 + side4 + side1 < side2 && side4 + side1 + side2 < side3) {
        cout << quadrilateralMessages[Invalid] << '\n';
        return false;
    }

    // Проверка на квадрат
    if (side1 == side2 && side2 == side3 && side3 == side4 && diagonal1 == diagonal2) {
        cout << quadrilateralMessages[Square] << '\n';
        return true;
    }

    // Проверка на прямоугольник (все углы прямые)
    if (side1 == side3 && side2 == side4) {
        cout << quadrilateralMessages[Rectangle] << '\n';
        return true;
    }

    // Проверка на ромб (все стороны равны)
    if (side1 == side2 && side2 == side3 && side3 == side4) {
        cout << quadrilateralMessages[Rhombus] << '\n';
        return true;
    }

    // Проверка на параллелограмм (противоположные стороны равны, углы между смежными равны)
    if (side1 == side3 && side2 == side4 && diagonal1 != diagonal2) {
        cout << quadrilateralMessages[Parallelogram] << '\n';
        return true;
    }

    // Проверка на трапецію (хоча б дві сторони паралельні)
    if ((side1 == side2 && side3 != side4) || (side1 != side2 && side3 == side4)) {
        cout << quadrilateralMessages[Trapezoid] << '\n';
        return true;
    }

    // Проверка на угловий чотирикутник (хоча б один угол не прямий)
    if (angleBetweenSides(side1, side2, side3) != 90.0 || angleBetweenSides(side2, side3, side4) != 90.0 || angleBetweenSides(side3, side4, side1) != 90.0 || angleBetweenSides(side4, side1, side2) != 90.0) {
        cout << quadrilateralMessages[AngularQuadrilateral] << '\n';
        return true;
    }

    // Проверка на выпуклий чотирикутник (відповідні перевірки)
    if (checkConvexity()) {
        cout << quadrilateralMessages[ConvexQuadrilateral] << '\n';
        return true;
    } else {
        cout << "Чотирикутник - не випуклий\n";
        return true;
    }

    cout << "Чотирикутник звичайний" << std::endl;
    return false;
}

double Quadrilateral::angleBetweenSides(double a, double b, double c) const {
    return std::acos((a * a + b * b - c * c) / (2 * a * b)) * (180.0 / M_PI);
}

bool Quadrilateral::checkConvexity() const {
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
//Pentagon//
std::unordered_map<Pentagon::PentagonType, std::string> Pentagon::pentagonMessages;

Pentagon::Pentagon(const std::vector<Point>& pts) : Shape(pts) {}

void Pentagon::initializePentagonMessages() const {
    pentagonMessages.insert({Invalid, "Даний п'ятикутник не може існувати"});
    pentagonMessages.insert({Regular, "П'ятикутник - правильний"});
    pentagonMessages.insert({Irregular, "П'ятикутник - неправильний"});
    pentagonMessages.insert({Convex, "П'ятикутник - випуклий"});
    pentagonMessages.insert({Concave, "П'ятикутник - невипуклий"});
}

bool Pentagon::isSpecial() const {
    if (pentagonMessages.empty()) {
        initializePentagonMessages();
    }

    double side1 = distanceBetweenPoints(points[0], points[1]);
    double side2 = distanceBetweenPoints(points[1], points[2]);
    double side3 = distanceBetweenPoints(points[2], points[3]);
    double side4 = distanceBetweenPoints(points[3], points[4]);
    double side5 = distanceBetweenPoints(points[4], points[0]);

    // Перевірка на існування
    if (side1 + side2 + side3 + side4 <= side5 ||
        side2 + side3 + side4 + side5 <= side1 ||
        side3 + side4 + side5 + side1 <= side2 ||
        side4 + side5 + side1 + side2 <= side3 ||
        side5 + side1 + side2 + side3 <= side4) {
        cout << pentagonMessages[Invalid] << '\n';
        return false;
    }

    // Перевірка на правильність (усі сторони та кути рівні)
    if (side1 == side2 && side2 == side3 && side3 == side4 && side4 == side5) {
        cout << pentagonMessages[Regular] << '\n';
        return true;
    }

    // Перевірка на випуклість або невипуклість
    if (checkConvexity()) {
        cout << pentagonMessages[Convex] << '\n';
        return true;
    } else {
        cout << pentagonMessages[Concave] << '\n';
        return true;
    }

    cout << "П'ятикутник звичайний" << std::endl;
    return false;
}

// Функція для перевірки випуклості
bool Pentagon::checkConvexity() const {
    int numVertices = points.size();
    for (int i = 0; i < numVertices; ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % numVertices];
        const Point& p3 = points[(i + 2) % numVertices];
        double crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
        if (crossProduct < 0) {
            return false; // Невипуклий п'ятикутник
        }
    }
    return true; // Випуклий п'ятикутник
}
//Polygon//
std::unordered_map<Polygon::PolygonType, std::string> Polygon::polygonMessages;

Polygon::Polygon(const std::vector<Point>& pts) : Shape(pts), numSides(pts.size()) {}

void Polygon::initializePolygonMessages() const {
    polygonMessages.insert({Invalid, "Даний багатокутник не може існувати"});
    polygonMessages.insert({Regular, "Багатокутник - правильний"});
    polygonMessages.insert({Irregular, "Багатокутник - неправильний"});
    polygonMessages.insert({Convex, "Багатокутник - випуклий"});
    polygonMessages.insert({Concave, "Багатокутник - невипуклий"});
}

bool Polygon::isSpecial() const {
    if (polygonMessages.empty()) {
        initializePolygonMessages();
    }

    std::vector<double> sides;
    for (int i = 0; i < numSides; ++i) {
        sides.push_back(distanceBetweenPoints(points[i], points[(i + 1) % numSides]));
    }

    // Перевірка на існування
    for (int i = 0; i < numSides; ++i) {
        double sum = 0;
        for (double side : sides) {
            sum += side;
        }
        if (sum - sides[i] <= sides[i]) {
            std::cout << polygonMessages[Invalid] << '\n';
            return false;
        }
    }

    // Перевірка на правильність (усі сторони рівні)
    bool isRegular = true;
    for (int i = 1; i < numSides; ++i) {
        if (sides[i] != sides[0]) {
            isRegular = false;
            break;
        }
    }

    if (isRegular) {
        std::cout << polygonMessages[Regular] << '\n';
        return true;
    }

    // Перевірка на випуклість або невипуклість
    if (checkConvexity()) {
        std::cout << polygonMessages[Convex] << '\n';
        return true;
    } else {
        std::cout << polygonMessages[Concave] << '\n';
        return true;
    }

    std::cout << "Багатокутник звичайний" << std::endl;
    return false;
}

// Функція для перевірки випуклості
bool Polygon::checkConvexity() const {
    for (int i = 0; i < numSides; ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % numSides];
        const Point& p3 = points[(i + 2) % numSides];
        double crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
        if (crossProduct < 0) {
            return false; // Невипуклий багатокутник
        }
    }
    return true; // Випуклий багатокутник
}
