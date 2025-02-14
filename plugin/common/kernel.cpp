/*
 * SPDX-FileCopyrightText: Copyright (c) 1993-2023 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
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

#include "common/kernel.h"
#include "common/plugin.h"
using namespace nvinfer1;
size_t detectionInferenceWorkspaceSize(bool shareLocation, int N, int C1, int C2, int numClasses, int numPredsPerClass,
    int topK, DataType DT_BBOX, DataType DT_SCORE)
{
    size_t wss[7];
    wss[0] = detectionForwardBBoxDataSize(N, C1, DT_BBOX);
    wss[1] = detectionForwardBBoxPermuteSize(shareLocation, N, C1, DT_BBOX);
    wss[2] = detectionForwardPreNMSSize(N, C2);
    wss[3] = detectionForwardPreNMSSize(N, C2);
    wss[4] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[5] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[6] = std::max(sortScoresPerClassWorkspaceSize(N, numClasses, numPredsPerClass, DT_SCORE),
        sortScoresPerImageWorkspaceSize(N, numClasses * topK, DT_SCORE));
    return calculateTotalWorkspaceSize(wss, 7);
}

size_t detectionInferenceLandmarkWorkspaceSize(bool shareLocation, int32_t N, int32_t C1, int32_t C2, int32_t C3, int32_t numClasses,
    int32_t numPredsPerClass, int32_t topK, DataType DT_BBOX, DataType DT_SCORE)
{
    size_t wss[8];
    wss[0] = detectionForwardBBoxDataSize(N, C1, DT_BBOX);
    wss[1] = detectionForwardBBoxPermuteSize(shareLocation, N, C1, DT_BBOX);
    wss[2] = detectionForwardPreNMSSize(N, C2);
    wss[3] = detectionForwardPreNMSSize(N, C2);
    wss[4] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[5] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[6] = std::max(sortScoresPerClassWorkspaceSize(N, numClasses, numPredsPerClass, DT_SCORE),
        sortScoresPerImageWorkspaceSize(N, numClasses * topK, DT_SCORE));
    wss[7] = detectionForwardLandmarkDataSize(N, C3, DT_BBOX);
    return calculateTotalWorkspaceSize(wss, 8);
}

size_t detectionInferenceLandmarkConfWorkspaceSize(bool shareLocation, int32_t N, int32_t C1, int32_t C2, int32_t C3, int32_t C4,
    int32_t numClasses, int32_t numPredsPerClass, int32_t topK, DataType DT_BBOX, DataType DT_SCORE)
{
    size_t wss[8];
    wss[0] = detectionForwardBBoxDataSize(N, C1, DT_BBOX);
    wss[1] = detectionForwardBBoxPermuteSize(shareLocation, N, C1, DT_BBOX);
    wss[2] = detectionForwardPreNMSSize(N, C2);
    wss[3] = detectionForwardPreNMSSize(N, C2);
    wss[4] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[5] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[6] = std::max(sortScoresPerClassWorkspaceSize(N, numClasses, numPredsPerClass, DT_SCORE),
        sortScoresPerImageWorkspaceSize(N, numClasses * topK, DT_SCORE));
    wss[7] = detectionForwardLandmarkDataSize(N, C3, DT_BBOX);
    wss[8] = detectionForwardPreNMSSize(N, C4);
    return calculateTotalWorkspaceSize(wss, 9);
}

namespace nvinfer1
{
namespace plugin
{
size_t detectionInferenceWorkspaceSize(bool shareLocation, int N, int C1, int C2, int numClasses, int numPredsPerClass,
    int topK, DataType DT_BBOX, DataType DT_SCORE)
{
    size_t wss[7];
    wss[0] = detectionForwardBBoxDataSize(N, C1, DT_BBOX);
    wss[1] = detectionForwardBBoxPermuteSize(shareLocation, N, C1, DT_BBOX);
    wss[2] = detectionForwardPreNMSSize(N, C2);
    wss[3] = detectionForwardPreNMSSize(N, C2);
    wss[4] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[5] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[6] = std::max(sortScoresPerClassWorkspaceSize(N, numClasses, numPredsPerClass, DT_SCORE),
        sortScoresPerImageWorkspaceSize(N, numClasses * topK, DT_SCORE));
    return calculateTotalWorkspaceSize(wss, 7);
}


size_t detectionInferenceLandmarkWorkspaceSize(bool shareLocation, int32_t N, int32_t C1, int32_t C2, int32_t C3, int32_t numClasses,
    int32_t numPredsPerClass, int32_t topK, DataType DT_BBOX, DataType DT_SCORE)
{
    size_t wss[8];
    wss[0] = detectionForwardBBoxDataSize(N, C1, DT_BBOX);
    wss[1] = detectionForwardBBoxPermuteSize(shareLocation, N, C1, DT_BBOX);
    wss[2] = detectionForwardPreNMSSize(N, C2);
    wss[3] = detectionForwardPreNMSSize(N, C2);
    wss[4] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[5] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[6] = std::max(sortScoresPerClassWorkspaceSize(N, numClasses, numPredsPerClass, DT_SCORE),
        sortScoresPerImageWorkspaceSize(N, numClasses * topK, DT_SCORE));
    wss[7] = detectionForwardLandmarkDataSize(N, C3, DT_BBOX);
    return calculateTotalWorkspaceSize(wss, 8);
}

size_t detectionInferenceLandmarkConfWorkspaceSize(bool shareLocation, int32_t N, int32_t C1, int32_t C2, int32_t C3, int32_t C4,
    int32_t numClasses, int32_t numPredsPerClass, int32_t topK, DataType DT_BBOX, DataType DT_SCORE)
{
    size_t wss[8];
    wss[0] = detectionForwardBBoxDataSize(N, C1, DT_BBOX);
    wss[1] = detectionForwardBBoxPermuteSize(shareLocation, N, C1, DT_BBOX);
    wss[2] = detectionForwardPreNMSSize(N, C2);
    wss[3] = detectionForwardPreNMSSize(N, C2);
    wss[4] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[5] = detectionForwardPostNMSSize(N, numClasses, topK);
    wss[6] = std::max(sortScoresPerClassWorkspaceSize(N, numClasses, numPredsPerClass, DT_SCORE),
        sortScoresPerImageWorkspaceSize(N, numClasses * topK, DT_SCORE));
    wss[7] = detectionForwardLandmarkDataSize(N, C3, DT_BBOX);
    wss[8] = detectionForwardPreNMSSize(N, C4);
    return calculateTotalWorkspaceSize(wss, 9);
}

} // namespace plugin
} // namespace nvinfer1
