// Copyright (c) 2015-2016 The Khronos Group Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and/or associated documentation files (the
// "Materials"), to deal in the Materials without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Materials, and to
// permit persons to whom the Materials are furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Materials.
//
// MODIFICATIONS TO THIS FILE MAY MEAN IT NO LONGER ACCURATELY REFLECTS
// KHRONOS STANDARDS. THE UNMODIFIED, NORMATIVE VERSIONS OF KHRONOS
// SPECIFICATIONS AND HEADER INFORMATION ARE LOCATED AT
//    https://www.khronos.org/registry/
//
// THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.

// Common validation fixtures for unit tests

#ifndef LIBSPIRV_TEST_VALIDATE_FIXTURES_H_
#define LIBSPIRV_TEST_VALIDATE_FIXTURES_H_

#include "UnitSPIRV.h"

namespace spvtest {

template <typename T, uint32_t OPTIONS = SPV_VALIDATE_ALL>
class ValidateBase : public ::testing::Test,
                     public ::testing::WithParamInterface<T> {
 public:
  ValidateBase();
  ~ValidateBase();

  virtual void TearDown();

  // Returns the a spv_const_binary struct
  spv_const_binary get_const_binary();

  void CompileSuccessfully(std::string code);

  // Performs validation on the SPIR-V code and compares the result of the
  // spvValidate function
  spv_result_t ValidateInstructions();

  std::string getDiagnosticString();
  spv_position_t getErrorPosition();

  spv_context context_;
  spv_binary binary_;
  spv_diagnostic diagnostic_;
  static const uint32_t validation_options_ = OPTIONS;
};
}
#endif
