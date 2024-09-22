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

#ifndef COBALT_WATCHDOG_WATCHDOG_H_
#define COBALT_WATCHDOG_WATCHDOG_H_

#include "third_party/blink/renderer/platform/bindings/script_wrappable.h"

#include <pthread.h>

#include <atomic>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "base/synchronization/condition_variable.h"
#include "base/synchronization/lock.h"
#include "base/values.h"
//#include "cobalt/base/application_state.h"
//#include "cobalt/persistent_storage/persistent_settings.h"
#include "third_party/blink/renderer/modules/watchdog/watchdog_thread.h"
#include "third_party/blink/renderer/platform/allow_discouraged_type.h"

namespace blink {

class Watchdog : public ScriptWrappable {
  DEFINE_WRAPPERTYPEINFO();

 public:

//  Watchdog();

  static bool Start();

  static bool Register(const String& name, const String& description,
                       int64_t time_interval_microseconds,
                       int64_t time_wait_microseconds = 0);

//  std::shared_ptr<Client> RegisterByClient(std::string name,
//                                           std::string description,
//                                           int64_t time_interval_microseconds,
//                                           int64_t time_wait_microseconds = 0);
//  bool Unregister(const std::string& name, bool lock = true);
//  bool UnregisterByClient(std::shared_ptr<Client> client);

  static bool ping(const String& name, const String& info);

//  bool PingByClient(std::shared_ptr<Client> client);
//  bool PingByClient(std::shared_ptr<Client> client, const std::string& info);
//  bool PingHelper(Client* client, const std::string& name,
//                  const std::string& info);
  static String GetWatchdogViolations(
      const Vector<String>& clients, bool clear = true);
//  bool GetPersistentSettingWatchdogEnable();
//  void SetPersistentSettingWatchdogEnable(bool enable_watchdog);
//  bool GetPersistentSettingWatchdogCrash();
//  void SetPersistentSettingWatchdogCrash(bool can_trigger_crash);

  // LogTrace API. See instrumentation_log.h for more information.
//  static bool LogEvent(const std::string& event);
//  static std::vector<std::string> GetLogTrace();
//  static void ClearLog();

//  bool GetPersistentSettingLogtraceEnable();
//  void SetPersistentSettingLogtraceEnable(bool enable_logtrace);

 private:
  static std::vector<std::string> convertToStdVector(const Vector<String>& wtfVector);
//  static WatchdogThread* watchdog_thread_;
};

}  // namespace cobalt

#endif  // COBALT_WATCHDOG_WATCHDOG_H_
