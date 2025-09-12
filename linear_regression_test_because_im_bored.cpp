#include<iostream>

float Return(double w, double b, double x);

int main(){
    using std::cin, std::cout;

    // Training data
    float inputs[] = {1.0f, 2.0f, 3.0f};
    float outputs[] = {3.0f, 5.0f, 7.0f};

    // Variables
    double w = 0.01;
    double b = 0.01;

    // Consts
    const float learning_rate = .1f;
    const short int epochs = 100;

    // Training loop
    for(int i = 0; i < epochs; i++){
        // Gradients
        double d_w = 0;
        double d_b = 0;

        for(int i = 0; i < sizeof(inputs); i++){

        }
    }

    return 0;
}

float Return(double w, double b, double x){
    return w * x + b;
}