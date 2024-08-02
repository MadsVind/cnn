
#include <matrixTest.hpp>

// Test cases for calcEigen method
TEST_CASE("Matrix calcEigen method", "[calcEigen]") {
    Matrix<double> matrix1;
    Matrix<double> matrix2;
    Matrix<double> matrix3;

    matrix1.addRow({1, 2, 3})
           .addRow({4, 5, 6})
           .addRow({7, 8, 9});

    matrix2.addRow({1, 0, 0})
           .addRow({0, 2, 0})
           .addRow({0, 0, 3});

    matrix3.addRow({4, -1, 0})
           .addRow({-1, 4, -1})
           .addRow({0, -1, 4});

    SECTION("Normal case with square matrix") {
        Matrix<double>::Eigen eigen = matrix1.eigen(1e-9);

        // Expected eigenvalues for the given matrix
        std::vector<double> expectedEigenValues = {16.1168, -1.11684, 0};

        // Compare eigenvalues
        REQUIRE(checkVecApprox(eigen.valueVec, expectedEigenValues));
    }

    SECTION("Diagonal matrix") {
        Matrix<double>::Eigen eigen = matrix2.eigen(1e-9);

        // Expected eigenvalues for the given matrix
        std::vector<double> expectedEigenValues = {1, 2, 3};

        // Compare eigenvalues
        REQUIRE(checkVecApprox(eigen.valueVec, expectedEigenValues));
    }


// !!! can't do before qr can do linear dependency
//    SECTION("Symmetric matrix") {
//        
//        Matrix<double>::Eigen eigen = matrix3.calcEigen(1e-9);
//
//        // Expected eigenvalues for the given matrix
//        std::vector<double> expectedEigenValues = {2.26795, 4, 5.73205};
//
//        // Compare eigenvalues
//        REQUIRE(checkVecApprox(eigen.valueVec, expectedEigenValues));
//    }

    SECTION("Non-square matrix") {
        Matrix<double> nonSquareMatrix;
        nonSquareMatrix.addRow({1, 2, 3})
                       .addRow({4, 5, 6});

        REQUIRE_THROWS(nonSquareMatrix.eigen(1e-9));
    }
}