#!/bin/bash
resultado=$(curl "https://api.telegram.org/bot${1}/getUpdates")
# Filtra o resultado para obter o último ID de atualização
ultimo_id=$(echo "$resultado" | jq -r '.result[-1].update_id')
# Limpar o histórico de comandos
curl "https://api.telegram.org/bot${1}/getUpdates?offset=$((ultimo_id+1))"

