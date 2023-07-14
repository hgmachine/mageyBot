# Set the bot token and chat ID
TOKEN="${1}"
CHAT_ID="${2}"

# Set the path to the image file
IMAGE_PATH="someone.jpg"

# Build the API URL
API_URL="https://api.telegram.org/bot$TOKEN/sendPhoto"

echo Sending photo...
curl -s -X POST "$API_URL" \
    -F chat_id="$CHAT_ID" \
    -F photo=@"$IMAGE_PATH"
