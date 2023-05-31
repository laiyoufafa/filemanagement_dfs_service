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

#ifndef OHOS_FILEMGMT_CLOUD_SYNC_ASSET_MANAGER_IMPL_H
#define OHOS_FILEMGMT_CLOUD_SYNC_ASSET_MANAGER_IMPL_H

#include "nocopyable.h"

#include "cloud_sync_asset_manager.h"

namespace OHOS::FileManagement::CloudSync {
class CloudSyncAssetManagerImpl final : public CloudSyncAssetManager, public NoCopyable {
public:
    static CloudSyncAssetManagerImpl &GetInstance();

    int32_t DownloadFile(const int32_t userId, const std::string &bundleName, AssetInfo &assetInfo) override;

private:
    CloudSyncAssetManagerImpl() = default;
};
} // namespace OHOS::FileManagement::CloudSync

#endif // OHOS_FILEMGMT_CLOUD_SYNC_ASSET_MANAGER_IMPL_H