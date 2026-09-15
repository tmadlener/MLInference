#ifndef MLINFERENCE_CORE_RUNNER_H
#define MLINFERENCE_CORE_RUNNER_H

namespace mlinfer {
class Session;

class Runner {
public:
  Runner() noexcept = default;
  ~Runner() = default;

  Runner(const Runner&) = delete;
  Runner& operator=(const Runner&) = delete;
  Runner(Runner&&) noexcept = default;
  Runner& operator=(Runner&&) noexcept = default;
};
} // namespace mlinfer

#endif // MLINFERENCE_CORE_RUNNER_H
