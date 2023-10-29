#include <iostream>
#include <vector>
#include <cmath>
#include <fstream> // std::ifstream
#include <sstream> // std::istringstream

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

double evaluateTrigExpression(const std::string &expression) {
    if (expression.find("cos") != std::string::npos) {
        double angle;
        sscanf(expression.c_str(), "cos(%lf)", &angle);
        return std::cos(angle * M_PI / 180.0);  // Convert to radians
    } else if (expression.find("sin") != std::string::npos) {
        double angle;
        sscanf(expression.c_str(), "sin(%lf)", &angle);
        return std::sin(angle * M_PI / 180.0);  // Convert to radians
    } else {
        // Check if it's a valid double value
        try {
            return std::stod(expression);
        } catch (const std::invalid_argument& e) { // if letters instad of numbers
          std::cerr << "Invalid value or expression: " << expression << " (if it's the last component, let's change it into 1)" << std::endl; // won't be used?
          return std::numeric_limits<double>::quiet_NaN(); // return NaN for invalid values
        }
    }
}

// Fonction pour résoudre le problème des moindres carrés
Eigen::VectorXd solveLeastSquares(const Eigen::MatrixXd& A, const std::vector<Eigen::VectorXd>& points) {
  Eigen::MatrixXd AtA = A.transpose() * A;
  Eigen::VectorXd Atb(6);
  Atb.setZero();

  for (int i = 0; i < points.size(); i++) {
    Atb += A.row(i).transpose() * points[i];
  }

  Eigen::VectorXd conicCoefficients = AtA.colPivHouseholderQr().solve(Atb); // use QR decomposition
  // dans le cours
  /* Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(A);
     Eigen::VectorXd x_qr = qr.solve(b); */
  return conicCoefficients; // return the conic coefficients which minimize the algebraic error for all points
}

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

  std::string filename = "points_hyperbola.txt"; // name of the file were are defined the coordinates of the 5 points (xi, yi), you can choose between:
  /*
  - points_circle.txt: a point on the unit circle: x = cos(theta) and y = sin(theta)
  - points_ellipse.txt: a point on an ellipse: x = a*cos(theta) and y = b*sin(theta) with a = semi-major axe and b = semi-minor axe
  - points_parabola.txt: a point on a parabola: ax² + bx + c = y, here a = 1, b = 2 et c = 3
  - points_hyperbola.txt: a point on a hyperbola: constant/x = y, here constant = 3
  */
  std::ifstream file(filename);

  if (!file.is_open()) { // verification of the file opening
    std::cerr << "error : the file cannot be opened." << std::endl;
    return 1;
  }

  //Eigen::MatrixXd points(5, 3);
  std::vector<Eigen::VectorXd> points; // a dynamic vector because we don't know his size yet
  std::string line;
  int index = 0; // index of the line where we add the new point
  while (std::getline(file, line)) { // each line of the file is read
    std::istringstream iss(line); // each line is turned into int
    std::string token;
    
    Eigen::VectorXd point(3);
    bool validLine = true;

    for (int i = 0; i < 3; ++i) {
      if (iss >> token) { // check the line format
        double value = evaluateTrigExpression(token); // if trigonomic expression (for cercle and ellipse)
        point(i) = value;
      } else {
        std::cerr << "Invalid line format: " << line << std::endl; // if not enough components
        validLine = false;
        break;
      }
    }

    if (validLine) {
      point(2) = std::fabs(point(2)); // to avoid complex conic
      if (point(2) == 0.0) { // if last component w = 0 (infinite point), we don't use it
        std::cout << "infinite point detected: (" << point(0) << ", " << point(1) << ")\n";
      } else if (std::isnan(point(2))){
        point(2) = 1.0; // if the last component is a letter, we change it into the number 1
      } else {
        std::cout << "regular point: (" << point(0) << ", " << point(1) << ", " << point(2) << ")\n";
        //points.row(index) = point;
        points.push_back(point);
        index++;
      }
    }
  }

  assert(index >= 5); // check the number of points read in the file (if there are enough points)
  
  file.close();

  // draw points
  
  // build the matrice A from the coordinates of the 5 points
  //Eigen::MatrixXd A(5, 6);
  Eigen::MatrixXd A(points.size(), 6);
  for (int i = 0; i < points.size(); i++) {
    //Eigen::VectorXd pt(3);
    Eigen::VectorXd pt = points[i];
    //double coordinate_x = pt(0);
    //double coordinate_y = pt(1);
    //double coordinate_w = pt(2);
    //pt << coordinate_x, coordinate_y, coordinate_w;
    viewer.push_point(pt, "p", 200,0,0);
    //A.row(i) << coordinate_x * coordinate_x, coordinate_x *coordinate_ y, coordinate_y * coordinate_y, coordinate_x * coordinate_w, coordinate_y * coordinate_w, coordinate_w * coordinate_w;
    A.row(i) << pt(0) * pt(0), pt(0) * pt(1), pt(1) * pt(1), pt(0) * pt(2), pt(1) * pt(2), pt(2) * pt(2); // each line of A represents an equation based on the algebraic error for one specific point
  }

  // draw line
  // viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // use the SVD to calculate the kernel of A
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
  Eigen::VectorXd svdResult = svd.matrixV().rightCols(1);
  // dans le cours
  /* Eigen::JacobiSVD<Eigen::MatrixXd> svd(A,Eigen::ComputeThinU | Eigen::ComputeThinV);
     Eigen::VectorXd x_svd = svd.solve(b);*/

  // the coefficients a, b, c, d, e, f of the conic are extarcted from x
  double a = svdResult(0);
  double b = svdResult(1);
  double c = svdResult(2);
  double d = svdResult(3);
  double e = svdResult(4);
  double f = svdResult(5);

  // print the coefficients of the conic
  std::cout << "Coefficients de la conique avec la méthode de la Décomposition en Valeurs Singulières : " << std::endl;
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "e = " << e << std::endl;
  std::cout << "f = " << f << std::endl;

  // draw conic
  Eigen::VectorXd conic(6);
  conic << a, b, c, d, e, f;
  viewer.push_conic(conic, 0,0,200);

  // us the least squares method
  //Eigen::VectorXd conicCoefficients = solveLeastSquares(A, points); // to minimize the sum of the squares of these previous errors for all points

  // the coefficients a, b, c, d, e, f of the conic are extarcted from x
  /*a = conicCoefficients(0);
  b = conicCoefficients(1);
  c = conicCoefficients(2);
  d = conicCoefficients(3);
  e = conicCoefficients(4);
  f = conicCoefficients(5);*/

  // print the coefficients of the conic
  /*std::cout << "Coefficients de la conique avec la méthode des Moindres Carrés : " << std::endl;
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "e = " << e << std::endl;
  std::cout << "f = " << f << std::endl;*/

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}
