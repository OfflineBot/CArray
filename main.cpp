
#include "./carray/carray.hpp"
#include <iostream>

using namespace CArray;

int main() {

    int iterations = 10000;
    float learning_rate = 0.01;
    float loss_break = 0.001;
    int input_size = 2;
    int hidden_size = 10;
    int output_size = 1;

    Array2<float> data_input = { {1, 1}, {0, 0}, {1, 0}, {0, 1} };
    Array1<float> input_mean = data_input.mean();
    Array1<float> input_std = data_input.std();
    Array2<float> norm_input = (data_input - input_mean) / input_std;

    Array2<float> data_output = { {0}, {0}, {1}, {11} };
    Array1<float> output_mean = data_output.mean();
    Array1<float> output_std = data_output.std();
    Array2<float> norm_output = (data_output - output_mean) / output_std;

    Array2<float> new_input = data_input;
    Array2<float> new_input_norm = (new_input - input_mean) / input_std;


    float min = -1.0; float max = 1.0;
    Array2<float> w1(input_size, hidden_size);
    Array1<float> b1(hidden_size);
    Array2<float> w2(hidden_size, output_size);
    Array1<float> b2(output_size);
    w1.random_uniform(min, max);
    b1.random_uniform(min, max);
    w2.random_uniform(min, max);
    b2.random_uniform(min, max);


    for (int i = 0; i < iterations; i++) {

        // forward
        Array2<float> z1 = linear(norm_input, w1, b1);
        Array2<float> a1 = relu(z1);
        Array2<float> z2 = linear(a1, w2, b2);

        float loss = mse_loss(z2, norm_output);

        // backward
        Array2<float> delta2 = z2 - norm_output;
        Array2<float> delta1 = delta2.dot(w2.t()) * deriv_sigmoid(z1);

        if (i % 100 == 0)
            printf("Iterations: %d | Loss: NOT IMPLEMENTED YET!\n", i);

    }

    return 0;
}
