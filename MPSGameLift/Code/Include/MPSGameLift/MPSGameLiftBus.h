/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace MPSGameLift
{
    class MPSGameLiftRequests
    {
    public:
        AZ_RTTI(MPSGameLiftRequests, "{973EF127-5D1B-43EF-A03B-CEFCDCF5CF16}");
        virtual ~MPSGameLiftRequests() = default;
        // Put your public methods here
    };
    
    class MPSGameLiftBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using MPSGameLiftRequestBus = AZ::EBus<MPSGameLiftRequests, MPSGameLiftBusTraits>;
    using MPSGameLiftInterface = AZ::Interface<MPSGameLiftRequests>;

} // namespace MPSGameLift
