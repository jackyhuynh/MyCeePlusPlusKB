#!/bin/bash

# Simple PR Review Helper Script (Free)
# Usage: ./scripts/review_pr.sh [branch_name]

BRANCH=${1:-"feature/add-fundamentals-test-suite"}
OUTPUT_FILE="pr_review_$(date +%Y%m%d_%H%M%S).txt"

echo "🤖 Preparing PR review for branch: $BRANCH"
echo "=================================================="

# Create review directory
mkdir -p reviews

# Get PR information
echo "## PR Review Summary" > "reviews/$OUTPUT_FILE"
echo "**Date:** $(date)" >> "reviews/$OUTPUT_FILE"
echo "**Branch:** $BRANCH" >> "reviews/$OUTPUT_FILE"
echo "**Base:** main" >> "reviews/$OUTPUT_FILE"
echo "" >> "reviews/$OUTPUT_FILE"

# Get changed files
echo "### Changed Files:" >> "reviews/$OUTPUT_FILE"
git diff --name-only main..$BRANCH | while read file; do
    echo "- \`$file\`" >> "reviews/$OUTPUT_FILE"
done
echo "" >> "reviews/$OUTPUT_FILE"

# Get diff stats
echo "### Change Statistics:" >> "reviews/$OUTPUT_FILE"
git diff --stat main..$BRANCH >> "reviews/$OUTPUT_FILE"
echo "" >> "reviews/$OUTPUT_FILE"

# Get the actual diff for C++ files
echo "### Code Changes (C++ Files Only):" >> "reviews/$OUTPUT_FILE"
echo '```diff' >> "reviews/$OUTPUT_FILE"
git diff main..$BRANCH -- '*.cpp' '*.h' '*.hpp' '*.cc' '*.cxx' >> "reviews/$OUTPUT_FILE"
echo '```' >> "reviews/$OUTPUT_FILE"

echo ""
echo "✅ Review file created: reviews/$OUTPUT_FILE"
echo ""
echo "📋 Next steps:"
echo "1. Open reviews/$OUTPUT_FILE"
echo "2. Copy the content"
echo "3. Paste into Claude Code with prompt:"
echo "   'Please review this PR diff for C++ code quality, security, and best practices'"
echo ""
echo "🔍 Quick file preview:"
echo "   - Files changed: $(git diff --name-only main..$BRANCH | wc -l)"
echo "   - Lines changed: $(git diff --shortstat main..$BRANCH)"