#!/bin/sh
#
# SPDX-FileCopyrightText: Copyright (c) 1993-2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#


# Use this script to process the ONNX files from resnet_example.py
# and generate the engine + JSON files for exploration with TREx.


SCRIPT=`realpath $0`
SCRIPT_DIR=`dirname $SCRIPT`
PROCESS_ENGINE=$SCRIPT_DIR/../../../utils/process_engine.py
ONNX_DIR=$SCRIPT_DIR/generated

# Batch size = 32
SHAPES='shapes=input_1:32x224x224x3'

python3 $PROCESS_ENGINE $ONNX_DIR/resnet.onnx $ONNX_DIR/fp32 $SHAPES
python3 $PROCESS_ENGINE $ONNX_DIR/resnet.onnx $ONNX_DIR/fp16 $SHAPES fp16
python3 $PROCESS_ENGINE $ONNX_DIR/resnet-qat.onnx $ONNX_DIR/qat $SHAPES best
