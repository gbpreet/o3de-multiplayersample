/*
 * Copyright (c) Contributors to the Open 3D Engine Project. For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once
#include <MPSGameLift/IRegionalLatencyFinder.h>


namespace MPSGameLift
{
    enum class MatchmakingFailReason
    {
        FailedToReceiveTicket,
        FailedToReceiveStatusUpdate,
        TimedOut
    };

    using MatchmakingTicketReceivedEvent = AZ::Event<AZStd::string>;
    using MatchmakingSuccessEvent = AZ::Event<>;
    using MatchmakingFailedEvent = AZ::Event<MatchmakingFailReason>;

    // Supports matchmaking request calls to a serverless backend
    class IMatchmaking
    {
    public:
        AZ_RTTI(IMatchmaking, "{371687E5-9626-4201-91E3-0FD1F79CB8B6}");
        virtual ~IMatchmaking() = default;

        // Request a match for the player.
        // @param RegionalLatencies A map of latency times between this client and a regional server endpoint.
        //     Regional latencies help determine the best server to join.
        // @return True if the request was sent; otherwise false.
        virtual bool RequestMatch(const RegionalLatencies& regionalLatencies) = 0;

        // Gets the current matchmaking ticket id if any
        // @return A matchmaking ticket id, or empty string if no ticket has been received.
        virtual AZStd::string GetTicketId() const = 0;

        // Adds a MatchmakingTicketReceivedEvent Handler which is invoked when FlexMatch gives the player back a matchmaking ticket.
        // This ticket id can be used by developers for debugging should matchmaking fail.
        // @param handler The MatchmakingTicketReceivedEvent Handler to add
        virtual void AddMatchmakingTicketReceivedEventHandler(MatchmakingTicketReceivedEvent::Handler& handler) = 0;

        // Adds a MatchmakingSuccessEvent Handler which is invoked when FlexMatch has discovered a valid game.
        // @param handler The MatchmakingSuccessEvent Handler to add
        virtual void AddMatchmakingSuccessEventHandler(MatchmakingSuccessEvent::Handler& handler) = 0;

        // Adds a MatchmakingFailedEvent Handler which is invoked when no match is found.
        // @param handler The MatchmakingFailedEvent Handler to add
        virtual void AddMatchmakingFailedEventHandler(MatchmakingFailedEvent::Handler& handler) = 0;
    };
} // namespace MPSGameLift
