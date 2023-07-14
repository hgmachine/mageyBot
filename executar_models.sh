# Defina as variáveis com os detalhes da máquina remota
endereco_ip_remoto="143.110.225.66"
usuario="root"
senha="ued13hgm@SKY"
comando_remoto="cd rails_root; docker-compose run app rails modelo:atualizar_eliminar["${1}"] RAILS_ENV=development"
clear
# Comando SSH para realizar o acesso remoto e executar o comando
# sshpass -p "$senha" ssh "$usuario"@"$endereco_ip_remoto" "$comando_remoto"
ssh "$usuario"@"$endereco_ip_remoto" "$comando_remoto"
