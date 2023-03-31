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

#include "data_sync/sync_state_manager.h"
#include "utils_log.h"
#include <type_traits>

namespace OHOS::FileManagement::CloudSync {
using namespace std;

Action SyncStateManager::UpdateSyncState(SyncState newState)
{
    std::unique_lock<std::shared_mutex> lck(syncMutex_);
    state_ = newState;
    stopSyncFlag_ = false;
    return nextAction_;
}

bool SyncStateManager::IsPendingSync(bool forceFlag)
{
    std::unique_lock<std::shared_mutex> lck(syncMutex_);
    if (state_ != SyncState::SYNCING) {
        state_ = SyncState::SYNCING;
        nextAction_ = Action::STOP;
        return false;
    }

    if (forceFlag) {
        nextAction_ = Action::FORCE_START;
    } else {
        nextAction_ = Action::START;
    }
    return true;
}

bool SyncStateManager::GetStopSyncFlag()
{
    return stopSyncFlag_;
}

void SyncStateManager::SetStopSyncFlag()
{
    std::unique_lock<std::shared_mutex> lck(syncMutex_);
    nextAction_ = Action::STOP;
    stopSyncFlag_ = true;
}
} // namespace OHOS::FileManagement::CloudSync