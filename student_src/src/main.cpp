#include <iostream>
#include <vector>

#include "conics.hpp"

// g++ -Wall -O2 -std=c++11 -I /usr/include/eigen3 main.cpp Geogebra_conics.cpp Entry.cpp Directory.cpp conics.cpp -o conics

int main() {
  Conic conic("points_hyperbola2.txt");
  /*name of the file were are defined the coordinates of the 5 points (xi, yi), you can choose between:
  - points_circle.txt: a point on the unit circle: x = cos(theta) and y = sin(theta)
  - points_ellipse.txt: a point on an ellipse: x = a*cos(theta) and y = b*sin(theta) with a = semi-major axe and b = semi-minor axe
  - points_parabola.txt: a point on a parabola: ax² + bx + c = y, here a = 1, b = 2 et c = 3
  - points_hyperbola.txt: a point on a hyperbola: constant/x = y, here constant = 3
  - points_hyperbola2.txt: hyperbola with non-aligned points
  */

  Eigen::VectorXd conicCoefficients = conic.solveLeastSquares();

  conic.printCoefficients(conicCoefficients);

  Viewer_conic viewer;

  conic.drawConic(conicCoefficients, viewer);

  viewer.display();
  viewer.render("output.html");

  return 0;
}
