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
#include "common/comm/l0/communicator/typed_base_communicator.hpp"

namespace native {
struct device_group_context;
}

class device_group_a2a_communicator
        : public typed_base_communicator<device_group_a2a_communicator,
                                         ccl::device_group_split_type::thread,
                                         ccl::device_topology_type::a2a,
                                         ccl::gpu_communicator_traits> {
public:
    using base_t = typed_base_communicator<device_group_a2a_communicator,
                                           ccl::device_group_split_type::thread,
                                           ccl::device_topology_type::a2a,
                                           ccl::gpu_communicator_traits>;

    device_group_a2a_communicator(ccl::unified_device_type&& device,
                                  size_t thread_idx,
                                  size_t proces_idx,
                                  const ccl::device_comm_attr_t& attr);

    void visit(ccl::gpu_comm_attr& comm_attr) override;

    void barrier(ccl::stream::impl_t& stream) override;

    COMM_IMPL_DECLARATION
    COMM_IMPL_CLASS_DECLARATION
    COMM_IMPL_SPARSE_DECLARATION
    COMM_IMPL_SPARSE_CLASS_DECLARATION

private:
    std::shared_ptr<native::device_group_context> ctx;
};
