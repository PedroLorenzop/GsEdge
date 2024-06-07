
Analise Das Condicoes do oceano
-

Este projeto visa monitorar parâmetros críticos da qualidade da água, utilizando a tecnologia Arduino para fornecer dados em tempo real sobre pH, turbidez e temperatura. Essas informações são essenciais para a preservação do ecossistema marinho e para a conscientização pública sobre a saúde dos oceanos.



## Componentes Utilizados
- Arduino Uno
- Sensor DHT22 para temperatura
- Fotorresistor para turbidez
- Potenciômetro para simulação do sensor de pH
- LEDs (vermelho, verde e azul) para indicação de pH
- Buzzer
- Display LCD I2C
- Resistores e jumpers
## Descrição do projeto

Leitura de pH:

    - Utiliza um potenciômetro para simular a leitura de um sensor de pH.
    - LEDs indicam se a água é ácida (vermelho), neutra (verde) ou básica (azul).
    - O buzzer emite som se a água for ácida, com variações de frequência.

Leitura de Turbidez:

    - Usa um fotorresistor para medir a turbidez da água, convertendo o valor para NTU (Unidade Nefelométrica de Turbidez).
    - Exibe a turbidez no display LCD.

Leitura de Temperatura:

    - Utiliza um sensor DHT22 para medir a temperatura da água.
    - Exibe a temperatura no display LCD.

Integração com Display LCD:

    - os valores de pH, turbidez e temperatura alternadamente.
## Conclusão 
Este projeto proporciona um método eficaz e acessível para monitorar a qualidade da água dos oceanos. Através da combinação de sensores e tecnologia Arduino, é possível obter dados críticos em tempo real, auxiliando na preservação do ecossistema marinho e na conscientização pública.
## 🔗 Links do projeto
[Projeto](https://wokwi.com/projects/399722347389581313)


## Autores

- [@Pedro de Lorezno](https://github.com/PedroLorenzop) (RM554730)
- [@Vinicius Castro](https://github.com/ViniciusCastroo) (RM556137)
- [@Metheus Cantiere](https://github.com/matheuscantiere) (RM558479)


## Licença

[MIT](https://choosealicense.com/licenses/mit/)

