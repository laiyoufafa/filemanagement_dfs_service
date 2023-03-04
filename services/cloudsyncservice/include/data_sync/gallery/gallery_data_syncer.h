/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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

#ifndef OHOS_FILEMGMT_GALLERY_DATA_SYNCER_H
#define OHOS_FILEMGMT_GALLERY_DATA_SYNCER_H

#include "data_sync/data_syncer.h"

namespace OHOS::FileManagement::CloudSync {
class GalleryDataSyncer final : public DataSyncer {
public:
    explicit GalleryDataSyncer(std::string appPackageName) : DataSyncer(appPackageName) {}
    ~GalleryDataSyncer() = default;

    void StartSync(int32_t userId, bool forceFlag, SyncTriggerType triggerType) override;
    void StopSync(int32_t userId, SyncTriggerType triggerType) override;

    int32_t UploadFile(int32_t userId, bool forceFlag);

private:
};
} // namespace OHOS::FileManagement::CloudSync

#endif // OHOS_FILEMGMT_GALLERY_DATA_SYNCER_H