# include "code_utils.h"

namespace robotmath{
    double clamp(double val, double min, double max){
        if(val<min){
            return min;
        }
        else if(val>max){
            return max;
        }
        else{
            return val;
        }
    }
}
