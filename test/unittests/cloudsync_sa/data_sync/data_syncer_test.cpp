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

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "data_sync/data_syncer.h"

#include "data_sync_manager.h"
#include "gallery_data_syncer.h"

#include "dfs_error.h"
#include "gallery_data_syncer.h"
#include "sync_rule/battery_status.h"
#include "sync_rule/cloud_status.h"

namespace OHOS::FileManagement::CloudSync::Test {
using namespace testing;
using namespace testing::ext;
using namespace std;

class DataSyncerMock final : public DataSyncer {
public:
    DataSyncerMock(const std::string bundleName, const int32_t userId);
    MOCK_METHOD0(Schedule, void());
    MOCK_METHOD0(Reset, void());
};

DataSyncerMock::DataSyncerMock(const std::string bundleName, const int32_t userId) : DataSyncer("com.ohos.test", 100) {}

class DataSyncerTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
    std::shared_ptr<DataSyncManager> dataSyncManager_;
    std::shared_ptr<DataSyncerMock> datasyncer_;
    std::shared_ptr<DataSyncer> datasyncer1_;
    std::shared_ptr<FileDataHandler> handler_;
};
void DataSyncerTest::SetUpTestCase(void)
{
    GTEST_LOG_(INFO) << "SetUpTestCase";
}

void DataSyncerTest::TearDownTestCase(void)
{
    GTEST_LOG_(INFO) << "TearDownTestCase";
}

void DataSyncerTest::SetUp(void)
{
    GTEST_LOG_(INFO) << "SetUp";
    int32_t userId = 100;
    string bundleName = "com.ohos.test";
    datasyncer_ = make_shared<DataSyncerMock>(bundleName, userId);
    dataSyncManager_ = make_shared<DataSyncManager>();
    datasyncer1_ = dataSyncManager_->GetDataSyncer(bundleName, userId);
    shared_ptr<GalleryDataSyncer> galleryDataSyncer_ = static_pointer_cast<GalleryDataSyncer>(datasyncer1_);
    handler_ = galleryDataSyncer_->fileHandler_;
}

void DataSyncerTest::TearDown(void)
{
    GTEST_LOG_(INFO) << "TearDown";
}

/**
 * @tc.name: SetSdkHelperTest1
 * @tc.desc: Verify the SetSdkHelper function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, SetSdkHelperTest1, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "SetSdkHelper Start";
    shared_ptr<SdkHelper> sdkHelper;
    try {
        datasyncer_->SetSdkHelper(sdkHelper);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "SetSdkHelper FAILED";
    }
    GTEST_LOG_(INFO) << "SetSdkHelper end";
}

/**
 * @tc.name: BeginTransactionTest
 * @tc.desc: Verify the BeginTransaction function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, BeginTransactionTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "BeginTransaction Start";
    try {
        datasyncer_->BeginTransaction();
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "BeginTransaction FAILED";
    }
    GTEST_LOG_(INFO) << "BeginTransaction end";
}

/**
 * @tc.name: EndTransactionTest
 * @tc.desc: Verify the EndTransaction function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, EndTransactionTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "EndTransaction Start";
    try {
        datasyncer_->EndTransaction();
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "EndTransaction FAILED";
    }
    GTEST_LOG_(INFO) << "EndTransaction end";
}

/**
 * @tc.name: GetBundleNameTest
 * @tc.desc: Verify the GetBundleName function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, GetBundleNameTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "GetBundleName Start";
    string res = datasyncer_->GetBundleName();
    EXPECT_EQ(res, datasyncer_->bundleName_);
    GTEST_LOG_(INFO) << "GetBundleName end";
}

/**
 * @tc.name: GetUserIdTest
 * @tc.desc: Verify the GetUserId function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, GetUserIdTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "GetUserId Start";
    int res = datasyncer_->GetUserId();
    EXPECT_EQ(res, datasyncer_->userId_);
    GTEST_LOG_(INFO) << "GetUserId end";
}

/**
 * @tc.name: GetSyncStateTest
 * @tc.desc: Verify the GetSyncState function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, GetSyncStateTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "GetSyncState Start";
    try {
        datasyncer_->GetSyncState();
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "GetSyncState FAILED";
    }
    GTEST_LOG_(INFO) << "GetSyncState end";
}

/**
 * @tc.name: CompletePullTest
 * @tc.desc: Verify the CompletePull function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, CompletePullTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "CompletePull Start";
    try {
        datasyncer_->CompletePull();
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "CompletePull FAILED";
    }
    GTEST_LOG_(INFO) << "CompletePull end";
}

/**
 * @tc.name: CompletePushTest
 * @tc.desc: Verify the CompletePush function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, CompletePushTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "CompletePush Start";
    try {
        datasyncer_->CompletePush();
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "CompletePush FAILED";
    }
    GTEST_LOG_(INFO) << "CompletePush end";
}

/**
 * @tc.name: StartDownloadFileTest
 * @tc.desc: Verify the StartDownloadFileTask function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, StartDownloadFileTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "StartDownloadFile Start";
    int res = datasyncer_->StartDownloadFile("/test", 100);
    EXPECT_EQ(res, E_OK);
    GTEST_LOG_(INFO) << "StartDownloadFile end";
}

/**
 * @tc.name: StopDownloadFileTest
 * @tc.desc: Verify the StopDownloadFileTask function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, StopDownloadFileTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "StopDownloadFile Start";
    int res = datasyncer_->StopDownloadFile("/test", 100);
    EXPECT_EQ(res, E_OK);
    GTEST_LOG_(INFO) << "StopDownloadFile end";
}

/**
 * @tc.name: RegisterDownloadFileCallbackTest
 * @tc.desc: Verify the RegisterDownloadFileCallback function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, RegisterDownloadFileCallbackTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "RegisterDownloadFileCallback Start";
    int res = datasyncer_->RegisterDownloadFileCallback(100, nullptr);
    EXPECT_EQ(res, E_OK);
    GTEST_LOG_(INFO) << "RegisterDownloadFileCallback end";
}

/**
 * @tc.name: UnregisterDownloadFileCallbackTest
 * @tc.desc: Verify the UnregisterDownloadFileCallback function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, UnregisterDownloadFileCallbackTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "UnregisterDownloadFileCallback Start";
    int res = datasyncer_->UnregisterDownloadFileCallback(100);
    EXPECT_EQ(res, E_OK);
    GTEST_LOG_(INFO) << "UnregisterDownloadFileCallback end";
}

/**
 * @tc.name: PullTest
 * @tc.desc: Verify the Pull function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, PullTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "Pull Start";
    datasyncer_->startCursor_ = "";
    int32_t result = datasyncer_->Pull(nullptr);
    EXPECT_EQ(result, E_OK);
    GTEST_LOG_(INFO) << "Pull end";
}

/**
 * @tc.name: PullTest001
 * @tc.desc: Verify the Pull function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, PullTest001, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "Pull Start";
    datasyncer_->startCursor_ = "pulltest";
    int32_t result = datasyncer_->Pull(nullptr);
    EXPECT_EQ(result, E_OK);
    GTEST_LOG_(INFO) << "Pull end";
}

/**
 * @tc.name: CleanTest
 * @tc.desc: Verify the CleanTest function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, CleanTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "CleanTest Start";
    int res = datasyncer_->Clean(0);
    EXPECT_EQ(res, E_OK);
    GTEST_LOG_(INFO) << "CleanTest end";
}

/**
 * @tc.name: CleanInnerTest001
 * @tc.desc: Verify the CleanInnerTest001 function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, CleanInnerTest001, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "CleanInnerTest001 Start";
    int action = 0;
    int32_t userId = 100;
    string bundleName = "com.ohos.photos";
    shared_ptr<GalleryDataSyncer> galleryDataSyncer_ = make_shared<GalleryDataSyncer>(bundleName, userId);
    int res = datasyncer_->CleanInner(galleryDataSyncer_->fileHandler_, action);
    galleryDataSyncer_ = nullptr;
    EXPECT_EQ(res, 2);
    GTEST_LOG_(INFO) << "CleanInnerTest001 end";
}


/**
 * @tc.name: PullRetryRecordsTest
 * @tc.desc: Verify the PullRetryRecords function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, PullRetryRecordsTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "PullRetryRecords Start";
    shared_ptr<TaskContext> context = make_shared<TaskContext>(handler_);
    try {
        datasyncer_->PullRetryRecords(context);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "PullRetryRecords FAILED";
    }
    GTEST_LOG_(INFO) << "PullRetryRecords end";
}

/**
 * @tc.name: CreateRecordsTest
 * @tc.desc: Verify the CreateRecords function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, CreateRecordsTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "CreateRecords Start";
    shared_ptr<TaskContext> context = make_shared<TaskContext>(handler_);
    try {
        datasyncer_->CreateRecords(context);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "CreateRecords FAILED";
    }
    GTEST_LOG_(INFO) << "CreateRecords end";
}

/**
 * @tc.name: DeleteRecordsTest
 * @tc.desc: Verify the DeleteRecords function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, DeleteRecordsTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "DeleteRecords Start";
    shared_ptr<TaskContext> context = make_shared<TaskContext>(handler_);
    try {
        datasyncer_->DeleteRecords(context);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "DeleteRecords FAILED";
    }
    GTEST_LOG_(INFO) << "DeleteRecords end";
}

/**
 * @tc.name: ModifyMdirtyRecordsTest
 * @tc.desc: Verify the ModifyMdirtyRecords function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, ModifyMdirtyRecordsTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "ModifyMdirtyRecords Start";
    shared_ptr<TaskContext> context = make_shared<TaskContext>(handler_);
    try {
        datasyncer_->ModifyMdirtyRecords(context);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "ModifyMdirtyRecords FAILED";
    }
    GTEST_LOG_(INFO) << "ModifyMdirtyRecords end";
}

/**
 * @tc.name: ModifyFdirtyRecordsTest001
 * @tc.desc: Verify the ModifyFdirtyRecords function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, ModifyFdirtyRecordsTest001, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "ModifyFdirtyRecords Start";
    shared_ptr<TaskContext> context = make_shared<TaskContext>(nullptr);
    try {
        datasyncer_->ModifyFdirtyRecords(context);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "ModifyFdirtyRecords FAILED";
    }
    GTEST_LOG_(INFO) << "ModifyFdirtyRecords end";
}

/**
 * @tc.name: ModifyFdirtyRecordsTest
 * @tc.desc: Verify the ModifyFdirtyRecords function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, ModifyFdirtyRecordsTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "ModifyFdirtyRecords Start";
    shared_ptr<TaskContext> context = make_shared<TaskContext>(handler_);
    try {
        datasyncer_->ModifyFdirtyRecords(context);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "ModifyFdirtyRecords FAILED";
    }
    GTEST_LOG_(INFO) << "ModifyFdirtyRecords end";
}

/**
 * @tc.name: PushTest
 * @tc.desc: Verify the Push function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, PushTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "Push Start";
    int res = datasyncer_->Push(nullptr);
    EXPECT_EQ(res, E_OK);
    GTEST_LOG_(INFO) << "Push end";
}

/**
 * @tc.name: SyncStateChangedNotifyTest
 * @tc.desc: Verify the SyncStateChangedNotify function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, SyncStateChangedNotifyTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "SyncStateChangedNotify Start";
    try {
        datasyncer_->SyncStateChangedNotify(CloudSyncState::STOPPED, ErrorType::NO_ERROR);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "SyncStateChangedNotify FAILED";
    }
    GTEST_LOG_(INFO) << "SyncStateChangedNotify end";
}

/**
 * @tc.name: GetErrorTypeTest
 * @tc.desc: Verify the GetErrorType function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, GetErrorTypeTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "GetErrorType Start";
    int32_t code = E_OK;
    ErrorType result = datasyncer_->GetErrorType(code);
    EXPECT_EQ(ErrorType::NO_ERROR, result);
    BatteryStatus::level_ = BatteryStatus::LEVEL_LOW;
    code = 123;
    result = datasyncer_->GetErrorType(code);
    EXPECT_EQ(ErrorType::BATTERY_LEVEL_LOW, result);
    BatteryStatus::level_ = BatteryStatus::LEVEL_TOO_LOW;
    code = 456;
    result = datasyncer_->GetErrorType(code);
    EXPECT_EQ(ErrorType::BATTERY_LEVEL_WARNING, result);
    GTEST_LOG_(INFO) << "GetErrorType end";
}

/**
 * @tc.name: OnFetchRetryRecordTest
 * @tc.desc: Verify the OnFetchRetryRecord function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, OnFetchRetryRecordTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "OnFetchRetryRecord Start";
    auto context = std::make_shared<DriveKit::DKContext>();
    auto database = std::make_shared<DriveKit::DKDatabase>(nullptr, DriveKit::DKDatabaseScope::DK_PRIVATE_DATABASE);
    DriveKit::DKRecordId recordId = "record1";
    DriveKit::DKRecord record;
    DriveKit::DKError error;
    try {
        datasyncer_->OnFetchRetryRecord(context, database, recordId, record, error);
        EXPECT_TRUE(true);
    } catch (...) {
        EXPECT_TRUE(false);
        GTEST_LOG_(INFO) << "OnFetchRetryRecord FAILED";
    }
    GTEST_LOG_(INFO) << "OnFetchRetryRecord end";
}

/**
 * @tc.name: StartSyncTest
 * @tc.desc: Verify the StartSync function
 * @tc.type: FUNC
 * @tc.require: I6JPKG
 */
HWTEST_F(DataSyncerTest, StartSyncTest, TestSize.Level1)
{
    GTEST_LOG_(INFO) << "StartSync Start";
    bool forceFlag = false;
    datasyncer_->syncStateManager_.state_ = SyncState::SYNCING;
    int res = datasyncer_->StartSync(forceFlag, SyncTriggerType::PENDING_TRIGGER);
    EXPECT_EQ(res, E_PENDING);
    GTEST_LOG_(INFO) << "StartSync end";
}

} // namespace OHOS::FileManagement::CloudSync::Test