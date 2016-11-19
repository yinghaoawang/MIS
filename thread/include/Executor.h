//
// Created by CIJhn on 11/17/2016.
//

#ifndef MISVM_EXECUTOR_H
#define MISVM_EXECUTOR_H


#include <functional>

class Executor {
    using Task=std::function<void()>;
    template<typename T>
    using ReturnTask = std::function<T()>;


};


#endif //MISVM_EXECUTOR_H
