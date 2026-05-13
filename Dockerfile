FROM ubuntu:22.04

# Avoid interactive prompts during install
ENV DEBIAN_FRONTEND=noninteractive

# Update and install Qt 6 + build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    qt6-base-dev \
    qt6-base-dev-tools \
    libqt6svg6-dev \
    qt6-webengine-dev \
    qt6-multimedia-dev \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    qt6-l10n-tools \
    libqt6opengl6-dev \
    libgl1-mesa-dev \
    libssl-dev \
    zlib1g-dev \
    libx11-dev \
    git \
    lcov \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

# Ensure 'qmake' command uses Qt 6
RUN ln -sf /usr/bin/qmake6 /usr/local/bin/qmake

# Default command: bash
CMD ["/bin/bash"]
