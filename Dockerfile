FROM ubuntu:14.04

# Avoid interactive prompts during install
ENV DEBIAN_FRONTEND=noninteractive

# Update and install Qt 4.8 + build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    qt4-dev-tools \
    libqt4-dev \
    libqt4-webkit \
    libqt4-svg \
    libqt4-network \
    libqt4-xml \
    libqt4-xmlpatterns \
    libqt4-script \
    libphonon-dev \
    libssl-dev \
    zlib1g-dev \
    git \
    lcov \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

# Default command: bash
CMD ["/bin/bash"]
