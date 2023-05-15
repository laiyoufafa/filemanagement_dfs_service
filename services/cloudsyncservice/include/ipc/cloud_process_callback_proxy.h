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

#ifndef OHOS_FILEMGMT_CLOUD_PROCESS_CALLBACK_PROXY_H
#define OHOS_FILEMGMT_CLOUD_PROCESS_CALLBACK_PROXY_H

#include "i_cloud_process_callback.h"

#include "iremote_proxy.h"

namespace OHOS::FileManagement::CloudSync {
class CloudProcessCallbackProxy : public IRemoteProxy<ICloudProcessCallback> {
public:
    explicit CloudProcessCallbackProxy(const sptr<IRemoteObject> &impl) : IRemoteProxy<ICloudProcessCallback>(impl) {}
    ~CloudProcessCallbackProxy() override {}

    void OnDownloadProcess(int64_t downloadedSize, int64_t totalSize) override;
private:
    static inline BrokerDelegator<CloudProcessCallbackProxy> delegator_;
};
} // namespace OHOS::FileManagement::CloudSync

#endif // OHOS_FILEMGMT_CLOUD_PROCESS_CALLBACK_PROXY_H
