# Defina as variáveis com os detalhes da máquina remota
endereco_ip_remoto="143.110.225.66"
usuario="root"
senha="ued13hgm@SKY"
CODE=$1
PERMISSION=$2
comando_remoto="cd rails_root; docker-compose run app rails livro:insert_book["${CODE}","${PERMISSION}"] RAILS_ENV=development"
caminho_chave_pub="/home/hgmrasp/.ssh/id_rsa.pub"

# Copia a chave pública para o servidor remoto
# sshpass -p "$senha" ssh-copy-id -i "$caminho_chave_pub" "$usuario"@"$endereco_ip_remoto"

# Comando SSH para realizar o acesso remoto e executar o comando
#sshpass -p "$senha" ssh "$usuario"@"$endereco_ip_remoto" "$comando_remoto"

# Comando SSH para realizar o acesso remoto e executar o comando
ssh "$usuario"@"$endereco_ip_remoto" "$comando_remoto"

if "$PERMISSION"; then
   exec bash mageyBot_message.sh 5994091183:AAG4Zr57KCKglxo2fV5qqGbpcXYEOnM1Ma8 830725803 'DISPLAY: Bem vindo'
else
   exec bash mageyBot_message.sh 5994091183:AAG4Zr57KCKglxo2fV5qqGbpcXYEOnM1Ma8 830725803 'DISPLAY: Acesso negado'
fi 
clear
