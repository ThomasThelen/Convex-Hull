# Convex-Hull
Computes the convex hull of a polygon


## Background
Convex hulls are used in many different areas and has its roots in computational geometry. Many problems like bounding boxes rely on first having a convex hull. All algorithms start with a set of points defining a polygon. This repository has a couple of different methods for obtaining the convex hull.

All of the repositories use the same structure: a Coordinate class and a ConvexHull class. The Coordinate class is identical throughout the projects however, the differences lie in the ConvexHull class.

## Two-Halves
This method computes the upper and lower halves of the convex hull, then combines them to give a complete convex hull.

## Single Hull
This method computes the convex hull in a single pass.


## 

## Using/Modifing The Code
If you need to use some of this code in your own code, here are a few tips. 
#### 1. You can replace the Coordinate class with your own point class. If you go this route, you'll have to replace the GetX and GetY calls along with any spots where the Coordinate constructor is called. You can also replace the Coordinate class with a std::pair<double, double>. Again, you'll have to make modifications to get rid of the Coordinate member function calls and replace them with std::pair::first and std::pair::second.

### 2. The lambda, isCounterClockwise, in ComputeConvexHull can be taken out and made into a full function if needed in other areas of the code.

### 3. ConvexHull::SortPoints can be implimented in a number of different ways, which can be found by google searching for convex hull or bounding box example code.
