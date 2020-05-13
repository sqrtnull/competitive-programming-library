/* <ConvexHull> */

struct Point
{
    double x,y;
    Point() {}
    Point(double x, double y) : x(x),y(y) {}
    static double dist(Point a, Point b) {
        double dx = a.x-b.x;
        double dy = a.y-b.y;
        return std::sqrt(dx*dx+dy*dy);
    }
    bool operator==(Point a) {
        if(a.x==x && a.y==y) return true;
        return false;
    }
};
using Polygon = std::vector<Point>;
Polygon ConvexHull(const Polygon& points) {
    Point lowest = points[0];
    for(Point p:points) {
        if(p.y<lowest.y || (p.y==lowest.y && p.x<lowest.x)) lowest = p;
    }
    std::map<double, Point> sorted;
    for(Point p:points) {
        if(p==lowest) continue;
        double ang = -(p.x-lowest.x)/Point::dist(p,lowest);
        if(sorted.count(ang)) {
            if(Point::dist(sorted[ang],lowest)<Point::dist(p,lowest)) sorted[ang] = p;
        } else sorted[ang] = p;
    }
    auto ccw = [] (Point c, Point a, Point b) {
        return ( (a.x-c.x)*(b.y-c.y) - (a.y-c.y)*(b.x-c.x) );
    };
    Polygon hull;
    hull.resize(sorted.size()+1);
    {
        int n = 1;
        hull[0] = lowest;
        for(auto e:sorted) {
            while(n>1 && ccw(hull[n-2],hull[n-1],e.second)<0) n--;
            hull[n]=e.second;
            n++;
        }
        hull.resize(n);
    }
    return hull;
}

double ConvexHullDiameter(const Polygon& points) {
    Polygon hull = ConvexHull(points);
    double max = 0;
    int n = hull.size();
    for(int i=0,j=0;i<n;i++) {
        while(Point::dist(hull[i],hull[(j+1)%n]) > Point::dist(hull[i],hull[j%n])) j++;
        max = std::max(max, Point::dist(hull[i],hull[j%n]));
    }
    return max;
}

/* <ConvexHull> */