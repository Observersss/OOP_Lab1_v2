
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
    vector<Point> points;

public:
    void printPoints() const;
    Shape(const vector<Point>& pts);
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
    static unordered_map<TriangleType, string> triangleMessages;

public:
    Triangle(const vector<Point>& pts);
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
    static unordered_map<QuadrilateralType, string> quadrilateralMessages;

public:
    Quadrilateral(const vector<Point>& pts);
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
    static unordered_map<PentagonType, string> pentagonMessages;

public:
    Pentagon(const vector<Point>& pts);
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
    static unordered_map<PolygonType, string> polygonMessages;
    int numSides;

public:
    Polygon(const vector<Point>& pts);
    void initializePolygonMessages() const;
    bool isSpecial() const override;
    bool checkConvexity() const;
};
