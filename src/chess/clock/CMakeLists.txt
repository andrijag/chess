add_library(ChessClock)

target_sources(ChessClock
    PRIVATE
        ChessClock.cpp
        Stopwatch.cpp
    PUBLIC
        FILE_SET HEADERS
)