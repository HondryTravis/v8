// Copyright 2020 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_TRACING_TRACE_CATEGORIES_H_
#define V8_TRACING_TRACE_CATEGORIES_H_

#include "src/base/macros.h"

#if defined(V8_USE_PERFETTO)

// Exports tracks events into the v8 namespace to avoid conflicts with embedders
// like Chrome.
#define PERFETTO_TRACK_EVENT_NAMESPACE v8

// Export trace categories and the track event data source in components builds.
#define PERFETTO_COMPONENT_EXPORT V8_EXPORT_PRIVATE

// For now most of v8 uses legacy trace events.
#define PERFETTO_ENABLE_LEGACY_TRACE_EVENTS 1

#include "perfetto/tracing.h"

// Trace category prefixes used in tests.
PERFETTO_DEFINE_TEST_CATEGORY_PREFIXES("v8-cat", "cat", "v8.Test2");

// List of categories used by built-in V8 trace events.
// clang-format off
PERFETTO_DEFINE_CATEGORIES(
    perfetto::Category("V8.HandleInterrupts"),
    perfetto::Category("v8"),
    perfetto::Category("v8.console"),
    perfetto::Category("v8.execute"),
    perfetto::Category("v8.runtime"),
    perfetto::Category::Group("devtools.timeline,v8"),
    perfetto::Category::Group("devtools.timeline,"
                              TRACE_DISABLED_BY_DEFAULT("v8.gc")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("devtools.timeline")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.compile")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.cpu_profiler")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.gc")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.gc_stats")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.ic_stats")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.runtime")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.runtime_stats")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.runtime_stats_sampling")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.turbofan")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.wasm")),
    perfetto::Category(TRACE_DISABLED_BY_DEFAULT("v8.zone_stats")),
    perfetto::Category::Group("v8,devtools.timeline"),
    perfetto::Category::Group(TRACE_DISABLED_BY_DEFAULT("v8.turbofan") ","
                              TRACE_DISABLED_BY_DEFAULT("v8.wasm")));
// clang-format on

#endif  // defined(V8_USE_PERFETTO)

#endif  // V8_TRACING_TRACE_CATEGORIES_H_
