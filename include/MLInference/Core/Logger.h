#ifndef MLINFERENCE_CORE_LOGGER_H
#define MLINFERENCE_CORE_LOGGER_H

#include <memory>
#include <string_view>

namespace mlinfer {

enum class LogLevel {
  Verbose = 0,
  Debug,
  Info,
  Warning,
  Error,
};

std::string_view name(LogLevel level) noexcept;

/// A simple logger class that streamlines internal logging while allowing to
/// connect it to an external sink (e.g. from a framework)
class Logger {
public:
  virtual ~Logger() = default;

  /// Would a message at \p level be emitted?
  ///
  /// This can be overriden (dynamically) by inheriting loggers
  virtual bool enabled([[maybe_unused]] LogLevel level) const noexcept { return true; }

  void log(LogLevel level, std::string_view message) const noexcept {
    if (enabled(level)) {
      emit(level, message);
    }
  }

protected:
  /// The actual call to emit a message
  ///
  /// This will only be called if logging is enabled for the provided \p level.
  virtual void emit(LogLevel level, std::string_view message) const noexcept = 0;
};

/// Get a default logger configured to emit at a given level.
///
/// At the moment this will yield a logger that emits to stdout
std::unique_ptr<Logger> makeDefaultLogger(LogLevel level = LogLevel::Info);

} // namespace mlinfer

#endif // MLINFERENCE_CORE_LOGGER_H
