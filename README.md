# The Convex Hull
If you've run across this project, chances are you need to create a bounding box around some polygon. At this point, you may not know what a convex hull is but don't worry-we'll define it before diggging into the code. In short, a convex hull is the outer most points on a polygon. Some applications (like the bounding box) only need the outer-most parts of the polygon to accomplish some task. You can imagine that when drawing a rectangle around a polygon, only the outer points matter. Note that polygons are 2-dimensional. When we extend out to 3 dimensions, we are no longer dealing with polygons, but polyhedrons[https://en.wikipedia.org/wiki/Polyhedron].

<br/>

Take for example, the two polygons below. When we draw the rectagle that encompasses ***all*** of the points in the polygon, we don't need to know anything about the inner points on the right hand side. We can "clean" this polygon by only considering the outer points: the convex hull, which is polygon 'B'. by 'clean', I mean we can pass the polygon to an algorithm that outputs only the outermost points. There are many different algorithms which do this-some are quicker than others.

<br/>

| Algorithm                         | Complexity         | Worst Case       | Algorithm Alias                           | Date Published |
|-----------------------------------|--------------------|------------------|-------------------------------------------|----------------|
| Grahm Scan                        | O(n)               |                  |                                           | 1972           |
| Monotone Chain                    | O(n) (When sorted) | O(nlog(n))       | Andrew's Algorithm                        | 1979           |
| Quickhull                         | O(nlog(n))         | O(n<sup>2</sup>) |                                           | 1977           |
| Gift Wrapping                     | O(nh)              | O(n<sup>2</sup>) | Jarvis March                              | 1970           |
| Chan's Algorithm                  | O(nlog(n)          |                  |                                           | 1996           |
| Kirkpatrick–Seidel                | O(nlog(h))         |                  | the ultimate planar convex hull algorithm | 1986           |
| Incremental Convex Hull Algorithm | O(nlog(n))         |                  |                                           | 1984           
----------------------------------------------------------------------------------------------------------------------------------------

<br/>

Before we give a real definition to convex hull, lets recap what a polygon is on a high level, and then dip down into set theory for a more complete definition.From The Math Open Reference, a polygon is

> A number of coplanar line segments, each connected end to end to form a closed shape.

We can rephrase this as 

> A set of line segments, each connected end to end to form a closed shape.

Note that we are dealing with ***segments***. Lines reach out towards infinity and we are only concerned with a section/segment of it. This requires two end points. Because polygons are in two dimensions, we know that our points are going to be a 2-tuple. 

A set, LS, to contain two 2-tuples, called the verticies and connect them with a line. We call LS a line segment.
<br>
Line Segment = {A, B} where A = {a,b), B = {c,d{ where a, b, c, d ( R^2
<br>
In summary, two points can be used to define a line segment. Collection of line segments arranged in a ring are called polygons.
<br>
Set of Points->Line Segment->Set of Line Segments->Polygons

## Background
Convex hulls are used in many different areas and has its roots in computational geometry. Many problems like bounding boxes rely on first having a convex hull. All algorithms start with a set of points defining a polygon. This repository has a couple of different methods for obtaining the convex hull.
<br>
All of the repositories use the same structure: a Coordinate class and a ConvexHull class. The Coordinate class is identical throughout the projects.
<br>

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






<center>##Soruces:</center>
<br>
Convex Hull Algorithms[https://en.wikipedia.org/wiki/Convex_hull_algorithms#Algorithms]




