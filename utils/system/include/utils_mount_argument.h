/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#ifndef UTILS_MOUNT_ARGUMENT_H
#define UTILS_MOUNT_ARGUMENT_H

#include <string>

namespace OHOS {
namespace Storage {
namespace DistributedFile {
namespace Utils {
struct MountArgument final {
    int userId_{0};
    bool accountless_{false};
    std::string groupId_;
    bool needInitDir_{false};
    bool useCache_{false};
    bool caseSensitive_{true};
    bool enableMergeView_{false};
    bool enableFixupOwnerShip_{false};
    bool enableOfflineStash_{true};
    bool externalFS_{false};
    std::string packageName_;

    std::string GetFullSrc() const;
    std::string GetFullDst() const;
    std::string GetCtrlPath() const;
    std::string GetCachePath() const;
    std::string OptionsToString() const;
    unsigned long GetFlags() const;
};

class MountArgumentDescriptors final {
public:
    static MountArgument Alpha(int userId = 0);
    static MountArgument
        SetAuthGroupMountArgument(const std::string &groupId, const std::string &packageName, bool accountless);
};
} // namespace Utils
} // namespace DistributedFile
} // namespace Storage
} // namespace OHOS
#endif // UTILS_MOUNT_ARGUMENT_H