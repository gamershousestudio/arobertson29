#include<iostream>

using namespace std;

double ForwardPass(double w, double b, double x){
    return w * x + b;
}

int main(){

    // Training data
    float inputs[] = {1.0f, 2.0f, 3.0f};
    float outputs[] = {3.0f, 5.0f, 7.0f};
    short int n = sizeof(inputs) / sizeof(inputs[0]);

    // Variables
    double w = 0.01;
    double b = 0.01;

    // Consts
    const float learning_rate = .1;
    const short int epochs = 1000;

    // Training loop
    for(int i = 0; i < epochs; i++){
        // Gradients
        double d_w = 0;
        double d_b = 0;

        for(int j = 0; j < n; j++){
            float x = inputs[j];
            float y = outputs[j];

            double y_pred = ForwardPass(w, b, x);

            double error = y_pred - y;

            d_w += (2 / (double)n) * error * x;
            d_b += (2 / (double)n) * error;
        }

        w = w - learning_rate * d_w;
        b = b - learning_rate * d_b;

        cout << "w: " << w << ";  b: " << b << ".\n";
    }

    return 0;
}