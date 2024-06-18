TAD Data
A TAD Data é uma classe projetada para organizar os dias da semana e os horários de maneira estruturada, facilitando a associação com as demais TADs do projeto.

Estrutura de Dados
Dias da Semana
Os dias da semana são representados por uma variável inteira que varia de 1 a 7, onde cada número corresponde a um dia específico da semana (por exemplo, 1 para segunda-feira, 2 para terça-feira, e assim por diante).

Horários
Cada dia é subdividido em quatro períodos:

Madrugada: 00:00 - 06:00
Manhã: 06:00 - 12:00
Tarde: 12:00 - 18:00
Noite: 18:00 - 00:00
Esses períodos são representados por um array de 4 bits, onde cada bit pode ser 0 ou 1. Cada posição no array indica se o período correspondente está ativo (1) ou inativo (0). Por exemplo, o horário que cobre apenas a manhã seria representado como 0010 (Noite = 0; Tarde = 0; Manhã = 1; Madrugada = 0).

Implementação
Todos esses dados são organizados em um vetor denominado schedule, que armazena os dias da semana junto com seus respectivos horários. Essa estrutura permite uma fácil manipulação e consulta dos horários disponíveis para cada dia.

Benefícios
Organização: Facilita a associação e manipulação dos dias e horários.
Eficiência: Representação compacta utilizando apenas 4 bits para os horários.
Flexibilidade: Permite fácil expansão e integração com outras TADs do projeto.
