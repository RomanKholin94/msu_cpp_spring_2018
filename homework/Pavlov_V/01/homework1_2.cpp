#include <chrono>
#include <iostream>
#include <chrono>
#include<ctime>

using namespace std;


class Timer
{
public:
    Timer()
    : start_(std::chrono::high_resolution_clock::now())
    {
    }
    
    ~Timer()
    {
        const auto finish = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count() << " us" << std::endl;
    }
    
private:
    const std::chrono::high_resolution_clock::time_point start_;
};


int main() {
    srand(time(0));
    int sum = 0;
    const unsigned int size = 10000;
    int **array;
    array = new int * [size];
    for(int i = 0; i < size; ++i){
        array[i] = new int[size];
    }
    
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            array[i][j] = rand() % 100;
        }
    }
    Timer t;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            sum += array[j][i];
        }
    }
    for (int i = 0; i < size; i++)
        delete[] array[i];
    delete[] array;
    
    return 0;
}


