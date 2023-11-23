#include <iostream>
#include <vector>

#include "conics.hpp"

using namespace MyConics;

// g++ -Wall -O2 -std=c++11 -I /usr/include/eigen3 -I include src/main.cpp src/Geogebra_conics.cpp src/Entry.cpp src/Directory.cpp src/conics.cpp src/conics_bundle.cpp -o conics
// clang++ -Wall -O2 -std=c++11 -I /usr/include/eigen3 -I include src/main.cpp src/Geogebra_conics.cpp src/Entry.cpp src/Directory.cpp src/conics.cpp src/conics_bundle.cpp -o conics

int main() {
  Conic conic("points_hyperbola2.txt");
  /*name of the file were are defined the coordinates of the 5 points (xi, yi), you can choose between:
  - points_circle.txt: a point on the unit circle: x = cos(theta) and y = sin(theta)
  - points_ellipse.txt: a point on an ellipse: x = a*cos(theta) and y = b*sin(theta) with a = semi-major axe and b = semi-minor axe
  - points_parabola.txt: a point on a parabola: ax² + bx + c = y, here a = 1, b = 2 et c = 3
  - points_hyperbola.txt: a point on a hyperbola: constant/x = y, here constant = 3
  - points_hyperbola2.txt: hyperbola with non-aligned points
  */
  conic.displayConic();

  ConicBundle conicBundle("points_hyperbola2.txt", "points_parabola.txt");
  conicBundle.displayConicBundle();
  return 0;
}
