#include <iostream>
using namespace std;

int main() {
    float rotate_speed = 482; // rpm
    float frequency = 1000;
    float delta_angle = 360 * rotate_speed / (60 * frequency);
    float error_estimate = 0.0;
    float sum = 0.0;
    int cnt = 0;
    float eec = 0.0;
    while (fabs(error_estimate) < 10) {
        float c = 0.0;
        float y = delta_angle;
        float t = sum + y;
        c = (t - sum) - y;
        float eey = c - eec;
        float eet = error_estimate + eey;
        eec = (eet - error_estimate) - eey;
        error_estimate = eet;
        sum = t;
        cout << sum << " " << error_estimate << " " << c << " " << eec << endl;
        cnt++;
    }
    cout << "time: " << cnt / frequency << "s" << endl;
    return 0;
}

// #include <iostream>
// #include <chrono>
// #include <thread>

// int main() {
//   const auto input_clock_period = std::chrono::seconds(1);
//   int prescaler_counter = 0;
//   int prescaler_buffer = 3;
//   int output_signal;

//   while (1) {
//     if (prescaler_counter != prescaler_buffer) {
//       output_signal = 0;
//       prescaler_counter++;
//     } else {
//       output_signal = 1;
//       prescaler_counter = 0;
//     }
//     std::cout << output_signal;
//     std::this_thread::sleep_for(input_clock_period);
//   }

//   return 0;
// }
