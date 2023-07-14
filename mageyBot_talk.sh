#!/bin/bash
resultado=$(curl "https://api.telegram.org/bot${1}/getUpdates")
success_ok=$(echo "$resultado" | jq -r '.result[].message.text')
echo "$success_ok"
