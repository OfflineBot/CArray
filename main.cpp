
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
    norm_input.replace(0, 0.001);

    Array2<float> data_output = { {0}, {0}, {1}, {1} };
    Array1<float> output_mean = data_output.mean();
    Array1<float> output_std = data_output.std();
    Array2<float> norm_output = (data_output - output_mean) / output_std;
    norm_output.replace(0, 0.001);

    Array2<float> new_input = { {1, 1}, {0, 0}, {1, 0}, {0, 1}, {1, 0}, {1, 0} };
    Array2<float> new_input_norm = (new_input - input_mean) / input_std;
    new_input_norm.replace(0, 0.001);


    float min = -1.0; float max = 1.0;
    Array2<float> w1(input_size, hidden_size);
    Array1<float> b1(hidden_size);
    Array2<float> w2(hidden_size, output_size);
    Array1<float> b2(output_size);
    w1.random_uniform(min, max);
    b1.random_uniform(min, max);
    w2.random_uniform(min, max);
    b2.random_uniform(min, max);

    // loop
    for (int i = 0; i < iterations; i++) {

        // forward
        Array2<float> z1 = linear(norm_input, w1, b1);
        Array2<float> a1 = relu(z1);
        Array2<float> z2 = linear(a1, w2, b2);

        float loss = mse_loss(z2, norm_output);

        if (loss < loss_break) {
            printf("Loss break at iteration: %d!\n", i);
            break;
        }

        if (i % 100 == 0)
            printf("Iterations: %d | Loss: %f\n", i, loss);

        // backward
        Array2<float> delta2 = z2 - norm_output;
        Array2<float> t_w2 = w2.t();

        Array2<float> d_sig = deriv_sigmoid(z1);
        Array2<float> delta1 = delta2.dot(t_w2) * d_sig;

        // gradients
        Array2<float> w2_gradient = a1.t().dot(delta2);
        Array1<float> b2_gradient = delta2.sum();
        Array2<float> w1_gradient = norm_input.t().dot(delta1);
        Array1<float> b1_gradient = delta1.sum();

        // update
        w2 -= w2_gradient * learning_rate;
        b2 -= b2_gradient * learning_rate;
        w1 -= w1_gradient * learning_rate;
        b1 -= b1_gradient * learning_rate;
    }

    Array2<float> z1 = linear(new_input_norm, w1, b1);
    Array2<float> a1 = relu(z1);
    Array2<float> z2 = linear(a1, w2, b2);
    Array2<float> output = z2 * output_std + output_mean;
    output.print();

    return 0;
}
