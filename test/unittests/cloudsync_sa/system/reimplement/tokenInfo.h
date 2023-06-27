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

#ifndef TOKEN_INFO_H
#define TOKEN_INFO_H

#include <iostream>

class TokenInfo {
public:
    static int32_t tokenid;
    static int32_t GetTokenId()
    {
        return tokenid;
    }
    void SetTokenId(int32_t tokenId)
    {
        tokenid = tokenId;
    }
};

#endif // TOKEN_INFO_H