==========================
ESTRUTURA DA BASE
==========================
A base é dividida em 3 diretórios principais:
1) PA: contém todos as notícias originais veiculadas pela PA. Use o diretório rawtexts apenas. 
2) newspapers: contém as notícias veiculadas nos dias posteriores à publicação da PA. Use apenas a pasta rawtexts. 
3) file_index: contém o caminho de todos os arquivos da base.

Dentro de cada diretório, os textos estão divididos entre courts e showbiz. Textos do showbiz só podem ter sido copiados de outros textos de showbiz.

==========================
INSTRUCAO PARA USO DA BASE
==========================

O objetivo do desafio é identificar quais textos jornalísticos (pasta newspapers) foram plagiados dos textos da PA (pasta PA). Os plágios foram classificados como textos foram totalmente copiados (wholly derived), quais foram parcialmente copiados (partially derived) e quais são originais (non_derived).


==========================================
COMO AVALIAR SE SEU ALGORITMO FUNCIONA BEM
==========================================

A resposta esperada está na pasta file_index, onde estão os arquivos de wholly_dirived, partially_derived e non_derived. 

Você deve inserir todos os textos de PA na sua estrutura e, para cada arquivo dentro de newspaper você deve processar e classificar se ele foi totalmente copiado, parcialmente copiado ou se é original. Depois que fizer isso para todos os textos, você deve verificar a pasta de file_index e contar quantos arquivos seu algoritmo acertou ou errou em cada categoria. 


