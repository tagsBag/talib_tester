#include <iostream>
#include <vector>
#include "talib/include/ta_func.h"

using namespace std;

int main()
{
    // 初始化talib
    if ( TA_Initialize() != TA_SUCCESS)
        return -1;

    double data[50] = {105.68, 93.74, 92.72, 90.52, 95.22, 100.35, 97.92, 98.83, 95.33, 93.4, 95.89, 96.68, 98.78, 98.66, 104.21, 107.48, 108.18, 109.36, 106.94, 107.73, 103.13, 114.92, 112.71, 113.05, 114.06, 117.63, 116.6, 113.72, 108.84, 108.43, 110.06, 111.79, 109.9, 113.95, 115.97, 116.52, 115.82, 117.91, 119.04, 120, 121.95, 129.08, 132.12, 135.72, 136.66, 139.78, 139.14, 139.99, 140.64, 143.66};
    const int data_size = sizeof(data) / sizeof(double);

    vector<double> outRealUpperBand;
    vector<double> outRealMiddleBand;
    vector<double> outRealLowerBand;
    int outBegIdx= 0;
    int outNbElement = 0;

    // dynamically allocate output arrays
    // 5, 2.0, 2.0, TA_MAType_SMA - are defaults for BBANDS
    int sz = data_size - TA_BBANDS_Lookback(20, 2.0, 2.0, TA_MAType_SMA);

    //assert(sz != 0);

    outRealUpperBand.resize(long(sz));
    outRealMiddleBand.resize(long(sz));
    outRealLowerBand.resize(long(sz));

    // get TA results
    TA_RetCode res = TA_BBANDS(0, data_size-1, data, 20, 2.0, 2.0, TA_MAType_SMA, &outBegIdx, &outNbElement,
                               outRealUpperBand.data(), outRealMiddleBand.data(), outRealLowerBand.data());

    if (res != TA_SUCCESS) {
        cout << "Error: " << res;
        return -1;
    }
    else {
        for (long i = 0; i < long(outNbElement); i++){
            cout << "day #" << long(outBegIdx)+i
                 << ": upper: " << outRealUpperBand[i]
                 << ",mid: " << outRealMiddleBand[i]
                 << ",lower: " << outRealLowerBand[i]
                 << ",%B: " << (data[long(outBegIdx)+i] - outRealLowerBand[i]) / (outRealUpperBand[i] - outRealLowerBand[i]);
            cout << endl;
            cout << "---------------------------------------------------" << endl;
        }
    }
    // 关闭talib
    TA_Shutdown();
    return 0;
}
