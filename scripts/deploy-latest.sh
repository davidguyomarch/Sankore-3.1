#!/bin/bash
# deploy-latest.sh
# Downloads an Open-Sankore Windows build from GitHub Actions
# into ../sankore-install/ (shared with UTM VM)
#
# Usage:
#   ./scripts/deploy-latest.sh          # latest successful build
#   ./scripts/deploy-latest.sh 29185891237  # specific run ID

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
INSTALL_DIR="$(dirname "$PROJECT_DIR")/sankore-install"
RUN_ID="${1:-}"

echo "=== Open-Sankore: Deploy Build ==="
echo "Target: $INSTALL_DIR"

# Clean and recreate
rm -rf "$INSTALL_DIR"
mkdir -p "$INSTALL_DIR"

# Download from GitHub Actions
cd "$PROJECT_DIR"
if [ -n "$RUN_ID" ]; then
    echo "Downloading artifact from run #$RUN_ID..."
    gh run download "$RUN_ID" --name Open-Sankore-Windows-x64 --dir "$INSTALL_DIR"
else
    echo "Downloading latest artifact from GitHub Actions..."
    gh run download --name Open-Sankore-Windows-x64 --dir "$INSTALL_DIR"
fi

# Copy the test runner script
cp "$SCRIPT_DIR/run-test.bat" "$INSTALL_DIR/"

FILE_COUNT=$(ls "$INSTALL_DIR" | wc -l | tr -d ' ')
echo ""
echo "✅ Done! $FILE_COUNT files deployed to:"
echo "   $INSTALL_DIR"
echo ""
echo "In your Windows VM, run: Z:\\sankore-install\\run-test.bat"
