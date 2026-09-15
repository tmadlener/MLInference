#ifndef MLINFERENCE_CORE_SESSION_H
#define MLINFERENCE_CORE_SESSION_H

#include "MLInference/Core/Error.h"
#include "MLInference/Core/Runner.h"

#include <memory>

namespace mlinfer {

class SessionState;
class IRunner;

/// The interface a session has to fulfill to be usable in a dynamic context
class ISession {
public:
  virtual ~ISession() = default;

  virtual Expected<std::unique_ptr<IRunner>> makeRunner() const = 0;
};

/// A session represents a loaded model
///
/// A session holds a loaded and **immutable** model. It's possible to create a
/// runner from this model which holds all mutable state
class Session {
public:
  Session() noexcept = default;
  Session(const Session&) noexcept = default;
  Session& operator=(const Session&) noexcept = default;
  Session(Session&&) noexcept = default;
  Session& operator=(Session&&) noexcept = default;
  ~Session() noexcept = default;

  Expected<std::unique_ptr<Runner>> makeRunner() const;

private:
  friend class Runner;

  explicit Session(std::shared_ptr<const SessionState> state) noexcept;

  std::shared_ptr<const SessionState> m_state;
};

}; // namespace mlinfer

#endif // MLINFERENCE_CORE_SESSION_H
