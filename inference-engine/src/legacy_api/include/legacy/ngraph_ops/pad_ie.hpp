// Copyright (C) 2018-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <memory>
#include <vector>

#include <ie_api.h>

#include "ngraph/node.hpp"
#include "ngraph/op/op.hpp"
#include "ngraph/op/pad.hpp"

namespace ngraph {
namespace op {

class INFERENCE_ENGINE_API_CLASS(PadIE) : public Op {
public:
    static constexpr NodeTypeInfo type_info{"PadIE", 1};
    const NodeTypeInfo& get_type_info() const override { return type_info; }

    explicit PadIE(const std::shared_ptr<op::v1::Pad>& pad);

    size_t get_version() const override { return 1; }

    void validate_and_infer_types() override;
    bool visit_attributes(AttributeVisitor& visitor) override;
    std::shared_ptr<Node> clone_with_new_inputs(const OutputVector& new_args) const override;

    PadMode get_pad_mode() { return m_pad_mode; }
    CoordinateDiff get_pads_begin() { return m_pads_begin; }
    CoordinateDiff get_pads_end() { return m_pads_end; }
    float get_pad_value() { return m_pad_value; }

private:
    PadMode m_pad_mode;
    CoordinateDiff m_pads_begin, m_pads_end;
    Shape m_output_shape;
    float m_pad_value = 0;
};
}  // namespace op
}  // namespace ngraph
