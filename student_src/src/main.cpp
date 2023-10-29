#include <iostream>
#include <vector>
#include <cmath>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"



int main()
{
  // the viewer will open a file whose path is writen in hard (bad!!). 
  // So you should either launch your program from the fine directory or change the path to this file.
  Viewer_conic viewer;

  // viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);

  // draw points
  /*Eigen::VectorXd pt1(2), pt2(2), pt3(2);
  pt1 <<  1.5,  2.0;
  pt2 <<  3.0,  1.0;
  pt3 << -2.0, -1.0;

  viewer.push_point(pt1, "p1", 200,0,0);
  viewer.push_point(pt2, "p2", 200,0,0);
  viewer.push_point(pt3, 200,0,0);*/

  // define the coordinates of the 5 points (xi, yi)
  Eigen::MatrixXd points(5, 2);
  
  // conic: circle
  // points << 1, 0, 0, 1, -1, 0, 0, -1, cos(45), sin(45); // un point quelconque du cercle unité s'écrit x = cos(theta) et y = sin(theta)

  // conic: ellipse
  // points << 2, 0, -2, 0, 0, 1, 0, -1, 2*cos(90), sin(90); // un point d'une ellipse : x = a*cos(theta) et y = b*sin(theta) avec a demi grand axe et b demi petit axe

  // conic: parabola
  points << 0, 3, 1, 6, 2, 11, 3, 18, 4, 27; // un point d'une parabole : ax² + bx + c = y, ici a = 1, b = 2 et c = 3

  // conic: hyperbola
  // points << 1.5, 0, 1.5, 6, 3, 2, 1, 5, 4.5, 2.8;
  
  /*Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(2), pt5(2);
  pt1 <<  1.5,  2.0;
  pt2 <<  3.0,  1.0;
  pt3 << -2.0, -1.0;
  pt4 << -3.0, -2.0;
  pt5 << 4.0, 3.0;*/
  
  // build the matrice A from the coordinates of the 5 points
  Eigen::MatrixXd A(5, 6);
  for (int i = 0; i < 5; i++) {
    Eigen::VectorXd pt(2);
    double x = points(i, 0);
    double y = points(i, 1);
    pt << x, y;
    viewer.push_point(pt, "p", 200,0,0);
    A.row(i) << x * x, x * y, y * y, x, y, 1;
  }
  /*double x = pt1(0,0);
  double y = pt1(0,1);
  A.row(0) << x * x, y * y, x * y, x, y, 1;
  x = pt2(0,0);
  y = pt2(0,1); 
  A.row(1) << x * x, y * y, x * y, x, y, 1;
  x = pt3(0,0);
  y = pt3(0,1);
  A.row(2) << x * x, y * y, x * y, x, y, 1;
  x = pt4(0,0);
  y = pt4(0,1);
  A.row(3) << x * x, y * y, x * y, x, y, 1;
  x = pt5(0,0);
  y = pt5(0,1);
  A.row(4) << x * x, y * y, x * y, x, y, 1;*/


  // draw line
  // viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // use the SVD to calculate the kernel of A
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
  Eigen::VectorXd x = svd.matrixV().rightCols(1);

  // the coefficients a, b, c, d, e, f of the conic are extarcted from x
  double a = x(0);
  double b = x(1);
  double c = x(2);
  double d = x(3);
  double e = x(4);
  double f = x(5);

  // print the coefficients of the conic
  std::cout << "Coefficients de la conique : " << std::endl;
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "e = " << e << std::endl;
  std::cout << "f = " << f << std::endl;

  // draw conic
  Eigen::VectorXd conic(6);
  //conic << -1.4, -0.3, -1, -0.6, 0.0, 0.8;

  // different types of conics:

  // cercle : a = c & b = 0
  // conic << 1, 0, 1, 3, 4, 5;
  // ellipse : b² - 4ac < 0
  conic << 2, 3, 3, 0, 1, 4;
  // parabola : b² - 4ac = 0
  // conic << 2, 4, 2, 1, 3, 5;
  // hyperbola : b² - 4ac > 0
  // conic << 1, 5, 2, 0, 3, 4;

  conic << a, b, c, d, e, f;
  viewer.push_conic(conic, 0,0,200);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}
