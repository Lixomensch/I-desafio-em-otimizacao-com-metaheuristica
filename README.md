# I Desafio em Otimizacao com Metaheuristica PUC GO
# Sumário

- [Equipe](#equipe)
- [Projeto](#projeto)
  - [Sobre o Desafio](#sobre-o-desafio)
  - [Dados](#dados)
  - [Hardware e Software Utilizados](#hardware-e-software-utilizados)
  - [Metaheurísticas Testadas](#metaheurísticas-testadas)
    - [Artificial Bee Colony (ABC)](#artificial-bee-colony-abc)
    - [Ant Colony Optimization (ACO)](#ant-colony-optimization-aco)
    - [Simulated Annealing (SA)](#simulated-annealing-sa)
    - [Genetic Algorithm (GA)](#genetic-algorithm-ga)
    - [Reactive Greedy Randomized Adaptive Search Procedure (Reactive GRASP)](#reactive-greedy-randomized-adaptive-search-procedure-reactive-grasp)
  - [Metaheurísticas Escolhidas](#metaheurísticas-escolhidas)
    - [Ant Colony Optimization (ACO)](#ant-colony-optimization-aco)
    - [Genetic Algorithm (GA)](#genetic-algorithm-ga)
  - [Resultados](#resultados)
  - [Conclusão](#conclusão)

## Equipe:
<div>
  
  [<img src="https://avatars.githubusercontent.com/u/98399932?v=4" alt="João Victor Porto" width="100">](https://github.com/Joao-vpf)
  [<img src="https://avatars.githubusercontent.com/u/104952737?v=4" alt="João Pedro Lemes" width="100">](https://github.com/Lixomensch)
  
</div>

## Projeto:
### Sobre o Desafio:
O problema do Caixeiro Viajante é um desafio clássico de otimização, que busca determinar a rota mais eficiente ou de menor custo que um viajante deve seguir para visitar uma série de cidades e retornar ao ponto de origem, sem passar duas vezes pela mesma cidade. Originado no século 19, o PCV é amplamente estudado tanto como um problema teórico quanto por suas aplicações práticas em áreas como logística, planejamento de rotas e fabricação de circuitos eletrônicos. Este desafio envolve a resolução do Problema do Caixeiro Viajante (PCV) utilizando técnicas de otimização com meta-heurísticas (MH).

### Dados:
[![Static Badge](https://img.shields.io/badge/Edital%20do%20Desafio%20-%20PDF%20-%20red?style=for-the-badge&logo=files&logoColor=red
)](https://github.com/Lixomensch/I-desafio-em-otimizacao-com-metaheuristica/blob/main/Files/Edital/edital_Idesafio_Otimização%20com%20metaheurísticas.pdf)
[![Static Badge](https://img.shields.io/badge/Instâncias%20Utilizadas%20-%20txt%20-%20red?style=for-the-badge&logo=files&logoColor=red
)](https://github.com/Lixomensch/I-desafio-em-otimizacao-com-metaheuristica/tree/main/dataset)

### Hardware e Software Utilizados:

### Metaheurísticas Testadas:

#### Artificial Bee Colony (ABC):
A otimização por colônia de abelhas (ABC) é uma metaheurística inspirada no comportamento de busca de alimentos das abelhas. Desenvolvida por Karaboga em 2005, a ABC é um método de otimização estocástico que simula o comportamento de busca das abelhas enquanto procuram por alimento. É uma técnica de busca baseada em população que utiliza uma estratégia de exploração e explotação para encontrar soluções ótimas ou subótimas para problemas de otimização.

Inicialmente, uma população de soluções candidatas, chamadas de "abelhas empregadas", é aleatoriamente gerada. Cada abelha empregada é então enviada para explorar uma área do espaço de busca. A qualidade das soluções é avaliada usando uma função de aptidão (fitness), que mede o quão bom é um determinado candidato em relação ao objetivo da otimização.

Após uma fase de exploração inicial, as abelhas empregadas compartilham informações sobre as fontes de alimento que encontraram com outras abelhas na colônia, conhecidas como "abelhas observadoras". As abelhas observadoras então inspecionam as fontes de alimento com base nas informações compartilhadas pelas abelhas empregadas. Elas podem escolher uma fonte de alimento com base em sua qualidade e proximidade.

Além disso, há uma fase de "abelhas exploradoras", que é responsável pela introdução de diversidade na população. Essas abelhas exploradoras procuram aleatoriamente novas soluções no espaço de busca, o que ajuda a evitar a estagnação prematura em ótimos locais subótimos.

Ao longo das iterações do algoritmo, as abelhas empregadas, observadoras e exploradoras continuam a explorar o espaço de busca, compartilhando informações e ajustando suas posições com base nas melhores soluções encontradas até o momento.

![ABC image](images/ABC.jpg)

#### Ant Colony Optimization (ACO):
A Otimização por Colônia de Formigas (ACO) é uma metaheurística baseada em inspirações tiradas do comportamento das formigas ao procurarem comida. Desenvolvida por Marco Dorigo no início da década de 1990, a ACO é usada para resolver problemas de otimização, especialmente aqueles relacionados a problemas de caminho mais curto e problemas de roteamento.

Ele simula o comportamento coletivo das formigas ao procurarem caminhos entre a colônia e fontes de comida. Cada formiga, durante sua busca, deposita feromônios nos caminhos que percorre. A quantidade de feromônio depositada é proporcional à qualidade do caminho (ou à solução) encontrada. Os caminhos com mais feromônios são mais atraentes para outras formigas.

Além disso, há uma evaporação gradual dos feromônios ao longo do tempo. Isso impede que os caminhos continuem sendo atraentes indefinidamente, incentivando a exploração de novos caminhos pela colônia de formigas.

![ACO image](images/ACO.png)

#### Simulated Annealing (SA):
A metaheurística do recozimento simulado, ou Simulated Annealing (SA) em inglês, é uma técnica de otimização inspirada no processo físico de recozimento de materiais metálicos. Desenvolvida por Kirkpatrick, Gelatt e Vecchi em 1983, o SA é usado para encontrar soluções aproximadas para problemas de otimização complexos.

Funciona de forma semelhante ao recozimento de metal: começa com uma solução inicial e, em seguida, perturba essa solução iterativamente, aceitando movimentos que levam a soluções piores em certas condições probabilísticas. Isso permite que o algoritmo escape de ótimos locais subótimos e explore o espaço de busca de forma mais eficiente.

O algoritmo é guiado por uma função de custo (ou função de energia), que avalia a qualidade de uma solução. Durante a busca, o SA tenta minimizar essa função de custo, ou seja, encontrar uma solução que minimize o valor da função.

A chave para o sucesso do SA está na manipulação da temperatura. A temperatura controla a probabilidade de aceitar soluções piores durante a busca. No início, a temperatura é alta, o que permite aceitar movimentos que levam a soluções piores com uma certa probabilidade. Isso ajuda o algoritmo a escapar de ótimos locais subótimos e explorar o espaço de busca de forma mais ampla. À medida que a busca avança, a temperatura é gradualmente reduzida, o que reduz a probabilidade de aceitar soluções piores. Isso permite que o algoritmo se concentre em refinar a solução em torno de ótimos locais locais.

Uma vez que a temperatura atinge um valor mínimo, o algoritmo termina e retorna a melhor solução encontrada durante a busca.

![Annealing image](images/Annealing.png)

#### Genetic algorithm (GA):
A metaheurística genética é uma técnica de otimização baseada na evolução biológica e na genética. Desenvolvida por John Holland na década de 1960 e popularizada por Goldberg, ela é inspirada nos processos de seleção natural e evolução das espécies.

O funcionamento básico de um algoritmo genético (AG) começa com uma população inicial de soluções candidatas, chamadas de indivíduos. Cada indivíduo é representado como uma sequência de genes, onde cada gene codifica uma característica ou parte da solução para o problema de otimização. Esses indivíduos são então avaliados com base em uma função de adaptação (fitness), que mede o quão bom é um determinado indivíduo em relação ao objetivo da otimização

Em seguida, o AG emprega operadores genéticos, como seleção, cruzamento e mutação, para criar uma nova geração de indivíduos. Durante a seleção, os indivíduos mais aptos têm uma maior probabilidade de serem escolhidos para reprodução, enquanto os menos aptos têm uma menor probabilidade. Isso permite que os melhores indivíduos passem suas características para as gerações subsequentes.

Durante o cruzamento (ou crossover), os indivíduos selecionados são combinados para produzir descendentes. Isso é feito trocando partes de suas representações genéticas. A ideia é combinar boas características de diferentes indivíduos para produzir soluções potencialmente melhores.

A mutação introduz aleatoriedade no processo, alterando aleatoriamente alguns genes dos indivíduos. Isso ajuda a explorar novas regiões do espaço de busca e a evitar a estagnação prematura em ótimos locais subótimos.

O processo de seleção, cruzamento e mutação é repetido ao longo de várias gerações até que uma condição de parada seja atingida, como um número máximo de gerações ou a convergência para uma solução satisfatória.

![Genetic image](images/Genetic.png)

#### Reactive Greedy Randomized Adaptive Search Procedure (Reactive GRASP)

O Reactive GRASP (Reactive Greedy Randomized Adaptive Search Procedure) é uma variante do GRASP (Greedy Randomized Adaptive Search Procedure), uma metaheurística que combina a estratégia gulosa (greedy) com uma componente aleatória para resolver problemas de otimização combinatória.

A estratégia gulosa é caracterizada pela escolha da melhor opção local em cada iteração, enquanto a aleatoriedade permite escapar de mínimos locais, explorando diferentes regiões do espaço de busca. O GRASP tradicional constrói uma solução inicial de forma gulosa e então realiza buscas locais em torno dessa solução para refiná-la.

O Reactive GRASP introduz uma variação adicional no processo, adaptando a estratégia gulosa com base no desempenho recente do algoritmo. Isso significa que, ao longo do tempo, a estratégia gulosa pode mudar para explorar diferentes áreas do espaço de busca. Essa adaptação é feita com base em informações coletadas durante a execução do algoritmo, como a qualidade das soluções encontradas.

O Reactive GRASP é particularmente eficaz em problemas onde as características do espaço de busca mudam ao longo do tempo, ou onde diferentes regiões do espaço de busca requerem diferentes abordagens de busca. Ele equilibra a exploração do espaço de busca com a exploração local, o que pode levar a uma melhor convergência para soluções de alta qualidade.

Essa abordagem reativa torna o algoritmo mais flexível e adaptável a diferentes tipos de problemas de otimização. O Reactive GRASP tem sido aplicado com sucesso em uma variedade de problemas, incluindo problemas de escalonamento, problemas de roteamento, problemas de design e muitos outros em diferentes áreas, como logística, engenharia, computação e finanças.

### Metaheurísticas Escolhidas:

#### Genetic algorithm (GA):

### Instâncias Utilizadas:
As instâncias utilizadas para testar nosso algoritmo foram obtidas da Universidade de Waterloo, localizada no Canadá.

Os conjuntos de dados foram selecionados a partir de duas fontes principais:

1. **Problemas Nacionais do Caixeiro Viajante (National Traveling Salesman Problems)**:
   - Fonte: [Página da Universidade de Waterloo sobre Problemas do Caixeiro Viajante em Nível Nacional](https://www.math.uwaterloo.ca/tsp/world/countries.html)
   - Instâncias Utilizadas:
     - Djibouti - 38 cidades
     - Qatar - 194 cidades
     - Uruguai - 734 cidades
     - Luxemburgo - 980 cidades

2. **Conjuntos de Dados VLSI (VLSI Data Sets)**:
   - Fonte: [Página da Universidade de Waterloo sobre Conjuntos de Dados VLSI](https://www.math.uwaterloo.ca/tsp/vlsi/index.html#XQF131)
   - Instâncias Utilizadas:
     - xqf131 - 131 pontos

Essas instâncias foram escolhidas por sua representatividade e desafio computacional, cobrindo uma variedade de tamanhos de problema que variam de pequenos conjuntos de cidades a conjuntos de dados VLSI mais complexos.

# Resultados:

## Tecnicas de otimização:

- opt_1: Otimizador conhecido como Single Swap Mutation Operator, em que é escolhido de forma aleatoria dois pontos no caminho que são trocados.
- opt_2: Otimizador conhecido como Inversion Mutation Operator, em que é percorrido todos os pares com n cidades e esses pares de posições são invertidos.
- opt_2s: É o mesmo otimizador do opt_2, contudo se difere em que é escolhido de forma aleatoria dois pontos e todo o caminho entre eles é invertido.

## Metaheurísticas Escolhidas:

#### Genetic algorithm (GA):
A metaheurística genética utilizada tiveram algumas alterações e implementações extras para melhoria na eficiencia, organização e desempenho comparado ao algoritmo base. Podemos listar todos os parametros implemetentados que sÃo:

- max_generations: Número máximo de gerações.
- max_population: Número máximo de genes na população.
- opt_range: Define a probabilidade de um gene ser selecionado na faixa de otimização. (Quanto maior mais mutante)
- opt_path_swap_it: Define o número de simulações no otimizador de caminho. (Mais iterações na otimização)
- tx_elite: Define a taxa de elitismo na população.
- verbose: Define se ativar ou não o modo verboso.
- simple_verbose: Define se ativar ou não o modo de verbosidade simples.
- alpha: Porcentagem do gene pai relativa ao gene da mãe. (Apenas para o crossover AHCAVG)
- balance: Define em relação à boa porcentagem da população que será usada para a nova geração (0 define como nenhum elitismo para a geração).
- tx_mutation_AHCAVG: Define a taxa de mutação na média aritmética. (Apenas para o crossover AHCAVG)
- fix_init: Define se haverá um número inicial fixo (-1 define como não existente).
- P_value: Define quantos pais foram considerados. (Apenas para o crossover VR)
- P_limiar: Define a quantidade mínima necessária para a cidade e para aparecer na mesma posição dos pais. (Apenas para o crossover VR)
cross_active: Armazena quais cruzamentos estão ativos ("BCR" -> Cruzamento da Melhor Rota de Custo, "AHCAVG" -> Média Aritmética desativada, "ER" -> Cruzamento de Recombinação de Borda, "VR" -> Cruzamento de Recombinação de Votação, "PMX" -> Cruzamento PMX).

No algoritmo genético, podemos dividir o processo em cinco etapas: ordenação da população com base no fitness, seleção dos genes por meio do elitismo, aplicação do crossover entre dois indivíduos para gerar novos genes, mutação de indivíduos ou a sua otimização e, por fim, salvar os novos genes para a próxima geração.

**Ordenação da população com base no fitness: ** Nessa etapa ocorre a ordenação da população em que aqueles com menor fitnees ficam em primeiro e os com maior fitness ficam por ultimo. <br>
**Seleção dos genes por meio do elitismo: ** Nessa etapa ocorre a seleção com base na **tx_elite** em que a uma porcentagem da população é salva diretamente para a nova geração e durante isso esse individuo é otimizado usando a tecnica 2 de otimização.

#### Metaheurísticas Descartadas no Projeto

- **Artificial Bee Colony (ABC):**
  - O ABC é uma técnica poderosa de otimização inspirada no comportamento das abelhas. Durante sua implementação, desenvolvemos um algoritmo simples e teórico. No entanto, nos testes realizados, o algoritmo não produziu resultados satisfatórios. Embora tenha apresentado um tempo de execução eficiente, observamos um erro considerável em comparação com as soluções conhecidas das instâncias utilizadas. Na busca por melhorias, não encontramos literatura adequada para otimizá-lo especificamente para problemas de TSP. Diante disso, optamos por descartar o ABC em favor de um algoritmo mais robusto com o qual já tínhamos familiaridade.

- **Simulated Annealing (SA):**
  - O SA é um algoritmo amplamente conhecido na área de otimização. Durante sua primeira implementação, sua teoria parecia simples e direta. No entanto, encontramos um desafio significativo: ele frequentemente ficava preso em ótimos locais subótimos devido à sua estrutura simples e à falta de aleatoriedade suficiente. Diante dessa limitação, decidimos descartá-lo em favor de um algoritmo mais robusto, capaz de oferecer maior flexibilidade na otimização e explorar uma gama mais ampla de soluções.

- **Reactive Greedy Randomized Adaptive Search Procedure (Reactive GRASP):**
  - O Reactive GRASP surge de uma lógica simples que utiliza um método guloso para resolver o TSP. Sua variante "Reactive GRASP" introduz a ideia de ter um array de coeficientes alpha, juntamente com o uso de probabilidades, para evitar ficar preso em ótimos locais subótimos. Inicialmente, ele mostrou-se muito promissor, com uma estrutura robusta capaz de se aproximar consideravelmente do ótimo global e, em alguns casos, até alcançá-lo. No entanto, sua maior limitação revelou-se ser o tempo de execução, especialmente em instâncias grandes, devido principalmente à sua função de "busca local". Por esse motivo, optamos por um algoritmo que fornecesse resultados satisfatórios em um tempo de execução menor.

### Conclusão: 
