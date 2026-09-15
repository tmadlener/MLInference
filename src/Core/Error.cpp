#include "MLInference/Core/Error.h"

#include <expected>
#include <format>

namespace mlinfer {
Error::Error(Kind kind, std::string message) : m_kind(kind), m_message(std::move(message)) {}

std::string Error::what() const { return std::format("{} ({})", m_message, name(m_kind)); }

std::string name(Error::Kind kind) noexcept {
  switch (kind) {
  case Error::Kind::Unclassified:
    return "Unclassified";
  case Error::Kind::InvalidArgument:
    return "InvalidArgument";
  case Error::Kind::FailedLoad:
    return "FailedLoad";
  case Error::Kind::Internal:
    return "Internal";
  }

  return "Invalide Error kind";
}

std::unexpected<Error> fail(Error::Kind kind, std::string message) {
  return std::unexpected(Error(kind, std::move(message)));
}

} // namespace mlinfer
