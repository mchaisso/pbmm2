// Author: Armin Töpfer

#pragma once

#include <string>
#include <vector>

#include <pbcopper/cli/CLI.h>

#include "PlainOption.h"

#include <pbmm2/MM2Settings.h>

namespace PacBio {
namespace minimap2 {
/// Contains user provided CLI configuration
struct AlignSettings : MM2Settings
{
    const std::string CLI;
    const std::vector<std::string> InputFiles;
    bool IsFromRTC;

    // alignment output filters
    float MinPercConcordance;
    int32_t MinAlignmentLength;

    std::string LogFile;
    Logging::LogLevel LogLevel;

    const std::string SampleName;
    int32_t ChunkSize;

    bool MedianFilter;

    bool Sort;
    int SortThreads;
    int64_t SortMemory;

    bool ZMW;
    bool HQRegion;

    bool Strip;
    bool SplitBySample;

    std::string Rg;

    bool CreatePbi;
    bool NoBAI;
    bool OutputUnmapped;

    std::string TcOverrides;

    /// Parses the provided CLI::Results and retrieves a defined set of options.
    AlignSettings(const PacBio::CLI::Results& options);

    int32_t ThreadCount(int32_t n);

    /// Given the description of the tool and its version, create all
    /// necessary CLI::Options for the ccs executable.
    static PacBio::CLI::Interface CreateCLI();
};
}  // namespace minimap2
}  // namespace PacBio
