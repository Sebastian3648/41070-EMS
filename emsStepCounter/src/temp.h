#include <Arduino.h>

class accelerometerData{
    public:
    accelerometerData();
    void collect();
    void computeVectors();
    void determineAverageDirectionChangeMagnitude();
    void saveCallibrationData();
    bool stepCheck();
    void dataClear();
};