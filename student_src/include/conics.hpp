#pragma once

#include <vector>
#include <Eigen/Dense>
#include "Geogebra_conics.hpp"

class Conic {
public:
    Conic(const std::string& filename); // constructor based on a file containing all the points

    Eigen::VectorXd solveLeastSquares();

    void printCoefficients(const Eigen::VectorXd& coefficients);

    void drawConic(const Eigen::VectorXd& coefficients, Viewer_conic& viewer);

private:
    std::string filename_;
    std::vector<Eigen::VectorXd> points_;
};