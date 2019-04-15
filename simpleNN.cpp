#include <torch/script.h>
#include <torch/torch.h>
#include <iostream>
#include <vector>
#include "dataset.h"

struct Net : torch::nn::Module {
  Net() {
    // Construct and register two Linear submodules.
    fc1 = register_module("fc1", torch::nn::Linear(4, 10));
    fc2 = register_module("fc2", torch::nn::Linear(10, 3));
  }

  // Implement the Net's algorithm.
  torch::Tensor forward(torch::Tensor x) {
    // Use one of many tensor manipulation functions.
    x = torch::relu(fc1->forward(x.view({-1,4})));
    x = torch::log_softmax(fc2->forward(x),1);
    return x;
  }

  torch::nn::Linear fc1{nullptr}, fc2{nullptr};
};

int main() {

  //loading data
  DataSet data_set("/home/vipul/Documents/vaibhawvipul/DeepLearning/simpleNN-pytorch-cpp/iris.csv");

  at::Tensor input_tensor;
  at::Tensor output_tensor;

  std::vector<float> input_vector;
  std::vector<float> target_output;
  
  // Iterate the data loader to yield batches from the dataset.
  for (unsigned i = 0; i < data_set.x1().size(); i++) {

    //form an input tensor combined of x1, x2, x3 and x4
    
    input_vector.push_back(data_set.x1()[i]);
    input_vector.push_back(data_set.x2()[i]);
    input_vector.push_back(data_set.x3()[i]);
    input_vector.push_back(data_set.x4()[i]);

    target_output.push_back(data_set.y()[i]);
    
  }

  at::TensorOptions options(at::ScalarType::Long);

  //float* data = tensor.data<float>();

  input_tensor = torch::from_blob(input_vector.data(),{150,4});
  input_tensor = input_tensor.toType(at::kFloat);

  output_tensor = torch::from_blob(target_output.data(),{long(target_output.size())});
  output_tensor = output_tensor.toType(at::ScalarType::Long);

  //loading model 
  auto net = std::make_shared<Net>();

  //setting up optimizer
  torch::optim::SGD optimizer(net->parameters(), /*lr=*/0.01);

  for (size_t epoch = 1; epoch <= 500; ++epoch) {
      // Reset gradients.
      optimizer.zero_grad();
      // Execute the model on the input data.
      torch::Tensor prediction = net->forward(input_tensor);
      // Compute a loss value to judge the prediction of our model.
      torch::Tensor loss = torch::nll_loss(prediction,output_tensor);
      // Compute gradients of the loss w.r.t. the parameters of our model.
      loss.backward();
      // Update the parameters based on the calculated gradients.
      optimizer.step();
      // Output the loss.
      std::cout << "Epoch: " << epoch << " | Loss: " << loss.item<float>() << std::endl;
      // Serialize your model periodically as a checkpoint.
      torch::save(net, "net.pt");
  }
  return 0;
}


