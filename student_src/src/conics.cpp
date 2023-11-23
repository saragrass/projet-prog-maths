#include <cmath>
#include <fstream> // std::ifstream
#include <sstream> // std::istringstream

#include "conics.hpp"

using namespace MyConics;

double evaluateTrigExpression(const std::string &expression) {
    // check if the expression contains "cos" or "sin"
    if (expression.find("cos") != std::string::npos) { // if std::string::find doesn't find th expression, it returns std::string::npos
        double angle;
        sscanf(expression.c_str(), "cos(%lf)", &angle); // "&lf" converts the string into a double
        return std::cos(angle * M_PI / 180.0); // converts the angle from degrees to radians
    } else if (expression.find("sin") != std::string::npos) {
        double angle;
        sscanf(expression.c_str(), "sin(%lf)", &angle);
        return std::sin(angle * M_PI / 180.0);
    } else {
        try {
            return std::stod(expression);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid value or expression: " << expression << " (if it's the last component, let's change it into 1)" << std::endl;
            return std::numeric_limits<double>::quiet_NaN(); // return NaN instead of an error, it allows to return a value anyway
        }
    }
}

/////////////////////////////////////////////////// conic

Conic::Conic() {}; // default constructor

Conic::Conic(const std::string& filename) : filename_(filename) { readPointsFromFile();} // constructor with a file containing points

Eigen::VectorXd Conic::solveLeastSquares() const{
    assert(points_.size() >= 5 && "There must be at least 5 points.");

    Eigen::MatrixXd A = buildMatrixA();
    Eigen::VectorXd coefficients = SVDMethod(A);

    return coefficients;
}

void Conic::readPointsFromFile() {
    std::ifstream file(filename_); // open the file with the given filename for reading
    try {
        if (!file.is_open()) {
            throw std::runtime_error("Error: the file cannot be opened.");
        }

        std::string line; 
        // read each line and analyse its content
        while (std::getline(file, line)) { // read a line from the file and store it in the string 'line'
            analyseLine(line);
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        throw;
    }

    file.close();
}

void Conic::analyseLine(const std::string& line) {
    std::istringstream iss(line);
    std::string token;

    Eigen::VectorXd point(3);
    bool validLine = true;

    // extract values from the line and build a 3D point
    for (int i = 0; i < 3; ++i) {
        if (iss >> token) {
            double value = evaluateTrigExpression(token);
            point(i) = value;
        } else {
            std::cerr << "Invalid line format: " << line << std::endl;
            validLine = false;
            break;
        }
    }

    if (validLine) {
        point(2) = std::fabs(point(2));
        if (point(2) == 0.0) {
            std::cout << "Infinite point detected: (" << point(0) << ", " << point(1) << ")\n";
        } else if (std::isnan(point(2))) {
            point(2) = 1.0;
        } else {
            std::cout << "Regular point: (" << point(0) << ", " << point(1) << ", " << point(2) << ")\n";
            points_.push_back(point);
        }
    }
}

Eigen::MatrixXd Conic::buildMatrixA() const {
    Eigen::MatrixXd A(points_.size(), 6);
    // fill matrix A based on the points
    for (size_t i = 0; i < points_.size(); i++) {
        Eigen::VectorXd pt = points_[i];
        A(i, 0) = pt(0) * pt(0);
        A(i, 1) = pt(0) * pt(1);
        A(i, 2) = pt(1) * pt(1);
        A(i, 3) = pt(0) * pt(2);
        A(i, 4) = pt(1) * pt(2);
        A(i, 5) = pt(2) * pt(2);
    }
    return A;
}

Eigen::VectorXd Conic::SVDMethod(const Eigen::MatrixXd& A) const {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
    Eigen::VectorXd coefficients = svd.matrixV().rightCols(1);
    return coefficients;
}

void Conic::printCoefficients(const Eigen::VectorXd& coefficients) const {
    std::cout << "Coefficients de la conique avec la méthode des Moindres Carrés : " << std::endl;
    for (int i = 0; i < coefficients.size(); ++i) {
        std::cout << "a" << i + 1 << " = " << coefficients(i) << std::endl;
    }
}

void Conic::drawConic(const Eigen::VectorXd& coefficients, Viewer_conic& viewer, const unsigned int &red, const unsigned int &green, const unsigned int &blue) const {
    // draw the points in the viewer
    for (const auto& pt : points_) {
        viewer.push_point(pt, "p", 200, 0, 0);
    }

    Eigen::VectorXd conic(6);
    // fill the conic vector with coefficients
    conic << coefficients(0), coefficients(1), coefficients(2), coefficients(3), coefficients(4), coefficients(5);
    // draw the conic in the viewer
    viewer.push_conic(conic, red, green, blue);
}

void Conic::displayConic() const {
    Eigen::VectorXd conicCoefficients = solveLeastSquares();

    printCoefficients(conicCoefficients);

    Viewer_conic viewer;

    drawConic(conicCoefficients, viewer);

    viewer.display();
    viewer.render("output.html");
}

/////////////////////////////////////////////////// conic bundle

ConicBundle::ConicBundle(const std::string& filenameA, const std::string& filenameB) : conicA_(filenameA), conicB_(filenameB) {}

Eigen::VectorXd ConicBundle::generateConicFromBundle(double t) const {
    double cosValue = std::cos(t);
    double sinValue = std::sin(t);

    Eigen::VectorXd conic = cosValue * conicA_.solveLeastSquares() + sinValue * conicB_.solveLeastSquares();
    
    double norm = conic.norm();
    conic /= norm;
    return conic;
}

void ConicBundle::displayConicBundle(double tStep) const {
    
    Viewer_conic viewer;

    for (double t = 0.0; t <= M_PI; t += tStep) {
        Eigen::VectorXd conicCoefficients = generateConicFromBundle(t);

        std::cout << "Conic for t = " << t << ":" << std::endl;
        printCoefficients(conicCoefficients);
        std::cout << std::endl;

        // gradiant from red to blue
        unsigned int red = static_cast<int>(255 * (1 - t / M_PI));
        unsigned int green = static_cast<int>(255 * 0.5 * (1 + std::sin(t - M_PI / 6.0)));
        unsigned int blue = static_cast<int>(255 * (t / M_PI));

        drawConic(conicCoefficients, viewer, red, green, blue);
    }

    viewer.display();
    viewer.render("output_bundle.html");
}
