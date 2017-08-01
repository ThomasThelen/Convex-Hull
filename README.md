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

Note that we are dealing with ***segments***. Lines reach out towards infinity and we are only concerned with a section/segment of it. This requires two end points. Because polygons are in two dimensions, we know that our points are going to be 2-tuples. 
<br>
ie
<br>
Point={(a,b) | a,b ( R}
<br>
If we extend our definition to Euclidean Space, we can say that our point is just an element of R^2.
<br>
When we have a set of two or more points, we can start connecting them together and creating line segments.
<br>
A set, LS, which contains two connected points is called a line segment.
<br>
Line Segment = {A, B} where A = {a,b), B = {c,d{ where a, b, c, d ( R^2
<br>
We can think of the line segment as being a subset of R^2. We are able to take many subsets of R^2 that contain two points and connect them with lines. When a point has two line segments connecting it, it is called a vertex.
<br>
<br>



## Background
Convex hulls are used in many different areas and has its roots in computational geometry. Many problems like bounding boxes rely on first having a convex hull. One aspect that all algorithms share is that they need a set of points defining a polygon.
<br>
All of the repositories use the same structure: a Coordinate class and a ConvexHull class. The Coordinate class is identical throughout the projects. You will commonly see
<br>
<code> std::vector<Coordinate> polygon </code>

<br>

defining the polygon that will be passed to the algorithm.

## Graham Scan
This algorithm computes the convex hull by using the Graham Scan. This implimentation assumes that the points are not sorted, which restricts the complexity time to O(nlogn). The complexity time of the convex hull algorim itself is O(n). If you have points that are already sorted, you can remove the sorting routines.

<br>
#####

## Gift Wrapping (Jarvis March)

## Using/Modifing The Code
If you need to use some of this code in your own code, here are a few tips. 
#### 1. You can replace the Coordinate class with your own point class. If you go this route, you'll have to replace the GetX and GetY calls along with any spots where the Coordinate constructor is called. You can also replace the Coordinate class with a std::pair<double, double>. Again, you'll have to make modifications to get rid of the Coordinate member function calls and replace them with std::pair::first and std::pair::second.

#### 2. The lambda, isCounterClockwise, in ComputeConvexHull can be taken out and made into a full function if needed in other areas of the code.

#### 3. ConvexHull::SortPoints can be implimented in a number of different ways, which can be found by google searching for convex hull or bounding box example code.






##Soruces
[Convex Hull Algorithm List](https://en.wikipedia.org/wiki/Convex_hull_algorithms#Algorithms)
<br>




