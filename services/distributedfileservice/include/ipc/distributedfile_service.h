/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
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

#ifndef DISTRIBUTEDFILE_SERVICE_H
#define DISTRIBUTEDFILE_SERVICE_H

#include "distributedfile_service_stub.h"
#include "iremote_stub.h"
#include "system_ability.h"

#include <mutex>

namespace OHOS {
namespace Storage {
namespace DistributedFile {
class DistributedFileService : public SystemAbility,
                               public DistributedFileServiceStub,
                               public std::enable_shared_from_this<DistributedFileService> {
    DECLARE_SYSTEM_ABILITY(DistributedFileService)
public:
    explicit DistributedFileService(int32_t saId, bool runOnCreate = true) : SystemAbility(saId, runOnCreate) {}
    ~DistributedFileService() {}
    void OnDump() override;
    void OnStart() override;
    void OnStop() override;

    int32_t SendFile(const std::string &cid,
                     const std::vector<std::string> &sourceFileList,
                     const std::vector<std::string> &destinationFileList,
                     const uint32_t fileCount) override;
    int32_t OpenFile(int32_t fd, const std::string &fileName, int32_t mode) override;
    int32_t RegisterNotifyCallback(sptr<IFileTransferCallback> &callback) override;
    int32_t UnRegisterNotifyCallback() override;
    int32_t IsDeviceOnline(const std::string &cid) override;

    static inline const std::string pkgName_ { "ohos.storage.distributedfile.service" };
private:
    void PublishSA();
    void StartManagers();
    int32_t CreateSourceResources(const std::vector<std::string> &sourceFileList, std::vector<char *> &sFileList);
    int32_t CreateDestResources(const std::vector<std::string> &destinationFileList, std::vector<char *> &dFileList);
    void DestroyFileList(std::vector<char *> &fileList);
};
} // namespace DistributedFile
} // namespace Storage
} // namespace OHOS
#endif // DISTRIBUTEDFILE_SERVICE_H
