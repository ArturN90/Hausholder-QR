#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <eigen3/Eigen/Dense>

int dimension;
int iter;


using namespace Eigen;

double householder(MatrixXf M, int dimension, int column);
VectorXf vector(MatrixXf M, int column);

//--------------VECTORS---------------------------
VectorXf vector(MatrixXf M, int column) {
  MatrixXf I = MatrixXf::Identity(dimension, dimension);
  VectorXf v(dimension);
  int i=0;
  v=M.col(column);

  if (column > 0){
	  do{	
		  v(i)=0.0;	  
		  i++;
	  }while(i<column);
  }
  double N = v.norm();
  

  v = N*I.col(column) + v ;
  return v;
}

//-----------------Householder-----------------------
MatrixXf householder(MatrixXf M, int column) {
  VectorXf VV(dimension);
  MatrixXf H(dimension, dimension);
  MatrixXf I = MatrixXf::Identity(dimension, dimension);
  VV=vector(M, column);

  H = I - 2* VV * VV.transpose() /(VV.transpose() *VV);
  return H;
}