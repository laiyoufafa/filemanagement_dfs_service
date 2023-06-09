/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TRANS_EVENT_H
#define TRANS_EVENT_H
#include <string>
#include "napi/native_api.h"

namespace OHOS {
namespace Storage {
namespace DistributedFile {
class Event {
public:
    virtual napi_value ToJsObject(napi_env env) = 0;
};

class TransEvent : public Event {
public:
    enum {
        TRANS_SUCCESS = 0,
        TRANS_FAILURE = 1
    };
public:
    TransEvent(int32_t err, std::string fname, int32_t num) : errorCode_(err), fileName_(fname), fileCount_(num) {}
    TransEvent(int32_t err, std::string fname) : errorCode_(err), fileName_(fname) {}
    TransEvent(int32_t err) : errorCode_(err) {}
    virtual ~TransEvent() {}
    napi_value ToJsObject(napi_env env);
    void SetName(std::string &name)
    {
        eventName_ = name;
    }
    std::string GetName()
    {
        return eventName_;
    }

private:
    std::string eventName_ = "";
    int32_t errorCode_ = TRANS_SUCCESS;
    std::string fileName_ = "";
    int32_t fileCount_ = 0;
};
} // namespace DistributedFile
} // namespace Storage
} // namespace OHOS
#endif // TRANS_EVENT_H