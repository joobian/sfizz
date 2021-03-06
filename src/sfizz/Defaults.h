// SPDX-License-Identifier: BSD-2-Clause

// Copyright (c) 2019-2020, Paul Ferrand, Andrea Zanellato
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once
#include "Range.h"
#include "Config.h"
#include <limits>
#include <cstdint>

enum class SfzTrigger { attack, release, release_key, first, legato };
enum class SfzLoopMode { no_loop, one_shot, loop_continuous, loop_sustain };
enum class SfzOffMode { fast, normal };
enum class SfzVelocityOverride { current, previous };
enum class SfzCrossfadeCurve { gain, power };
enum class SfzSelfMask { mask, dontMask };

namespace sfz
{
namespace Default
{
    // The categories match http://sfzformat.com/
    // ******* SFZ 1 *******
    // Sound source: sample playback
	constexpr float delay { 0.0 };
	constexpr float delayRandom { 0.0 };
	constexpr Range<float> delayRange { 0.0, 100.0 };
	constexpr int64_t offset { 0 };
	constexpr int64_t offsetRandom { 0 };
	constexpr Range<int64_t> offsetRange { 0, std::numeric_limits<uint32_t>::max() };
	constexpr Range<int64_t> offsetCCRange = offsetRange;
	constexpr Range<uint32_t> sampleEndRange { 0, std::numeric_limits<uint32_t>::max() };
	constexpr Range<uint32_t> sampleCountRange { 0, std::numeric_limits<uint32_t>::max() };
	constexpr SfzLoopMode loopMode { SfzLoopMode::no_loop };
	constexpr Range<uint32_t> loopRange { 0, std::numeric_limits<uint32_t>::max() };

    // common defaults
    constexpr Range<uint8_t> midi7Range { 0, 127 };
    constexpr Range<float> normalizedRange { 0.0f, 1.0f };
    constexpr Range<float> symmetricNormalizedRange { -1.0, 1.0 };

    // Wavetable oscillator
    constexpr float oscillatorPhase { 0.0 };
    constexpr Range<float> oscillatorPhaseRange { -1.0, 360.0 };
    constexpr int oscillatorMulti { 1 };
    constexpr Range<int> oscillatorMultiRange { 1, config::oscillatorsPerVoice };
    constexpr float oscillatorDetune { 0 };
    constexpr Range<float> oscillatorDetuneRange { -9600, 9600 };

    // Instrument setting: voice lifecycle
	constexpr uint32_t group { 0 };
	constexpr Range<uint32_t> groupRange { 0, std::numeric_limits<uint32_t>::max() };
	constexpr SfzOffMode offMode { SfzOffMode::fast };
    constexpr Range<uint32_t> polyphonyRange { 0, config::maxVoices };
    constexpr SfzSelfMask selfMask { SfzSelfMask::mask };

        // Region logic: key mapping
	constexpr Range<uint8_t> keyRange { 0, 127 };
    constexpr auto velocityRange = normalizedRange;

        // Region logic: MIDI conditions
	constexpr Range<uint8_t> channelRange { 1, 16 };
	constexpr Range<uint8_t> midiChannelRange { 0, 15 };
    constexpr Range<float> stepCCRange { 0, 127 };
    constexpr Range<uint8_t> smoothCCRange { 0, 127 };
    constexpr Range<uint8_t> curveCCRange { 0, 255 };
    constexpr Range<uint16_t> ccNumberRange { 0, config::numCCs };
    constexpr auto ccValueRange = normalizedRange;
    constexpr Range<int> bendRange = { -8192, 8192 };
    constexpr Range<float> bendValueRange = symmetricNormalizedRange;
    constexpr int bend { 0 };
	constexpr SfzVelocityOverride velocityOverride { SfzVelocityOverride::current };

    // Region logic: internal conditions
	constexpr Range<float> randRange { 0.0, 1.0 };
	constexpr Range<uint8_t> aftertouchRange { 0, 127 };
	constexpr uint8_t aftertouch { 0 };
	constexpr Range<float> bpmRange { 0.0, 500.0 };
	constexpr float bpm { 120.0 };
	constexpr uint8_t sequenceLength{ 1 };
	constexpr uint8_t sequencePosition{ 1 };
	constexpr Range<uint8_t> sequenceRange { 1, 100 };

    // Region logic: Triggers
	constexpr SfzTrigger trigger { SfzTrigger::attack };
        constexpr Range<float> ccTriggerValueRange = normalizedRange;

        // Performance parameters: amplifier
	constexpr float globalVolume { -7.35f };
	constexpr float volume { 0.0f };
	constexpr Range<float> volumeRange { -144.0, 6.0 };
	constexpr Range<float> volumeCCRange { -144.0, 48.0 };
	constexpr Range<float> volumeStepRange { 0, 48.0 };
	constexpr float amplitude { 100.0 };
	constexpr Range<float> amplitudeRange { 0.0, 100.0 };
	constexpr float pan { 0.0 };
	constexpr Range<float> panRange { -100.0, 100.0 };
	constexpr Range<float> panCCRange { -200.0, 200.0 };
	constexpr Range<float> panStepRange { 0.0, 200.0 };
	constexpr float position { 0.0 };
	constexpr Range<float> positionRange { -100.0, 100.0 };
	constexpr Range<float> positionCCRange { -200.0, 200.0 };
	constexpr Range<float> positionStepRange { 0.0, 200.0 };
	constexpr float width { 100.0 };
	constexpr Range<float> widthRange { -100.0, 100.0 };
	constexpr Range<float> widthCCRange { -200.0, 200.0 };
	constexpr Range<float> widthStepRange { 0.0, 200.0 };
	constexpr uint8_t ampKeycenter { 60 };
	constexpr float ampKeytrack { 0.0 };
	constexpr Range<float> ampKeytrackRange { -96, 12 };
	constexpr float ampVeltrack { 100.0 };
	constexpr Range<float> ampVeltrackRange { -100.0, 100.0 };
	constexpr Range<float> ampVelcurveRange { 0.0, 1.0 };
	constexpr float ampRandom { 0.0 };
	constexpr Range<float> ampRandomRange { 0.0, 24.0 };
	constexpr Range<uint8_t> crossfadeKeyInRange { 0, 0 };
	constexpr Range<uint8_t> crossfadeKeyOutRange { 127, 127 };
    constexpr Range<float> crossfadeVelInRange { 0.0f, 0.0f };
    constexpr Range<float> crossfadeVelOutRange { 1.0f, 1.0f };
    constexpr Range<float> crossfadeCCInRange { 0.0f, 0.0f };
    constexpr Range<float> crossfadeCCOutRange { 1.0f, 1.0f };
    constexpr SfzCrossfadeCurve crossfadeKeyCurve { SfzCrossfadeCurve::power };
	constexpr SfzCrossfadeCurve crossfadeVelCurve { SfzCrossfadeCurve::power };
	constexpr SfzCrossfadeCurve crossfadeCCCurve { SfzCrossfadeCurve::power };
	constexpr float rtDecay { 0.0f };
	constexpr Range<float> rtDecayRange { 0.0f, 200.0f };

    // Performance parameters: Filters
    constexpr int numFilters { 2 };
    constexpr float filterCutoff { 0 };
    constexpr float filterResonance { 0 };
    constexpr float filterGain { 0 };
    constexpr int filterKeytrack { 0 };
    constexpr uint8_t filterKeycenter { 60 };
    constexpr int filterRandom { 0 };
    constexpr int filterVeltrack { 0 };
    constexpr int filterCutoffCC { 0 };
    constexpr float filterResonanceCC { 0 };
    constexpr float filterGainCC { 0 };
    constexpr Range<float> filterCutoffRange { 0.0f, 20000.0f };
    constexpr Range<int> filterCutoffModRange { -9600, 9600 };
    constexpr Range<float> filterGainRange { -96.0f, 96.0f };
    constexpr Range<float> filterGainModRange { -96.0f, 96.0f };
    constexpr Range<int> filterKeytrackRange { 0, 1200 };
    constexpr Range<int> filterRandomRange { 0, 9600 };
    constexpr Range<int> filterVeltrackRange { -9600, 9600 };
    constexpr Range<float> filterResonanceRange { 0.0f, 96.0f };
    constexpr Range<float> filterResonanceModRange { 0.0f, 96.0f };

    // Performance parameters: EQ
    constexpr int numEQs { 3 };
    constexpr float eqBandwidth { 1.0f };
    constexpr float eqBandwidthCC { 0.0f };
    constexpr float eqFrequencyUnset { 0.0f };
    constexpr float eqFrequency1 { 50.0f };
    constexpr float eqFrequency2 { 500.0f };
    constexpr float eqFrequency3 { 5000.0f };
    constexpr float eqFrequencyCC { 0.0f };
    constexpr float eqGain { 0.0f };
    constexpr float eqGainCC { 0.0f };
    constexpr float eqVel2frequency { 0.0f };
    constexpr float eqVel2gain { 0.0f };
    constexpr Range<float> eqBandwidthRange { 0.001f, 4.0f };
    constexpr Range<float> eqBandwidthModRange { -4.0f, 4.0f };
    constexpr Range<float> eqFrequencyRange { 0.0f, 30000.0f };
    constexpr Range<float> eqFrequencyModRange { -30000.0f, 30000.0f };
    constexpr Range<float> eqGainRange { -96.0f, 96.0f };
    constexpr Range<float> eqGainModRange { -96.0f, 96.0f };

     // Performance parameters: pitch
	constexpr uint8_t pitchKeycenter { 60 };
	constexpr int pitchKeytrack { 100 };
	constexpr Range<int> pitchKeytrackRange { -1200, 1200 };
	constexpr int pitchRandom { 0 };
	constexpr Range<int> pitchRandomRange { 0, 9600 };
	constexpr int pitchVeltrack { 0 };
	constexpr Range<int> pitchVeltrackRange { -9600, 9600 };
	constexpr int transpose { 0 };
	constexpr Range<int> transposeRange { -127, 127 };
	constexpr int tune { 0 };
	constexpr Range<int> tuneRange { -9600, 9600 }; // ±100 in SFZv1, more in ARIA
    constexpr Range<int> tuneCCRange { -9600, 9600 };
    constexpr Range<int> tuneStepRange { 0, 9600 };
    constexpr Range<int> bendBoundRange { -9600, 9600 };
    constexpr Range<int> bendStepRange { 1, 1200 };
    constexpr int bendUp { 200 }; // No range here because the bounds can be inverted
    constexpr int bendDown { -200 };
    constexpr int bendStep { 1 };

    // Envelope generators
	constexpr float attack { 0 };
	constexpr float decay { 0 };
	constexpr float delayEG { 0 };
	constexpr float hold { 0 };
	constexpr float release { 0 };
	constexpr float vel2release { 0.0f };
	constexpr float start { 0.0 };
	constexpr float sustain { 100.0 };
	constexpr float vel2sustain { 0.0 };
	constexpr int depth { 0 };
	constexpr Range<float> egTimeRange { 0.0, 100.0 };
	constexpr Range<float> egPercentRange { 0.0, 100.0 };
	constexpr Range<int> egDepthRange { -12000, 12000 };
	constexpr Range<float> egOnCCTimeRange { -100.0, 100.0 };
	constexpr Range<float> egOnCCPercentRange { -100.0, 100.0 };

    // ***** SFZ v2 ********
	constexpr bool checkSustain { true }; // sustain_sw
	constexpr bool checkSostenuto { true }; // sostenuto_sw
    constexpr Range<int> octaveOffsetRange { -10, 10 }; // octave_offset
    constexpr Range<int> noteOffsetRange { -127, 127 }; // note_offset

    constexpr Range<int> apanWaveformRange { 0, std::numeric_limits<int>::max() };
    constexpr Range<float> apanFrequencyRange { 0, std::numeric_limits<float>::max() };
    constexpr Range<float> apanPhaseRange { 0.0, 360.0 };
    constexpr Range<float> apanLevelRange { 0.0, 100.0 };
}
}
