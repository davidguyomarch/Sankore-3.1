#!/bin/bash
# deploy-latest.sh
# Downloads the latest Open-Sankore Windows build from GitHub Actions
# into ../sankore-install/ (shared with UTM VM)

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
INSTALL_DIR="$(dirname "$PROJECT_DIR")/sankore-install"

echo "=== Open-Sankore: Deploy Latest Build ==="
echo "Target: $INSTALL_DIR"
echo ""

# Clean and recreate
rm -rf "$INSTALL_DIR"
mkdir -p "$INSTALL_DIR"

# Download from GitHub Actions
cd "$PROJECT_DIR"
echo "Downloading latest artifact from GitHub Actions..."
gh run download --name Open-Sankore-Windows-x64 --dir "$INSTALL_DIR"

# Copy the test runner script
cp "$SCRIPT_DIR/run-test.bat" "$INSTALL_DIR/"

FILE_COUNT=$(ls "$INSTALL_DIR" | wc -l | tr -d ' ')
echo ""
echo "✅ Done! $FILE_COUNT files deployed to:"
echo "   $INSTALL_DIR"
echo ""
echo "In your Windows VM, run Open-Sankore.exe from the shared folder."
