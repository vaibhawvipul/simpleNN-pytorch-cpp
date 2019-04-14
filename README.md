# simpleNN-pytorch-cpp
A simple Neural Network in pytorch using cpp frontend

How to build - 

- download libTorch - [refer this doc](https://pytorch.org/cppdocs/installing.html)
- git clone the repo
- `cd simpleNN-pytorch-cpp` 
- `cmake -DCMAKE_PREFIX_PATH=/path/to/libtorch ..`
- `mkdir build`
- `make -j`

after the above steps you will get an executable in `build` folder.

Run - 

- `./simpleNN`

**Error** - 

Right now I am facing the following error, if you fix it then feel free to raise a PR - 

```
terminate called after throwing an instance of 'c10::Error'
  what():  Expected Tensor (not Variable) for argument #2 'mat2' (checked_tensor_unwrap at /pytorch/aten/src/ATen/Utils.h:77)
frame #0: std::function<std::string ()>::operator()() const + 0x11 (0x7fcee0d54bf1 in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libc10.so)
frame #1: c10::Error::Error(c10::SourceLocation, std::string const&) + 0x2a (0x7fcee0d5452a in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libc10.so)
frame #2: <unknown function> + 0xcbd069 (0x7fced7490069 in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #3: <unknown function> + 0xccc95d (0x7fced749f95d in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #4: at::native::mm(at::Tensor const&, at::Tensor const&) + 0x65 (0x7fced7287da5 in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #5: at::TypeDefault::mm(at::Tensor const&, at::Tensor const&) const + 0x5d (0x7fced762f89d in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #6: <unknown function> + 0xabac05 (0x7fced728dc05 in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #7: at::native::matmul(at::Tensor const&, at::Tensor const&) + 0x27 (0x7fced728e4e7 in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #8: at::TypeDefault::matmul(at::Tensor const&, at::Tensor const&) const + 0x5d (0x7fced76310bd in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #9: at::native::linear(at::Tensor const&, at::Tensor const&, at::Tensor const&) + 0x71 (0x7fced727ce21 in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #10: at::TypeDefault::linear(at::Tensor const&, at::Tensor const&, at::Tensor const&) const + 0x6c (0x7fced7631b2c in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libcaffe2.so)
frame #11: torch::nn::LinearImpl::forward(at::Tensor const&) + 0x5d (0x7fcee1b52c3d in /home/vipul/Documents/vaibhawvipul/DeepLearning/libtorch/lib/libtorch.so.1)
frame #12: Net::forward(at::Tensor) + 0x8f (0x430fe1 in ./simpleNN)
frame #13: main + 0x48b (0x42d304 in ./simpleNN)
frame #14: __libc_start_main + 0xf0 (0x7fced5c74830 in /lib/x86_64-linux-gnu/libc.so.6)
frame #15: _start + 0x29 (0x4288e9 in ./simpleNN)


```
- 
