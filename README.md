Gerador de api REST feito em C++

Api REST gerada é escrita em Golang.

Go download: https://golang.org/dl/

É necessário configurar as variáveis de ambiante após a instalação da linguagem GO.

workspace padrão do go:

    Go-workspace
                |
                - bin
                |
                - pkg
                |
                - src

É necessário o uso do pacote MUX para que a api REST funcione.

Execute o seguinte comando dentro da pasta "src":

\> go get github.com/gorilla/mux

Agora cole o arguivo "myRest.go" gerado pelo programa em C++ dentro da pasta "src"

Execute o comando para criar o executavel da api:

\> go build myRest.go

Para executar o programa basta digitar o nome do executável:

\> myRest.exe

URLs geradas disponíveis são:

o nome "users" e usado apenas para exemplo.

Retornar uma lista de objetos:

GET => http://localhost:3000/users

Retornar um objeto por Id:

GET => http://localhost:3000/users/1

Criar um novo objeto:

POST => http://localhost:3000/users

Atualizar um objeto por Id:

PUT => http://localhost:3000/users/update/1

Deletar um objeto por Id:

DELETE => http://localhost:3000/users/delete/1

Observações:

    Este programa lida apenas com estruturas simples que possuam apenas INT, STRING e FLOAT.

    3 Objetos iniciais são gerados automaticamente. É recomendável alterar seus parâmetros.

