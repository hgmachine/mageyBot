# Set the bot token and chat ID
TOKEN="${1}"
CHAT_ID="${2}"
MESSAGE="${3}"

# Build the API URL
API_URL="https://api.telegram.org/bot$TOKEN/sendPhoto"

echo Sending message...    
curl -X POST -H 'Content-Type: application/json' -d '{"chat_id": "'"$CHAT_ID"'", "text":

"'"$MESSAGE"'", "disable_notification": true}' https://api.telegram.org/bot$TOKEN/sendMessage

