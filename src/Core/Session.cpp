#include "MLInference/Core/Session.h"

namespace mlinfer {
Session::Session(std::shared_ptr<const SessionState> state) noexcept : m_state(std::move(state)) {}

} // namespace mlinfer
