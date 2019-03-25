# TrabalhoRamses_19_1
Trabalho do Ramses para a cadeira de ARQ1 (2019/1), contendo arquivo fonte em .c e .rad

Descrição do trabalho disponível em: https://moodle.inf.ufrgs.br/pluginfile.php/69094/mod_resource/content/25/TrabalhoRamses_19_1_Rev1.pdf

Resumidamente, o programa deve ler um vetor de valores de 16 bits alocados em espaços de 8 bits, inverter cada parte (MSB (byte mais significativo) e LSB (byte menos significativo)).
Por exemplo: o valor de 16 bits 1010010100001010 é alocado como valores de 8 bits: 10100101 e 00001010. O primeiro deverá ser invertido para 01011010 e o segundo para: 10100000.
Após, as partes de 8 bits devem ser invertidas entre si. No exemplo, as partes de 8 bits invertidas 01011010 e 10100000 se juntarão num valor de 16 bits 1010000001011010).
O processo é feito com todos os valores do vetor, ao que os valores finais após as inversões deverão ser somados em um número final de 16 bits, que por sua vez será também invertido no mesmo algoritmo, gerando o resultado final da execução.

Qualquer cópia dos códigos, seja parcial ou total, é expressamente proibida, tendo em vista a anulação do trabalho para todas as partes caso constatado plágio.
