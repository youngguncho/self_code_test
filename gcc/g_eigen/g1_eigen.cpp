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
    mat1.setRandom(3, 20);

    Array3f pt;
    pt << 1, 0, 0;

    MatrixXf pt_mat;
    pt_mat = pt.rowwise().replicate(20);    
    eigen_cout ("pt", pt);
    eigen_cout ("pt_mat", pt_mat);


    Vector3f vpt;
    vpt << -1, 1, 0;
    MatrixXf vpt_mat;
    vpt_mat = vpt.rowwise().replicate(20);
    eigen_cout("vpt", vpt);
    eigen_cout("vpt_mat", vpt_mat);

    MatrixXf norm = vpt_mat.colwise().norm();
    
    ArrayXXf last(1, 20);
    last = norm.cwiseQuotient(norm);
    
    eigen_cout("vpt_norm", norm);
    eigen_cout("vpt last", last);
    eigen_cout("vpt acos", last.acos());
    
    VectorXf dd = VectorXf::Constant(10, 1);
    eigen_cout("vector", dd);


    VectorXf block_mat = pt_mat.col(4);
    eigen_cout("block mat", block_mat);    
    
    JacobiSVD<Matrix<float, Dynamic, Dynamic, RowMajor> > svd(mat1, ComputeThinU | ComputeThinV);
    cout << "Its singular values are:" << endl << svd.singularValues() << endl;
    cout << "Its left singular vectors are the columns of the thin U matrix:" << endl << svd.matrixU() << endl;
    cout << "Its right singular vectors are the columns of the thin V matrix:" << endl << svd.matrixV() << endl;

    MatrixXf V_mat = svd.matrixV();
    cout << "plane param " << endl << V_mat  << endl << svd.matrixV().col(3) << endl;

    return 0;
}
