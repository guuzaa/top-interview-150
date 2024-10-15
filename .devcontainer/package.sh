#!/usr/bin/env bash
#-------------------------------------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License. See https://go.microsoft.com/fwlink/?linkid=2090316 for license information.
#-------------------------------------------------------------------------------------------------------------
#
set -e

apt-get -y update

apt-get -y install \
    build-essential \
    clang-12 \
    clang-format-12 \
    clang-tidy-12 \
    cmake \
    doxygen \
    git \
    pkg-config \
    zlib1g-dev \
    libelf-dev \
    libdwarf-dev