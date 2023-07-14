#!/bin/bash
resultado=$(curl "https://api.telegram.org/bot${1}/getUpdates")
# Filtra o resultado para obter a palavra Sim na ultima mensagem 
nope=$(echo "$resultado" | jq -r '.result[-1].message.text')
if [ "$nope" = "Nope" ]; then
   exec bash mageyBot_message.sh "${1}" "${2}" 'DISPLAY: Senha/código inválido!'
else
   exec bash mageyBot_what.sh "${1}" "${3}" 
fi
exec bash mageyBot_cleaner.sh "${1}" 
