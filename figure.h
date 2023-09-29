
#pragma once
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
struct Point {
    double x;
    double y;
    Point(double x, double y) : x(x), y(y) {}
    Point() {}
};

class Shape {
protected:
    std::vector<Point> points;

public:
    void printPoints() const;
    Shape(const std::vector<Point>& pts);
    static double distanceBetweenPoints(const Point& p1, const Point& p2);
    virtual bool isSpecial() const = 0;
    double perimeter() const;
    double gaussArea() const;
    virtual ~Shape() {}
};

class Triangle : public Shape {
protected:
    enum TriangleType {
        Invalid,
        Equilateral,
        Isosceles,
        Right,
        Scalene,
        Convex,
        Concave
    };
    static std::unordered_map<TriangleType, std::string> triangleMessages;

public:
    Triangle(const std::vector<Point>& pts);
    bool isSpecial() const override;
    bool isConvex() const;
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
    Quadrilateral(const std::vector<Point>& pts);
    void initializeQuadrilateralMessages() const;
    bool isSpecial() const override;
    double angleBetweenSides(double a, double b, double c) const;
    bool checkConvexity() const;
};
class Pentagon : public Shape {
protected:
    enum PentagonType {
        Invalid,
        Regular,
        Irregular,
        Convex,
        Concave
    };
    static std::unordered_map<PentagonType, std::string> pentagonMessages;

public:
    Pentagon(const std::vector<Point>& pts);
    void initializePentagonMessages() const;
    bool isSpecial() const override;
    bool checkConvexity() const;
};
class Polygon : public Shape {
protected:
    enum PolygonType {
        Invalid,
        Regular,
        Irregular,
        Convex,
        Concave
    };
    static std::unordered_map<PolygonType, std::string> polygonMessages;
    int numSides;

public:
    Polygon(const std::vector<Point>& pts);
    void initializePolygonMessages() const;
    bool isSpecial() const override;
    bool checkConvexity() const;
};
