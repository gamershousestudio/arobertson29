#include<iostream>

using namespace std;

double ForwardPass(double w, double b, double x)
{
    return w * x + b;
}

int main()
{

    // Training data
    double inputs[] = {11.0, 37.0, 56.0};
    double outputs[] = {983, 3219, 4853};
    short int n = sizeof(inputs) / sizeof(inputs[0]);

    // Variables
    double w = 0.01;
    double b = 0.01;

    // Consts
    const double learning_rate = .1;
    const long int epochs = 10000;

    // Training loop
    for(long int i = 0; i < epochs; i++)
    {
        // Gradients
        double d_w = 0;
        double d_b = 0;

        for(int j = 0; j < n; j++)
        {
            double x = inputs[j];
            double y = outputs[j];

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