// ## Task-1 : Raw Array 
// ### Create an array containing 5 sensor readings.
# include <iostream>
int main(){
    int sensor_data[5] = { 17, 26, 34, 1, 7};
    int a = 1;
    for (int i = 0; i < 5; i++){
        std::cout << "Sensor Number " << a << ":" << " Data : " << sensor_data[i] << std::endl;
        a++;
    }
}