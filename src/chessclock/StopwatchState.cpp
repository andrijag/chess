#include "StopwatchState.h"

#include "Stopwatch.h"

std::chrono::time_point<std::chrono::system_clock> StopwatchState::getStartTime(const Stopwatch *stopwatch) const { return stopwatch->getStartTime(); }

void StopwatchState::setStartTime(Stopwatch *stopwatch, std::chrono::time_point<std::chrono::system_clock> startTime) { stopwatch->setStartTime(startTime); }

std::chrono::milliseconds StopwatchState::getElapsedTime(const Stopwatch *stopwatch) const { return stopwatch->getElapsedTime(); }

void StopwatchState::setElapsedTime(Stopwatch *stopwatch, std::chrono::milliseconds elapsedTime) { stopwatch->setElapsedTime(elapsedTime); }

void StopwatchState::changeState(Stopwatch *stopwatch, std::unique_ptr<StopwatchState> state) { stopwatch->changeState(std::move(state)); }

std::chrono::time_point<std::chrono::system_clock> getCurrentTime() { return std::chrono::system_clock::now(); }