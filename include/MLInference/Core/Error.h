#ifndef MLINFERENCE_CORE_ERROR_H
#define MLINFERENCE_CORE_ERROR_H

#include <expected>
#include <string>

namespace mlinfer {

/// Class representing an error and related information
struct Error {
  enum class Kind {
    Unclassified = 0,
    InvalidArgument, ///< Trying to call a function with an invalid argument
    FailedLoad,      ///< Model could not be loaded

    Internal, ///< Catch all for the rest
  };

  Error(Kind kind, std::string message);

  Kind kind() const noexcept { return m_kind; }
  const std::string& message() const noexcept { return m_message; }
  /// Get a combined message of the internal message and the kind
  std::string what() const;

private:
  Kind m_kind{Kind::Unclassified};
  std::string m_message{};
};

/// Get the (string) name of an Error::Kind
std::string name(Error::Kind kind) noexcept;

/// Type alias used throughout the library connecting an expected type and our
/// Error class
template <typename T>
using Expected = std::expected<T, Error>;

/// Helper function to make returning failures easier
std::unexpected<Error> fail(Error::Kind kind, std::string message);

} // namespace mlinfer

#endif // MLINFERENCE_CORE_ERROR_H
