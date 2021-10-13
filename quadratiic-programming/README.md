
## Setup OSQP
### 1. Download source
```
git clone --recursive https://github.com/osqp/osqp
```
### 2. Create `build` directory
```
cd osqp
mkdir build
cd build
```
### 3. Create Makefiles and Compile OSQP and install
```
cmake -G "Unix Makefiles" ..
cmake --build .
sudo make install
```
