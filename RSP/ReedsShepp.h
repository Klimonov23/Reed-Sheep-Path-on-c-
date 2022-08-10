#ifndef SHIT2_REEDSSHEPP_H
#define SHIT2_REEDSSHEPP_H
#include <boost/math/constants/constants.hpp>
#include <cassert>
#include <limits>

typedef int (*ReedsSheppPathSamplingCallback)(double q[3], void* user_data);
typedef int (*ReedsSheppPathTypeCallback)(int t, void* user_data);

class ReedsSheppStateSpace
{
public:

    // The Reeds-Shepp path segment types
    enum ReedsSheppPathSegmentType { RS_NOP=0, RS_LEFT=1, RS_STRAIGHT=2, RS_RIGHT=3 };

    // Reeds-Shepp path types
    static const ReedsSheppPathSegmentType reedsSheppPathType[18][5];


    class ReedsSheppPath
    {
    public:
        ReedsSheppPath(const ReedsSheppPathSegmentType* type=reedsSheppPathType[0],
                       double t=std::numeric_limits<double>::max(), double u=0., double v=0.,
                       double w=0., double x=0.);

        double length() const { return totalLength_; }

        // Path segment types
        const ReedsSheppPathSegmentType* type_;
        // Path segment lengths
        double length_[5];
        // Total length
        double totalLength_;
    };

    ReedsSheppStateSpace(double turningRadius) : rho_(turningRadius) {}

    double distance(double q0[3], double q1[3]); //return total length of Reed Shepps curve from q0 to q1 with specified turning radius

    //Return the tuple of path segment type for the Reed Sheps curve from q0 to q1 with specified turning radius
    void type(double q0[3], double q1[3], ReedsSheppPathTypeCallback cb, void* user_data);

    //Return list of tuple (x,y,theta) uniformly sampled from corresponding Reed Shepps curve
    void sample(double q0[3], double q1[3], double step_size, ReedsSheppPathSamplingCallback cb, void* user_data);

    // Return the shortest Reeds-Shepp path from SE(2) state state1 to SE(2) state state2
    ReedsSheppPath reedsShepp(double q0[3], double q1[3]);

public:
    void interpolate(double q0[3], ReedsSheppPath &path, double seg, double q[3]);

    //Turning radius
    double rho_;
};
#endif //SHIT2_REEDSSHEPP_H
