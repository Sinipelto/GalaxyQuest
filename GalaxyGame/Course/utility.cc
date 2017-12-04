#include "utility.hh"
#include <cstdlib>
#include <cassert>
#include <cmath>

namespace Common
{
    static bool initialized = false;

    void utilityInit(int seed)
    {
        assert(!initialized && "UTILITY: Must not initialize twice.");

        srand(seed);

        initialized = true;
    }

    int randomMinMax(int min, int max)
    {
        assert(initialized && "UTILITY: Must be initialized before use.");
        assert(min <= max && "UTILITY: Maximum must be at least minimum.");

        return rand() % (max - min + 1) + min;
    }

    double distance(double x1, double y1, double x2, double y2)
    {
        assert(initialized && "UTILITY: Must be initialized before use.");

        double x_diff = x1 - x2;
        double y_diff = y1 - y2;

        return sqrt(x_diff*x_diff + y_diff*y_diff);
    }
}
