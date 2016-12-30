#include <iostream>
#include <string>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/SVD>

using namespace std;
using namespace Eigen;

template <typename T>
inline void eigen_cout (string name, T data)
{
    cout << name << endl << data << endl;
};


int main(void)
{
    MatrixXf mat1;
    mat1.setRandom(5, 4);
    
    JacobiSVD<Matrix<float, Dynamic, Dynamic, RowMajor> > svd(mat1, ComputeThinU | ComputeThinV);
    cout << "Its singular values are:" << endl << svd.singularValues() << endl;
    cout << "Its left singular vectors are the columns of the thin U matrix:" << endl << svd.matrixU() << endl;
    cout << "Its right singular vectors are the columns of the thin V matrix:" << endl << svd.matrixV() << endl;

    MatrixXf V_mat = svd.matrixV();
    cout << "plane param " << endl << V_mat  << endl << svd.matrixV().col(3) << endl;

    return 0;
}
