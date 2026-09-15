#include "MLInference/Core/Logger.h"

#include <format>
#include <iostream>
#include <mutex>

namespace mlinfer {

std::string_view name(LogLevel level) noexcept {
  switch (level) {
  case LogLevel::Verbose:
    return "Verbose";
  case LogLevel::Debug:
    return "Debug";
  case LogLevel::Info:
    return "Info";
  case LogLevel::Warning:
    return "Warning";
  case LogLevel::Error:
    return "Error";
  }

  return "Invalid Log Level";
}

class StreamLogger final : public Logger {
public:
  ~StreamLogger() = default;
  StreamLogger(LogLevel level) : m_threshold(level) {}

  bool enabled(LogLevel level) const noexcept final { return level >= m_threshold; }

protected:
  void emit(LogLevel level, std::string_view message) const noexcept final {
    static std::mutex streamMutex;
    const std::lock_guard<std::mutex> lock{streamMutex};
    std::cout << std::format("[MLInference ({})] | {}", name(level), message) << std::endl;
  }

private:
  LogLevel m_threshold;
};

std::unique_ptr<Logger> makeDefaultLogger(LogLevel level) { return std::make_unique<StreamLogger>(LogLevel::Info); }

} // namespace mlinfer
