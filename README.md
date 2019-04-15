# simpleNN-pytorch-cpp
A simple Neural Network for iris dataset in pytorch using cpp frontend

How to build - 

- download libTorch - [refer this doc](https://pytorch.org/cppdocs/installing.html)
- download iris dataset - [here](https://raw.githubusercontent.com/uiuc-cse/data-fa14/gh-pages/data/iris.csv)
- `git clone https://github.com/vaibhawvipul/simpleNN-pytorch-cpp.git`
- `cd simpleNN-pytorch-cpp` 
- `cmake -DCMAKE_PREFIX_PATH=/path/to/libtorch`
- `mkdir build`
- `make -j`

Run - 

- `./simpleNN`

