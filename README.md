# jogo-da-velha

# Como as funções funcionam??

**void estruturarJogo() {}**
-> Esta função é responsável por percorrer uma matriz 3x3
através do for, acessando os campos e preenchendo com espaços
vazios.

**int validacaoCaractere() {}**
-> Esta função é responsável por validar se os caracteres digitados
foram 'x' ou 'o'.

**int validacaoCoordenada() {}**
-> Esta função é responsável por validar se as coordenadas digitadas estão de acordo com as disponíveis nos campos da matriz.

**int validacaoPosicaoVazia() {}**
-> Esta função é responsável por validar se a posição escolhida pelo
jogador está vazia.

**void imprimirMatrizJogo() {}**
-> Função responsável por imprimir o desenho do jogo da velha paralelamente a função que estrutura a a matriz.

**int validacaoGanharPelaLinha() {}**
-> Função que valida se o jogador ganhou pelas linhas

**int validacaoGanharPelaColuna() {}**
-> Função que valida se o jogador ganhou pelas colunas

**int validacaoGanharPelaDiagonalPrimaria() {}**
-> Função que valida se o jogador ganhou pelas Diagonal Primaria

**int validacaoGanharDiagonalSecundaria() {}**
-> Função que valida se o jogador ganhou pelas Diagonal Secundaria

**void iniciarJogo() {}**
-> Função responsável por inicializar o jogo e o decorrer de toda a lógica
