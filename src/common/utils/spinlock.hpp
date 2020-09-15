/*
 Copyright 2016-2020 Intel Corporation
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
     http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#pragma once

#include <atomic>
#include <immintrin.h>

class ccl_spinlock {
public:
    ccl_spinlock();
    ccl_spinlock(const ccl_spinlock&) = delete;
    ~ccl_spinlock() = default;

    void lock();
    bool try_lock();
    void unlock();

private:
    std::atomic_flag flag;
};
