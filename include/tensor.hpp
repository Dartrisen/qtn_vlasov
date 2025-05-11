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

class Tensor {
public:
    // ctor: build zero-initialized tensor
    Tensor(const std::vector<Index>& dims);

    // element access
    Complex&       at(const std::vector<Index>& idx);
    const Complex& at(const std::vector<Index>& idx) const;

    const std::vector<Index>& dimensions() const;
    size_t                    rank()       const;

    void randomize(Real scale = 1.0);
    void normalize();

    // high-level ops
    static Tensor contract(const Tensor& A, const Tensor& B,
                           Index a_dim, Index b_dim);
    std::tuple<Tensor,std::vector<Real>,Tensor>
        svd(Index left_dims, Index right_dims) const;

private:
    std::vector<Complex> data_;
    std::vector<Index>   dimensions_;

    size_t calculateFlatIndex(const std::vector<Index>& idx) const;
};

} // namespace TNMaxwellVlasov
