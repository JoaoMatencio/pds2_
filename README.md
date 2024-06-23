# <p style="text-align: center;"> Sistema de Automação Residencial com Possibilidade de Implementação de IA</p>


## Descrição 
O programa aqui implementado tem como objetivo permitir ou restringir o acesso de usuários cadastrados previamente as áreas de uma residência, assim como realizar o monitoramento de tais áreas durante o seu acesso.



### Classe `Administrador`: 
À classe `Administrador` caberá a tarefa de incluir usuários num container tipo MAP, cujas chaves serão os nomes dos usuários e os valores serão objetos do tipo user.  Ela ainda terá como função realizar a pesquisa de usuários, ......

### Classe `User`:
A classe `User` tem como objetivo representar os indivíduos autorizados a acessar áreas específicas dentro de um sistema de automação residencial. Cada usuário é identificado por um número único de identificação (userID) e um nome associado.

### Classe `Permissão`:
A classe `Permissão` será responsável por receber dados do usuário, como dia, horário e local, e determinar se o usuário pode ou não entrar no local especificado. Esta classe será capaz de verificar as condições de permissão com base nas informações fornecidas e retornará uma resposta indicando se o acesso é permitido ou negado. A classe Permissão ainda terá a função de registrar e gerenciar essas permissões, garantindo que as regras de acesso sejam rigorosamente seguidas.

### Classe `Data`:
A classe `Data` é projetada para organizar os dias da semana e os horários de maneira estruturada, associando-os eficientemente com outras TADs do projeto. Os dias da semana são representados por um número inteiro de 1 a 7, correspondendo a cada dia de segunda-feira a domingo. Cada dia é dividido em quatro períodos - madrugada, manhã, tarde e noite - representados por um array de 4 bits, onde cada bit indica se o período está ativo (1) ou inativo (0). Os dados são armazenados em um vetor chamado schedule, permitindo uma fácil manipulação e consulta dos horários para cada dia. Esta organização oferece benefícios de eficiência, flexibilidade e uma representação compacta, facilitando a integração com outras partes do projeto.

### Classe `Status`
A classe `Status` é responsável por monitorar e registrar o estado da porta e os logs de eventos relacionados ao seu status. Ela oferece métodos para abrir e fechar a porta, além de escrever, ler e modificar os logs de eventos. A classe `Status` garante que todas as operações realizadas na porta sejam registradas de forma detalhada, proporcionando uma maneira eficiente de rastrear e verificar o histórico de acessos e alterações no estado da porta.

