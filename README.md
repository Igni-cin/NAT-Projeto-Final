# Projeto-Final
Este projeto tem como objetivo instruir a instalação e utilização da ferramenta Open Source [Mull](https://github.com/mull-project/mull?tab=readme-ov-file), **Mull** é uma ferramenta baseada em LLVM/Clang capaz de injetar e achar mutações em programas baseados em C/C++.

# Requisitos para funcionamento
- LLVM (versão compatível com Mull)
- Clang
- **Obs.: para o funcionamento perfeito desse tutorial é essencial a utilização do SOP Ubuntu 24.04.2 LTS e as versões clang-18(18.1.3), mesmo que as intruções do repositório sejam bem claras quanto a compatibilidade das versões 20.04/22.04 do Ubuntu e llvm/Clang do 12 ao 18, acontecem muitos problemas pra compatibilizar com o repositório atual.**

# Instalação da ferramenta
Para configurar o repositório apt para inserir o **Mull** basta inserir:

```bash
"curl -1sLf 'https://dl.cloudsmith.io/public/mull-project/mull-stable/setup.deb.sh' | sudo -E bash"
```

Instalar a versão recente do Mull:

```bash
sudo apt-get update
sudo apt-get install mull-18
```

Verificar se instalação e versão:

```bash
mull-runner-18 --version
```
Resultado esperado: 
```bash
Mull: Practical mutation testing for C and C++
Home: https://github.com/mull-project/mull
Docs: https://mull.readthedocs.io
Support: https://mull.readthedocs.io/en/latest/Support.html
Version: 0.25.0
Commit: 319e8b0
Date: 01 Mar 2025
LLVM: 18.1.3
```
Concluidos esse passos o **Mull** já está funcional

# Testando funcionalidades
Para testar as funcionalidades basta clonar esse repositório inserindo:

```bash
"git clone https://github.com/Igni-cin/NAT-Projeto-Final.git"
```
Clonado o repositorio, entre na pasta:
```bash
cd NAT-Projeto-Final
```
dentro dessa pasta temos dois diretorios (calculator e triangle), o calculator contém um arquivo calculator.c que simula algumas funções de uma calculadora, já o triangle possui dois arquivos o triangle.c e o mull.yml que realizam, respectivamente, a identificação das caracteristicas de um triangulo e quais mutantes serão gerados ao realizarmos as compilações:

Primeiro teste
```bash
cd calculator
```
Compilação do binário da calculadora
```bash
cd calculator
```
Conferir presença de mutantes
```bash
mull-runner-18 ./calculator
```
Resultador esperado
```bash
[warning] Could not find dynamic library: libc.so.6
[info] Warm up run (threads: 1)
       [################################] 1/1. Finished in 1ms
[info] Filter mutants (threads: 1)
       [################################] 1/1. Finished in 0ms
[info] Baseline run (threads: 1)
       [################################] 1/1. Finished in 2ms
[info] No mutants found. Mutation score: infinitely high
[info] Total execution time: 5ms
```

```bash
mull-runner-18 ./calculator
```
Resultados
```bash
[warning] Could not find dynamic library: libc.so.6
[info] Warm up run (threads: 1)
       [################################] 1/1. Finished in 2ms
[info] Filter mutants (threads: 1)
       [################################] 1/1. Finished in 0ms
[info] Baseline run (threads: 1)
       [################################] 1/1. Finished in 1ms
[info] Running mutants (threads: 8)
       [################################] 9/9. Finished in 48ms
[info] Survived mutants (1/9):
/home/igor/mull_tests/calculator.c:25:15: warning: Survived: Replaced > with >= [cxx_gt_to_ge]
    return (a > b) ? a : b;
              ^
[info] Mutation score: 88%
[info] Total execution time: 51ms
[info] Surviving mutants: 1
```
