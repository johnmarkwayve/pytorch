#include <torch/nn/modules/loss.h>

namespace F = torch::nn::functional;

namespace torch {
namespace nn {

L1LossImpl::L1LossImpl(const L1LossOptions& options_) : options(options_) {}

void L1LossImpl::reset() {}

void L1LossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::L1Loss()";
}

Tensor L1LossImpl::forward(const Tensor& input, const Tensor& target) {
  return F::l1_loss(input, target, options);
}

// ============================================================================

KLDivLossImpl::KLDivLossImpl(const KLDivLossOptions& options_)
    : options(options_) {}

void KLDivLossImpl::reset() {}

void KLDivLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::KLDivLoss()";
}

Tensor KLDivLossImpl::forward(const Tensor& input, const Tensor& target) {
  return F::kl_div(input, target, options);
}

// ============================================================================

MSELossImpl::MSELossImpl(const MSELossOptions& options_) : options(options_) {}

void MSELossImpl::reset() {}

void MSELossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::MSELoss()";
}

Tensor MSELossImpl::forward(const Tensor& input, const Tensor& target) {
  return F::mse_loss(input, target, options);
}

// ============================================================================

BCELossImpl::BCELossImpl(const BCELossOptions& options_) : options(options_) { // NOLINT(modernize-pass-by-value)
  reset();
}

void BCELossImpl::reset() {
  register_buffer("weight", options.weight());
}

void BCELossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::BCELoss()";
}

Tensor BCELossImpl::forward(const Tensor& input, const Tensor& target) {
  return F::binary_cross_entropy(input, target, options);
}

// ============================================================================

HingeEmbeddingLossImpl::HingeEmbeddingLossImpl(
    const HingeEmbeddingLossOptions& options_)
    : options(options_) {}

void HingeEmbeddingLossImpl::reset() {}

void HingeEmbeddingLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::HingeEmbeddingLoss(margin=" << options.margin() << ")";
}

Tensor HingeEmbeddingLossImpl::forward(
    const Tensor& input,
    const Tensor& target) {
  return F::hinge_embedding_loss(input, target, options);
}

// ============================================================================

MultiMarginLossImpl::MultiMarginLossImpl(
    const MultiMarginLossOptions& options_) // NOLINT(modernize-pass-by-value)
    : options(options_) {
  reset();
}

void MultiMarginLossImpl::reset() {
  TORCH_CHECK(
      (options.p() == 1) || (options.p() == 2),
      "only p == 1 and p == 2 supported");
  TORCH_CHECK(!options.weight().defined() || options.weight().dim() == 1);

  register_buffer("weight", options.weight());
}

void MultiMarginLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::MultiMarginLoss(p=" << options.p()
         << ", margin=" << options.margin() << ", weight=" << options.weight()
         << ", reduction=" << enumtype::get_enum_name(options.reduction()) << ")";
}

Tensor MultiMarginLossImpl::forward(const Tensor& input, const Tensor& target) {
  return F::multi_margin_loss(input, target, options);
}

// ============================================================================

CosineEmbeddingLossImpl::CosineEmbeddingLossImpl(
    const CosineEmbeddingLossOptions& options_)
    : options(options_) {}

void CosineEmbeddingLossImpl::reset() {}

void CosineEmbeddingLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::CosineEmbeddingLoss(margin=" << options.margin() << ")";
}

Tensor CosineEmbeddingLossImpl::forward(
    const Tensor& input1,
    const Tensor& input2,
    const Tensor& target) {
  return F::cosine_embedding_loss(input1, input2, target, options);
}
// ============================================================================

MultiLabelSoftMarginLossImpl::MultiLabelSoftMarginLossImpl(
    const torch::nn::MultiLabelSoftMarginLossOptions& options_) // NOLINT(modernize-pass-by-value)
    : options(options_) {
  reset();
}

void MultiLabelSoftMarginLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::MultiLabelSoftMarginLoss()";
}

void MultiLabelSoftMarginLossImpl::reset() {
  register_buffer("weight", options.weight());
}

Tensor MultiLabelSoftMarginLossImpl::forward(
    const Tensor& input,
    const Tensor& target) {
  return F::multilabel_soft_margin_loss(input, target, options);
}

// ============================================================================

TripletMarginLossImpl::TripletMarginLossImpl(
    const TripletMarginLossOptions& options_)
    : options(options_) {}

void TripletMarginLossImpl::reset() {}

void TripletMarginLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::TripletMarginLoss(margin=" << options.margin()
         << ", p=" << options.p() << ", eps=" << options.eps() << std::boolalpha
         << ", swap=" << options.swap() << ")";
}

Tensor TripletMarginLossImpl::forward(
    const Tensor& anchor,
    const Tensor& positive,
    const Tensor& negative) {
  return F::triplet_margin_loss(anchor, positive, negative, options);
}

// ============================================================================

MultiLabelMarginLossImpl::MultiLabelMarginLossImpl(
    const torch::nn::MultiLabelMarginLossOptions& options_)
    : options(options_) {}

void MultiLabelMarginLossImpl::reset() {}

void MultiLabelMarginLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::MultiLabelMarginLoss()";
}

Tensor MultiLabelMarginLossImpl::forward(const Tensor& input, const Tensor& target) {
  return F::multilabel_margin_loss(input, target, options);
}

// ============================================================================

SoftMarginLossImpl::SoftMarginLossImpl(
    const torch::nn::SoftMarginLossOptions& options_) : options(options_) {}

void SoftMarginLossImpl::reset() {}

void SoftMarginLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::SoftMarginLoss()";
}

Tensor SoftMarginLossImpl::forward(const Tensor& input, const Tensor& target) {
  return F::soft_margin_loss(input, target, options);
}

// ============================================================================

SmoothL1LossImpl::SmoothL1LossImpl(
    const torch::nn::SmoothL1LossOptions& options_) : options(options_) {}

void SmoothL1LossImpl::reset() {}

void SmoothL1LossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::SmoothL1Loss";
}

Tensor SmoothL1LossImpl::forward(const Tensor& input, const Tensor& target) {
  return F::smooth_l1_loss(input, target, options);
}
  
// ============================================================================
  
CTCLossImpl::CTCLossImpl(const CTCLossOptions& options_) : options(options_) {}

void CTCLossImpl::reset() {}

void CTCLossImpl::pretty_print(std::ostream& stream) const {
  stream << "torch::nn::CTCLoss()";
}

Tensor CTCLossImpl::forward(const Tensor& log_probs, const Tensor& targets,
                 const Tensor& input_lengths, const Tensor& target_lengths) {
  return F::ctc_loss(log_probs, targets, input_lengths, target_lengths, options);
}

} // namespace nn
} // namespace torch
