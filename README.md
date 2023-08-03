# Contagem de Componentes Conexos em Imagens
Este é um projeto de processamento de imagens que tem como objetivo contar o número de componentes conexos das formas pretas em uma imagem com fundo branco e diversas bolas pretas de diâmetros diferentes.

## Descrição do Problema
Dada uma imagem de entrada com as características mencionadas, o programa deve ser capaz de identificar e rotular as formas pretas presentes na imagem, atribuindo um número diferente a cada componente conexo. Em seguida, o programa deve contar quantos componentes conexos existem na imagem.

## Algoritmo de Rotulação de Componentes Conexos
O algoritmo de rotulação de componentes conexos, a ser utilizado neste projeto, pode ser encontrado na Seção 2.4.3 do livro Processamento de Imagens Digitais, de Rafael C. Gonzalez e Richard E. Woods. A Figura 2 do livro apresenta uma representação visual do algoritmo e suas etapas.

## Funcionamento do Programa
- Leitura da imagem de entrada contendo as formas pretas e o fundo branco.

- Pré-processamento da imagem, se necessário, para melhorar a detecção das formas.

- Aplicação do algoritmo de rotulação de componentes conexos para identificar as bolas pretas.

- Contagem do número de componentes conexos detectados.
Exibição do resultado da contagem na saída do programa.

## Instruções para Execução do Programa:

Para executar o programa de contagem de componentes conexos em imagens, siga os passos abaixo:

1. Abra o terminal ou prompt de comando no diretório onde se encontra o código-fonte do programa.

2. Digite o seguinte comando para compilar o código:

   ```
   make
   ```

   O comando `make` irá compilar o programa e gerar o executável `rotula`.

3. Após a compilação bem-sucedida, utilize o comando abaixo para executar o programa e realizar a contagem dos componentes conexos em uma imagem específica:

   ```
   ./rotula [imagem.pgm]
   ```

   Substitua `[imagem.pgm]` pelo caminho e nome do arquivo da imagem que deseja processar.

   **Exemplo:**

   ```
   ./rotula beans1.pgm
   ```

   Neste exemplo, o programa será executado utilizando a imagem `beans.pgm` como entrada, contando o número de componentes conexos das formas pretas presentes na imagem.

4. O programa processará a imagem e exibirá o resultado na saída do terminal, mostrando o número total de componentes conexos detectados.

Lembre-se de que é necessário ter o compilador e as dependências corretas para a compilação e execução do programa. Certifique-se de atender a todos os requisitos antes de executar os comandos acima.

**Observações:**
- Certifique-se de que o arquivo de imagem fornecido esteja no formato PGM (Portable Graymap) suportado pelo programa.
- Verifique se o arquivo da imagem está localizado no mesmo diretório do programa ou forneça o caminho completo até o arquivo, caso esteja em outro diretório.
