// Copyright 2022 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//#include "third_party/blink/renderer/modules/watchdog/watchdog_thread.h"
#include "third_party/blink/renderer/modules/watchdog/watchdog.h"
#include "base/logging.h"

#include <unistd.h>

#include <algorithm>
#include <sstream>
#include <utility>
#include <vector>

#include "base/command_line.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/json/json_reader.h"
#include "base/json/json_writer.h"
#include "base/logging.h"
#include "base/time/time.h"
#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
//#include "starboard/configuration_constants.h"

//#if defined(_DEBUG)
//#include "cobalt/browser/switches.h"
//#endif  // defined(_DEBUG)
namespace blink {

bool Watchdog::Start() {
  LOG(INFO) << "Watchdog::Start()";

  WatchdogThread::CreateInstance();
  return true;
}

bool Watchdog::Register(const String& name, const String& description,
                        int64_t time_interval_microseconds,
                        int64_t time_wait_microseconds) {
//  Replace replace = NONE;
  WatchdogThread* watchdog_thread = WatchdogThread::GetInstance();

  return watchdog_thread->Register(name.Ascii(),
                                   description.Ascii(),
                                   time_interval_microseconds,
                                   time_wait_microseconds);
}

bool Watchdog::ping(const String& name, const String& info) {
  return WatchdogThread::GetInstance()->Ping(name.Ascii(), info.Ascii());
}

String Watchdog::GetWatchdogViolations(
    const Vector<String>& clients, bool clear) {
  const std::string violationsJson =
      WatchdogThread::GetInstance()->GetWatchdogViolations(convertToStdVector(
          clients), clear);

  return String(violationsJson);
}

std::vector<std::string> Watchdog::convertToStdVector(const Vector<String>& wtfVector) {
  std::vector<std::string> stdVector;
  stdVector.reserve(wtfVector.size());

  for (const auto& wtfString: wtfVector) {
    stdVector.push_back(wtfString.Ascii());
  }

  return stdVector;
}

//bool Watchdog::LogEvent(const std::string& event) {
//  if (is_logtrace_disabled_) {
//    return true;
//  }
//
//  return instrumentation_log_.LogEvent(event);
//}
//
//std::vector<std::string> Watchdog::GetLogTrace() {
//  if (is_logtrace_disabled_) {
//    return {};
//  }
//
//  return instrumentation_log_.GetLogTrace();
//}
//
//void Watchdog::ClearLog() {
//  if (is_logtrace_disabled_) {
//    return;
//  }
//
//  instrumentation_log_.ClearLog();
//}

}  // namespace blink
