// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_PROFILER_STACK_COPIER_SIGNAL_H_
#define BASE_PROFILER_STACK_COPIER_SIGNAL_H_

#include <memory>

#include "base/base_export.h"
#include "base/profiler/stack_copier.h"

namespace base {

class ThreadDelegate;

// Supports stack copying on platforms where a signal must be delivered to the
// profiled thread and the stack is copied from the signal handler.
class BASE_EXPORT StackCopierSignal : public StackCopier {
 public:
  StackCopierSignal(std::unique_ptr<ThreadDelegate> thread_delegate);
  ~StackCopierSignal() override;

  // StackCopier:
  bool CopyStack(StackBuffer* stack_buffer,
                 uintptr_t* stack_top,
                 ProfileBuilder* profile_builder,
                 RegisterContext* thread_context) override;

  using StackCopier::CopyStackContentsAndRewritePointers;

 private:
  std::unique_ptr<ThreadDelegate> thread_delegate_;
};

}  // namespace base

#endif  // BASE_PROFILER_STACK_COPIER_SIGNAL_H_
