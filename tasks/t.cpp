#include "std_lib_facilities.h"

struct Point {
    int x, y;
};


vector<Point> coordinates(const Point c, const int n)
{
  vector<Point> vp;
  double R = 100, angle;

  if (n >= 3 && n <= 8)
  {
    for (int i = 3; i < n;)
    {
      i++;
      R *= tan(M_PI / i) / sin(M_PI / i);
    }

    for (int i = 0; i < n; i++)
    {
      angle = 2 * M_PI / n * i;
      vp.push_back(Point{int(R * cos(angle) + c.x), int(R * sin(angle) + c.y)});
    }
  }
  else
    error("Wrong n!");
  return vp;
}

int main()
{
  Point center{650, 350};
  int n = 6;
  vector<Point> v1 = coordinates(center, n);
  for (int i = 0; i < n; i++)
    cout << v1[i].x << " " << v1[i].y << endl;
}

  