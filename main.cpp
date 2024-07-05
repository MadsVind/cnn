#include "main.hpp"

typedef std::vector<std::vector<std::vector<float>>> Weights;

std::vector<float> createRandomVector(int size) {
    std::vector<float> randomVector;
    for (int i = 0; i < size; i++) {
        randomVector.push_back(rand() % 100 / 100.0f);
    }
    return randomVector;
}

Weights createWeights(std::vector<int> layers) {
    Weights weights;
    for (int i = 0; i < layers.size() - 1; i++) {
        std::vector<std::vector<float>> layerWeights;
        for (int j = 0; j < layers[i]; j++) {
            layerWeights.push_back(createRandomVector(layers[i + 1]));
        }
        weights.push_back(layerWeights);
    }
    return weights;
}

std::vector<float> createBias(std::vector<int> layers) {
    std::vector<float> bias;
    for (int i = 1; i < layers.size(); i++) {
        bias.push_back(rand() % 100 / 100.0f);
    }
    return bias;
}

void printWeights(Weights weights) {
    for (int i = 0; i < weights.size(); i++) {
        for (int j = 0; j < weights[i].size(); j++) {
            for (int k = 0; k < weights[i][j].size(); k++) {
                std::cout << weights[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}


std::vector<float> sigmoid(std::vector<float> input) {
    std::vector<float> output;
    for (int i = 0; i < input.size(); i++) {
        output.push_back(1 / (1 + exp(-input[i])));
    }
    return output;
}

//std::vector<float> feedForward(std::vector<float> input, Weights weights, std::vector<float> bias) {
//    if (input.size() != weights[0].size()) {
//        std::cout << "Input size does not match input layer size" << std::endl;
//        return {};
//    }
//    std::vector<float> output;
//    for (int i = 0; i < weights.size(); i++) {
//        
//    }
//}


int main() {
    //srand(time(NULL));

    //std::vector<int> layers = {3, 5, 6, 4, 1}; 
    //Weights weights = createWeights(layers);
    //std::vector<float> bias = createBias(layers);
    //printWeights(weights);

    Matrix<double> A;
    A.addRow({1.0, 2.0})
     .addRow({3.0, 4.0})
     .addRow({5.0, 6.0});

    Matrix<double> B;
    B.addRow({7.0, 8.0, 9.0})
     .addRow({10.0, 11.0, 12.0});

    Matrix<double> C;
    C.addRow({1.0, 2.0, 3.0})
     .addRow({4.0, 5.0, 6.0});

    Matrix<double> D = B.transpose();

    Matrix<double> I;
    I.addRow({7.0, 11.0, 2.0})
     .addRow({13.0, 5.0, 10.0})
     .addRow({12.0, 3.0, 6.0});

    I.inverse().print();
    //D.print();

    return 0;
}
