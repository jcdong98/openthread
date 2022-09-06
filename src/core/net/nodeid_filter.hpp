/*
 *  Copyright (c) 2022, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file includes definitions for node ID filtering.
 */

#ifndef NODEID_FILTER_HPP_
#define NODEID_FILTER_HPP_

#include "openthread-core-config.h"

#include "common/bit_vector.hpp"
#include "common/locator.hpp"
#include "common/non_copyable.hpp"

namespace ot {
namespace NodeId {

/**
 * @addtogroup core-nodeidfilter
 *
 * @brief
 *   This module includes definitions for node ID filtering.
 *
 * @{
 *
 */

/**
 * This class implements a node ID filter.
 *
 */
class Filter : public InstanceLocator, private NonCopyable
{
public:
    /**
     * This constructor initializes the Filter object.
     *
     */
    explicit Filter(Instance &aInstance);

    /**
     * This method returns whether the node is connectable.
     *
     * @param[in]  aNodeId  The node ID to connect.
     *
     * @returns    The state of connectivity.
     *
     */
    bool IsConnectable(uint16_t aNodeId) const;

    /**
     * This method denies the connection to a specified node.
     *
     * @param[in]  aNodeId  The node ID to deny connection.
     *
     */
    void Deny(uint16_t aNodeId);

    /**
     * This method restores the connection state to default.
     *
     */
    void Clear();

private:
    BitVector<OPENTHREAD_SIMULATION_MAX_NETWORK_SIZE> mDeniedNodeIdsBitVector;
};

} // namespace NodeId
} // namespace ot

#endif // NODEID_FILTER_HPP_
