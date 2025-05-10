#pragma once

#include <vector>
#include <complex>
#include <memory>

namespace TNMaxwellVlasov {

// Basic type definitions
using Real    = double;
using Complex = std::complex<Real>;
using Index   = int;

// Forward declarations
class Tensor;
class TensorNetwork;
class MPSWavefunction;
class VlasovOperator;
class MaxwellOperator;
class TimeEvolution;

} // namespace TNMaxwellVlasov
