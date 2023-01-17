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

#ifndef OHOS_FILEMGMT_CLOUD_SYNC_SERVICE_STUB_H
#define OHOS_FILEMGMT_CLOUD_SYNC_SERVICE_STUB_H

#include <map>

#include "i_cloud_sync_service.h"
#include "iremote_stub.h"

namespace OHOS::FileManagement::CloudSync {
class CloudSyncServiceStub : public IRemoteStub<ICloudSyncService> {
public:
    CloudSyncServiceStub();
    virtual ~CloudSyncServiceStub() = default;
    int32_t OnRemoteRequest(uint32_t code, MessageParcel &data, MessageParcel &reply, MessageOption &option) override;

private:
    using ServiceInterface = int32_t (CloudSyncServiceStub::*)(MessageParcel &data, MessageParcel &reply);
    std::map<uint32_t, ServiceInterface> opToInterfaceMap_;

    int32_t HandleRegisterCallbackInner(MessageParcel &data, MessageParcel &reply);
};
} // namespace OHOS::FileManagement::CloudSync

#endif // OHOS_FILEMGMT_CLOUD_SYNC_SERVICE_STUB_H