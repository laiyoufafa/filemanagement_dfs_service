/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_FILEMGMT_CLOUD_SYNC_CALLBACK_H
#define OHOS_FILEMGMT_CLOUD_SYNC_CALLBACK_H

#include <string>

namespace OHOS::FileManagement::CloudSync {
using DeathCallback = std::function<void()>;

class CloudSyncCallback {
public:
    virtual void OnStartSyncFinished(const std::string &appPackageName, int32_t errCode) = 0;
    virtual void OnStopSyncFinished(const std::string &appPackageName, int32_t errCode) = 0;
    virtual ~CloudSyncCallback() = default;
};
} // namespace OHOS::FileManagement::CloudSync

#endif // OHOS_FILEMGMT_CLOUD_SYNC_CALLBACK_H