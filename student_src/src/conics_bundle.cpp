#include "conics.hpp"

using namespace MyConics;

ConicBundle::ConicBundle();

ConicBundle::ConicBundle(const std::string& filenameA, const std::string& filenameB) :

ConicBundle::~ConicBundle() {}; // destructor

Eigen::VectorXd ConicBundle::generateConicFromBundle(double t) const {
    double cosValue = std::cos(t);
    double sinValue = std::sin(t);

    Eigen::VectorXd conic = cosValue * m_conicA_.solveLeastSquares() + sinValue * m_conicB_.solveLeastSquares();
    
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
