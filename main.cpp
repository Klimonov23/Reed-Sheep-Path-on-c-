#include <iostream>
#include "RSP/ReedsShepp.h"
int main() {
    double step_size = 0.5;
    float rho = 5.8;
    auto *reedsSheppStateSpace=new ReedsSheppStateSpace(rho);
    double arr[3]={0.0, 0.0, M_PI/4};
    double arr1[3]={3.0, 4.0,0.0};
    std::cout << reedsSheppStateSpace->distance(arr,arr1) << std::endl;
    ReedsSheppStateSpace::ReedsSheppPath path = reedsSheppStateSpace->reedsShepp(arr,arr1);
    double dist = rho * path.length();
    for (double seg=0.0; seg<=dist; seg+=step_size){
        double qnew[3] = {};
        reedsSheppStateSpace->interpolate(arr, path, seg/rho, qnew);
        std::cout<<qnew[0]<<"  "<<qnew[1]<< " "<< qnew[2]<<std::endl;
    }
    return 0;
}
