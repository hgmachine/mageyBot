# Defina as variáveis com os detalhes da máquina remota
endereco_ip_remoto="143.110.225.66"
usuario="root"
senha="ued13hgm@SKY"
CODE=$1
CHAVE_PRIVADA="/home/hgmrasp/.ssh/id_rsa"
PERMISSION=$2
comando_remoto="cd rails_root; docker-compose run app rails livro:insert_book["${CODE}","${PERMISSION}"] RAILS_ENV=development"

# Comando SSH para realizar o acesso remoto e executar o comando
ssh -i "$CHAVE_PRIVADA" "$usuario"@"$endereco_ip_remoto" "$comando_remoto"

if ["${PERMISSION}" = "Sim" ]; then
   exec bash mageyBot_message.sh 5994091183:AAG4Zr57KCKglxo2fV5qqGbpcXYEOnM1Ma8 830725803 'DISPLAY: A porta será aberta.'
else
   exec bash mageyBot_message.sh 5994091183:AAG4Zr57KCKglxo2fV5qqGbpcXYEOnM1Ma8 830725803 'DISPLAY: A porta permacecerá fechada.'
fi   
