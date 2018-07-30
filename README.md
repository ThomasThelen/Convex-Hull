# The Convex Hull
[![CodeFactor](https://www.codefactor.io/repository/github/thomasthelen/convex-hull/badge)](https://www.codefactor.io/repository/github/thomasthelen/convex-hull)

If you've run across this project, chances are you need to create a bounding box around some polygon. At this point, you may not know what a convex hull is but don't worry-we'll define it before digging into the code. In short, a convex hull is the outer most points on a polygon. Some applications (like the bounding box) only need the outer-most parts of the polygon to accomplish some task. Note that polygons are 2-dimensional. When we extend out to 3 dimensions, we are no longer dealing with polygons, but [polyhedrons](https://en.wikipedia.org/wiki/Polyhedron).

<br/>

Consider the two polygons below. If we are interested in the global features of polygon A, we can see that the jagged right side does not contribute to its size. The convex hull of polygon A is polygon B. Note that we discarded the points on the jagged side and instead connected the two exterior points.

<br/>

![polygons](https://github.com/ThomasThelen/Convex-Hull/blob/master/Images/PolyDiff.png "Two Polygons")

<br/>

First, let's identify the concave line segments; this is shown in polygon A in the figure below. The two red line segments are concave, along with the two green line segments. Removing the two vertices, we arrive at polygon B. Note that there is a larger concave segment, colored red in polygon C. Once removing the vertex, we arrive at polygon D: the convex hull. Note that all vertices are convex. 

<br/>

![Convex Hull Process](https://github.com/ThomasThelen/Convex-Hull/blob/master/Images/Process.png "Examining the Convex Hull")

<br/>

To emphasize the convex/convex difference, refer to the image below. The first shows a concave segment. The second highlighted segment is convex. 

<br/>

![Concave/Convex Line Segments](https://github.com/ThomasThelen/Convex-Hull/blob/master/Images/ConcaveConvex.png "Concave/Convex")

<br/>

Now that we have the basic vocabulary down, we can define what a convex polygon is. Math Open Reference defines a convex polygon as
> Definition: A polygon that has all interior angles less than 180°
> (Result: All the vertices point 'outwards', away from the center.)

Looking back at the example pictures above, you will notice that the convex line segments are all 180° or higher. We can use the last example to illustrate.

<br/>

![Concave/Convex Polygons](https://github.com/ThomasThelen/Convex-Hull/blob/master/Images/ConcaveConvexPolygons.png "Concave/Convex Polygons")

<br/>

The first polygon has vertices that have connecting line segments that are all greater 180°, it is convex. Note that we can pick any two points and draw a line that is completely contained in the polygon. The second polygon however, has an angle (B) which is less than 180°. We can take two points and connect a line which falls outside the polygon border. This polygon is concave.

<br/>

The goal of a convex hull algorithm is to take a polygon, and give the set of vertices  that gives the smallest convex polygon. The more common convex hull algorithms are listed below.

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



## Code Structure
All of the repositories use the same structure: a Coordinate class and a ConvexHull class. The Coordinate class is identical throughout the projects. You will commonly see

<br/>

<code> std::vector<Coordinate> polygon </code>

<br/>

defining the polygon that will be passed to the algorithm. The first step is creating a vector of coordinates.

There is also a Polygon class, which has a member function that computes the convex hull. The Polygon constructor takes a vector of coordinates, and stores it internally. In case you don't want to keep the original polygon around, you may use the move constructor. The second step is creating this polygon class, and passing the set of polygon points to it. 

<br/> 

To compute the convex hull, call
<code>Polygon::ComputeConvexHull()</code>
which returns a vector of coordinates defining the convex polygon. 

## Graham Scan
This project computes the convex hull by using the Graham Scan. This implementation assumes that the points are not sorted, which restricts the complexity time to O(nlogn). The complexity time of the convex hull algorithm itself is O(n). If you have points that are already sorted, you can remove the sorting routines.

<br/>

## Using/Modifying The Code
If you need to use some of this code in your own code, here are a few tips. 

#### 1. You can replace the Coordinate class with your own point class. If you go this route, you'll have to replace the GetX and GetY calls along with any spots where the Coordinate constructor is called. You'll also have to modify the container that is returned from Polygon::ComputeConvexHull. You can also replace the Coordinate class with a std::pair<double, double>. Again, you'll have to make modifications to get rid of the Coordinate member function calls and replace them with std::pair::first and std::pair::second.

#### 2. The lambda, isCounterClockwise, in ComputeConvexHull can be taken out and made into a full function if needed in other areas of the code.

#### 3. ConvexHull::SortPoints can be implemented in a number of different ways, which can be found by google searching for convex hull or bounding box example code.



## Soruces
[Convex Hull Algorithm List](https://en.wikipedia.org/wiki/Convex_hull_algorithms#Algorithms)
<br>




