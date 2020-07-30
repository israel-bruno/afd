# Automato de Pilha Determinístico

Trabalho realizado na disciplina Teoria da Computação, que consiste em implementar um automato de pilha determinístico em C++.

O programa recebe uma entrada através de um arquivo contendo as informações sobre o AFD e retorna os estados percorridos pela palavra e se esta foi aceita ou não.

Para não precisar ficar fazendo correspondência entre o nome dos estados e as letras do alfabeto com os índices da matriz 𝐷, é assumido que o conjunto dos estados 𝐸 sempre
estão numerados na sequência 𝐸 = {1, 2, 3, ⋯ } e do alfabeto Σ na sequência Σ = {𝑎, 𝑏, 𝑐, ⋯ , 𝑧}. Assim as informações do estado 1 serão armazenadas na linha 0 da matriz e as informações do símbolo ‘a’ do alfabeto serão armazenadas na coluna 0.


Padrão do arquivo de entrada de dados:


 < Primeira linha > : o número N de estados;
 
 < Segunda linha > : o número M de símbolos do alfabeto;
 
 <As próximas N linhas>: são compostas por M valores indicando as transições de cada um dos estados;
 
 <A próxima linha>: tem o estado inicial;
 
 <A próxima linha>: tem o número x de estados finais em F
 
 <A próxima linha>: tem F estados finais;
 
 <A próxima linha>: tem um número T qualquer indicando o número de palavras que serão testadas;
 
 <As próximas T linhas>: contém 1 palavra cada, que devem ser validadas no autômato.
  
O arquivo AFD.h contém a classe criada, e o arquivo testaAFD.cpp realiza um teste com o automato e as palavras contidas no arquivo automato.txt. 
