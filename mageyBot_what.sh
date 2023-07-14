#!/bin/bash
resultado=$(curl "https://api.telegram.org/bot${1}/getUpdates")
# Filtra o resultado para obter a palavra Sim na última mensagem
success_ok=$(echo "$resultado" | jq -r '.result[-1].message.text')
clear
if [[ $success_ok == "null" ]]; then
   echo "DISPLAY: Tente mais tarde"
elif [[ $success_ok == "Sim" ]]; then
   PERMISSION=true
   bash executar_books.sh "${2}" "${PERMISSION}"
else
   PERMISSION=false
   bash executar_books.sh "${2}" "${PERMISSION}"
fi
bash mageyBot_cleaner.sh "${1}"

