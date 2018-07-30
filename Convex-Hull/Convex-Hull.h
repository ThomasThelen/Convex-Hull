#pragma once
#include <vector>

class Coordinate
{
public:
	Coordinate();
	Coordinate(double x, double y);

	double GetX() const;
	double GetY() const;

	void SetX(const double x);
	void SetY(const double y);

private:
	double m_x;
	double m_y;
};

/*
Class: ConvexHull

Purpose: Holds all of the functions for computing the convex hull. The constructor takes a vector of user supplied coordinates,
		 which is stored internally in m_polygon. ComputeConvexHull takes m_polygon and creates a new vector of coordinates which
		 define the convex hull. 
Use:
		 

*/
class Polygon
{
public:
	Polygon(std::vector<Coordinate>&& polygon);
	Polygon(const std::vector<Coordinate>& polygon);
	Polygon();

	bool CrossProduct(const Coordinate& pointA, const Coordinate& pointB, const Coordinate& pointC);

	std::vector<Coordinate> GetConvexHull();
	std::vector<Coordinate> ComputeConvexHull();
private:
	void SetConvexHull(std::vector<Coordinate>&& convexPolygon);
	void SetConvexHull(std::vector<Coordinate> convexPolygon);
	bool SortPoints(const Coordinate& pointA, const Coordinate& pointB);

	std::vector<Coordinate> m_polygon;
	std::vector<Coordinate> m_convexHull;
};
