#pragma once

#include <vector>
#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

namespace MyConics {
    class Conic {
        public:
            Conic();

            Conic(const std::string& filename); // constructor based on a file containing all the points

            virtual Eigen::VectorXd solveLeastSquares() const;

            virtual void printCoefficients(const Eigen::VectorXd& coefficients) const;

            virtual void drawConic(const Eigen::VectorXd& coefficients, Viewer_conic& viewer, const unsigned int &red = 0, const unsigned int &green = 0, const unsigned int &blue = 200) const;

            virtual void displayConic() const;

        private:
            void readPointsFromFile();
            void analyseLine(const std::string& line);
            Eigen::MatrixXd buildMatrixA() const;
            Eigen::VectorXd SVDMethod(const Eigen::MatrixXd& A) const;

        private:
            std::string filename_;
            std::vector<Eigen::VectorXd> points_;
    };
    
    class ConicBundle : public Conic {
        public:
            ConicBundle(const std::string& filenameA, const std::string& filenameB);

            virtual Eigen::VectorXd generateConicFromBundle(double t) const;

            virtual void displayConicBundle(double tStep = 0.1) const;

        private:
            Conic conicA_;
            Conic conicB_;
    };
}
